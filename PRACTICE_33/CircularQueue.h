#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Event.h"


// ȯ������ (ť) ����ü
typedef struct Circle_Queue
{
	Event* pEv;
	int capacity;
	int front;
	int end;
	int num_elements;
} CirQ;



CirQ* initCirQ(CirQ* pCirQ, int capacity); // ȯ������(ť) ����ü �����޸��Ҵ� �� �ʱⰪ set
void fprintCirQ(FILE* fout, CirQ* pCirQ); // �������
bool isCirQFull(CirQ* pCirQ); // ť�� ���ִ°�
bool isCirQEmpty(CirQ* pCirQ); // ť�� ����ִ°�
Event* enCirQ(CirQ* pCirQ, Event ev); // �̺�Ʈ �߰� _ FIFO �̹Ƿ� �������� �߰�
Event* deCirQ(CirQ* pCirQ); // �̺�Ʈ ���̱� _ FIFO �̹Ƿ� �տ������� ���� _ ȯ���̹Ƿ� ù��°�� �ڷ� �и�
void delCirQ(CirQ* pCirQ); // ȯ������ �����Ҵ� ����



#endif 