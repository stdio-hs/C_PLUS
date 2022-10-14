#include "Code.h"




double average_value(double x, double y) // call-by-value
{
	double result;

	result = (x + y) / 2.0;
	return result;
}

double average_pointer(double* px, double* py) // call-by-pointer
{
	double result;

	result = (*px + *py) / 2.0;
	return result;
}

void average_reference(double x, double y, double& result) // call-by-reference
{
	result = (x + y) / 2.0;
}
