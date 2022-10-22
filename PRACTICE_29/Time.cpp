#include "Time.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


// HW 9_1

// �Է�
Time inputDATA()
{
	Time time;
	scanf_s("%d", &time.hour);
	scanf_s("%d", &time.min);
	scanf_s("%d", &time.sec);

	return time;
}

// ���
void outputDATA(const Time* time)
{
	printf("(% 03d : % 03d : % 03d)", time->hour, time->min, time->sec);
}

// (��) ����
void incrementTime(Time* time, int incr_secs)
{
	int A = time->hour;
	int B = time->min;
	int C = time->sec + incr_secs;
	int i = 0;

	if (C >= 60)
	{
		i = C / 60; // ������ �ø� �� ���
		B = B + i; // ������ �ø���
		C = C % 60; // ���� �� ���
	}

	if (B >= 60)
	{
		i = B / 60; // �÷� �ø� �� ���
		A = A + i; // �÷� �ø���
		B = B % 60; // ���� �� ���
	}

	if (A >= 24)
	{
		A = A % 24; // ���� �� ���
	}

	time->hour = A;
	time->min = B;
	time->sec = C;
}

// �ð� ��
int compareTime(const Time* t_1, const Time* t_2)
{
	int S_t1, S_t2;
	int diff;
	
	S_t1 = (t_1->sec) + (t_1->min * 60) + (t_1->hour * 60 * 60); // t_1 �� ���
	S_t2 = (t_2->sec) + (t_2->min * 60) + (t_2->hour * 60 * 60); // t_2 �� ���
	
	if (S_t2 < S_t1) // 23�� 59�� 59�ʸ� �Ѿ�� �Ǿ��� ��� ���� ��Ȳ.
	{
		S_t2 = S_t2 + 60 * 60 * 24; // ��� �� ����� 86400 (=60*60*24) �̸� �����Ͽ��� ��� �ۿ� ��� ����. �߰��ذ��� ����ʿ� 
	}

	diff = S_t2 - S_t1; // �ð� ����

	return diff;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


// HW 9_2

// �Է�_2
Time inputDATA_2(int hour, int min, int sec)
{
	Time time;

	time.hour = hour;
	time.min = min;
	time.sec = sec;

	return time;
}

// ����
void selectionSortTime(Time time[], int size)
{
	for (int a = 0; a < size; a++)
	{
		int b = a;
		for (int i = a + 1; i < size; i++) // �ּҰ� Ž��
		{
			int minT = time[b].sec + time[b].min * 60 + time[b].hour * 3600;
			int iT = time[i].sec + time[i].min * 60 + time[i].hour * 3600;
			b = (minT > iT) ? i : b;
		}
		if (b != a) // SWAP
		{
			Time temp = time[a];
			time[a] = time[b];
			time[b] = temp;
		}
	}
}