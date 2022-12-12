#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Event.h"


// 환형버퍼 (큐) 구조체
typedef struct Circle_Queue
{
	Event* pEv;
	int capacity;
	int front;
	int end;
	int num_elements;
} CirQ;



CirQ* initCirQ(CirQ* pCirQ, int capacity); // 환형버퍼(큐) 구조체 동적메모리할당 및 초기값 set
void fprintCirQ(FILE* fout, CirQ* pCirQ); // 파일출력
bool isCirQFull(CirQ* pCirQ); // 큐가 차있는가
bool isCirQEmpty(CirQ* pCirQ); // 큐가 비어있는가
Event* enCirQ(CirQ* pCirQ, Event ev); // 이벤트 추가 _ FIFO 이므로 마지막에 추가
Event* deCirQ(CirQ* pCirQ); // 이벤트 줄이기 _ FIFO 이므로 앞에서부터 제거 _ 환형이므로 첫번째가 뒤로 밀림
void delCirQ(CirQ* pCirQ); // 환형버퍼 동적할당 해제



#endif 