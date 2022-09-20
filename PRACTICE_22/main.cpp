/*

파일명 : PRACTICE_22

프로그램의 목적 및 기본기능 : 정렬 _ 작은배열 / 큰배열 출력

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 04월 10일 _ 프로젝트 생성 / 문제 이해 / 관련 지식 공부
  2022년 04월 11일 _ 프로젝트 완성
  2022년 04월 13일 _ 프로젝트 수정

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


// [ switch 1번 ] ( 퀵 vs 합병 vs 선택 _ 정렬시간비교 + SMALLARRAY) 
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

	for (int size = 10; size <= SMALL_SIZE; size += 5) // 10부터 SMALL_SIZE(100으로 정의해둠)까지 5씩 커지는 배열을 각각 측정시킨다.
	{
		array = (int*)calloc(size, sizeof(int)); // 동적메모리할당하기. 
		if (array == NULL)
		{
			printf("Error in memory allocation for array\n");
			exit(1);
		}
		genBigRandArray(array, size, base); // 각 사이즈에 맞는 중복되지않는 난수배열 가져오기.


		QueryPerformanceCounter(&t1); // 시간측정_시작
		quickSort(array, size); // 퀵정렬
		QueryPerformanceCounter(&t2); // 시간측정_종료
		t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000000; // 시간측정값계산
		elapsed_time_QS = elapsed_time; // 퀵정렬 _ 시간측정값 저장.


		QueryPerformanceCounter(&t1); // 시간측정_시작
		mergeSort(array, size); // 합병정렬
		QueryPerformanceCounter(&t2); // 시간측정_종료
		t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000000; // 시간측정값계산
		elapsed_time_MS = elapsed_time; // 합병정렬 _ 시간측정값 저장.


		QueryPerformanceCounter(&t1); // 시간측정_시작
		selectionSort(array, size); // 선택정렬
		QueryPerformanceCounter(&t2); // 시간측정_종료
		t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000000; // 시간값계산
		elapsed_time_SS = elapsed_time; // 선택정렬 _ 시간측정값 저장.


		printf("%10d %15.2lf %16.2lf %17.2lf\n", size, elapsed_time_QS, elapsed_time_MS, elapsed_time_SS); // 퀵정렬,합병정렬,선택정렬 _ 시간측정값 출력	


		free(array); // 동적배열 반환
	}
	printf("-------------------------------------------------------------------\n");
}


// [ switch 2번 ] ( 퀵 vs 합병 vs 선택 _ 정렬시간비교 + BIGARRAY) 
void BIGARRAY()
{
	int* array;
	int base = 10;

	LARGE_INTEGER freq, t1, t2;
	LONGLONG t_diff;
	double elapsed_time, elapsed_time_QS, elapsed_time_MS, elapsed_time_SS;

	int size = 10000; // 배열크기 시작을 10000으로 설정.



	QueryPerformanceFrequency(&freq);
	printf("Compare the performance of sorting algorithms for small array\n");
	printf("===================================================================\n");
	printf("Array size     QuickSork[ms]     MergeSort[ms]    SelectionSort[ms]\n");
	printf("-------------------------------------------------------------------\n");

	for (int size = 10000; size <= BIG_SIZE; size *= 2)
	{
		array = (int*)calloc(size, sizeof(int)); // 동적메모리할당하기. 
		if (array == NULL)
		{
			printf("Error in memory allocation for array\n");
			exit(1);
		}
		genBigRandArray(array, size, base); // 각 사이즈에 맞는 중복되지않는 난수배열 가져오기.


		QueryPerformanceCounter(&t1); // 시간측정_시작
		quickSort(array, size); // 퀵정렬
		QueryPerformanceCounter(&t2); // 시간측정_종료
		t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // 시간측정값계산
		elapsed_time_QS = elapsed_time; // 퀵정렬 _ 시간측정값 저장.


		QueryPerformanceCounter(&t1); // 시간측정_시작
		mergeSort(array, size); // 합병정렬
		QueryPerformanceCounter(&t2); // 시간측정_종료
		t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // 시간측정값계산
		elapsed_time_MS = elapsed_time; // 합병정렬 _ 시간측정값 저장.

		if (size < SELECT_LIMIT_SIZE) // 배열크기가 커지면 선택정렬이 너무 오래걸리기에 선택정렬은 일정 구간부터 그만 측정하기.
		{
			QueryPerformanceCounter(&t1); // 시간측정_시작
			selectionSort(array, size); // 선택정렬
			QueryPerformanceCounter(&t2); // 시간측정_종료
			t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
			elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // 시간값계산
			elapsed_time_SS = elapsed_time; // 선택정렬 _ 시간측정값 저장.
		}


		if (size < SELECT_LIMIT_SIZE) // 퀵정렬,합병정렬,선택정렬 _ 시간측정값 출력	
		{
			printf("%10d %15.2lf %16.2lf %17.2lf\n", size, elapsed_time_QS, elapsed_time_MS, elapsed_time_SS);
		}
		else // 퀵정렬,합병정렬 _ 시간측정값 출력
		{
			printf("%10d %15.2lf %16.2lf                 -\n", size, elapsed_time_QS, elapsed_time_MS);	
		}


		free(array); // 동적배열 반환
	}

\
	printf("-------------------------------------------------------------------\n");
}

