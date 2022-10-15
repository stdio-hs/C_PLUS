/*

파일명 : PRACTICE_24

프로그램의 목적 및 기본기능 : 동적메모리할당 2차원배열 / 연산

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 04월 16일 _ 프로젝트 완성

*/


#include "Code.h"
#include "Mtrx.h"

void test_MATRX();

int main()
{
	printf(" - - - - - - - - - - - - - - - [ 배열 기본 사칙연산 ] - - - - - - - - - - - - - - - \n\n");
	test_MATRX();
}

void test_MATRX()
{
	int a_row_size, a_col_size; // 4*7 배열
	int b_row_size, b_col_size; // 7*4 배열


	double** dMA; // 첫번째 2차원배열
	double** dMB; // 두번쨰 2차원배열
	double** dMC; // 세번째 2차원배열  

	double** dMD; // 덧셈
	double** dME; // 뺄셈
	double** dMF; // 곱셈

	FILE* fn;
	fn = fopen(WRITE_FILE, "r");
	if (fn == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}


	// 첫번째 2차원배열
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )
	dMA = fgetMtrx(fn, a_row_size, a_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("mA = \n"); // 출력_1 ( 첫줄 )
	printMtrx(dMA, a_row_size, a_col_size); // 출력_2 ( 메인 )
	printf("\n");


	// 두번째 2차원배열
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )
	dMB = fgetMtrx(fn, a_row_size, a_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("mB = \n"); // 출력_1 ( 첫줄 )
	printMtrx(dMB, a_row_size, a_col_size); // 출력_2 ( 메인 )
	printf("\n");


	// 세번째 2차원배열
	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )
	dMC = fgetMtrx(fn, b_row_size, b_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("mC = \n"); // 출력_1 ( 첫줄 )
	printMtrx(dMC, b_row_size, b_col_size); // 출력_2 ( 메인 )
	printf("\n");


	// 덧셈
	dMD = createDoubleMtrx(a_row_size, a_col_size);
	addMtrx(dMA, dMB, dMD, a_row_size, a_col_size);
	printf("mD = mA + mB = \n");
	printMtrx(dMD, a_row_size, a_col_size);
	printf("\n");


	// 뺄셈
	dME = createDoubleMtrx(a_row_size, a_col_size);
	subMtrx(dMA, dMB, dME, a_row_size, a_col_size);
	printf("mE = mA - mB = \n");
	printMtrx(dME, a_row_size, a_col_size);
	printf("\n");


	// 곱셈
	dMF = createDoubleMtrx(a_row_size, b_col_size);
	multiplyMtrx(dMA, dMC, dMF, a_row_size, b_col_size, a_col_size);
	printf("mF = mA * mC = \n");
	printMtrx(dMF, a_row_size, b_col_size);
	printf("\n");



	deleteMtrx(dMA, a_row_size); // dMA 함수 반환
	deleteMtrx(dMB, a_row_size); // dMB 함수 반환
	deleteMtrx(dMC, b_row_size); // dMC 함수 반환
	fclose(fn);
}
