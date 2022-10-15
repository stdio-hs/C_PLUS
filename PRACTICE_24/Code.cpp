#include "Code.h"



// 2�����Ǽ��迭�� ���� ���� �Լ� _ ( ��/�� >> dM[] )
double** createDoubleMtrx(int row_size, int col_size)
{
	double** dM; // ����������_�����͸� ����Ű�� ������ (2�����迭�̱⶧��)
	dM = (double**)calloc(row_size, sizeof(double*)); // ��(��) double������� �����޸� �Ҵ�
	for (int r = 0; r < row_size; r++)
	{
		dM[r] = (double*)calloc(col_size, sizeof(double)); // ��(��) �����ŭ ��ĭ��ĭ �ݺ����� ���� ��(��)�� double������� �����޸� �Ҵ�
	}
	return dM; // dM���� �����ϱ�. ( ��/�� >> dM[] )
}

// 2�����Ǽ��迭�� ���Ϸκ��� �Է¹޾ƿ��� �Լ� _ ( ��/�� >> dM[] )
double** fgetMtrx(FILE* fp, int row_size, int col_size)
{
	double d = 0.0;
	double** dM;

	if (fp == NULL)
	{
		printf("Error in getDoubleMtrx() - file pointer is NULL !!\n");
		exit(-1); // ���Ͽ� �ƹ��͵� ���� ���, ( ���� + ����â���� )
	}

	dM = createDoubleMtrx(row_size, col_size); // ��&�� ũ�⸸ŭ �����޸� �Ҵ�

	for (int m = 0; m < row_size; m++) // ��
		for (int n = 0; n < col_size; n++) // ��
		{
			if (fscanf_s(fp, "%lf", &d) != EOF) // EOF �� ������ ���� �ǹ��Ѵ�. <stdio.h> ������ EOF = -1�� ���ǵǾ� ����.
				dM[m][n] = d;
			// ���Ϸκ��� ������ �����͸� �ش� ������ �ϳ��� �����ϱ�.
			// ex) [0][0], [0][1], [0][2], [1][0], [1][1], [1][2]
		}

	return dM; // dM���� ���Ͻ�Ų��. ( ��/�� >> dM[] )
}

// 2�����Ǽ��迭�� ���� ��ȯ �Լ�
void deleteMtrx(double** dM, int row_size)
{
	for (int a = 0; a < row_size; a++)
	{
		free(dM[a]); // ��(��) �ȿ� �ִ� ��(��)���� �ϳ��� �����޸𸮸� ��ȯ�Ѵ�.
		// free(*dM++)
		// free(*(dM+i))
	}
	free(dM); // ���� ����� �����ִ� ��(��)�� �����޸� ��ȯ�Ѵ�.
}

// 2�����Ǽ��迭�� ����â ���
void printMtrx(double** dM, int row_size, int col_size)
{
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;


	for (int i = 0; i < row_size; i++) // ��
	{
		for (int j = 0; j < col_size; j++) // ��
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



