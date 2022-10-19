#include "Date.h"

void printDate(DATE date)
{
	printf("(%04d, %2d, %2d)", date.year, date.month, date.day);
}

int compareDate(DATE d1, DATE d2)
{
	if (d1.year > d2.year)
		return 1;
	else if (d1.year < d2.year)
		return -1;


	else if (d1.month > d2.month)
		return 1;
	else if (d1.month < d2.month)
		return -1;


	else if (d1.day > d2.day)
		return 1;
	else if (d1.day < d2.day)
		return -1;


	else
		return 0;
}