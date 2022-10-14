/*

파일명 : PRACTICE_23

프로그램의 목적 및 기본기능 : call-by-value / call-by-pointer / call-by-reference 방식 비교

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 04월 15일 _ 프로젝트 완성

*/

#include "Code.h"


void main()
{

	double x, y;
	double result_1, result_2, result_3;

	srand(time(0));
	x = rand() % 100;
	y = rand() % 100;
	printf("랜덤 X 의 값은 = %.2lf 입니다.\n", x);
	printf("랜덤 Y 의 값은 = %.2lf 입니다.\n\n", y);

	printf(" < X와 Y의 평균 값은 ? > \n");

	result_1 = average_value(x, y);
	printf("1. call-by-average = %.2lf\n", result_1);

	result_2 = average_pointer(&x, &y);
	printf("2. call-by-pointer = %.2lf\n", result_2);

	average_reference(x, y, result_3);
	printf("3. call-by-reference = %.2lf\n", result_3);


}