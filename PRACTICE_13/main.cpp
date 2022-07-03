/**
* 
파일명 : PRACTICE_13 

프로그램의 목적 및 기본기능 : 5*5 크기의 행렬 A, B에 대한 곱셈 연산

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 03월 17일

**/

#define SIZE 5 //정사각형 행렬의 크기
#include <stdio.h>

void printMtrx(double M[][SIZE], int size) // 행렬을 표시하기 위한 확장 완성형 코드
{
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			if (r == 0 && c == 0)
				printf("%c%c  ", 0xa6, 0xa3);
			else if (r == (size - 1) && c == 0)
				printf("%c%c  ", 0xa6, 0xa6);
			else if (c == 0)
				printf("%c%c  ", 0xa6, 0xa2);

			printf("%7.2lf ", M[r][c]);
			if (r == 0 && c == (size - 1))
				printf("%c%c ", 0xa6, 0xa4);
			else if (r == (size - 1) && c == (size - 1))
				printf("%c%c ", 0xa6, 0xa5);
			else if (c == (size - 1))
				printf("%c%c ", 0xa6, 0xa2);
		}
		printf("\n");
	}
	printf("\n");
}


void multiplyMtrx(double A[][SIZE], double B[][SIZE], double E[][SIZE], int size)
{
	for (int r = 0; r < size; r++) // row _ 행 _ 가로
	{
		for (int c = 0; c < size; c++) // column _ 열 _ 세로
		{
			E[r][c] = 0; // E = A * B
			for (int k = 0; k < size; k++)
				E[r][c] += A[r][k] * B[k][c];
		}
	}
}


int main()
{
	double A[SIZE][SIZE] = {
	{5,4,3,2,1},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25} }; // Matrix A 행렬

	double B[SIZE][SIZE] = {
		{1,0,0,0,0},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,0,0,0,1} }; // Matrix B 행렬

	double X[SIZE][SIZE]; //임시 행렬


	printf("행렬 A : \n");
	printMtrx(A, SIZE); // printMtrx 활용하여, A 출력

	printf("행렬 B : \n");
	printMtrx(B, SIZE); // printMtrx 활용하여, B 출력


	printf("행렬 A * B : \n");
	multiplyMtrx(A, B, X, SIZE);
	printMtrx(X, SIZE); // pritMtrx 활용하여, A*B 함수 호출하여, 출력
}
