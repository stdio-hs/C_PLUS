#include "Code.h"



//�ѤѤѤѤ�--�ѤѤ�--�ѤѤѤ�----��--�Ѥ� [ �����޸��Ҵ� �ּ���ġ Ȯ�� �Լ� ] �ѤѤѤѤѤѤѤѤ�--��--��--�ѤѤ�----��


// �ش� �����޸��Ҵ� �ּ���ġ Ȯ�� �Լ�
void checkAddress_2DArray(double** dM, int row_size, int col_size)
{
	printf("dM = %p\n", dM); // %p �� �ּҸ� ����Ų��.
	printf("dM[0] = %p\n", dM[0]);
	printf("dM[1] = %p\n", dM[1]);
	printf("dM[2] = %p\n", dM[2]);
	printf("&dM[0][0] = %p\n", &dM[0][0]);
	printf("&dM[1][0] = %p\n", &dM[1][0]);
	printf("&dM[2][0] = %p\n", &dM[2][0]);
	printf("\n");
}


//�ѤѤѤѤ�--�ѤѤ�--�ѤѤѤ�----��--�Ѥ� [ 2�����Ǽ��迭 ���� �Լ� ] �ѤѤѤѤѤѤѤѤ�--��--��--�ѤѤ�----��


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
double** fgetDoubleMtrx(FILE* fp, int row_size, int col_size)
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
void deleteDoubleMtrx(double** dM, int row_size)
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


//�ѤѤѤѤ�--�ѤѤ�--�ѤѤѤ�----��--�Ѥ� [ 2�����Ǽ��迭(���) ���� �Լ� ] �ѤѤѤѤѤѤѤѤ�--��--��--�ѤѤ�----��


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

// ( ��/��/��ü ) ���
double** getStatisticsMtrx(double** dM, int row_size, int col_size)
{
	double sum = 0.00;
	double average = 0.00;

	double** dMA; 
	dMA = createDoubleMtrx(row_size + 1, col_size + 1); // �����迭�����Դϴ�.


	// ( ���� 2�����迭 dM �� >> Ȯ��2�����迭 dMA )�� ���� ���� �Ű��ش�.
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			dMA[i][j] = dM[i][j];
			sum += dM[i][j]; // �� �κп��� 2�����迭 �� ���� �̸� ���س��´� ( ��� ��ü ����� ���ϱ� ����. )
		}
	}

	// ( ���� 2�����迭 dM�� ��� �ִ� �� row�� ����ִ� col ) ��հ��� dMA �迭�� �־��ش�.
	for (int i = 0; i < row_size; i++) // ����
	{
		for (int j = 0; j < col_size; j++)
		{
			dMA[i][col_size] = (dMA[i][col_size] + dM[i][j]);
		}
	}
	for (int a = 0; a < row_size; a++) // ���
	{
		dMA[a][col_size] = (dMA[a][col_size] / col_size);
	}


	// ( ���� 2�����迭 dM�� ��� �ִ� �� col�� ����ִ� row ) ��հ��� dMA �迭�� �־��ش�.
	for (int i = 0; i < col_size; i++) // ����
	{
		for (int j = 0; j < row_size; j++)
		{
			dMA[row_size][i] = (dMA[row_size][i] + dM[j][i]);
		}
	}
	for (int a = 0; a < col_size; a++) // ���
	{
		dMA[row_size][a] = (dMA[row_size][a] / row_size);
	}


	average = sum / (row_size * col_size); // ��� ���ϴ� ����
	dMA[row_size][col_size] = average; // �ش� �κп� ��� ���� �־��ش�.
	
	return dMA; // (Ȯ��� 2�����迭��) dMA�Լ��� ���Ͻ����ش�.
}





