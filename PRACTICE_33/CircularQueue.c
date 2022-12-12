
#include "CircularQueue.h"

// 환형버퍼(큐) 구조체 동적메모리할당 및 초기값 set
CirQ* initCirQ(CirQ* pCirQ, int capacity)
{
	Event* pEv;


	// 동적메모리할당 
	// 1차원배열 : 구현이 쉬움. but 사이즈를 미리 알아야 함.
	// 리스트 : 구현이 어려움. but 제한된 사이즈로부터 자유로움.
	pEv = (Event*)calloc(capacity, sizeof(Event));
	if (pEv == NULL)
	{
		printf("ERROR!! Not Generated Events in memory\n");
		exit(-1);
	}


	//초기값 set
	pCirQ->pEv = pEv;
	pCirQ->capacity = capacity;
	pCirQ->front = pCirQ->end = 0;
	pCirQ->num_elements = 0;
	return pCirQ;
}

// 파일출력
void fprintCirQ(FILE* fout, CirQ* pCirQ)
{
	Event ev;
	int index; // 이벤트 순서 번호

	// 파일출력_1 ( 환형버퍼(큐) 내부 이벤트 개수, 환형버퍼(큐) 에서 맨 처음 이벤트의 인덱스 번호)
	fprintf(fout, " %2d Elements in CirQ_Event (index_front:%2d) :\n", pCirQ->num_elements, pCirQ->front);

	if (isCirQEmpty(pCirQ)) // (큐가 비어있는가) 함수 활용
	{
		fprintf(fout, "pCirQ_Event is Empty");
	}
	else
	{
		fprintf(fout, "\t");

		// 환형버퍼(큐) 안에 있는 이벤트에 대한 정보 출력
		for (int i = 0; i < pCirQ->num_elements; i++)
		{
			index = pCirQ->front + i; // 환형내부에서 맨 첫번째를 기준으로 +1로 인덱스 번호 set
			if (index >= pCirQ->capacity) // 만약 인덱스 번호가 최대치(capacity)에 도달하면,
				index %= pCirQ->capacity; // 인덱스번호 다시 처음인 0으로 set

			ev = pCirQ->pEv[index]; // 인덱스 번호에 맞는 이벤트를 가져옴
			fprintEvent(fout, &ev); // 파일 출력_2 ( 이벤트정보 )

			if ((i + 1) % EVENT_PER_LINE == 0 && (i + 1) != pCirQ->num_elements) // 줄바꿈
				fprintf(fout, "\n\t");
		}
		fprintf(fout, "\n");
	}
}

// 해당 파트가 차있는가
bool isCirQFull(CirQ* pCirQ)
{
	if (pCirQ->num_elements == pCirQ->capacity)
		return true;
	else
		return false;
}

// 해당 파트가 비어있는가
bool isCirQEmpty(CirQ* pCirQ)
{
	if (pCirQ->num_elements == 0)
		return true;
	else
		return false;
}

// 이벤트 추가 _ FIFO 이므로 마지막에 추가
Event* enCirQ(CirQ* pCirQ, Event ev)
{
	if (isCirQFull(pCirQ))
	{
		return NULL;
	}



	pCirQ->pEv[pCirQ->end] = ev; // 환형버퍼(큐) 안에서 마지막 번호에 이벤트 생성
	pCirQ->num_elements++; // 생성될때마다, 이벤트 개수 추가
	pCirQ->end++; // 생성될때마다, end 번호 ++


	 // 만약 인덱스 번호가 최대치(capacity)에 도달하면,
	if (pCirQ->end == pCirQ->capacity)
	{
		pCirQ->end = pCirQ->end % pCirQ->capacity; // 인덱스번호 다시 처음인 0으로 set
	}

	return &(pCirQ->pEv[pCirQ->end]); // 마지막 이벤트 주소 반환
}

// 이벤트 줄이기 _ FIFO 이므로 앞에서부터 제거 _ 환형이므로 첫번째가 뒤로 밀림
Event* deCirQ(CirQ* pCirQ)
{
	if (isCirQEmpty(pCirQ))
	{
		return NULL;
	}


	Event* pEv = &(pCirQ->pEv[pCirQ->front]); // 맨 처음에 있는(front) 이벤트를 가져온다.
	pCirQ->front++; // 이벤트 번호 추가 ( 한칸씩 뒤로 밀리기 때문 )
	pCirQ->num_elements--; // 생성될때마다, end 번호 --

	 // 만약 인덱스 번호가 최대치(capacity)에 도달하면,
	if (pCirQ->front == pCirQ->capacity)
		pCirQ->front = pCirQ->front % pCirQ->capacity; // 인덱스번호 다시 처음인 0으로 set


	return pEv; // 아까 얻은 이벤트 반환
}

// 환형버퍼 동적할당 해제
void delCirQ(CirQ* pCirQ) // 환형 큐 동적할당 해제 함수 (모든 것이 끝난 후, 해제)
{
	if (pCirQ->pEv != NULL)
		free(pCirQ->pEv);
	pCirQ->pEv = NULL;
	pCirQ->num_elements = 0;
	pCirQ->front = pCirQ->end = 0;
	pCirQ->num_elements = 0;
}