/*

파일명 : PRACTCIE_21

프로그램의 목적 및 기본기능 : 다양한 정렬

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 04월 04일 _ 프로젝트 생성 / 문제 이해 / 관련 지식 공부
  2022년 04월 05일 _ 선택정렬 / 병합정렬
  2022년 04월 06일 _ 퀵정렬
  2022년 04월 07일 _ 하이브리드 / 프로젝트 완성
  2022년 04월 08일 _ LAB 검사 _ 멀지배열이 퀵배열보다 빠른 결과..?
  2022년 04월 09일 _ 프로젝트 재검토 및 일부수정
  2022년 04월 12일 _ 퀵정렬 수정 (강의자료코드 >> 임시저장소.cpp)
  2022년 04월 13일 _ 하이브리드정렬 수정 / 주석정리

*/


#include "BigArray_Algorithms.h"
#include "BigArray_Sortings.h"

#define SMALL_SIZE 100
void compare_sorting_algorithms_smallIntArray(); // siwtch 1번
void testBigRandArray(); // siwtch 2번
void PM_Hybrid_QS_SS_IntArray(); // siwtch 3번



// main 함수
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



// [ switch 1번 ] ( 퀵 vs 합병 vs 선택 _ 정렬시간비교) 
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



//  [ switch 2번 ] ( 정렬 전&후 비교) _ 하이브리드정렬로 설정해둠. 
void testBigRandArray()
{
	int* bigArray;
	int size, offset;
	while (1)
	{
		printf("Input bigRandArray_size (0 to quit) and offset : ");
		scanf_s("%d %d", &size, &offset); // 배열크기 + offset 입력값 받기.
		if (size == 0) // 입력값이 없을경우 break;
		{
			break;
		}


		bigArray = (int*)calloc(size, sizeof(int)); // 동적메모리할당.
		if (bigArray == NULL)
		{
			printf("Error in memory allocation");
			exit(1);
		}


		genBigRandArray(bigArray, size, offset); // 중복되지않는 난수배열 생성.


		printf("Generated non-duplicated random array : \n");
		printBigArraySample(bigArray, size, 10, 2); // 정렬되지않은 배열 출력
		printf("\n\nSorted array : \n");
		hybridQuickSelectionSort(bigArray, size); // 하이브리드정렬
		printBigArraySample(bigArray, size, 10, 2); // 정렬된 배열 출력
	
		
		free(bigArray); // 동적메모리반환
	}
}


//  [ switch 3번 ] ( 퀵정렬 vs 하이브리드정렬)
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


	for (size = 100000; size <= 500000; size += 100000) // ( 10만 20만 30만 40만 50만 )
	{

		// 퀵정렬
		array = (int*)calloc(size, sizeof(int)); // 동적메모리할당
		if (array == NULL)
		{
			printf("Error in memory allocation!");
			exit(1);
		}

		genBigRandArray(array, size, base); // 중복되지않는 난수배열 생성.

		QueryPerformanceCounter(&t1); // 시간측정_시작
		quickSort(array, size); // 퀵정렬
		QueryPerformanceCounter(&t2); // 시간측정_종료

		t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // 시간값계산
		elapsed_QS = elapsed_time; // 퀵정렬 _ 시간측정값 저장.
		free(array); //동적메모리반환



		// 하이브리드정렬
		array = (int*)calloc(size, sizeof(int)); // 동적메모리할당
		if (array == NULL)
		{
			printf("Error in memory allocation!");
			exit(1);
		}

		genBigRandArray(array, size, base); // 중복되지않는 난수배열 생성.

		QueryPerformanceCounter(&t1); // 시간측정_시작
		hybridQuickSelectionSort(array, size); // 하이브리드정렬
		QueryPerformanceCounter(&t2); // 시간측정_종료

		t_diff = t2.QuadPart - t1.QuadPart; // 시간차이 = 시간측정_종료 - 시간측정_시작
		elapsed_time = ((double)t_diff / (double)freq.QuadPart) * 1000; // 시간값계산
		elapsed_HYBRID = elapsed_time; // 퀵정렬 _ 시간측정값 저장.
		free(array); //동적메모리반환
		
		

		// 출력
		printf("%10d %15.2lf %15.2lf\n", size, elapsed_QS, elapsed_HYBRID);
	}
	printf("-----------------------------------------------------------------\n");
}