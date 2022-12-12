/*

���ϸ� : PRACRICE_32

���α׷��� ���� �� �⺻��� : Circular Queue ( ȯ�� ť ) 

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 
2022�� 05�� 23�� _ ������Ʈ ���� �� ���� ( ��Ʃ�� )
2022�� 05�� 24�� _ ������Ʈ �ϼ�
2022�� 05�� 25�� _ ������Ʈ ����

*/

#include "CircularQueue.h"

#define OUTPUT "output.txt"

#define GENERATE_EVENT 0 // ����
#define NUMBER_OF_EVENTS 128 // ��ü ������
#define MAX_ROUND 100


void test_FIFO_CirQ_Event(FILE* fout, int max_events_P_round);

int main(void)
{
	// �ؽ�Ʈ���Ͽ��� _ ������
	FILE* fout = NULL;
	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("ERROR! output.txt does not OPEN!!\n");
		exit(-1);
	}

	// ȯ��ť_�׽�Ʈ�Լ� ����
	test_FIFO_CirQ_Event(fout, NUMBER_OF_EVENTS);

	// ���ϴݱ�
	fclose(fout);
	return 0;
}


void test_FIFO_CirQ_Event(FILE* fout, int max_events_P_round)
{
	CirQ* pCirQ_Event;
	Event* pEv = NULL;
	Event Processed_Events[NUMBER_OF_EVENTS];

	int total_P_E = 0;
	int total_G_E = 0;
	int num_events = 0;
	int num_G_R = 0;
	int num_P_R = 0;

	// ȯ�� ť ����
	pCirQ_Event = (CirQ*)calloc(1, sizeof(CirQ));

	// ť ���� ũ�� ���
	printf("Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);
	fprintf(fout, "Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);


	// EVENT ����ü ����
	pCirQ_Event = initCirQ(pCirQ_Event, max_events_P_round);



	for (int round = 0; round < MAX_ROUND; round++)
	{

		// << ENQUE >>
		if (total_G_E < NUMBER_OF_EVENTS)
		{
			num_events = max_events_P_round;
			if (total_G_E + num_events > NUMBER_OF_EVENTS)
				num_events = NUMBER_OF_EVENTS - total_G_E;
			fprintf(fout, "Generated and enque %2d events\n", num_events);
			num_G_R = 0;


			for (int i = 0; i < num_events; i++)
			{
				if (isCirQFull(pCirQ_Event)) // ���� ȯ�� ť�� ��������
				{
					fprintf(fout, "   !!! CirQ_Event is full --> SKIP Generation and Enqueueing of Event. \n");
					break; // �� ��� �����Ѵ�.
				}

				pEv = genEvent(pEv, total_G_E, GENERATE_EVENT, NUMBER_OF_EVENTS - total_G_E - 1);


				fprintf(fout, ">>>>> Enqueue event = ");
				fprintEvent(fout, pEv);

				enCirQ(pCirQ_Event, *pEv);// enqueue
				fprintCirQ(fout, pCirQ_Event); // �̺�Ʈ1�� ���
				free(pEv);
				total_G_E++;
				num_G_R++;
			}


			// << DEQUE >>
			fprintf(fout, "\nDequeuing Data from Event Circular queue: \n");
			num_events = max_events_P_round;

			if ((total_P_E + num_events) > NUMBER_OF_EVENTS)
				num_events = NUMBER_OF_EVENTS - total_P_E;

			fprintf(fout, "Dequeue %2d events\n", num_events);
			num_P_R = 0;
			for (int i = 0; i < num_events; i++)
			{
				if (isCirQEmpty(pCirQ_Event))
					break;
				pEv = deCirQ(pCirQ_Event);
				if (pEv != NULL)
				{
					fprintf(fout, "<<< Dequeued event = ");
					fprintEvent(fout, pEv);
					fprintf(fout, "\n");
					Processed_Events[total_P_E] = *pEv;
					total_P_E++;
					num_P_R++;
				}
				fprintCirQ(fout, pCirQ_Event);
			}
		}
		if (total_P_E >= NUMBER_OF_EVENTS)
			break;
		// ���� Processe�� �����ٸ�( ��� �̺�Ʈ���� Dequeue�ߴٸ�) �ݺ��� ����
	}

	// ENQUE DEQUE ��� ����â ���
	printf("Processed Events : \n");
	for (int i = 0; i < NUMBER_OF_EVENTS; i++)
	{
		printf("Ev(id: %3d, pri: %3d), ", Processed_Events[i].event_no, Processed_Events[i].event_pri);
		printf("\n");
	}
	printf("\n");


	delCirQ(pCirQ_Event); // �����޸� ��ȯ
}
