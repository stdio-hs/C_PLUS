/*

���ϸ� : PRACTICE_27

���α׷��� ���� �� �⺻��� : ��Ŀ������α׷�

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 04�� 26�� _ ������Ʈ ���� �� ����
  2022�� 05�� 03�� _ ������Ʈ �ϼ�

*/

#include "Matrix.h"

const char* input = "Array_2D_input.txt"; // Matrix �����


int main()
{
	FILE* fin;

	double** mA, ** mB, ** mC, ** mD, ** mE, ** mF, ** inv_mF, **mG;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	int d_row_size, d_col_size;
	int e_row_size, e_col_size;
	int f_row_size, f_col_size;
	int g_row_size, g_col_size;

	fin = fopen(input, "r");
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}

	// mA
	mA = fGetMtrx(fin, &a_row_size, &a_col_size);
	printf("mA = \n");
	printMtrx(mA, a_row_size, a_col_size);
	printf("\n");

	// mB
	mB = fGetMtrx(fin, &b_row_size, &b_col_size);
	printf("mB = \n");
	printMtrx(mB, b_row_size, b_col_size);
	printf("\n");

	// mC
	mC = fGetMtrx(fin, &c_row_size, &c_col_size);
	printf("mC = \n");
	printMtrx(mC, c_row_size, c_col_size);
	printf("\n");



	// MD = MA + MB
	d_row_size = a_row_size;
	d_col_size = b_col_size;
	mD = addMtrx(mA, mB, d_row_size, d_col_size);
	printf("mD = mA + mB \n");
	printMtrx(mD, d_row_size, d_col_size);
	printf("\n");

	// ME = MA - MB
	e_row_size = a_row_size;
	e_col_size = b_col_size;
	mE = subMtrx(mA, mB, e_row_size, e_col_size);
	printf("mE = mA - mB \n");
	printMtrx(mE, e_row_size, e_col_size);
	printf("\n");

	// MF = MA x MC
	f_row_size = a_row_size;
	f_col_size = c_col_size;
	mF = mulMtrx(mA, mC, a_row_size, a_col_size, c_col_size);
	printf("mF = mA * mC \n");
	printMtrx(mF, f_row_size, f_col_size);
	printf("\n");



	// inv_mF
	inv_mF = (double**)calloc(f_row_size, sizeof(double*));
	for (int i = 0; i < f_row_size; i++)
	{
				inv_mF[i] = (double*)calloc(f_row_size, sizeof(double));
	}
	invMtrxGaussJordanElim_FileOut(mF, inv_mF, f_row_size);
	printf(" Inv_mF : \n");
	printMtrx(inv_mF, f_row_size, f_col_size);
	printf("\n");

	// mG = mF * inv_mF
	g_row_size = f_row_size;
	g_col_size = f_col_size;
	mG = mulMtrx(mF, inv_mF, f_row_size, f_col_size, f_col_size);
	printf("mF = mA * mC \n");
	printMtrx(mG, g_row_size, g_col_size);
	printf("\n");




	// �����޸� ��ȯ & ���� �ݱ�
	deleteMtrx(mA, a_row_size, a_col_size);
	deleteMtrx(mB, b_row_size, b_col_size);
	deleteMtrx(mC, c_row_size, c_col_size);
	deleteMtrx(mD, d_row_size, d_col_size);
	deleteMtrx(mE, e_row_size, e_col_size);
	deleteMtrx(mF, f_row_size, f_col_size);
	deleteMtrx(inv_mF, f_row_size, f_col_size);
	deleteMtrx(mG, g_row_size, g_col_size);

	fclose(fin);

}
