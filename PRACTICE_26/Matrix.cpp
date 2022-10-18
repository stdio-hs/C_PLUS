#include "Matrix.h"


// = = = = = = = = = = = = = = = = = = = [ MTRX �⺻ ] = = = = = = = = = = = = = = = = = = = 


// 2���� �迭�� �������� ������ ��, �ش� �迭�� fscanf�� ����Ͽ� ���Ϸκ��� �迭 �޾� ����.
double** fGetMtrx(FILE* fin, int* pRow_size, int* pCol_size)
{
	double data = 0.00;
	double** dM;

	if (fin == NULL)
	{
		printf("Error in fGetMtrx() - file pointer is NULL !!\n");
		return NULL;
	}
	fscanf_s(fin, "%d %d", pRow_size, pCol_size); // ���Ͽ� �����Ͱ� ������ ���, ���Ϸκ��� ������ �о����.

	dM = (double**)calloc(*pRow_size, sizeof(double*)); // ���� ����ŭ �����迭�Ҵ�
	for (int r = 0; r < *pRow_size; r++) // �� �ȿ� �ִ� �ุŭ �����迭�Ҵ�.
	{
		dM[r] = (double*)calloc(*pCol_size, sizeof(double));
	}

	for (int r = 0; r < *pRow_size; r++) // �� ���������� �Ʒ��� ���ʷ�
	{
		for (int c = 0; c < *pCol_size; c++) // �� �� ����������
		{
			if (fscanf(fin, "%lf", &data) != EOF) // ������ �޾ƿ���.
				dM[r][c] = data;
		}
	}

	return dM; // dM���� ���Ͻ�Ų��. ( ��/�� >> dM[] )
}

// 2���� �迭�� ���� ��ȯ �Լ�
void deleteMtrx(double** dM, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++)
	{
		free(dM[r]);
		// ��(��) �ȿ� �ִ� ��(��)���� �ϳ��� �����޸𸮸� ��ȯ�Ѵ�.
		// // free(*dM++)
		// free(*(dM+i))
	}
	free(dM); // ���� ����� �����ִ� ��(��)�� �����޸� ��ȯ�Ѵ�.
}

// 2���� �迭�� ����â ���
void printMtrx(double** dM, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;


	for (int r = 0; r < row_size; r++) // ��
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

// 2���� �迭�� ���� ���
void fprintMtrx(FILE* fout, double** dM, int row_size, int col_size)//��� ���� ���
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


// = = = = = = = = = = = = = = = = = = = [ MTRX ���� ] = = = = = = = = = = = = = = = = = = = 


// ����
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

// ����
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

// ����
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


// �����
void invMtrxGaussJordanElim_FileOut(double** mA, double** inv_A, int size_N)
{
	// �ظ� ���ϴ� ���� �ƴϴ� �Ǻ����� ���� �ʴ´� 
	int j, k, p = 0;
	double pivWeight, w;
	double** mAUG; // ������ + �׵����



	// Part 1. �������� x (��������*2) ũ���� ���
	mAUG = (double**)calloc(size_N, sizeof(double*)); // ��
	for (int i = 0; i < size_N; i++) // �� * 2
		mAUG[i] = (double*)calloc(size_N * 2, sizeof(double));

	// ������ mAUG �迭�� ������ �� �ֱ�. 
	for (j = 0; j < size_N; j++) // ��
	{
		// 1)
		for (k = 0; k < size_N; k++) // ��
			mAUG[j][k] = mA[j][k];

		// 2)
		for (k = size_N; k < size_N * 2; k++) // �޺κ��� �׵������ �־��ش�.
			mAUG[j][k] = (k == (j + size_N)) ? 1.0 : 0.0;
	}


	//Part 2.  // SCALING + �Ұſ���
	for (p = 0; p < size_N; p++)
	{
		if (mAUG[p][p] != 1.0) // �밢 ������ 1�� �ƴҶ� 1�� �����ϸ�
		{
			pivWeight = mAUG[p][p];//p-p ������ ������ p���� ���ҵ��� �����ֱ� ���� 
			mAUG[p][p] = 1.0;//p-p�� 1�� �����
			for (k = p + 1; k < size_N * 2; k++)//p������ ������ ���� p-p������ �����ش�
			{
				mAUG[p][k] /= pivWeight;//���δ� �����ش�
			}
		}

		for (j = 0; j < size_N; j++) // p���� ���� p-p�����ϰ� ��� 0���� ������ �Ѵ�
		{
			if ((j != p) && (mAUG[j][p] != 0.0)) // p���� �ƴϰ�, 0�� �ƴ϶��
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


	//Part 3. ������� �и����ش�
	for (j = 0; j < size_N; j++) // ��
	{
		for (k = 0; k < size_N; k++) // ��
		{
			inv_A[j][k] = mAUG[j][k + size_N];
		}
	}

}