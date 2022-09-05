/*

���ϸ� : PRACTICE_19

���α׷��� ���� �� �⺻��� : �ߺ����� �ʴ� ���� �迭 ��� _ ( 1. ����â ��� / 2. �ؽ�Ʈ���� ��� )


���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 4�� 1��

*/

#include "BigArray.h"


int main()
{
	int* array = NULL; // ���� �޸� �迭�� ������
	int size;


	FILE* fout = NULL; // FILE ������ fout�� �����ϰ� NULL�� �ʱ�ȭ
	fout = fopen(Output_File, "w"); //������ ������� ����, �ּҸ� fout�� ����
	if (fout == NULL) // ������ ���� ���� ���, ( ���� + �������� )
	{
		printf("Error in creation of Output_File");
	}

	printf("Input size of big array ( more than 500000 ) = ");
	scanf_s("%d", &size);

	array = (int*)calloc(size, sizeof(int)); //�����޸�(�迭) �ޱ� _ �����(����,������)
	if (array == NULL) // �޸𸮸� �Ҵ� ���� ���� ���.
	{
		printf("Error in dynamic memeory allocation for integer array of size (%d)\n", size);
		exit(-1); // ����
	}

	getBigRandArray(array, size); // �����޸��Ҵ��Ͽ� �ߺ����� �ʴ� ���� �迭 ����
	printBigArraySample(array, size, LINE_SIZE); // (����â) ū �迭 ���

	fprintBigArraySample(fout, array, size, LINE_SIZE, NUM_LINE); // (����) ū �迭 ���

}