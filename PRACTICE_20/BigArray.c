#include "BigArray.h"

// (실행창) 계산값 출력
void getArrayStatistics(int* data_array, int num_data)
{
	int data;
	int min = 0, max = 0;
	double sum = 0.0, avg = 0.0, var = 0.0, std = 0.0;
	double diff, diff_sum = 0.0;


	for (int i = 0; i < num_data; i++)
	{
		data = data_array[i];

		if (i == 0) // ( 기준값을 위해 ) num_data[0]을 최대 최소 비교기준값으로 설정.
		{
			min = max = data_array[0];
		}
		else {
			if (data < min)
				min = data; // 최소값
			if (data > max)
				max = data; // 최대값
		}
		sum += data; // 합
	}

	avg = sum / (double)num_data; // 평균

	for (int i = 0; i < num_data; i++) // 분산 _ 1
	{
		diff = data_array[i] - avg;
		diff_sum += diff * diff;
	}
	var = diff_sum / (double)num_data; //분산 _ 2
	std = sqrt(var); // 표준편차

	// 실행창 출력
	if (num_data < 50000) // 배열 사이즈가 작을 경우.
	{
		printf("Total ( %d ) integer data : \n", num_data);
		printArray(data_array, num_data, 10);
		printf("min : ( %d ) / max : ( %d ) / ", min, max);
		printf("sum : ( %.2lf ) / average : ( %.2lf ) / ", sum, avg);
		printf("variance : ( %.2lf ) / standard deviation : ( %.2lf\n )", var, std);
	}
	else if (num_data >= 50000) // 배열 사이즈가 클 경우. ( 중간 부분 생략함. )
	{
		printf("Total ( %3d ) integer data : \n", num_data);
		printBigArraySample(data_array, num_data, LINE_SIZE, NUM_LINE);
		printf("min ( %3d ) / max( %3d ) / sum( %8.2lf ) / average ( %8.2lf ) / ", min, max, sum, avg);
		printf("variance ( %8.2lf ) / standard deviation ( %8.2lf ) \n", var, std);
	}
}
// (파일) 계산값 출력
void fgetArrayStatistics(FILE* fout, int* data_array, int num_data)
{

	int data;
	int min = 0, max = 0;
	double sum = 0.0, avg = 0.0, var = 0.0, std = 0.0;
	double diff, diff_sum = 0.0;


	for (int i = 0; i < num_data; i++)
	{
		data = data_array[i];

		if (i == 0) // ( 기준값을 위해 ) num_data[0]을 최대 최소 비교기준값으로 설정.
		{
			min = max = data_array[0];
		}
		else {
			if (data < min)
				min = data; // 최소값
			if (data > max)
				max = data; // 최대값
		}
		sum += data; // 합
	}

	avg = sum / (double)num_data; // 평균


	for (int i = 0; i < num_data; i++) // 분산 _ 1
	{
		diff = data_array[i] - avg;
		diff_sum += diff * diff;
	}
	var = diff_sum / (double)num_data; // 분산 _ 2
	std = sqrt(var); // 표준편차

	// 메모장 출력
	if (num_data < 50000) // 배열 사이즈가 작을 경우.
	{
		fprintf(fout, "Total ( %d ) integer data : \n", num_data);
		fprintArray(fout, data_array, num_data, 10);
		fprintf(fout, "min : ( %d ) / max : ( %d ) / ", min, max);
		fprintf(fout, "sum : ( %.2lf ) / average : ( %.2lf ) / ", sum, avg);
		fprintf(fout, "variance : ( %.2lf ) / standard deviation : ( %.2lf\n )", var, std);
	}

	else if (num_data >= 50000) // 배열 사이즈가 클 경우. ( 중간 부분 생략함. )
	{
		fprintf(fout, "Total ( %3d ) integer data : \n", num_data);
		fprintBigArraySample(fout, data_array, num_data, LINE_SIZE, NUM_LINE);
		fprintf(fout, "min ( %3d ) / max( %3d ) / sum( %8.2lf ) / average ( %8.2lf ) / ", min, max, sum, avg);
		fprintf(fout, "variance ( %8.2lf ) / standard deviation ( %8.2lf ) \n", var, std);
	}
}


// (실행창) 배열 출력
void printArray(int* array, int size, int line_size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%5d", array[i]);
		if ((i + 1) % line_size == 0) // line_size만큼 출력되면 줄바꿈
		{
			printf("\n");
		}
	}
	printf("\n");
}
// (파일) 배열 출력
void fprintArray(FILE* fout, int* array, int size, int line_size)
{
	for (int i = 0; i < size; i++)
	{
		fprintf(fout, "%5d", array[i]);
		if ((i + 1) % line_size == 0)  // line_size만큼 출력되면 줄바꿈
		{
			fprintf(fout, "\n");
		}
	}
}


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

	srand((unsigned)time(0));
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
void printBigArraySample(int* array, int size, int line_size, int num_size)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array++)
		{
			printf("%8d", *array);
		}
		printf("\n");
	}
	printf("    .  .  .  .  .  . \n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < line_size; j++, array--)
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
	for (int i = 0; i < line_size; i++)
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

