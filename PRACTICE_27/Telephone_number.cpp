#include "Telephone_number.h"

void printTelephoneNumber(TEL_NUMBER telNo)
{
	printf("(tel: +%d-", telNo.nation_code);
	printf("%03d-%04d-%04d)", telNo.region_no, telNo.switch_no, telNo.line_no);
}

int compareTelNumber(TEL_NUMBER tn1, TEL_NUMBER tn2)
{
	if (tn1.nation_code > tn2.nation_code)
		return 1;
	else if (tn1.nation_code < tn2.nation_code)
		return -1;


	else if (tn1.region_no > tn2.region_no)
		return 1;
	else if (tn1.region_no < tn2.region_no)
		return -1;


	else if (tn1.switch_no > tn2.switch_no)
		return 1;
	else if (tn1.switch_no < tn2.switch_no)
		return -1;


	else if (tn1.line_no > tn2.line_no)
		return 1;
	else if (tn1.line_no < tn2.line_no)
		return -1;


	else
		return 0;
}