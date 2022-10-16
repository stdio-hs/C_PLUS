/*

파일명 : PRACTICE_25

프로그램의 목적 및 기본기능 : 동적메모리할당 2차원배열 / 연산 및 평균

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 04월 11일 _ 프로젝트 이해 / 구조 틀 짜기.
  2022년 04월 12일 _ Code.h & Code.cpp 작성 _ 내일 getStatisticsMtrx()만들기.
  2022년 04월 13일 _ getStatisticsMtrx() 함수 만들기.
  2022년 04월 14일 _ main.cpp 작성
  2022년 04월 15일 _ getStatisticsMtrx() 를 realloc로 해도 되지 않나? 의문

*/

#include "Code.h"

void checkAddress_2DArray_for_Matrix(); // 동적메모리할당 주소위치 확인
void test_2D_DynamicArray_FileIO_Statistics(); // 동적메모리할당하여 파일로부터 행렬 입력
void test_Matrix_Addition_Subtraction(); // 행렬 덧셈 & 뺄셈
void test_Matrix_Multiplication(); // 행렬 곱셈



// main 함수
int main()
{
	int menu;
	while (1)
	{
		printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		printf("Testing Matrix Operations with 2-Dimensional Dynamic Array \n"); 
		printf(" 1: Check addresses of 2-Dim array for Matrix / 동적메모리할당 주소위치 확인 \n");
		printf(" 2: Test 2-D Dynamic Array Creation for Matrix with File I/O, Statistics / 파일로부터 행렬 가져오기. \n");
		printf(" 3: Test Matrix Addition, Subtraction / 행렬 ( 덧셈 &  뺄셈 )\n");
		printf(" 4: Test Matrix Multiplication / 행렬 ( 곱셈 ) \n");
		printf("-1: Quit\n");
		printf("Input menu (-1 to quit) : ");
		scanf_s("%d", &menu);
		if (menu == -1)
			break;
		printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");


		printf("\n");
		switch (menu)
		{
		case 1:
			checkAddress_2DArray_for_Matrix();
			break;
		case 2:
			test_2D_DynamicArray_FileIO_Statistics();
			break;
		case 3:
			test_Matrix_Addition_Subtraction();
			break;
		case 4:
			test_Matrix_Multiplication();
			break;
		default:
			break;
		}
	} // end while
}



// 동적메모리할당 주소위치 확인
void checkAddress_2DArray_for_Matrix()
{
	double** dM;
	int row_size = 3;
	int col_size = 3;

	dM = createDoubleMtrx(row_size, col_size); // 가로세로 길이만큼 동적메모리 할당
	checkAddress_2DArray(dM, row_size, col_size); // 동적메모리할당한 위치를 파악하기.
	deleteDoubleMtrx(dM, row_size); // 동적메모리 반환시켜주기.
}

// 2차원배열 출력 + ( 행/열/전체 ) 평균값 추가한 확장 2차원배열 출력
void test_2D_DynamicArray_FileIO_Statistics()
{
	
	FILE* fn;
	int a_row_size, a_col_size; // 3*5 배열
	int b_row_size, b_col_size; // 3*3 배열
	double** dMA; // 첫번째 2차원배열
	double** dMB; // 두번쨰 2차원배열
	double** dMR;


	fn = fopen(WRITE_FILE, "r");
	if (fn == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}




	// 첫번째 2차원배열
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )

	dMA = fgetDoubleMtrx(fn, a_row_size, a_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size); // 출력_1 ( 첫줄 )
	printMtrx(dMA, a_row_size, a_col_size); // 출력_2 ( 메인 )
	printf("\n");
	
	dMR = getStatisticsMtrx(dMA, a_row_size, a_col_size); // ( 행/열/전체 ) 평균값을 추가한 2차원배열(확장) 
	printf("Matrix_A ( %d x %d ) with row & col averages : \n", a_row_size, a_col_size);
	printMtrx(dMR, a_row_size + 1, a_col_size + 1); printf("\n"); // ( 행/열/전체 ) 평균값을 추가한 2차원배열(확장) _ 출력
	deleteDoubleMtrx(dMR, a_row_size + 1); // dMR 함수 반환
	


	// 두번째 2차원배열
	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size);  // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )

	dMB = fgetDoubleMtrx(fn, b_row_size, b_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size); // 출력_1 ( 첫줄 )
	printMtrx(dMB, b_row_size, b_col_size); printf("\n"); // 출력_2 ( 메인 )
	printf("\n");

	dMR = getStatisticsMtrx(dMB, b_row_size, b_col_size); // ( 행/열/전체 ) 평균값을 추가한 2차원배열(확장)
	printf("Matrix_B ( %d x %d) with row & col averages : \n", b_row_size, b_col_size);
	printMtrx(dMR, b_row_size + 1, b_col_size + 1); printf("\n"); // ( 행/열/전체 ) 평균값을 추가한 2차원배열(확장) _ 출력
	deleteDoubleMtrx(dMR, b_row_size + 1); // dMR 함수 반환


	// 동적메모리할당받은것들 반환
	deleteDoubleMtrx(dMA, a_row_size);
	deleteDoubleMtrx(dMB, b_row_size);
	fclose(fn);
}

// 2차원배열 ( 덧셈 / 뺄셈 ) 
void test_Matrix_Addition_Subtraction()
{
	FILE* fn;
	double** dMA, ** dMB, ** dMC, ** dMD;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	int d_row_size, d_col_size;
	
	fn = fopen(WRITE_FILE_2, "r");
	if (fn == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}

	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )
	dMA = fgetDoubleMtrx(fn, a_row_size, a_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size);  // 출력_1 ( 첫줄 )
	printMtrx(dMA, a_row_size, a_col_size); // 출력_2 ( 메인 )
	printf("\n");

	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )
	dMB = fgetDoubleMtrx(fn, b_row_size, b_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);  // 출력_1 ( 첫줄 )
	printMtrx(dMB, b_row_size, b_col_size); // 출력_2 ( 메인 )
	printf("\n");


	if ((a_row_size != b_row_size) || (a_col_size != b_col_size))
	{
		printf("Error in input matrix dimension: row_size and/or col_size are not equal !!\n");
		fclose(fn);
		return;
	}



	// 덧셈 ( + )
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	dMC = createDoubleMtrx(c_row_size, c_col_size);
	addMtrx(dMA, dMB, dMC, a_row_size, a_col_size);
	printf("Matrix_C (%d x %d) = Matrix_A + Matrix_B : \n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);
	printf("\n");
	
	
	
	// 뺄셈 ( - )
	d_row_size = a_row_size;
	d_col_size = b_col_size;
	dMD = createDoubleMtrx(d_row_size, d_col_size);
	subMtrx(dMA, dMB, dMD, a_row_size, a_col_size);
	printf("Matrix_D (%d x %d) = Matrix_A - Matrix_B : \n", d_row_size, d_col_size);
	printMtrx(dMD, d_row_size, d_col_size);
	printf("\n");



	// 동적메모리 반환 
	deleteDoubleMtrx(dMA, a_row_size);
	deleteDoubleMtrx(dMB, b_row_size);
	deleteDoubleMtrx(dMD, d_row_size);
	deleteDoubleMtrx(dMC, c_row_size);
	fclose(fn);
}

// 2차원배열 ( 곱셈 )
void test_Matrix_Multiplication()
{
	FILE* fn;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	double** dMA, ** dMB, ** dMC;
	fn = fopen(WRITE_FILE, "r");
	
	if (fn == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}
	
	
	
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )
	dMA = fgetDoubleMtrx(fn, a_row_size, a_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size); // 출력_1 ( 첫줄 )
	printMtrx(dMA, a_row_size, a_col_size); // 출력_2 ( 메인 )
	printf("\n");



	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size); // 파일로부터 2개의 실수를 받아, 행과 열에 저장. _ ( 첫번째 배열 행과 열 )
	dMB = fgetDoubleMtrx(fn, b_row_size, b_col_size); // 행과열만큼 동적메모리를 할당시키고, 각 칸에 파일로부터 값을 저장시킨다.
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size); // 출력_1 ( 첫줄 )
	printMtrx(dMB, b_row_size, b_col_size); // 출력_2 ( 메인 )
	printf("\n");


	int k_size;

	// MC = MA x MB
	c_row_size = a_row_size;  
	c_col_size = b_col_size;
	dMC = createDoubleMtrx(c_row_size, c_col_size);
	k_size = a_col_size;
	multiplyMtrx(dMA, dMB, dMC, c_row_size, c_col_size, k_size);
	printf("Matrix_C (%d x %d) = Matrix_A x Matrix_B : \n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);
	printf("\n");



	deleteDoubleMtrx(dMA, a_row_size);
	deleteDoubleMtrx(dMB, b_row_size);
	deleteDoubleMtrx(dMC, c_row_size);
	fclose(fn);
}
