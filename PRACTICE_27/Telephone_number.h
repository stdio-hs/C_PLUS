#ifndef TELEPHONE_H
#define TELEPHONE_H

#define U_SHORT unsigned short
#include <stdio.h>



typedef struct
{
	U_SHORT nation_code;
	U_SHORT region_no;
	U_SHORT switch_no;
	U_SHORT line_no;
} TEL_NUMBER;


void printTelephoneNumber(TEL_NUMBER telNo);
int compareTelNumber(TEL_NUMBER tn1, TEL_NUMBER tn2);



#endif // !TELEPHONE_H