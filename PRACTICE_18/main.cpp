/*

���ϸ� : PRACTICE_18

���α׷��� ���� �� �⺻��� : " * " �� �׸��� ����

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 4�� 2�� ~ 2022�� 4�� 3��

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