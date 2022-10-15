#include "Mtrx.h"
#include "Code.h"



// ���� ( + )
void addMtrx(double** mA, double** mB, double** mR, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++) // ��
		for (int c = 0; c < col_size; c++) // ��
			mR[r][c] = mA[r][c] + mB[r][c];
}

// �E�� ( - )
void subMtrx(double** mA, double** mB, double** mR, int row_size, int col_size)
{
	for (int r = 0; r < row_size; r++) // ��
		for (int c = 0; c < col_size; c++) // ��
			mR[r][c] = mA[r][c] - mB[r][c];
}

// ���� ( * )
void multiplyMtrx(double** mA, double** mB, double** mR, int row_size, int col_size, int k_size)
{
	for (int r = 0; r < row_size; r++) // ��
	{
		for (int c = 0; c < col_size; c++) // ��
		{
			mR[r][c] = 0;
			for (int k = 0; k < k_size; k++)
				mR[r][c] += mA[r][k] * mB[k][c];
		}
	}
}