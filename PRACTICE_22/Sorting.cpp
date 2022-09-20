#include "Sorting.h"


// SWAP �Լ� _ �ڵ带 �����ϰ� �ϱ� ����, SWAP �κ��� �Լ� ���
void Swap(int arr[], int a, int b)
{
	int temp = arr[a]; // ����ҿ��� array[���� ��ŷ ��] �� ����ش�.
	arr[a] = arr[b]; // array[���� ��ŷ ��] ���� array[���ο� ��ŷ ��] �� ����ش�.
	arr[b] = temp; // array[���ο� ��ŷ ��] �� �Ʊ� ����ҿ� �־�� ���� �־��ش�.
}


// �������� (��������)
void selectionSort(int* array, int size) // ��������
{
	int index_min;


	for (int a = 0; a < size - 1; a++) // array[0] ���� array[size-1] ���� �ϳ��ϳ� �� + ����.
	{
		index_min = a; // ���������� ���������� �� ��, ���� ������ �κ��� ��ŷ�س��´�.

		for (int b = a + 1; b < size; b++) // < ��ŷ�� �� ���� ��.> ~ < size(������) > �ϳ��ϳ� ���Ѵ�. 
		{
			if (array[b] < array[index_min]) // ������ ��, ( array[�񱳴��] < array[��ŷ�� ��] ) �� ���
			{
				index_min = b; // �ش� �񱳴��(b)�� ��ŷindex_min���� �ٲپ��ش�. (���� ��ŷ �Ҹ�)  
			}
		}

		if (index_min != a) // ( = ���縶ŷ�� ��ŷ�� �ٸ���. ) ��. �ٷ� �� for �ݺ������� �񱳴���� index_min �� �޾��� ���. 
		{
			Swap(array, a, index_min);
		}
	}
}


// �������� (�պ�����)
void mergeSort(int* array, int size)
{
	// ���������� ������(����Լ�ȣ��)�� �ٸ��� �ӽ� �迭 ����ҿ��� �������� ������ �Ѵ�.
	// ���� tmp_array ��� �ӽ� �迭 ����Ҹ� �����޸��Ҵ��Ͽ� �����´�.
	int* tmp_array; // �迭�� �Ǻ��ϱ� ���� �ӽ� �迭 �����.
	tmp_array = (int*)calloc(size, sizeof(int)); // �����޸��Ҵ�
	if (tmp_array == NULL)
	{
		printf("Error in creation of tmp_array (size = %d) int mergerSort()!\n", size);
		exit(1);
	} // �����޸� �Ҵ� ���� ���� ���.

	_mergeSort(array, tmp_array, 0, size - 1);
	// �ӽ������ ����� �������� �Ϸ� ����.

	free(tmp_array); // �����޸� ��� ������ �׻� �ݳ��ϱ�.
}
void _mergeSort(int* array, int* tmp_array, int left, int right)
{
	if (left >= right)
		return;
	// ����Լ��� ��� ������ �ݺ���Ű�ٰ� ���� �迭�� �ΰ��� ������ ���.
	// ex) array[0] >= array[1] >> (����Լ�)array[0] >= array[0] >> [0 >= 0] >> ���ǽ� �����ϰ� �ȴٸ�,
	// �����ϱ� ���ܰ� ������ �����Ͽ� ����()���� �Ѿ.

	int i, j, k;
	int mid = (left + right) / 2;

	_mergeSort(array, tmp_array, left, mid); // �迭�� ������ �ɰ��� ���ʹ迭
	_mergeSort(array, tmp_array, mid + 1, right); // �迭�� ������ �ɰ��� �����ʹ迭

	for (i = mid; i >= left; i--)
	{
		tmp_array[i] = array[i];
	}

	for (j = 1; j <= right - mid; j++)
	{
		tmp_array[right - j + 1] = array[j + mid];
	}

	for (i = left, j = right, k = left; k <= right; k++) // ��ġ��
	{
		if (tmp_array[i] < tmp_array[j])
			array[k] = tmp_array[i++];
		else
			array[k] = tmp_array[j--];
	}
}


// ������ _ �����ڷ��ڵ尡 �ƴ� ��ü�� �ڵ�.
void quickSort(int* array, int size)  // �����޸� �Ҵ� ���� ������� ó���� �� ���ϴ� �Լ�.
{
	_quickSort(array, 0, size - 1);
}
void _quickSort(int* array, int left, int right)
{
	if (left <= right) // ���� ���� <= ���� ���� �� ���.
	{
		int pivot = _partition(array, left, right); // _partition �Լ��� ȣ���Ų��. 

		if (left < (pivot - 1)) // �Ǻ��� ���� ���� �ƴ� ���.
		{
			_quickSort(array, left, pivot - 1); // �ϳ��� ���̰� ���� ������ ���� ��, �����Ľ�Ų��.
		}

		if ((pivot + 1) < right) // �Ǻ��� ���� ���� �ƴ� ���.
		{
			_quickSort(array, pivot + 1, right); // �ϳ��� ���ϰ� ���� ������ ���� ��, �����Ľ�Ų��.
		}
	}
}
int _partition(int* array, int left, int right)
{
	int pivot = array[left]; // �Ǻ��� ��ġ�� ���� ������ �����Ѵ�.
	int low = left + 1; // ���� �� + 1 = �Ǻ� �ٷ� ������ �ִ� ��
	int high = right; // ���� ��


	while (low <= high)
	{
		while (low <= right && pivot >= array[low]) // �Ǻ����� ū ���� ã�� ���� 
		{
			low++; // low�� ���������� �̵� 
		}
		while (high >= (left + 1) && pivot <= array[high]) // �Ǻ����� ���� ���� ã�� ���� 
		{
			high--; // high�� �������� �̵�
		}


		if (low <= high) // low�� high�� ������ ���� �ʾ��� ���.
		{
			Swap(array, low, high); // SWAP ����
		}
	}
	Swap(array, left, high); // �Ǻ��� high�� SWAP ����

	return high;  // �Ű��� high �� ���� 
}