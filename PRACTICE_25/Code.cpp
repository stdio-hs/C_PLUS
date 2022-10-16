#include "Code.h"



//ㅡㅡㅡㅡㅡ--ㅡㅡㅡ--ㅡㅡㅡㅡ----ㅡ--ㅡㅡ [ 동적메모리할당 주소위치 확인 함수 ] ㅡㅡㅡㅡㅡㅡㅡㅡㅡ--ㅡ--ㅡ--ㅡㅡㅡ----ㅡ


// 해당 동적메모리할당 주소위치 확인 함수
void checkAddress_2DArray(double** dM, int row_size, int col_size)
{
	printf("dM = %p\n", dM); // %p 는 주소를 가리킨다.
	printf("dM[0] = %p\n", dM[0]);
	printf("dM[1] = %p\n", dM[1]);
	printf("dM[2] = %p\n", dM[2]);
	printf("&dM[0][0] = %p\n", &dM[0][0]);
	printf("&dM[1][0] = %p\n", &dM[1][0]);
	printf("&dM[2][0] = %p\n", &dM[2][0]);
	printf("\n");
}


//ㅡㅡㅡㅡㅡ--ㅡㅡㅡ--ㅡㅡㅡㅡ----ㅡ--ㅡㅡ [ 2차원실수배열 관련 함수 ] ㅡㅡㅡㅡㅡㅡㅡㅡㅡ--ㅡ--ㅡ--ㅡㅡㅡ----ㅡ


// 2차원실수배열의 동적 생성 함수 _ ( 행/열 >> dM[] )
double** createDoubleMtrx(int row_size, int col_size)
{
	double** dM; // 이중포인터_포인터를 가리키는 포인터 (2차원배열이기때문)
	dM = (double**)calloc(row_size, sizeof(double*)); // 행(ㅣ) double사이즈로 동적메모리 할당
	for (int r = 0; r < row_size; r++)
	{
		dM[r] = (double*)calloc(col_size, sizeof(double)); // 행(ㅣ) 사이즈만큼 한칸한칸 반복문을 통해 열(ㅡ)을 double사이즈로 동적메모리 할당
	}
	return dM; // dM으로 리턴하기. ( 행/열 >> dM[] )
}

// 2차원실수배열을 파일로부터 입력받아오기 함수 _ ( 행/열 >> dM[] )
double** fgetDoubleMtrx(FILE* fp, int row_size, int col_size)
{
	double d = 0.0;
	double** dM;

	if (fp == NULL)
	{
		printf("Error in getDoubleMtrx() - file pointer is NULL !!\n");
		exit(-1); // 파일에 아무것도 없을 경우, ( 에러 + 실행창종료 )
	}

	dM = createDoubleMtrx(row_size, col_size); // 행&열 크기만큼 동적메모리 할당

	for (int m = 0; m < row_size; m++) // 행
		for (int n = 0; n < col_size; n++) // 열
		{
			if (fscanf_s(fp, "%lf", &d) != EOF) // EOF 는 파일의 끝을 의미한다. <stdio.h> 에서는 EOF = -1로 정의되어 있음.
				dM[m][n] = d;
			// 파일로부터 가져온 데이터를 해당 구역에 하나씩 대입하기.
			// ex) [0][0], [0][1], [0][2], [1][0], [1][1], [1][2]
		}

	return dM; // dM으로 리턴시킨다. ( 행/열 >> dM[] )
}

// 2차원실수배열의 동적 반환 함수
void deleteDoubleMtrx(double** dM, int row_size)
{
	for (int a = 0; a < row_size; a++)
	{
		free(dM[a]); // 행(ㅣ) 안에 있는 열(ㅡ)들을 하나씩 동적메모리를 반환한다.
		// free(*dM++)
		// free(*(dM+i))
	}
	free(dM); // 열을 지우고 남아있는 행(ㅣ)을 동적메모리 반환한다.
}

// 2차원실수배열의 실행창 출력
void printMtrx(double** dM, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;


	for (int i = 0; i < row_size; i++) // 행
	{
		for (int j = 0; j < col_size; j++) // 열
		{
			if ((i == 0) && (j == 0))
				printf("%c%c%7.2lf", a6, a3, dM[i][j]);

			else if ((i == 0) && j == (col_size - 1))
				printf("%7.2lf%c%c", dM[i][j], a6, a4);

			else if ((i > 0) && (i < row_size - 1) && (j == 0))
				printf("%c%c%7.2lf", a6, a2, dM[i][j]);

			else if ((i > 0) && (i < row_size - 1) && (j == (col_size - 1)))
				printf("%7.2lf%c%c", dM[i][j], a6, a2);

			else if ((i == (row_size - 1)) && (j == 0))
				printf("%c%c%7.2lf", a6, a6, dM[i][j]);

			else if ((i == (row_size - 1)) && (j == (col_size - 1)))
				printf("%7.2lf%c%c", dM[i][j], a6, a5);

			else
				printf("%7.2lf", dM[i][j]);
		}
		printf("\n");
	}
}


//ㅡㅡㅡㅡㅡ--ㅡㅡㅡ--ㅡㅡㅡㅡ----ㅡ--ㅡㅡ [ 2차원실수배열(행렬) 연산 함수 ] ㅡㅡㅡㅡㅡㅡㅡㅡㅡ--ㅡ--ㅡ--ㅡㅡㅡ----ㅡ


// 덧셈 ( + )
void addMtrx(double** mA, double** mB, double** mR, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++) // 행
		for (int c = 0; c < col_size; c++) // 열
			mR[r][c] = mA[r][c] + mB[r][c];
}

// 뺼셈 ( - )
void subMtrx(double** mA, double** mB, double** mR, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++) // 행
		for (int c = 0; c < col_size; c++) // 열
			mR[r][c] = mA[r][c] - mB[r][c];
}

// 곱셈 ( * )
void multiplyMtrx(double** mA, double** mB, double** mR, int row_size, int col_size, int k_size)
{
	for (int r = 0; r < row_size; r++) // 행
	{
		for (int c = 0; c < col_size; c++) // 열
		{
			mR[r][c] = 0;
			for (int k = 0; k < k_size; k++)
				mR[r][c] += mA[r][k] * mB[k][c];
		}
	}
}

// ( 행/열/전체 ) 평균
double** getStatisticsMtrx(double** dM, int row_size, int col_size)
{
	double sum = 0.00;
	double average = 0.00;

	double** dMA; 
	dMA = createDoubleMtrx(row_size + 1, col_size + 1); // 동적배열생성입니다.


	// ( 기존 2차원배열 dM 값 >> 확장2차원배열 dMA )에 기존 값을 옮겨준다.
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			dMA[i][j] = dM[i][j];
			sum += dM[i][j]; // 이 부분에서 2차원배열 총 합을 미리 구해놓는다 ( 행렬 전체 평균을 구하기 위해. )
		}
	}

	// ( 기존 2차원배열 dM에 담겨 있는 각 row에 담겨있는 col ) 평균값을 dMA 배열에 넣어준다.
	for (int i = 0; i < row_size; i++) // 덧셈
	{
		for (int j = 0; j < col_size; j++)
		{
			dMA[i][col_size] = (dMA[i][col_size] + dM[i][j]);
		}
	}
	for (int a = 0; a < row_size; a++) // 평균
	{
		dMA[a][col_size] = (dMA[a][col_size] / col_size);
	}


	// ( 기존 2차원배열 dM에 담겨 있는 각 col에 담겨있는 row ) 평균값을 dMA 배열에 넣어준다.
	for (int i = 0; i < col_size; i++) // 덧셈
	{
		for (int j = 0; j < row_size; j++)
		{
			dMA[row_size][i] = (dMA[row_size][i] + dM[j][i]);
		}
	}
	for (int a = 0; a < col_size; a++) // 평균
	{
		dMA[row_size][a] = (dMA[row_size][a] / row_size);
	}


	average = sum / (row_size * col_size); // 평균 구하는 공식
	dMA[row_size][col_size] = average; // 해당 부분에 평균 값을 넣어준다.
	
	return dMA; // (확장된 2차원배열인) dMA함수를 리턴시켜준다.
}





