#ifndef DATE_H
#define DATE_H

#include <stdio.h>

typedef struct
{
	int year;
	int month;
	int day;
} DATE;


void printDate(DATE date);
int compareDate(DATE d1, DATE d2);


#endif // !DATE_H

