#include "Event.h"

// 이벤트 생성
Event* genEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri)
{
	pEv = (Event*)calloc(1, sizeof(Event));
	if (pEv == NULL)
	{
		printf("ERROR!! Not Generated Events in memory\n");
		exit(-1);
	}
	initEvent(pEv, ev_no, ev_genID, ev_pri); // ( 초기값 set ) 함수 활용

	return pEv;
}

// 이벤트 초기값 set
void initEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri)
{
	pEv->event_no = ev_no; // 이벤트넘버
	pEv->event_gen_addr = ev_genID;
	pEv->event_pri = ev_pri; // 우선순위
}

// 이벤트 실행창 출력
void printEvent(Event* pEv)
{
	printf("Ev(no: %3d, pri: %2d) ", pEv->event_no, pEv->event_pri);
}

// 이벤트 텍스트파일 출력
void fprintEvent(FILE* fout, Event* pEv)
{
	fprintf(fout, "Ev(no:%3d, pri:%2d) ", pEv->event_no, pEv->event_pri);
}