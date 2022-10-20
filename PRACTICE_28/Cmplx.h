/*

���ϸ� : PRACTICE_28

���α׷��� ���� �� �⺻��� : ����ü _ ���Ҽ�

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 05�� 10�� _ ������Ʈ ���� �� �ϼ�

*/


#ifndef CMPLX_H
#define CMPLX_H

#include <stdio.h>
#include <math.h>

// ����ü
typedef struct _Cmplx
{
	double real;
	double imaginary;
	double magnitude;
} Cmplx;


void printCmplx(const Cmplx c);
Cmplx addCmplx(const Cmplx c1, const Cmplx c2);
Cmplx subtractCmplx(const Cmplx c1, const Cmplx c2);
Cmplx multiplyCmplx(const Cmplx c1, const Cmplx c2);
Cmplx divideCmplx(const Cmplx c1, const Cmplx c2);
Cmplx inputCmplx();
double compareCmplx(const Cmplx c1, const Cmplx c2);
void quickSortCmplx(Cmplx c[], const int size);
void _quickSortCmplx(Cmplx c[], int minI, int maxI);

#endif