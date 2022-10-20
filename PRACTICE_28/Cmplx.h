/*

파일명 : PRACTICE_28

프로그램의 목적 및 기본기능 : 구조체 _ 복소수

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 05월 10일 _ 프로젝트 이해 및 완성

*/


#ifndef CMPLX_H
#define CMPLX_H

#include <stdio.h>
#include <math.h>

// 구조체
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