#include "Matrix.h"


// = = = = = = = = = = = = = = = = = = = [ MTRX 기본 ] = = = = = = = = = = = = = = = = = = = 


// 2차원 배열을 동적으로 생성한 후, 해당 배열에 fscanf를 사용하여 파일로부터 배열 받아 저장.
double** fGetMtrx(FILE* fin, int* pRow_size, int* pCol_size)
{
	double data = 0.00;
	double** dM;

	if (fin == NULL)
	{
		printf("Error in fGetMtrx() - file pointer is NULL !!\n");
		return NULL;
	}
	fscanf_s(fin, "%d %d", pRow_size, pCol_size); // 파일에 데이터가 존재할 경우, 파일로부터 데이터 읽어오기.

	dM = (double**)calloc(*pRow_size, sizeof(double*)); // 파일 열만큼 동적배열할당
	for (int r = 0; r < *pRow_size; r++) // 열 안에 있는 행만큼 동적배열할당.
	{
		dM[r] = (double*)calloc(*pCol_size, sizeof(double));
	}

	for (int r = 0; r < *pRow_size; r++) // 행 위에서부터 아래로 차례로
	{
		for (int c = 0; c < *pCol_size; c++) // 각 열 순차적으로
		{
			if (fscanf(fin, "%lf", &data) != EOF) // 데이터 받아오기.
				dM[r][c] = data;
		}
	}

	return dM; // dM으로 리턴시킨다. ( 행/열 >> dM[] )
}

// 2차원 배열의 동적 반환 함수
void deleteMtrx(double** dM, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(dM[r]);
		// 행(ㅣ) 안에 있는 열(ㅡ)들을 하나씩 동적메모리를 반환한다.
		// // free(*dM++)
		// free(*(dM+i))
	}
	free(dM); // 열을 지우고 남아있는 행(ㅣ)을 동적메모리 반환한다.
}

// 2차원 배열의 실행창 출력
void printMtrx(double** dM, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;


	for (int r = 0; r < row_size; r++) // 행
	{
		if (r == 0)
			printf("%c%c ", 0xa6, 0xa3);
		else if (r == row_size - 1)
			printf("%c%c ", 0xa6, 0xa6);
		else
			printf("%c%c ", 0xa6, 0xa2);

		for (int c = 0; c < col_size; c++)
			printf("%7.2f ", dM[r][c]);

		if (r == 0)
			printf("%c%c ", 0xa6, 0xa4);
		else if (r == row_size - 1)
			printf("%c%c ", 0xa6, 0xa5);
		else
			printf("%c%c ", 0xa6, 0xa2);
		printf("\n");
	}

}

// 2차원 배열의 파일 출력
void fprintMtrx(FILE* fout, double** dM, int row_size, int col_size)//행렬 파일 출력
{
	for (int r = 0; r < row_size; r++)
	{
		if (r == 0)
			fprintf(fout, "%c%c ", 0xa6, 0xa3);
		else if (r == row_size - 1)
			fprintf(fout, "%c%c ", 0xa6, 0xa6);
		else
			fprintf(fout, "%c%c ", 0xa6, 0xa2);

		for (int c = 0; c < col_size; c++)
			fprintf(fout, "%7.2f ", dM[r][c]);

		if (r == 0)
			fprintf(fout, "%c%c ", 0xa6, 0xa4);
		else if (r == row_size - 1)
			fprintf(fout, "%c%c ", 0xa6, 0xa5);
		else
			fprintf(fout, "%c%c ", 0xa6, 0xa2);
		fprintf(fout, "\n");
	}
}


// = = = = = = = = = = = = = = = = = = = [ MTRX 연산 ] = = = = = = = = = = = = = = = = = = = 


// 덧셈
double** addMtrx(double** A, double** B, int row_size, int col_size)
{
	double** R;
	R = (double**)calloc(row_size, sizeof(double*));
	for (int r = 0; r < row_size; r++)
	{
		R[r] = (double*)calloc(col_size, sizeof(double));
	}
	for (int r = 0; r < row_size; r++)
		for (int c = 0; c < col_size; c++)
		{
			R[r][c] = A[r][c] + B[r][c];
		}
	return R;
}

// 뺄셈
double** subMtrx(double** A, double** B, int row_size, int col_size)
{
	double** R;
	R = (double**)calloc(row_size, sizeof(double*));
	for (int r = 0; r < row_size; r++)
	{
		R[r] = (double*)calloc(col_size, sizeof(double));
	}
	for (int r = 0; r < row_size; r++)
		for (int c = 0; c < col_size; c++)
		{
			R[r][c] = A[r][c] - B[r][c];
		}
	return R;
}

// 곱셈
double** mulMtrx(double** A, double** B, int row_size, int k_size, int col_size)
{
	double** R;
	R = (double**)calloc(row_size, sizeof(double*));
	for (int r = 0; r < row_size; r++)
	{
		R[r] = (double*)calloc(col_size, sizeof(double));
	}
	for (int r = 0; r < row_size; r++)
		for (int c = 0; c < col_size; c++)
		{
			R[r][c] = 0.0;
			for (int k = 0; k < k_size; k++)
			{
				R[r][c] += A[r][k] * B[k][c];
			}
		}
	return R;
}


// 역행렬
void invMtrxGaussJordanElim_FileOut(double** mA, double** inv_A, int size_N)
{
	// 해를 구하는 것이 아니니 피봇팅은 하지 않는다 
	int j, k, p = 0;
	double pivWeight, w;
	double** mAUG; // 계수행렬 + 항등행렬



	// Part 1. 변수개수 x (변수개수*2) 크기의 행렬
	mAUG = (double**)calloc(size_N, sizeof(double*)); // 행
	for (int i = 0; i < size_N; i++) // 열 * 2
		mAUG[i] = (double*)calloc(size_N * 2, sizeof(double));

	// 생성한 mAUG 배열에 데이터 값 넣기. 
	for (j = 0; j < size_N; j++) // 행
	{
		// 1)
		for (k = 0; k < size_N; k++) // 열
			mAUG[j][k] = mA[j][k];

		// 2)
		for (k = size_N; k < size_N * 2; k++) // 뒷부분은 항등행렬을 넣어준다.
			mAUG[j][k] = (k == (j + size_N)) ? 1.0 : 0.0;
	}


	//Part 2.  // SCALING + 소거연산
	for (p = 0; p < size_N; p++)
	{
		if (mAUG[p][p] != 1.0) // 대각 성분이 1이 아닐때 1로 스케일링
		{
			pivWeight = mAUG[p][p];//p-p 원소의 값으로 p행의 원소들을 나눠주기 위해 
			mAUG[p][p] = 1.0;//p-p는 1로 만든다
			for (k = p + 1; k < size_N * 2; k++)//p이후의 열들을 전부 p-p값으로 나눠준다
			{
				mAUG[p][k] /= pivWeight;//전부다 나눠준다
			}
		}

		for (j = 0; j < size_N; j++) // p열에 대해 p-p제외하고 모두 0으로 만들어야 한다
		{
			if ((j != p) && (mAUG[j][p] != 0.0)) // p행이 아니고, 0이 아니라면
			{
				w = mAUG[j][p];
				mAUG[j][p] = 0.0;
				for (k = p + 1; k < 2 * size_N; k++)
				{
					mAUG[j][k] -= w * mAUG[p][k];
				}
			}
		}
	}


	//Part 3. 역행렬을 분리해준다
	for (j = 0; j < size_N; j++) // 행
	{
		for (k = 0; k < size_N; k++) // 열
		{
			inv_A[j][k] = mAUG[j][k + size_N];
		}
	}

}