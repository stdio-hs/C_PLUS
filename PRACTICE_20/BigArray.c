#include "BigArray.h"

// (����â) ��갪 ���
void getArrayStatistics(int* data_array, int num_data)
{
	int data;
	int min = 0, max = 0;
	double sum = 0.0, avg = 0.0, var = 0.0, std = 0.0;
	double diff, diff_sum = 0.0;


	for (int i = 0; i < num_data; i++)
	{
		data = data_array[i];

		if (i == 0) // ( ���ذ��� ���� ) num_data[0]�� �ִ� �ּ� �񱳱��ذ����� ����.
		{
			min = max = data_array[0];
		}
		else {
			if (data < min)
				min = data; // �ּҰ�
			if (data > max)
				max = data; // �ִ밪
		}
		sum += data; // ��
	}

	avg = sum / (double)num_data; // ���

	for (int i = 0; i < num_data; i++) // �л� _ 1
	{
		diff = data_array[i] - avg;
		diff_sum += diff * diff;
	}
	var = diff_sum / (double)num_data; //�л� _ 2
	std = sqrt(var); // ǥ������

	// ����â ���
	if (num_data < 50000) // �迭 ����� ���� ���.
	{
		printf("Total ( %d ) integer data : \n", num_data);
		printArray(data_array, num_data, 10);
		printf("min : ( %d ) / max : ( %d ) / ", min, max);
		printf("sum : ( %.2lf ) / average : ( %.2lf ) / ", sum, avg);
		printf("variance : ( %.2lf ) / standard deviation : ( %.2lf\n )", var, std);
	}
	else if (num_data >= 50000) // �迭 ����� Ŭ ���. ( �߰� �κ� ������. )
	{
		printf("Total ( %3d ) integer data : \n", num_data);
		printBigArraySample(data_array, num_data, LINE_SIZE, NUM_LINE);
		printf("min ( %3d ) / max( %3d ) / sum( %8.2lf ) / average ( %8.2lf ) / ", min, max, sum, avg);
		printf("variance ( %8.2lf ) / standard deviation ( %8.2lf ) \n", var, std);
	}
}
// (����) ��갪 ���
void fgetArrayStatistics(FILE* fout, int* data_array, int num_data)
{

	int data;
	int min = 0, max = 0;
	double sum = 0.0, avg = 0.0, var = 0.0, std = 0.0;
	double diff, diff_sum = 0.0;


	for (int i = 0; i < num_data; i++)
	{
		data = data_array[i];

		if (i == 0) // ( ���ذ��� ���� ) num_data[0]�� �ִ� �ּ� �񱳱��ذ����� ����.
		{
			min = max = data_array[0];
		}
		else {
			if (data < min)
				min = data; // �ּҰ�
			if (data > max)
				max = data; // �ִ밪
		}
		sum += data; // ��
	}

	avg = sum / (double)num_data; // ���


	for (int i = 0; i < num_data; i++) // �л� _ 1
	{
		diff = data_array[i] - avg;
		diff_sum += diff * diff;
	}
	var = diff_sum / (double)num_data; // �л� _ 2
	std = sqrt(var); // ǥ������

	// �޸��� ���
	if (num_data < 50000) // �迭 ����� ���� ���.
	{
		fprintf(fout, "Total ( %d ) integer data : \n", num_data);
		fprintArray(fout, data_array, num_data, 10);
		fprintf(fout, "min : ( %d ) / max : ( %d ) / ", min, max);
		fprintf(fout, "sum : ( %.2lf ) / average : ( %.2lf ) / ", sum, avg);
		fprintf(fout, "variance : ( %.2lf ) / standard deviation : ( %.2lf\n )", var, std);
	}

	else if (num_data >= 50000) // �迭 ����� Ŭ ���. ( �߰� �κ� ������. )
	{
		fprintf(fout, "Total ( %3d ) integer data : \n", num_data);
		fprintBigArraySample(fout, data_array, num_data, LINE_SIZE, NUM_LINE);
		fprintf(fout, "min ( %3d ) / max( %3d ) / sum( %8.2lf ) / average ( %8.2lf ) / ", min, max, sum, avg);
		fprintf(fout, "variance ( %8.2lf ) / standard deviation ( %8.2lf ) \n", var, std);
	}
}


// (����â) �迭 ���
void printArray(int* array, int size, int line_size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%5d", array[i]);
		if ((i + 1) % line_size == 0) // line_size��ŭ ��µǸ� �ٹٲ�
		{
			printf("\n");
		}
	}
	printf("\n");
}
// (����) �迭 ���
void fprintArray(FILE* fout, int* array, int size, int line_size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(fout, "%5d", array[i]);
		if ((i + 1) % line_size == 0)  // line_size��ŭ ��µǸ� �ٹٲ�
		{
			fprintf(fout, "\n");
		}
	}
}


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

	srand((unsigned)time(0));
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
void printBigArraySample(int* array, int size, int line_size, int num_size)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array++)
		{
			printf("%8d", *array);
		}
		printf("\n");
	}
	printf("    .  .  .  .  .  . \n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array--)
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
	for (int i = 0; i < line_size; i++)
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

