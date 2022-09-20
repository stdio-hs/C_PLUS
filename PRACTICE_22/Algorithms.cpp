#include "Algorithms.h"



// �ߺ������ʴ� ���� ������. + offset
void genBigRandArray(int* bigRandArray, int size, int offset)
{
	char* flag;
	unsigned int uint32;
	unsigned int bigRand;
	int count = 0;

	flag = (char*)calloc(size, sizeof(char));
	// flag �����޸�(�迭) �ޱ�
	// main �Լ����� [for���� Ȱ���Ͽ� ����� ������]��ŭ (char)flag �����޸� ����.

	srand((unsigned)time(0));
	while (count < size) // ó������ ������ ��������� �ϳ��� �˻�. (�ߺ��Ȱ��� �ִ���) 
	{
		uint32 = ((long)rand() << 15) | (long)rand(); // 15��Ʈ ������ (long)rand() ������ �ް�, �·� 15��Ʈ �̵� ��, (long)rand() �Լ� �ѹ� �� �޾� ����. _ �� ū ���� ����.  
		bigRand = uint32 % size; // unsigned int �� ���� �ʹ� ū uint32 �̹Ƿ� %size �� �Ͽ�, ���� ����Ͽ� �ߺ��� ���� �ִ��� �� ����.

		if (flag[bigRand] == 1) // ���� �ش� flag[bigRand]�� ���� �����ϸ�, �ݺ��� ��� �������� �̵�.
		{
			continue;
		}
		else // ���� �ش� flag[bigRand]�� ���� �������� ������,
		{
			flag[bigRand] = 1; // 1�� �����Ѵٷ� ������ְ�,
			bigRandArray[count++] = bigRand; // ���� ���� array[] �迭�� bigRand �Լ� ����.
		}
	}
	free(flag); // �����迭�� �׻� ��� ��, �ʱ�ȭ �����ش�.
}

// ū �迭 ��� _ ����â
void printBigArraySample(int* bigArray, int size, int items_per_line, int num_sample_lines)
{
	int count = 0;

	for (int first = 1; first < items_per_line * num_sample_lines;)
	{
		for (int j = 0; j < items_per_line; j++)
		{
			if (count >= size)
			{
				printf("\n");
				return;
			}
			printf("%10d", bigArray[first++]);
			count++;
		}
		printf("\n");
	}

	printf("\n     . . . . . . . . . . . . . . . \n\n");

	for (int last = size - items_per_line * num_sample_lines; last < size;)
	{
		for (int j = 0; j < items_per_line; j++)
		{
			if (count >= size)
			{
				printf("\n");
				return;
			}
			printf("%10d", bigArray[last++]);
		}
		printf("\n");
		count++;
	}
}




// �����Լ� _ �����Լ��� �� �������� ���� ���, �����񱳰� ���ǹ������Ƿ� ��ü������ ������.
/*
void suffleArray(int* array, int size)
{
	int i1, i2, d;
	srand((unsigned)time(NULL));

	for (int i = 0; i < size / 2; i++)
	{
		i1 = ((unsigned long)rand() << 15 | rand()) % size;
		i2 = ((unsigned long)rand() << 15 | rand()) % size;

		d = array[i1];
		array[i1] = array[i2];
		array[i2] = d;
	}
}
*/
