#ifndef EVENT_H
#define EVENT_H
#pragma warning(disable: 4996) // scanf오류 안뜨게 하는 pragma정의 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define EVENT_PER_LINE 1// 텍스트파일 출력 _ 줄바꿈 관련


// Event 구조체 선언
typedef struct EVENTS
{
	int event_no; // 이벤트 넘버
	int event_gen_addr; // 이벤트 생성 주소
	int event_pri; // 이벤트 우선순위
} Event;


Event* genEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri); // 이벤트 생성
void initEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri); // 이벤트 초기값 set
void printEvent(Event* pEv); // 이벤트 실행창 출력
void fprintEvent(FILE* fout, Event* pEv); // 이벤트 텍스트파일 출력

#endif 