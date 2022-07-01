/**

파일명: PRACTICE_05

프로그램의 목적 및 기본기능 : 초단위로 입력된 값을 시,분,초로 환산하는 프로그램

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 03월 09일

**/

#include <stdio.h>

int main()
{
	int x_1, x_2, x_3; // input second, input second - time, input second - time - minute
	int t, m, s; // output _ time, minute, second

	printf("<<< 초단위로 입력된 값을 시,분,초로 환산해주는 프로그램입니다. >>\n\n");
	printf("초단위로 숫자를 입력하시오. : ");
	scanf_s("%d", &x_1); // 숫자입력 (초단위)

	t = x_1 / 3600; // 시 계산
	x_2 = x_1 - t * 3600; // 입력값(초) - 시(초) 
	
	m = x_2 / 60; // 분 계산
	x_3 = x_2 - m * 60; // 입력값(초) - 시(초) - 분(초)

	s = x_3;

	printf("[ %d sec = %d시간 %d분 %d초 입니다. ]\n",x_1, t, m, s);

	return 0;
}

