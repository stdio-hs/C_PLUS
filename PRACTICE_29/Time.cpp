#include "Time.h"

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


// HW 9_1

// 입력
Time inputDATA()
{
	Time time;
	scanf_s("%d", &time.hour);
	scanf_s("%d", &time.min);
	scanf_s("%d", &time.sec);

	return time;
}

// 출력
void outputDATA(const Time* time)
{
	printf("(% 03d : % 03d : % 03d)", time->hour, time->min, time->sec);
}

// (초) 증가
void incrementTime(Time* time, int incr_secs)
{
	int A = time->hour;
	int B = time->min;
	int C = time->sec + incr_secs;
	int i = 0;

	if (C >= 60)
	{
		i = C / 60; // 분으로 올릴 초 계산
		B = B + i; // 분으로 올리기
		C = C % 60; // 최종 초 계산
	}

	if (B >= 60)
	{
		i = B / 60; // 시로 올릴 분 계산
		A = A + i; // 시로 올리기
		B = B % 60; // 최종 분 계산
	}

	if (A >= 24)
	{
		A = A % 24; // 최종 시 계산
	}

	time->hour = A;
	time->min = B;
	time->sec = C;
}

// 시간 비교
int compareTime(const Time* t_1, const Time* t_2)
{
	int S_t1, S_t2;
	int diff;
	
	S_t1 = (t_1->sec) + (t_1->min * 60) + (t_1->hour * 60 * 60); // t_1 초 계산
	S_t2 = (t_2->sec) + (t_2->min * 60) + (t_2->hour * 60 * 60); // t_2 초 계산
	
	if (S_t2 < S_t1) // 23시 59분 59초를 넘어가게 되었을 경우 예외 상황.
	{
		S_t2 = S_t2 + 60 * 60 * 24; // 대신 이 방법은 86400 (=60*60*24) 미만 증가하였을 경우 밖에 사용 못함. 추가해결방법 고민필요 
	}

	diff = S_t2 - S_t1; // 시간 차이

	return diff;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


// HW 9_2

// 입력_2
Time inputDATA_2(int hour, int min, int sec)
{
	Time time;

	time.hour = hour;
	time.min = min;
	time.sec = sec;

	return time;
}

// 정렬
void selectionSortTime(Time time[], int size)
{
	for (int a = 0; a < size; a++)
	{
		int b = a;
		for (int i = a + 1; i < size; i++) // 최소값 탐색
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