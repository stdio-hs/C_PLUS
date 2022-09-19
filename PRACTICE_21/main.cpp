/*

���ϸ� : PRACTCIE_21

���α׷��� ���� �� �⺻��� : �پ��� ����

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 04�� 04�� _ ������Ʈ ���� / ���� ���� / ���� ���� ����
  2022�� 04�� 05�� _ �������� / ��������
  2022�� 04�� 06�� _ ������
  2022�� 04�� 07�� _ ���̺긮�� / ������Ʈ �ϼ�
  2022�� 04�� 08�� _ LAB �˻� _ �����迭�� ���迭���� ���� ���..?
  2022�� 04�� 09�� _ ������Ʈ ����� �� �Ϻμ���
  2022�� 04�� 12�� _ ������ ���� (�����ڷ��ڵ� >> �ӽ������.cpp)
  2022�� 04�� 13�� _ ���̺긮������ ���� / �ּ�����

*/


#include "BigArray_Algorithms.h"
#include "BigArray_Sortings.h"

#define SMALL_SIZE 100
void compare_sorting_algorithms_smallIntArray(); // siwtch 1��
void testBigRandArray(); // siwtch 2��
void PM_Hybrid_QS_SS_IntArray(); // siwtch 3��



// main �Լ�
int main(void)
{
	int menu;

	while (1)
	{
		printf("\n\n*****************************************************************************************\n");
		printf("\nTest Array Algorithms :\n");
		printf("  1: Performance Comparison of Selection Sort and Quick Sort for Small Integer Array\n");
		printf("  2: Test bigRandArray (Array_size : 1,000,000 ~ 50,000,000)\n");
		printf("  3: Performance Measurements of hybrid_QS_SS for Integer Array\n");
		printf("Input menu (0 to terminate) : ");
		scanf_s("%d", &menu);
		printf("\n");
		if (menu == 0)
			break;
		switch (menu)
		{
		case 1:
			compare_sorting_algorithms_smallIntArray();
			break;
		case 2:
			testBigRandArray();
			break;
		case 3:
			PM_Hybrid_QS_SS_IntArray();
			break;
		default:
			break;
		}
	}
	return 0;
}



// [ switch 1�� ] ( �� vs �պ� vs ���� _ ���Ľð���) 
void compare_sorting_algorithms_smallIntArray()
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



//  [ switch 2�� ] ( ���� ��&�� ��) _ ���̺긮�����ķ� �����ص�. 
void testBigRandArray()
{
	int* bigArray;
	int size, offset;
	while (1)
	{
		printf("Input bigRandArray_size (0 to quit) and offset : ");
		scanf_s("%d %d", &size, &offset); // �迭ũ�� + offset �Է°� �ޱ�.
		if (size == 0) // �Է°��� ������� break;
		{
			break;
		}


		bigArray = (int*)calloc(size, sizeof(int)); // �����޸��Ҵ�.
		if (bigArray == NULL)
		{
			printf("Error in memory allocation");
			exit(1);
		}


		genBigRandArray(bigArray, size, offset); // �ߺ������ʴ� �����迭 ����.


		printf("Generated non-duplicated random array : \n");
		printBigArraySample(bigArray, size, 10, 2); // ���ĵ������� �迭 ���
		printf("\n\nSorted array : \n");
		hybridQuickSelectionSort(bigArray, size); // ���̺긮������
		printBigArraySample(bigArray, size, 10, 2); // ���ĵ� �迭 ���
	
		
		free(bigArray); // �����޸𸮹�ȯ
	}
}


//  [ switch 3�� ] ( ������ vs ���̺긮������)
void PM_Hybrid_QS_SS_IntArray()
{
	int* array;
	int size, base = 10;
	LARGE_INTEGER freq, t1, t2;
	LONGLONG t_diff;
	double elapsed_time, elapsed_QS, elapsed_HYBRID;

	printf("QS_SS_THRESHOLD = %d\n", QUICK_SELECTION_THRESHOLD);
	printf("=================================================================\n");
	printf("Array size    QuickSort[ms]    HybridQuickSelectionSort[ms]\n");
	printf("-----------------------------------------------------------------\n");
	QueryPerformanceFrequency(&freq);


	for (size = 100000; size <= 500000; size += 100000) // ( 10�� 20�� 30�� 40�� 50�� )
	{

		// ������
		array = (int*)calloc(size, sizeof(int)); // �����޸��Ҵ�
		if (array == NULL)
		{
			printf("Error in memory allocation!");
			exit(1);
		}

		genBigRandArray(array, size, base); // �ߺ������ʴ� �����迭 ����.

		QueryPerformanceCounter(&t1); // �ð�����_����
		quickSort(array, size); // ������
		QueryPerformanceCounter(&t2); // �ð�����_����

		t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // �ð������
		elapsed_QS = elapsed_time; // ������ _ �ð������� ����.
		free(array); //�����޸𸮹�ȯ



		// ���̺긮������
		array = (int*)calloc(size, sizeof(int)); // �����޸��Ҵ�
		if (array == NULL)
		{
			printf("Error in memory allocation!");
			exit(1);
		}

		genBigRandArray(array, size, base); // �ߺ������ʴ� �����迭 ����.

		QueryPerformanceCounter(&t1); // �ð�����_����
		hybridQuickSelectionSort(array, size); // ���̺긮������
		QueryPerformanceCounter(&t2); // �ð�����_����

		t_diff = t2.QuadPart - t1.QuadPart; // �ð����� = �ð�����_���� - �ð�����_����
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // �ð������
		elapsed_HYBRID = elapsed_time; // ������ _ �ð������� ����.
		free(array); //�����޸𸮹�ȯ
		
		

		// ���
		printf("%10d %15.2lf %15.2lf\n", size, elapsed_QS, elapsed_HYBRID);
	}
	printf("-----------------------------------------------------------------\n");
}