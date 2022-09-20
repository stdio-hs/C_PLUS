/*

���ϸ� : PRACTICE_22

���α׷��� ���� �� �⺻��� : ���� _ �����迭 / ū�迭 ���

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 04�� 10�� _ ������Ʈ ���� / ���� ���� / ���� ���� ����
  2022�� 04�� 11�� _ ������Ʈ �ϼ�
  2022�� 04�� 13�� _ ������Ʈ ����

*/


#include "Algorithms.h"
#include "Sorting.h"

#define SMALL_SIZE 100
#define BIG_SIZE 50000000
#define SELECT_LIMIT_SIZE 50000


void SMALLARRAY(); 
void BIGARRAY();

int main()
{
	int menu;

	while (1)
	{
		printf("\n\n******************************************************************************\n");
		printf("                           <<<   Test Sorting   >>>\n");
		printf("  1: Compare the performance of sorting algorithms for [[[ SMALL ARRAY ]]] \n");
		printf("  2: Compare the performance of sorting algorithms for [[[ BIG ARRAY ]]]\n");
		printf("Input menu (0 to terminate) : ");
		scanf_s("%d", &menu);
		printf("\n");
		if (menu == 0)
			break;
		switch (menu)
		{
		case 1:
			SMALLARRAY();
			break;
		case 2:
			BIGARRAY();
			break;
		default:
			break;
		}
	}
	return 0;
}


// [ switch 1�� ] ( �� vs �պ� vs ���� _ ���Ľð��� + SMALLARRAY) 
void SMALLARRAY()
{
	int* array;
	int base = 10;

	LARGE_INTEGER freq, t1, t2;
	LONGLONG t_diff;
	double elapsed_time, elapsed_time_QS, elapsed_time_MS, elapsed_time_SS;


	QueryPerformanceFrequency(&freq);
	printf("Compare the performance of sorting algorithms for small array\n");
	printf("===================================================================\n");
	printf("Array size     QuickSork[us]     MergeSort[us]    SelectionSort[us]\n");
	printf("-------------------------------------------------------------------\n");

	for (int size = 10; size <= SMALL_SIZE; size += 5) // 10���� SMALL_SIZE(100���� �����ص�)���� 5�� Ŀ���� �迭�� ���� ������Ų��.
	{
		array = (int*)calloc(size, sizeof(int)); // �����޸��Ҵ��ϱ�. 
		if (array == NULL)
		{
			printf("Error in memory allocation for array\n");
			exit(1);
		}
		genBigRandArray(array, size, base); // �� ����� �´� �ߺ������ʴ� �����迭 ��������.


		QueryPerformanceCounter(&t1); // �ð�����_����
		quickSort(array, size); // ������
		QueryPerformanceCounter(&t2); // �ð�����_����
		t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000000; // �ð����������
		elapsed_time_QS = elapsed_time; // ������ _ �ð������� ����.


		QueryPerformanceCounter(&t1); // �ð�����_����
		mergeSort(array, size); // �պ�����
		QueryPerformanceCounter(&t2); // �ð�����_����
		t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000000; // �ð����������
		elapsed_time_MS = elapsed_time; // �պ����� _ �ð������� ����.


		QueryPerformanceCounter(&t1); // �ð�����_����
		selectionSort(array, size); // ��������
		QueryPerformanceCounter(&t2); // �ð�����_����
		t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000000; // �ð������
		elapsed_time_SS = elapsed_time; // �������� _ �ð������� ����.


		printf("%10d %15.2lf %16.2lf %17.2lf\n", size, elapsed_time_QS, elapsed_time_MS, elapsed_time_SS); // ������,�պ�����,�������� _ �ð������� ���	


		free(array); // �����迭 ��ȯ
	}
	printf("-------------------------------------------------------------------\n");
}


// [ switch 2�� ] ( �� vs �պ� vs ���� _ ���Ľð��� + BIGARRAY) 
void BIGARRAY()
{
	int* array;
	int base = 10;

	LARGE_INTEGER freq, t1, t2;
	LONGLONG t_diff;
	double elapsed_time, elapsed_time_QS, elapsed_time_MS, elapsed_time_SS;

	int size = 10000; // �迭ũ�� ������ 10000���� ����.



	QueryPerformanceFrequency(&freq);
	printf("Compare the performance of sorting algorithms for small array\n");
	printf("===================================================================\n");
	printf("Array size     QuickSork[ms]     MergeSort[ms]    SelectionSort[ms]\n");
	printf("-------------------------------------------------------------------\n");

	for (int size = 10000; size <= BIG_SIZE; size *= 2)
	{
		array = (int*)calloc(size, sizeof(int)); // �����޸��Ҵ��ϱ�. 
		if (array == NULL)
		{
			printf("Error in memory allocation for array\n");
			exit(1);
		}
		genBigRandArray(array, size, base); // �� ����� �´� �ߺ������ʴ� �����迭 ��������.


		QueryPerformanceCounter(&t1); // �ð�����_����
		quickSort(array, size); // ������
		QueryPerformanceCounter(&t2); // �ð�����_����
		t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // �ð����������
		elapsed_time_QS = elapsed_time; // ������ _ �ð������� ����.


		QueryPerformanceCounter(&t1); // �ð�����_����
		mergeSort(array, size); // �պ�����
		QueryPerformanceCounter(&t2); // �ð�����_����
		t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // �ð����������
		elapsed_time_MS = elapsed_time; // �պ����� _ �ð������� ����.

		if (size < SELECT_LIMIT_SIZE) // �迭ũ�Ⱑ Ŀ���� ���������� �ʹ� �����ɸ��⿡ ���������� ���� �������� �׸� �����ϱ�.
		{
			QueryPerformanceCounter(&t1); // �ð�����_����
			selectionSort(array, size); // ��������
			QueryPerformanceCounter(&t2); // �ð�����_����
			t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
			elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // �ð������
			elapsed_time_SS = elapsed_time; // �������� _ �ð������� ����.
		}


		if (size < SELECT_LIMIT_SIZE) // ������,�պ�����,�������� _ �ð������� ���	
		{
			printf("%10d %15.2lf %16.2lf %17.2lf\n", size, elapsed_time_QS, elapsed_time_MS, elapsed_time_SS);
		}
		else // ������,�պ����� _ �ð������� ���
		{
			printf("%10d %15.2lf %16.2lf                 -\n", size, elapsed_time_QS, elapsed_time_MS);	
		}


		free(array); // �����迭 ��ȯ
	}

\
	printf("-------------------------------------------------------------------\n");
}

