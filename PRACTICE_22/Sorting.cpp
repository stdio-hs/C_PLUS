#include "Sorting.h"


// SWAP 함수 _ 코드를 간결하게 하기 위해, SWAP 부분은 함수 출력
void Swap(int arr[], int a, int b)
{
	int temp = arr[a]; // 저장소에는 array[기존 마킹 값] 을 담아준다.
	arr[a] = arr[b]; // array[기존 마킹 값] 에는 array[새로운 마킹 값] 을 담아준다.
	arr[b] = temp; // array[새로운 마킹 값] 에 아까 저장소에 넣어둔 값을 넣어준다.
}


// 셀렉솔팅 (선택정렬)
void selectionSort(int* array, int size) // 선택정렬
{
	int index_min;


	for (int a = 0; a < size - 1; a++) // array[0] 부터 array[size-1] 까지 하나하나 비교 + 대입.
	{
		index_min = a; // 순차적으로 선택정렬을 할 때, 가장 왼쪽인 부분을 마킹해놓는다.

		for (int b = a + 1; b < size; b++) // < 마킹한 곳 다음 것.> ~ < size(끝까지) > 하나하나 비교한다. 
		{
			if (array[b] < array[index_min]) // 비교했을 때, ( array[비교대상] < array[마킹한 곳] ) 일 경우
			{
				index_min = b; // 해당 비교대상(b)을 마킹index_min으로 바꾸어준다. (기존 마킹 소멸)  
			}
		}

		if (index_min != a) // ( = 현재마킹과 마킹이 다르다. ) 즉. 바로 위 for 반복문에서 비교대상이 index_min 을 받았을 경우. 
		{
			Swap(array, a, index_min);
		}
	}
}


// 머지솔팅 (합병정렬)
void mergeSort(int* array, int size)
{
	// 머지솔팅은 퀵솔팅(재귀함수호출)과 다르게 임시 배열 저장소에서 가져오는 식으로 한다.
	// 따라서 tmp_array 라는 임시 배열 저장소를 동적메모리할당하여 가져온다.
	int* tmp_array; // 배열을 판별하기 위한 임시 배열 저장소.
	tmp_array = (int*)calloc(size, sizeof(int)); // 동적메모리할당
	if (tmp_array == NULL)
	{
		printf("Error in creation of tmp_array (size = %d) int mergerSort()!\n", size);
		exit(1);
	} // 동적메모리 할당 받지 못한 경우.

	_mergeSort(array, tmp_array, 0, size - 1);
	// 임시저장소 만들고 병합정렬 하러 가기.

	free(tmp_array); // 동적메모리 사용 끝나면 항상 반납하기.
}
void _mergeSort(int* array, int* tmp_array, int left, int right)
{
	if (left >= right)
		return;
	// 재귀함수를 계속 받으며 반복시키다가 비교할 배열이 두개만 남았을 경우.
	// ex) array[0] >= array[1] >> (재귀함수)array[0] >= array[0] >> [0 >= 0] >> 조건식 충족하게 된다면,
	// 충족하기 전단계 값으로 리턴하여 다음()으로 넘어감.

	int i, j, k;
	int mid = (left + right) / 2;

	_mergeSort(array, tmp_array, left, mid); // 배열을 반으로 쪼개서 왼쪽배열
	_mergeSort(array, tmp_array, mid + 1, right); // 배열을 반으로 쪼개서 오른쪽배열

	for (i = mid; i >= left; i--)
	{
		tmp_array[i] = array[i];
	}

	for (j = 1; j <= right - mid; j++)
	{
		tmp_array[right - j + 1] = array[j + mid];
	}

	for (i = left, j = right, k = left; k <= right; k++) // 합치기
	{
		if (tmp_array[i] < tmp_array[j])
			array[k] = tmp_array[i++];
		else
			array[k] = tmp_array[j--];
	}
}


// 퀵솔팅 _ 강의자료코드가 아닌 자체적 코드.
void quickSort(int* array, int size)  // 동적메모리 할당 받은 사이즈로 처음과 끝 구하는 함수.
{
	_quickSort(array, 0, size - 1);
}
void _quickSort(int* array, int left, int right)
{
	if (left <= right) // 좌측 끝값 <= 우측 끝값 일 경우.
	{
		int pivot = _partition(array, left, right); // _partition 함수를 호출시킨다. 

		if (left < (pivot - 1)) // 피봇이 좌측 끝이 아닐 경우.
		{
			_quickSort(array, left, pivot - 1); // 하나를 줄이고 우측 끝으로 보낸 후, 재정렬시킨다.
		}

		if ((pivot + 1) < right) // 피봇이 우측 끝이 아닐 경우.
		{
			_quickSort(array, pivot + 1, right); // 하나를 더하고 좌측 끝으로 보낸 후, 재정렬시킨다.
		}
	}
}
int _partition(int* array, int left, int right)
{
	int pivot = array[left]; // 피봇의 위치는 좌측 끝으로 설정한다.
	int low = left + 1; // 좌측 끝 + 1 = 피봇 바로 우측에 있는 수
	int high = right; // 우측 끝


	while (low <= high)
	{
		while (low <= right && pivot >= array[low]) // 피봇보다 큰 값을 찾는 과정 
		{
			low++; // low를 오른쪽으로 이동 
		}
		while (high >= (left + 1) && pivot <= array[high]) // 피봇보다 작은 값을 찾는 과정 
		{
			high--; // high를 왼쪽으로 이동
		}


		if (low <= high) // low와 high가 교차가 되지 않았을 경우.
		{
			Swap(array, low, high); // SWAP 실행
		}
	}
	Swap(array, left, high); // 피봇과 high을 SWAP 실행

	return high;  // 옮겨진 high 값 리턴 
}