/*

파일명 : PRACTICE_18

프로그램의 목적 및 기본기능 : " * " 로 그리는 도형

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 4월 2일 ~ 2022년 4월 3일

*/


#include "draw_shape.h"

int main()
{
	int width = 20;
	int length = 10;
	int base = 10;


	printf("Drawing a rectangle (FULL) of width = %d, length = %d\n", width, length);
	draw_rectangle(width, length);

	printf("Drawing a rectangle (EMPTY) of width = %d, length = %d\n", width, length);
	draw_rectangle_2(width, length);

	printf("Drawing a right triangle of base = %d\n", base);
	draw_right_triangle(base);

	printf("Drawing a right triangle (EMPTY) of base = %d\n", base);
	draw_right_triangle_2(base);

	printf("Drawing a reversed right triangle of base = %d\n", base);
	draw_reverse_right_triangle(base);

	width = 21;
	printf("Drawing a diamond of width = %d\n", width);
	draw_diamond(width);
}