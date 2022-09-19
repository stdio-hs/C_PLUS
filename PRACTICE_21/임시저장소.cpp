// 선택솔팅 SWAP가 내부에 있는 코드
/*
void selectionSort(int* array, int size) // 선택정렬
{
	int index_min;
	int storage;

	for (int a = 0; a < size - 1; a++) // array[0] 부터 array[size-1] 까지 하나하나 비교 + 대입.
	{
		index_min = a; // 순차적으로 선택정렬을 할 때, 가장 왼쪽인 부분을 마킹해놓는다.

		for (int b = a + 1; b < size; b++) // < 마킹한 곳 다음 것.> ~ < size(끝까지) > 하나하나 비교한다. 
		{
			if (array[b] < array[index_min]) // 비교했을 때, ( array[비교대상] < array[마킹한 곳] ) 일 경우
			{
				index_min = b; // 해당 비교대상(b)을 마킹index_min으로 바꾸어준다. (기존 마킹 소멸) 
				storage = array[b]; // 저장소에는 array[index_min or b] 값을 넣어준다. 
			}
		}

		if (index_min != a) // ( = 현재마킹과 마킹이 다르다. ) 즉. 바로 위 for 반복문에서 비교대상이 index_min 을 받았을 경우. 
		{
			storage = array[a]; // 저장소에는 array[기존 마킹 값] 을 담아준다. 
			array[a] = array[index_min]; // array[기존 마킹 값] 에는 array[새로운 마킹 값] 을 담아준다.
			array[index_min] = storage; // array[새로운 마킹 값] 에 아까 저장소에 넣어둔 값을 넣어준다.
		}
	}
}
*/



// 합병솔팅 강의자료 참고 코드
/*

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
*/



// 퀵솔팅 강의자료 참고 코드 _ for문
/*
void quickSort(int* array, int size)
{
	_quickSort(array, size, 0, size - 1);
}

void _quickSort(int* array, int size, int left, int right)
{
	int pI, newPI; // 피봇 인덱스, 피봇 인덱스_2
	if (left >= right) // 맨 좌측이 맨 우측보다 크거나 같으면 재귀 함수를 리턴시킨다.
	{
		return;
	}
	else if (left < right)
	{
		pI = (left + right) / 2; // 피봇 인덱스는 중앙 값으로 설정한다.
	}

	newPI = _partition(array, size, left, right, pI); // 피봇인덱스 값을 _partition에 넣어주어 피봇인덱스_2로 받아낸다.
	if (left < (newPI - 1)) // 피봇인덱스_2가 맨 좌측이 아닐 경우,
	{
		_quickSort(array, size, left, newPI - 1); // 피봇인덱스_2를 한사이즈 줄이고, 맨 우측으로 이동시키고 다시 정렬한다. _ 재귀함수
	}
	if ((newPI + 1) < right) // 피봇인덱스_2가 맨 우측이 아닐 경우,
	{
		_quickSort(array, size, newPI + 1, right); // 피봇인덱스_2를 한사이즈 올리고, 맨 좌측으로 이동시키고 다시 정렬한다. _ 재귀함수
	}
}

int _partition(int* array, int size, int left, int right, int pivotIndex)
{
	int pivotValue; // 피봇값
	int newPI; // 피봇값_2
	int temp, i;
	pivotValue = array[pivotIndex]; // 피봇으로 지정된 배열을 pivotValue 에 대입한다.

	array[pivotIndex] = array[right]; // 배열 맨 우측에 있는 값을 피봇으로 지정한다.
	array[right] = pivotValue; // 처음에 피봇으로 지정된 배열 (현재는 pivotValue)에 담겨있는 값 을 배열 맨 우측에 있는 값에 넣어준다.
	// 이 과정은 SWAP 과정.

	newPI = left; // 피봇값_2는 해당 배열에서 맨 왼쪽 값.
	for (i = left; i <= right - 1; i++) // i는 해당 배열에서 가장 왼쪽에서부터 하나씩 올라가며 반복문
	{
		if (array[i] <= pivotValue) // 탐색하고자 하는 값이 피벗보다 작거나 같을경우
		{
			temp = array[i];
			array[i] = array[newPI];
			array[newPI] = temp; // SWAP을 통하여 피봇값_2에 탐색하는곳의 값을 넣어준다.
			newPI = newPI + 1; // SWAP 과정이 끝나면 새로운 피벗의 값을 ++ 해준다.
		}
	}

	pivotValue = array[right];
	array[right] = array[newPI];
	array[newPI] = pivotValue;

	return newPI;
}
*/



// 하이브리드정렬 (선택정렬+퀵정렬) _ 파티션이 내부에 있는코드
/*

void _hybridQuickSelectionSort(int* bigArray, int size, int left, int right)
{
	int pI, newPI; // 피봇인덱스_1 피봇인덱스_2
	int part = right - left; // 현재 배열 사이즈 크기를 나타낸다.



	if (part < QUICK_SELECTION_THRESHOLD)
	{
		hy_selectionSort(bigArray, part, left, right + 1); // 선택정렬
		return;
	}



	// 퀵정렬구간 시작
	if (left >= right) // 맨 좌측값이 맨 우측값보다 크거나 같으면 재귀함수를 리턴시킨다.
	{
		return;
	}
	else if (left < right) // 맨 좌측값이 맨 우측값보다 작을경우.
	{
		pI = (left + right) / 2; // 피봇인덱스_1 를 배열의 중앙값으로 설정한다.
	}
	newPI = _partition(bigArray, left, right); // 퀵정렬




	if (left < (newPI - 1)) // 피봇인덱스_2가 맨 좌측이 아닐 경우.
	{
		_hybridQuickSelectionSort(bigArray, size, left, newPI - 1); // 피봇인덱스_2를 한사이즈 줄이고, 맨 우측으로 이동시키고 다시 정렬한다. _ 재귀함수
	}
	if ((newPI + 1) < right) // 피봇인덱스_2가 맨 우측이 아닐 경우,
	{
		_hybridQuickSelectionSort(bigArray, size, newPI + 1, right); // 피봇인덱스_2를 한사이즈 올리고, 맨 좌측으로 이동시키고 다시 정렬한다. _ 재귀함수
	}
}

*/

