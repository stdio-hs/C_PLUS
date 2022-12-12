
#include "CircularQueue.h"

// ȯ������(ť) ����ü �����޸��Ҵ� �� �ʱⰪ set
CirQ* initCirQ(CirQ* pCirQ, int capacity)
{
	Event* pEv;


	// �����޸��Ҵ� 
	// 1�����迭 : ������ ����. but ����� �̸� �˾ƾ� ��.
	// ����Ʈ : ������ �����. but ���ѵ� ������κ��� �����ο�.
	pEv = (Event*)calloc(capacity, sizeof(Event));
	if (pEv == NULL)
	{
		printf("ERROR!! Not Generated Events in memory\n");
		exit(-1);
	}


	//�ʱⰪ set
	pCirQ->pEv = pEv;
	pCirQ->capacity = capacity;
	pCirQ->front = pCirQ->end = 0;
	pCirQ->num_elements = 0;
	return pCirQ;
}

// �������
void fprintCirQ(FILE* fout, CirQ* pCirQ)
{
	Event ev;
	int index; // �̺�Ʈ ���� ��ȣ

	// �������_1 ( ȯ������(ť) ���� �̺�Ʈ ����, ȯ������(ť) ���� �� ó�� �̺�Ʈ�� �ε��� ��ȣ)
	fprintf(fout, " %2d Elements in CirQ_Event (index_front:%2d) :\n", pCirQ->num_elements, pCirQ->front);

	if (isCirQEmpty(pCirQ)) // (ť�� ����ִ°�) �Լ� Ȱ��
	{
		fprintf(fout, "pCirQ_Event is Empty");
	}
	else
	{
		fprintf(fout, "\t");

		// ȯ������(ť) �ȿ� �ִ� �̺�Ʈ�� ���� ���� ���
		for (int i = 0; i < pCirQ->num_elements; i++)
		{
			index = pCirQ->front + i; // ȯ�����ο��� �� ù��°�� �������� +1�� �ε��� ��ȣ set
			if (index >= pCirQ->capacity) // ���� �ε��� ��ȣ�� �ִ�ġ(capacity)�� �����ϸ�,
				index %= pCirQ->capacity; // �ε�����ȣ �ٽ� ó���� 0���� set

			ev = pCirQ->pEv[index]; // �ε��� ��ȣ�� �´� �̺�Ʈ�� ������
			fprintEvent(fout, &ev); // ���� ���_2 ( �̺�Ʈ���� )

			if ((i + 1) % EVENT_PER_LINE == 0 && (i + 1) != pCirQ->num_elements) // �ٹٲ�
				fprintf(fout, "\n\t");
		}
		fprintf(fout, "\n");
	}
}

// �ش� ��Ʈ�� ���ִ°�
bool isCirQFull(CirQ* pCirQ)
{
	if (pCirQ->num_elements == pCirQ->capacity)
		return true;
	else
		return false;
}

// �ش� ��Ʈ�� ����ִ°�
bool isCirQEmpty(CirQ* pCirQ)
{
	if (pCirQ->num_elements == 0)
		return true;
	else
		return false;
}

// �̺�Ʈ �߰� _ FIFO �̹Ƿ� �������� �߰�
Event* enCirQ(CirQ* pCirQ, Event ev)
{
	if (isCirQFull(pCirQ))
	{
		return NULL;
	}



	pCirQ->pEv[pCirQ->end] = ev; // ȯ������(ť) �ȿ��� ������ ��ȣ�� �̺�Ʈ ����
	pCirQ->num_elements++; // �����ɶ�����, �̺�Ʈ ���� �߰�
	pCirQ->end++; // �����ɶ�����, end ��ȣ ++


	 // ���� �ε��� ��ȣ�� �ִ�ġ(capacity)�� �����ϸ�,
	if (pCirQ->end == pCirQ->capacity)
	{
		pCirQ->end = pCirQ->end % pCirQ->capacity; // �ε�����ȣ �ٽ� ó���� 0���� set
	}

	return &(pCirQ->pEv[pCirQ->end]); // ������ �̺�Ʈ �ּ� ��ȯ
}

// �̺�Ʈ ���̱� _ FIFO �̹Ƿ� �տ������� ���� _ ȯ���̹Ƿ� ù��°�� �ڷ� �и�
Event* deCirQ(CirQ* pCirQ)
{
	if (isCirQEmpty(pCirQ))
	{
		return NULL;
	}


	Event* pEv = &(pCirQ->pEv[pCirQ->front]); // �� ó���� �ִ�(front) �̺�Ʈ�� �����´�.
	pCirQ->front++; // �̺�Ʈ ��ȣ �߰� ( ��ĭ�� �ڷ� �и��� ���� )
	pCirQ->num_elements--; // �����ɶ�����, end ��ȣ --

	 // ���� �ε��� ��ȣ�� �ִ�ġ(capacity)�� �����ϸ�,
	if (pCirQ->front == pCirQ->capacity)
		pCirQ->front = pCirQ->front % pCirQ->capacity; // �ε�����ȣ �ٽ� ó���� 0���� set


	return pEv; // �Ʊ� ���� �̺�Ʈ ��ȯ
}

// ȯ������ �����Ҵ� ����
void delCirQ(CirQ* pCirQ) // ȯ�� ť �����Ҵ� ���� �Լ� (��� ���� ���� ��, ����)
{
	if (pCirQ->pEv != NULL)
		free(pCirQ->pEv);
	pCirQ->pEv = NULL;
	pCirQ->num_elements = 0;
	pCirQ->front = pCirQ->end = 0;
	pCirQ->num_elements = 0;
}