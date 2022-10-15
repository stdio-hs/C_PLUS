/*

���ϸ� : PRACTICE_24

���α׷��� ���� �� �⺻��� : �����޸��Ҵ� 2�����迭 / ����

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 04�� 16�� _ ������Ʈ �ϼ�

*/


#include "Code.h"
#include "Mtrx.h"

void test_MATRX();

int main()
{
	printf(" - - - - - - - - - - - - - - - [ �迭 �⺻ ��Ģ���� ] - - - - - - - - - - - - - - - \n\n");
	test_MATRX();
}

void test_MATRX()
{
	int a_row_size, a_col_size; // 4*7 �迭
	int b_row_size, b_col_size; // 7*4 �迭


	double** dMA; // ù��° 2�����迭
	double** dMB; // �ι��� 2�����迭
	double** dMC; // ����° 2�����迭  

	double** dMD; // ����
	double** dME; // ����
	double** dMF; // ����

	FILE* fn;
	fn = fopen(WRITE_FILE, "r");
	if (fn == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}


	// ù��° 2�����迭
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )
	dMA = fgetMtrx(fn, a_row_size, a_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("mA = \n"); // ���_1 ( ù�� )
	printMtrx(dMA, a_row_size, a_col_size); // ���_2 ( ���� )
	printf("\n");


	// �ι�° 2�����迭
	fscanf_s(fn, "%d %d", &a_row_size, &a_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )
	dMB = fgetMtrx(fn, a_row_size, a_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("mB = \n"); // ���_1 ( ù�� )
	printMtrx(dMB, a_row_size, a_col_size); // ���_2 ( ���� )
	printf("\n");


	// ����° 2�����迭
	fscanf_s(fn, "%d %d", &b_row_size, &b_col_size); // ���Ϸκ��� 2���� �Ǽ��� �޾�, ��� ���� ����. _ ( ù��° �迭 ��� �� )
	dMC = fgetMtrx(fn, b_row_size, b_col_size); // �������ŭ �����޸𸮸� �Ҵ��Ű��, �� ĭ�� ���Ϸκ��� ���� �����Ų��.
	printf("mC = \n"); // ���_1 ( ù�� )
	printMtrx(dMC, b_row_size, b_col_size); // ���_2 ( ���� )
	printf("\n");


	// ����
	dMD = createDoubleMtrx(a_row_size, a_col_size);
	addMtrx(dMA, dMB, dMD, a_row_size, a_col_size);
	printf("mD = mA + mB = \n");
	printMtrx(dMD, a_row_size, a_col_size);
	printf("\n");


	// ����
	dME = createDoubleMtrx(a_row_size, a_col_size);
	subMtrx(dMA, dMB, dME, a_row_size, a_col_size);
	printf("mE = mA - mB = \n");
	printMtrx(dME, a_row_size, a_col_size);
	printf("\n");


	// ����
	dMF = createDoubleMtrx(a_row_size, b_col_size);
	multiplyMtrx(dMA, dMC, dMF, a_row_size, b_col_size, a_col_size);
	printf("mF = mA * mC = \n");
	printMtrx(dMF, a_row_size, b_col_size);
	printf("\n");



	deleteMtrx(dMA, a_row_size); // dMA �Լ� ��ȯ
	deleteMtrx(dMB, a_row_size); // dMB �Լ� ��ȯ
	deleteMtrx(dMC, b_row_size); // dMC �Լ� ��ȯ
	fclose(fn);
}
