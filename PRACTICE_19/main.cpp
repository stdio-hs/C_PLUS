/*

파일명 : PRACTICE_19

프로그램의 목적 및 기본기능 : 중복되지 않는 난수 배열 출력 _ ( 1. 실행창 출력 / 2. 텍스트파일 출력 )


프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 4월 1일

*/

#include "BigArray.h"


int main()
{
	int* array = NULL; // 동적 메모리 배열의 포인터
	int size;


	FILE* fout = NULL; // FILE 포인터 fout를 생성하고 NULL로 초기화
	fout = fopen(Output_File, "w"); //파일을 쓰기모드로 열고, 주소를 fout에 저장
	if (fout == NULL) // 파일을 열지 못할 경우, ( 에러 + 실행종료 )
	{
		printf("Error in creation of Output_File");
	}

	printf("Input size of big array ( more than 500000 ) = ");
	scanf_s("%d", &size);

	array = (int*)calloc(size, sizeof(int)); //동적메모리(배열) 받기 _ 씨얼록(갯수,사이즈)
	if (array == NULL) // 메모리를 할당 받지 못할 경우.
	{
		printf("Error in dynamic memeory allocation for integer array of size (%d)\n", size);
		exit(-1); // 종료
	}

	getBigRandArray(array, size); // 동적메모리할당하여 중복되지 않는 난수 배열 생성
	printBigArraySample(array, size, LINE_SIZE); // (실행창) 큰 배열 출력

	fprintBigArraySample(fout, array, size, LINE_SIZE, NUM_LINE); // (파일) 큰 배열 출력

}