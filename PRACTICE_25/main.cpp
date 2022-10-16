/*

���ϸ� : PRACTICE_25

���α׷��� ���� �� �⺻��� : �����޸��Ҵ� 2�����迭 / ���� �� ���

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 04�� 11�� _ ������Ʈ ���� / ���� Ʋ ¥��.
  2022�� 04�� 12�� _ Code.h & Code.cpp �ۼ� _ ���� getStatisticsMtrx()�����.
  2022�� 04�� 13�� _ getStatisticsMtrx() �Լ� �����.
  2022�� 04�� 14�� _ main.cpp �ۼ�
  2022�� 04�� 15�� _ getStatisticsMtrx() �� realloc�� �ص� ���� �ʳ�? �ǹ�

*/

#include "Code.h"

void checkAddress_2DArray_for_Matrix(); // �����޸��Ҵ� �ּ���ġ Ȯ��
void test_2D_DynamicArray_FileIO_Statistics(); // �����޸��Ҵ��Ͽ� ���Ϸκ��� ��� �Է�
void test_Matrix_Addition_Subtraction(); // ��� ���� & ����
void test_Matrix_Multiplication(); // ��� ����



// main �Լ�
int main()
{
	int menu;
	while (1)
	{
		printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
		printf("Testing Matrix Operations with 2-Dimensional Dynamic Array \n"); 
		printf(" 1: Check addresses of 2-Dim array for Matrix / �����޸��Ҵ� �ּ���ġ Ȯ�� \n");
		printf(" 2: Test 2-D Dynamic Array Creation for Matrix with File I/O, Statistics / ���Ϸκ��� ��� ��������. \n");
		printf(" 3: Test Matrix Addition, Subtraction / ��� ( ���� &  ���� )\n");
		printf(" 4: Test Matrix Multiplication / ��� ( ���� ) \n");
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



// �����޸��Ҵ� �ּ���ġ Ȯ��
void checkAddress_2DArray_for_Matrix()
{
	double** dM;
	int row_size = 3;
	int col_size = 3;

	dM = createDoubleMtrx(row_size, col_size); // ���μ��� ���̸�ŭ �����޸� �Ҵ�
	checkAddress_2DArray(dM, row_size, col_size); // �����޸��Ҵ��� ��ġ�� �ľ��ϱ�.
	deleteDoubleMtrx(dM, row_size); // �����޸� ��ȯ�����ֱ�.
}

// 2�����迭 ��� + ( ��/��/��ü ) ��հ� �߰��� Ȯ�� 2�����迭 ���
void test_2D_DynamicArray_FileIO_Statistics()
{
	
	FILE* fn;
	int a_row_size, a_col_size; // 3*5 �迭
	int b_row_size, b_col_size; // 3*3 �迭
	double** dMA; // ù��° 2�����迭
	double** dMB; // �ι��� 2�����迭
	double** dMR;


	fn = fopen(WRITE_FILE, "r");
	if (fn == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}




	// ù��° 2�����迭
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )

	dMA = fgetDoubleMtrx(fn, a_row_size, a_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size); // ���_1 ( ù�� )
	printMtrx(dMA, a_row_size, a_col_size); // ���_2 ( ���� )
	printf("\n");
	
	dMR = getStatisticsMtrx(dMA, a_row_size, a_col_size); // ( ��/��/��ü ) ��հ��� �߰��� 2�����迭(Ȯ��) 
	printf("Matrix_A ( %d x %d ) with row & col averages : \n", a_row_size, a_col_size);
	printMtrx(dMR, a_row_size + 1, a_col_size + 1); printf("\n"); // ( ��/��/��ü ) ��հ��� �߰��� 2�����迭(Ȯ��) _ ���
	deleteDoubleMtrx(dMR, a_row_size + 1); // dMR �Լ� ��ȯ
	


	// �ι�° 2�����迭
	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size);  // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )

	dMB = fgetDoubleMtrx(fn, b_row_size, b_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size); // ���_1 ( ù�� )
	printMtrx(dMB, b_row_size, b_col_size); printf("\n"); // ���_2 ( ���� )
	printf("\n");

	dMR = getStatisticsMtrx(dMB, b_row_size, b_col_size); // ( ��/��/��ü ) ��հ��� �߰��� 2�����迭(Ȯ��)
	printf("Matrix_B ( %d x %d) with row & col averages : \n", b_row_size, b_col_size);
	printMtrx(dMR, b_row_size + 1, b_col_size + 1); printf("\n"); // ( ��/��/��ü ) ��հ��� �߰��� 2�����迭(Ȯ��) _ ���
	deleteDoubleMtrx(dMR, b_row_size + 1); // dMR �Լ� ��ȯ


	// �����޸��Ҵ�����͵� ��ȯ
	deleteDoubleMtrx(dMA, a_row_size);
	deleteDoubleMtrx(dMB, b_row_size);
	fclose(fn);
}

// 2�����迭 ( ���� / ���� ) 
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

	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )
	dMA = fgetDoubleMtrx(fn, a_row_size, a_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size);  // ���_1 ( ù�� )
	printMtrx(dMA, a_row_size, a_col_size); // ���_2 ( ���� )
	printf("\n");

	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )
	dMB = fgetDoubleMtrx(fn, b_row_size, b_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);  // ���_1 ( ù�� )
	printMtrx(dMB, b_row_size, b_col_size); // ���_2 ( ���� )
	printf("\n");


	if ((a_row_size != b_row_size) || (a_col_size != b_col_size))
	{
		printf("Error in input matrix dimension: row_size and/or col_size are not equal !!\n");
		fclose(fn);
		return;
	}



	// ���� ( + )
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	dMC = createDoubleMtrx(c_row_size, c_col_size);
	addMtrx(dMA, dMB, dMC, a_row_size, a_col_size);
	printf("Matrix_C (%d x %d) = Matrix_A + Matrix_B : \n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);
	printf("\n");
	
	
	
	// ���� ( - )
	d_row_size = a_row_size;
	d_col_size = b_col_size;
	dMD = createDoubleMtrx(d_row_size, d_col_size);
	subMtrx(dMA, dMB, dMD, a_row_size, a_col_size);
	printf("Matrix_D (%d x %d) = Matrix_A - Matrix_B : \n", d_row_size, d_col_size);
	printMtrx(dMD, d_row_size, d_col_size);
	printf("\n");



	// �����޸� ��ȯ 
	deleteDoubleMtrx(dMA, a_row_size);
	deleteDoubleMtrx(dMB, b_row_size);
	deleteDoubleMtrx(dMD, d_row_size);
	deleteDoubleMtrx(dMC, c_row_size);
	fclose(fn);
}

// 2�����迭 ( ���� )
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
	
	
	
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )
	dMA = fgetDoubleMtrx(fn, a_row_size, a_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size); // ���_1 ( ù�� )
	printMtrx(dMA, a_row_size, a_col_size); // ���_2 ( ���� )
	printf("\n");



	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )
	dMB = fgetDoubleMtrx(fn, b_row_size, b_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size); // ���_1 ( ù�� )
	printMtrx(dMB, b_row_size, b_col_size); // ���_2 ( ���� )
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
