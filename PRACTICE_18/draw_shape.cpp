#include "draw_shape.h"


int draw_rectangle(int width, int length) // 꽉찬 사각형
{
	for (int a = 0; a < length; a++) // 세로 반복문
	{
		for (int b = 0; b < width; b++) // 가로 반복문
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");
	return 0;
}

int draw_rectangle_2(int width, int length) // 비어있는 사각형
{
	for (int a = 0; a < width; a++) // 비어있는 사각형 첫줄만 출력
	{
		printf("*");
	}
	printf("\n");

	for (int b = 0; b < length - 2; b++) // ( 첫줄, 마지막줄 ) 을 제외하고 사각형 세로출력 반복문 
	{
		printf("*"); // [ (*)   * ] 을 위해 첫번째 별 출력
		for (int c = 0; c < width - 2; c++) // [ *   * ] 에서 가운데 공백출력 반복문
		{
			printf(" ");
		}
		printf("*"); // [ *   (*) ] 을 위해 마지막 별 출력
		printf("\n");
	}

	for (int a = 0; a < width; a++) // 비어있는 사각형 마지막줄 출력
	{
		printf("*");
	}

	printf("\n\n\n");
	return 0;
}

int draw_right_triangle(int base) // 직각삼각형
{
	int i = 1;

	for (int a = 0; a < base; a++) // 직각삼각형 세로출력 반복문
	{
		for (int b = 0; b < i; b++) // 직각삼각형 가로출력 반복문
		{
			printf("*");
		}
		printf("\n");
		i++; // 직각삼각형 세로출력 반복문 과정중 아래로 갈수록 가로출력을 하나씩 늘려준다.
	}
	printf("\n\n");
	return 0;
}

int draw_right_triangle_2(int base) // 비어있는 직각삼각형
{
	int i = 1;

	printf("*\n"); // 비어있는 삼각형 첫줄 출력

	for (int a = 0; a < base - 2; a++) // (첫줄, 마지막줄) 을 제외하고 사각형 세로출력 반복문
	{
		printf("*");
		for (int b = 0; b < i-1; b++) // [ *   * ] 에서 가운데 공백출력 반복문
		{
			printf(" ");
		}

		printf("*"); // 비어있는 직각삼각형 마지막줄 출력
		printf("\n");
		i++;
	}

	for (int c = 0; c < base; c++)
	{
		printf("*");
	}

	printf("\n\n\n");
	return 0;
}

int draw_reverse_right_triangle(int base) // 180도 회전시킨 직각삼각형
{
	int i = base;

	for (int a = 0; a < base; a++) // 180_직각삼각형 세로출력 반복문
	{
		for (int b = 0; b < i; b++) // 180_직각삼각형 가로출력 반복문
		{
			printf("*");
		}
		printf("\n");
		i--; // 직각삼각형 세로출력 반복문 과정중 아래로 갈수록 가로출력을 하나씩 줄여준다.
	}

	printf("\n\n");
	return 0;
}

int draw_diamond(int width) // (너비가 주어진) 다이아몬드
{
	int x = width / 2; // 공백출력을 위한 선언
	int i = 1;

	// 세로가 주어진 다이아몬드는 비교적 쉽게 코드를 짰지만, 너비가 주어진 다이아몬드라 고민을 했다.
	// 다이아몬드를 그린다가 아닌, 출력되는 [ 1. 공백 / 2. * ] 을 나누어 생각하여, (삼각형출력활용)
	// 증가 혹은 감소 하는 규칙을 찾아 코드로 작성하고 출력을 합친다.

	while (i != width + 2)
		// + 세로출력 반복문 _ 중간지점까지 ( 이등변삼각형 출력 )
		// (가로줄 21개 출력할때, +2가 더해져 조건식에 들어왔을때) 23일때 반복문 탈출 
		
	{ 
		for (int b = 0; b < x; b++) // 가로 공백출력 반복문
		{
			printf(" ");
		}
		for (int c = 0; c < i; c++) // 가로 별출력 반복문
		{
			printf("*");
		}

		printf("\n");
		x--; // 세로반복문에 따라 가로공백출력을 1개씩 줄여간다.
		i += 2; // 세로반복문에 따라 가로별출력을 2개씩 늘려간다.
	}

	i = width;
	int y = 1;
	while (i != -1) // (가로줄 1개 출력할때, -2가 더해져 조건식에 들어왔을때) -1일때 반복문 탈출 
	{

		for (int d = 0; d < y; d++) // 가로공백출력 반복문
		{
			printf(" ");
		}

		i -= 2; // 세로반복문에 따라 가로별출력을 2개씩 늘려간다.
		for (int d = 0; d < i; d = d++) // 가로별출력 반복문
		{
			printf("*");
		}

		printf("\n");
		y++; // 세로반복문에 따라 가로공백출력을 1개씩 늘려간다.
	}

	return 0;
}

