#include "Algorithms.h"



// 중복되지않는 난수 생성기. + offset
void genBigRandArray(int* bigRandArray, int size, int offset)
{
	char* flag;
	unsigned int uint32;
	unsigned int bigRand;
	int count = 0;

	flag = (char*)calloc(size, sizeof(char));
	// flag 동적메모리(배열) 받기
	// main 함수에서 [for문을 활용하여 출력한 사이즈]만큼 (char)flag 동적메모리 생성.

	srand((unsigned)time(0));
	while (count < size) // 처음부터 정해진 사이즈까지 하나씩 검사. (중복된것이 있는지) 
	{
		uint32 = ((long)rand() << 15) | (long)rand(); // 15비트 단위의 (long)rand() 난수를 받고, 좌로 15비트 이동 후, (long)rand() 함수 한번 더 받아 연결. _ 더 큰 값을 위해.  
		bigRand = uint32 % size; // unsigned int 에 담기기 너무 큰 uint32 이므로 %size 를 하여, 값을 축소하여 중복된 것이 있는지 비교 진행.

		if (flag[bigRand] == 1) // 만약 해당 flag[bigRand]에 값이 존재하면, 반복문 계속 진행으로 이동.
		{
			continue;
		}
		else // 만약 해당 flag[bigRand]에 값이 존재하지 않으면,
		{
			flag[bigRand] = 1; // 1이 존재한다로 만들어주고,
			bigRandArray[count++] = bigRand; // 이제 기존 array[] 배열에 bigRand 함수 대입.
		}
	}
	free(flag); // 동적배열은 항상 사용 후, 초기화 시켜준다.
}

// 큰 배열 출력 _ 실행창
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




// 셔플함수 _ 셔플함수를 각 측정마다 넣을 경우, 측정비교가 무의미해지므로 자체적으로 생략함.
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
