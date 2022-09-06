/*

파일명 : PRACTICE_20

프로그램의 목적 및 기본기능 : 다양한 배열 연습 _ 동적메모리

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 3월 29일 ~ 2022년 3월 01일

*/

#include "BigArray.h"

void arrayStatistics_basicArray(FILE* fout); // 함수 내 선언한 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_externArray(FILE* fout); // BigArray.h 인 외부 소스파일 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_fileDataArray(FILE* fout); // Data_Input.txt 에 담겨져 있는 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_inputArray(FILE* fout); // 입력장치(키보드)로 입력한 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_genBigRandArray(FILE* fout); // 중복되지 않는 난수 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산


void main()
{
	int menu = 0;

	FILE* fout = NULL; // FILE 포인터 fout를 생성하고 NULL로 초기화
	fout = fopen(Data_Output_File, "w"); //파일을 쓰기모드로 열고, 주소를 fout에 저장

	if (fout == NULL) // 파일을 열지 못할 경우, ( 에러 + 실행종료 )
	{
		printf("Error in creation of Data_Output_File");
	}

	while (1)
	{
		printf("\n\n");
		printf(" \n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
		printf("\n\n << Test Array Handling >> \n");
		printf(" ( 1 : data_array / 2 : extern_array / 3 : data_file / 4 : data_input / 5 : gen_BigRandArray / Esc : terminate ) : ");
		menu = _getche(); // getche() = ( 입력값 >> 화면출력 + 버퍼X )

		if (menu == ESC) // ESC 사용시 종료.
			break;

		switch (menu) // switch 문을 활용하여, 함수 출력.
		{
		case '1':
			arrayStatistics_basicArray(fout); // 함수 내 선언한 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
			break;

		case '2':
			arrayStatistics_externArray(fout); // BigArray.h 인 외부 소스파일 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
			break;

		case '3':
			arrayStatistics_fileDataArray(fout); // Data_Output_File.txt 내 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
			break;

		case '4':
			arrayStatistics_inputArray(fout); // 입력장치(키보드)로 입력한 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
			break;

		case '5':
			arrayStatistics_genBigRandArray(fout); // 중복되지 않는 난수 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
			break;

		default:
			break;
		}
	}

	// ???????????????? 이 부분 질문!!!! ??????????????????
	 
		fclose(fout);
}


// 함수 내 선언한 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_basicArray(FILE* fout)
{
	int num_data = 10;
	int data_array[MAX_SIZE] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }; // 함수 내 선언한 배열

	printf("\n\n     ArrayStatistics_basicArray ............... \n\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_basicArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	// 여기까지는 실행창 출력

	fprintf(fout, "\n ArrayStatistics_basicArray ...............\n");
	fgetArrayStatistics(fout, data_array, num_data);
	// 여기까지는 메모장 출력

}

// BigArray.h 인 외부 소스파일 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_externArray(FILE* fout)
{
	int num_data = 0; // 외부 소스파일에 사이즈를 알 수 없기에, 일단 0으로 설정 후 사이즈 측정.
	extern int data_array[MAX_SIZE]; // 외부 소스파일 Data_array 가져오기.

	for (int i = 0; ; i++)
	{
		if (data_array[i] == -1) // -1일 경우, for문 탈출
			break;
		else
			num_data++; // 카운트 ( 이유 : 배열 크기를 알기 위해. )
	}

	printf("\n\n     ArrayStatistics_externArray ............... \n\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_basicArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	// 여기까지 실행창 출력

	fprintf(fout, "\n ArrayStatistics_externArray ............... \n");
	fgetArrayStatistics(fout, data_array, num_data);
	// 여기까지 메모장 출력
}

// Data_Input.txt 에 담겨져 있는 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_fileDataArray(FILE* fout)
{
	int data; // .txt 에서 가져온 배열(한개씩) 임시 저장소
	int num_data = 0; // 배열 사이즈 
	int data_array[MAX_SIZE] = { 0 }; // .txt 에서 가져온 배열 메인저장소

	FILE* fin; // Data_Input.txt 파일 포인터 선언

	fin = fopen(Data_Input_File, "r"); // Data_Input.txt 파일 열어서 읽기모드
	if (fin == NULL) // 열리지 않을경우.
	{
		printf("Error in opening input data file !!\n");
		return;
	}

	while (fscanf_s(fin, "%d", &data) != EOF)
		// << 응용공부 >>
		// 열릴경우, 하나의 상수씩 가져오기 (공백전까지 인식)
		// EOF(End Of File) >> 내용이 없을 경우. -1 출력
	{
		if (data == -1)
		{
			break;
		}

		data_array[num_data] = data; // .txt 에서 하나씩 가져온 상수들 data_array[] 배열에 넣기.
		num_data++;
	}
	fclose(fin); // 파일을 열어주었으면, 닫기.

	printf("\n\n     ArrayStatistics_fileDataArray ............... \n\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_fileDataArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
	// 여끼까지 실행창 출력

	fprintf(fout, "\nArrayStatistics_fileDataArray ............... \n");
	fgetArrayStatistics(fout, data_array, num_data);
	// 여기까지 메모장 출력
}

// 입력장치(키보드)로 입력한 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_inputArray(FILE* fout)
{
	int num_data, data;
	int data_array[100] = { 0 };

	printf("\n\n     ArrayStatistics_inputArray  ...............  \n\n");
	printf("Please input the number of integers (less than %d) = ", MAX_SIZE); // MAX_SIZE = 100
	scanf_s("%d", &num_data); // 배열 크기를 사용자로부터 입력받기.
	printf("Input %d  integer data : ", num_data);

	for (int i = 0; i < num_data; i++) // 입력값을 하나씩 data_array[] 배열에 담기.
	{
		scanf_s("%d", &data);
		data_array[i] = data;
	}

	printf("\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_inputArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
	// 여기까지 실행창 출력

	fprintf(fout, "\nArrayStatistics_inputArray  ...............  \n");
	fgetArrayStatistics(fout, data_array, num_data);
	// 여기까지 메모장 출력

}

// 중복되지 않는 난수 배열 + ( 최소, 최대, 합, 평균, 분산, 표준편차 ) 계산
void arrayStatistics_genBigRandArray(FILE* fout)
{
	int num_data;
	int* dyn_array = NULL;

	printf("\nArrayStatistics_genBigRandArray  ...............  \n");
	printf("Big Array Size (more than 50000) = ");
	scanf_s("%d", &num_data); // ( 50000 이상 ) 배열 사이즈 사용자로부터 입력 받기.
	printf("Creating big random integer array (size : %d)\n", num_data);

	dyn_array = (int*)calloc(num_data, sizeof(int)); // 동적메모리 (배열) 받기. _ 씨얼록(갯수, 사이즈)
	if (dyn_array == NULL) // 메모리를 할당 받지 못할 경우.
	{
		printf("Error in dynamic creation of big_array (size = %d) !!!", num_data);
		exit(-1); // 종료
	}

	getBigRandArray(dyn_array, num_data);
	getArrayStatistics(dyn_array, num_data);
	printf("\narrayStatistics_genBigRandArray - completed. Result is also stored in output file(% s).\n", Data_Output_File);
	// 여기까지 실행창 출력

	fprintf(fout, "\nArrayStatistics_genBigRandArray  ...............  \n");
	fgetArrayStatistics(fout, dyn_array, num_data);
	// 여기까지 메모장 출력

	free(dyn_array); // 동적 메모리 반환
}
