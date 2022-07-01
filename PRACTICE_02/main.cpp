/**

파일명: PRACTICE_02

프로그램의 목적 및 기본기능 : 직각삼각형의 밑변/높이 입력받고, 직각삼각형의 넓이/둘레 계산

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 03월 07일

**/

#include <stdio.h>
#include <math.h>

int main()
{
	int b, h; // base밑변 height높이
	double r, a; // radious둘레 area넓이
	double x; // 삼각형 나머지 변의 길이

	printf("직각삼각형의 밑변을 입력하시오 : ");
	scanf_s("%d", &b);
	printf("직각삼각형의 높이를 입력하시오 : ");
	scanf_s("%d", &h);

	x = sqrt(b * b + h * h);

	r = x + b + h; // 둘레 계산
	a = (b * h) / 2; // 넓이 계산

	printf("직각삼각형의 넓이는 %.lf 입니다.\n", a);
	printf("직각삼각형의 둘레는 %.lf 입니다.", r);

	return 0;
}

