/**
파일명: PL22_HW02_3_21912240_이현성
프로그램의 목적 및 기본기능 : 실수 2개를 입력받아 덧셈, 뺄셈, 곱셈, 나눗셈 결과를 출력하는 프로그램
프로그램 작성자 : 이현성
프로그램 작성일지 : 2022년 03월 09일
**/

#include <stdio.h>

int main()
{
	double x, y; // 실수 데이터 2개
	double arr[4]; // 덧셈, 뺄셈, 곱셈, 나눗셈 결과 저장 

	printf("<<< 실수 2개를 입력받아 (덧셈, 뺄셈, 곱셈, 나눗셈) 결과를 출력하는 프로그램 입니다. >>>\n\n");
	printf("첫번째 실수를 입력하시오. ");
	scanf_s("%lf", &x);
	printf("두번째 실수를 입력하시오. ");
	scanf_s("%lf", &y);
	printf("\n");

	arr[0] = x + y;
	arr[1] = x - y;
	arr[2] = x * y;
	arr[3] = x / y;

	printf("%.2lf + %.2lf = %.2lf\n", x, y, arr[0]);
	printf("%.2lf - %.2lf = %.2lf\n", x, y, arr[1]);
	printf("%.2lf * %.2lf = %.2lf\n", x, y, arr[2]);
	printf("%.2lf / %.2lf = %.2lf\n", x, y, arr[3]);

	return 0;
}

