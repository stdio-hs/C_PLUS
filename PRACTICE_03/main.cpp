/**

파일명: PRACTICE_03

프로그램의 목적 및 기본기능 : 원기둥의 (반지름/높이)를 입력, 원기둥의 (부피/겉넓이) 출력 

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 03월 07일

**/

#include <stdio.h>
#define PI 3.14

int main()
{
	int r, h; // radius반지름 height높이
	double v, sa; // volume부피 surface area겉넓이

	printf("원기둥의 반지름을 입력하시오 : ");
	scanf_s("%d", &r);
	printf("원기둥의 높이를 입력하시오 : ");
	scanf_s("%d", &h);

	v = r * r * PI * h; // 부피
	sa = (2 * r * r * PI) + (2 * PI * r * h); // 겉넓이

	printf("원기둥의 부피는 %.2lf 입니다.\n", v);
	printf("원기둥의 겉넓이는 %.2lf 입니다.", sa);

	return 0;
}

