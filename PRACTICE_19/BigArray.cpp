#include "BigArray.h"

// 랜덤 숫자 생성기 _ 동적사용
void getBigRandArray(int* array, int bigRandSize) //아주 거대한 랜덤 숫자 생성기
{
	char* flag;
	unsigned int uint32;
	unsigned int bigRand;
	int count = 0;

	flag = (char*)calloc(bigRandSize, sizeof(char));
	// flag 동적메모리(배열) 받기
	// main 함수에서 [for문을 활용하여 출력한 사이즈]만큼 (char)flag 동적메모리 생성.

	while (count < bigRandSize) // 처음부터 정해진 사이즈까지 하나씩 검사. (중복된것이 있는지) 
	{
		uint32 = ((long)rand() << 15) | (long)rand(); // 15비트 단위의 (long)rand() 난수를 받고, 좌로 15비트 이동 후, (long)rand() 함수 한번 더 받아 연결. _ 더 큰 값을 위해.  
		bigRand = uint32 % bigRandSize; // unsigned int 에 담기기 너무 큰 uint32 이므로 %size 를 하여, 값을 축소하여 중복된 것이 있는지 비교 진행.

		if (flag[bigRand] == 1) // 만약 해당 flag[bigRand]에 값이 존재하면, 반복문 계속 진행으로 이동.
		{
			continue;
		}
		else // 만약 해당 flag[bigRand]에 값이 존재하지 않으면,
		{
			flag[bigRand] = 1; // 1이 존재한다로 만들어주고,
			array[count++] = bigRand; // 이제 기존 array[] 배열에 bigRand 함수 대입.
		}
	}
}


// (실행창) 큰 배열 출력
void printBigArraySample(int* array, int size, int line_size)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array++) // 앞에서부터 하나씩 출력 _ ( 30개 출력 )
		{
			printf("%8d", *array);
		}
		printf("\n");
	}
	printf("    .  .  .  .  .  . \n\n");  // 출력해야 할 수가 너무 많아서 중간 부분 생략.

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array--) // 뒤에서부터 하나씩 출력 _ ( 30개 출력 )
		{
			printf("%8d", *(array + size - 31));
		}
		printf("\n");
	}
}

// (파일) 큰 배열 출력
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_line)
{
	int count = 1;
	for (int i = 0; i < num_line; i++)
	{
		for (int j = 0; j < line_size; j++, array++) // 앞에서부터 하나씩 출력 _ ( 30개 출력 )
		{
			fprintf(fout, "%8d", *array);
			count++;
		}
		fprintf(fout, "\n");
	}
	fprintf(fout, "    .  .  .  .  .  . \n"); // 출력해야 할 수가 너무 많아서 중간 부분 생략.

	for (int i = 0; i < num_line; i++)
	{
		for (int j = 0; j < line_size; j++, array--) // 뒤에서부터 하나씩 출력 _ ( 30개 출력 )
		{
			fprintf(fout, "%8d", *(array + size - count));
		}
		fprintf(fout, "\n");
	}
}

