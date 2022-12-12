#ifndef EVENT_H
#define EVENT_H
#pragma warning(disable: 4996) // scanf���� �ȶ߰� �ϴ� pragma���� 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define EVENT_PER_LINE 1// �ؽ�Ʈ���� ��� _ �ٹٲ� ����


// Event ����ü ����
typedef struct EVENTS
{
	int event_no; // �̺�Ʈ �ѹ�
	int event_gen_addr; // �̺�Ʈ ���� �ּ�
	int event_pri; // �̺�Ʈ �켱����
} Event;


Event* genEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri); // �̺�Ʈ ����
void initEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri); // �̺�Ʈ �ʱⰪ set
void printEvent(Event* pEv); // �̺�Ʈ ����â ���
void fprintEvent(FILE* fout, Event* pEv); // �̺�Ʈ �ؽ�Ʈ���� ���

#endif 