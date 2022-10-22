#ifndef TIME_H
#define TIME_H

#include <stdio.h>

// Time ±¸Á¶Ã¼
typedef struct
{
	int hour;
	int min;
	int sec;
} Time;


// HW 9_1
Time inputDATA();
void outputDATA(const Time* time);
void incrementTime(Time* t, int incr_sec);
int compareTime(const Time* t1, const Time* t2);


// HW 9_2
Time inputDATA_2(int hour, int min, int sec);
void selectionSortTime(Time time[], const int size);


//int elapsedSeconds(const Time* t);
//void selectSortTime(Time* times, int size);

#endif