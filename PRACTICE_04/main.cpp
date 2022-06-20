/**
파일명: PRACTICE_04
프로그램의 목적 및 기본기능 : 학생 성적 데이터를 (10개) 입력 받은 후, 최대값 최소값, 평균값을 구하는 프로그램입니다.
프로그램 작성자 : 이현성
프로그램 작성일지 : 2022년 03월 07일
**/

#include <stdio.h>

int main()
{
	int arr[10];
	int i;
	int max, min;
	double sum, average;



	for (i = 0; i < 10; i++)
	{
		printf("%d 번째 학생의 성적을 입력하시오. : ", i+1);
		scanf_s("%d", &arr[i]);
	}


	max = 0;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("가장 우수한 성적 : %d\n", max);


	min = 100;
	for (i = 0; i < 10; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	printf("가장 낮은 성적 : %d\n", min);


	sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum += arr[i];
	}
	average = sum / 10;
	printf("평균 성적 : %.lf", average);


	return 0;
}