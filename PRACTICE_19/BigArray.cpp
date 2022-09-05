#include "BigArray.h"

// ���� ���� ������ _ �������
void getBigRandArray(int* array, int bigRandSize) //���� �Ŵ��� ���� ���� ������
{
	char* flag;
	unsigned int uint32;
	unsigned int bigRand;
	int count = 0;

	flag = (char*)calloc(bigRandSize, sizeof(char));
	// flag �����޸�(�迭) �ޱ�
	// main �Լ����� [for���� Ȱ���Ͽ� ����� ������]��ŭ (char)flag �����޸� ����.

	while (count < bigRandSize) // ó������ ������ ��������� �ϳ��� �˻�. (�ߺ��Ȱ��� �ִ���) 
	{
		uint32 = ((long)rand() << 15) | (long)rand(); // 15��Ʈ ������ (long)rand() ������ �ް�, �·� 15��Ʈ �̵� ��, (long)rand() �Լ� �ѹ� �� �޾� ����. _ �� ū ���� ����.  
		bigRand = uint32 % bigRandSize; // unsigned int �� ���� �ʹ� ū uint32 �̹Ƿ� %size �� �Ͽ�, ���� ����Ͽ� �ߺ��� ���� �ִ��� �� ����.

		if (flag[bigRand] == 1) // ���� �ش� flag[bigRand]�� ���� �����ϸ�, �ݺ��� ��� �������� �̵�.
		{
			continue;
		}
		else // ���� �ش� flag[bigRand]�� ���� �������� ������,
		{
			flag[bigRand] = 1; // 1�� �����Ѵٷ� ������ְ�,
			array[count++] = bigRand; // ���� ���� array[] �迭�� bigRand �Լ� ����.
		}
	}
}


// (����â) ū �迭 ���
void printBigArraySample(int* array, int size, int line_size)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array++) // �տ������� �ϳ��� ��� _ ( 30�� ��� )
		{
			printf("%8d", *array);
		}
		printf("\n");
	}
	printf("    .  .  .  .  .  . \n\n");  // ����ؾ� �� ���� �ʹ� ���Ƽ� �߰� �κ� ����.

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array--) // �ڿ������� �ϳ��� ��� _ ( 30�� ��� )
		{
			printf("%8d", *(array + size - 31));
		}
		printf("\n");
	}
}

// (����) ū �迭 ���
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_line)
{
	int count = 1;
	for (int i = 0; i < num_line; i++)
	{
		for (int j = 0; j < line_size; j++, array++) // �տ������� �ϳ��� ��� _ ( 30�� ��� )
		{
			fprintf(fout, "%8d", *array);
			count++;
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "    .  .  .  .  .  . \n"); // ����ؾ� �� ���� �ʹ� ���Ƽ� �߰� �κ� ����.

	for (int i = 0; i < num_line; i++)
	{
		for (int j = 0; j < line_size; j++, array--) // �ڿ������� �ϳ��� ��� _ ( 30�� ��� )
		{
			fprintf(fout, "%8d", *(array + size - count));
		}
		fprintf(fout, "\n");
	}
}

