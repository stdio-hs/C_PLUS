// ���ü��� SWAP�� ���ο� �ִ� �ڵ�
/*
void selectionSort(int* array, int size) // ��������
{
	int index_min;
	int storage;

	for (int a = 0; a < size - 1; a++) // array[0] ���� array[size-1] ���� �ϳ��ϳ� �� + ����.
	{
		index_min = a; // ���������� ���������� �� ��, ���� ������ �κ��� ��ŷ�س��´�.

		for (int b = a + 1; b < size; b++) // < ��ŷ�� �� ���� ��.> ~ < size(������) > �ϳ��ϳ� ���Ѵ�. 
		{
			if (array[b] < array[index_min]) // ������ ��, ( array[�񱳴��] < array[��ŷ�� ��] ) �� ���
			{
				index_min = b; // �ش� �񱳴��(b)�� ��ŷindex_min���� �ٲپ��ش�. (���� ��ŷ �Ҹ�) 
				storage = array[b]; // ����ҿ��� array[index_min or b] ���� �־��ش�. 
			}
		}

		if (index_min != a) // ( = ���縶ŷ�� ��ŷ�� �ٸ���. ) ��. �ٷ� �� for �ݺ������� �񱳴���� index_min �� �޾��� ���. 
		{
			storage = array[a]; // ����ҿ��� array[���� ��ŷ ��] �� ����ش�. 
			array[a] = array[index_min]; // array[���� ��ŷ ��] ���� array[���ο� ��ŷ ��] �� ����ش�.
			array[index_min] = storage; // array[���ο� ��ŷ ��] �� �Ʊ� ����ҿ� �־�� ���� �־��ش�.
		}
	}
}
*/



// �պ����� �����ڷ� ���� �ڵ�
/*

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
*/



// ������ �����ڷ� ���� �ڵ� _ for��
/*
void quickSort(int* array, int size)
{
	_quickSort(array, size, 0, size - 1);
}

void _quickSort(int* array, int size, int left, int right)
{
	int pI, newPI; // �Ǻ� �ε���, �Ǻ� �ε���_2
	if (left >= right) // �� ������ �� �������� ũ�ų� ������ ��� �Լ��� ���Ͻ�Ų��.
	{
		return;
	}
	else if (left < right)
	{
		pI = (left + right) / 2; // �Ǻ� �ε����� �߾� ������ �����Ѵ�.
	}

	newPI = _partition(array, size, left, right, pI); // �Ǻ��ε��� ���� _partition�� �־��־� �Ǻ��ε���_2�� �޾Ƴ���.
	if (left < (newPI - 1)) // �Ǻ��ε���_2�� �� ������ �ƴ� ���,
	{
		_quickSort(array, size, left, newPI - 1); // �Ǻ��ε���_2�� �ѻ����� ���̰�, �� �������� �̵���Ű�� �ٽ� �����Ѵ�. _ ����Լ�
	}
	if ((newPI + 1) < right) // �Ǻ��ε���_2�� �� ������ �ƴ� ���,
	{
		_quickSort(array, size, newPI + 1, right); // �Ǻ��ε���_2�� �ѻ����� �ø���, �� �������� �̵���Ű�� �ٽ� �����Ѵ�. _ ����Լ�
	}
}

int _partition(int* array, int size, int left, int right, int pivotIndex)
{
	int pivotValue; // �Ǻ���
	int newPI; // �Ǻ���_2
	int temp, i;
	pivotValue = array[pivotIndex]; // �Ǻ����� ������ �迭�� pivotValue �� �����Ѵ�.

	array[pivotIndex] = array[right]; // �迭 �� ������ �ִ� ���� �Ǻ����� �����Ѵ�.
	array[right] = pivotValue; // ó���� �Ǻ����� ������ �迭 (����� pivotValue)�� ����ִ� �� �� �迭 �� ������ �ִ� ���� �־��ش�.
	// �� ������ SWAP ����.

	newPI = left; // �Ǻ���_2�� �ش� �迭���� �� ���� ��.
	for (i = left; i <= right - 1; i++) // i�� �ش� �迭���� ���� ���ʿ������� �ϳ��� �ö󰡸� �ݺ���
	{
		if (array[i] <= pivotValue) // Ž���ϰ��� �ϴ� ���� �ǹ����� �۰ų� �������
		{
			temp = array[i];
			array[i] = array[newPI];
			array[newPI] = temp; // SWAP�� ���Ͽ� �Ǻ���_2�� Ž���ϴ°��� ���� �־��ش�.
			newPI = newPI + 1; // SWAP ������ ������ ���ο� �ǹ��� ���� ++ ���ش�.
		}
	}

	pivotValue = array[right];
	array[right] = array[newPI];
	array[newPI] = pivotValue;

	return newPI;
}
*/



// ���̺긮������ (��������+������) _ ��Ƽ���� ���ο� �ִ��ڵ�
/*

void _hybridQuickSelectionSort(int* bigArray, int size, int left, int right)
{
	int pI, newPI; // �Ǻ��ε���_1 �Ǻ��ε���_2
	int part = right - left; // ���� �迭 ������ ũ�⸦ ��Ÿ����.



	if (part < QUICK_SELECTION_THRESHOLD)
	{
		hy_selectionSort(bigArray, part, left, right + 1); // ��������
		return;
	}



	// �����ı��� ����
	if (left >= right) // �� �������� �� ���������� ũ�ų� ������ ����Լ��� ���Ͻ�Ų��.
	{
		return;
	}
	else if (left < right) // �� �������� �� ���������� �������.
	{
		pI = (left + right) / 2; // �Ǻ��ε���_1 �� �迭�� �߾Ӱ����� �����Ѵ�.
	}
	newPI = _partition(bigArray, left, right); // ������




	if (left < (newPI - 1)) // �Ǻ��ε���_2�� �� ������ �ƴ� ���.
	{
		_hybridQuickSelectionSort(bigArray, size, left, newPI - 1); // �Ǻ��ε���_2�� �ѻ����� ���̰�, �� �������� �̵���Ű�� �ٽ� �����Ѵ�. _ ����Լ�
	}
	if ((newPI + 1) < right) // �Ǻ��ε���_2�� �� ������ �ƴ� ���,
	{
		_hybridQuickSelectionSort(bigArray, size, newPI + 1, right); // �Ǻ��ε���_2�� �ѻ����� �ø���, �� �������� �̵���Ű�� �ٽ� �����Ѵ�. _ ����Լ�
	}
}

*/

