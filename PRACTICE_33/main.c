/*

파일명 : PRACRICE_32

프로그램의 목적 및 기본기능 : Circular Queue ( 환형 큐 ) 

프로그램 작성자 : 이현성

프로그램 작성일지 : 
2022년 05월 23일 _ 프로젝트 이해 및 공부 ( 유튜브 )
2022년 05월 24일 _ 프로젝트 완성
2022년 05월 25일 _ 프로젝트 수정

*/

#include "CircularQueue.h"

#define OUTPUT "output.txt"

#define GENERATE_EVENT 0 // 시작
#define NUMBER_OF_EVENTS 128 // 전체 사이즈
#define MAX_ROUND 100


void test_FIFO_CirQ_Event(FILE* fout, int max_events_P_round);

int main(void)
{
	// 텍스트파일열기 _ 쓰기모드
	FILE* fout = NULL;
	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("ERROR! output.txt does not OPEN!!\n");
		exit(-1);
	}

	// 환영큐_테스트함수 실행
	test_FIFO_CirQ_Event(fout, NUMBER_OF_EVENTS);

	// 파일닫기
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

	// 환형 큐 생성
	pCirQ_Event = (CirQ*)calloc(1, sizeof(CirQ));

	// 큐 생성 크기 출력
	printf("Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);
	fprintf(fout, "Initializing FIFO CirQ of capacity (%d)\n", max_events_P_round);


	// EVENT 구조체 삽입
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
				if (isCirQFull(pCirQ_Event)) // 만약 환형 큐가 차있으면
				{
					fprintf(fout, "   !!! CirQ_Event is full --> SKIP Generation and Enqueueing of Event. \n");
					break; // 그 즉시 종료한다.
				}

				pEv = genEvent(pEv, total_G_E, GENERATE_EVENT, NUMBER_OF_EVENTS - total_G_E - 1);


				fprintf(fout, ">>>>> Enqueue event = ");
				fprintEvent(fout, pEv);

				enCirQ(pCirQ_Event, *pEv);// enqueue
				fprintCirQ(fout, pCirQ_Event); // 이벤트1개 출력
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
		// 만약 Processe가 끝났다면( 모든 이벤트들을 Dequeue했다면) 반복문 중지
	}

	// ENQUE DEQUE 모두 실행창 출력
	printf("Processed Events : \n");
	for (int i = 0; i < NUMBER_OF_EVENTS; i++)
	{
		printf("Ev(id: %3d, pri: %3d), ", Processed_Events[i].event_no, Processed_Events[i].event_pri);
		printf("\n");
	}
	printf("\n");


	delCirQ(pCirQ_Event); // 동적메모리 반환
}
