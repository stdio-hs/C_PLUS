#include "Event.h"

// �̺�Ʈ ����
Event* genEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri)
{
	pEv = (Event*)calloc(1, sizeof(Event));
	if (pEv == NULL)
	{
		printf("ERROR!! Not Generated Events in memory\n");
		exit(-1);
	}
	initEvent(pEv, ev_no, ev_genID, ev_pri); // ( �ʱⰪ set ) �Լ� Ȱ��

	return pEv;
}

// �̺�Ʈ �ʱⰪ set
void initEvent(Event* pEv, int ev_no, int ev_genID, int ev_pri)
{
	pEv->event_no = ev_no; // �̺�Ʈ�ѹ�
	pEv->event_gen_addr = ev_genID;
	pEv->event_pri = ev_pri; // �켱����
}

// �̺�Ʈ ����â ���
void printEvent(Event* pEv)
{
	printf("Ev(no: %3d, pri: %2d) ", pEv->event_no, pEv->event_pri);
}

// �̺�Ʈ �ؽ�Ʈ���� ���
void fprintEvent(FILE* fout, Event* pEv)
{
	fprintf(fout, "Ev(no:%3d, pri:%2d) ", pEv->event_no, pEv->event_pri);
}