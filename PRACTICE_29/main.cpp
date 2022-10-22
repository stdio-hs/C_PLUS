/*

파일명 : PRACTCIE_29

프로그램의 목적 및 기본기능 : 구조체 _ 시계

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 05월 10일 _ 프로젝트 이해 및 완성
  2022년 05월 11일 _ 예외상황 수정 _ 초 비교 -> 24시가 넘어가서 00시로 초기화 되어 초 비교에서 생기는 예외상황


*/

#include "Time.h"
#define NUM_TIMES 5


int main()
{
	Time t_1, t_2;
	int incr_secs, diff_secs;

	printf(" < 시, 분, 초 > 를 입력하시오. \n");
	t_1 = t_2 = inputDATA(); // (시,분,초) 입력
	printf("Input time t1 = "); // 출력
	outputDATA(&t_1);
	printf("\n\n");

	// 초단위 증가
	printf("input seconds to increment < 86400 미만 > : "); // (증가) 입력 
	scanf_s("%d", &incr_secs);
	incrementTime(&t_2, incr_secs); // 계산
	printf("After incrementing %d secs / t_2 = ", incr_secs);
	outputDATA(&t_2);                               
	printf("\n\n");

	// 시간차이
	diff_secs = compareTime(&t_1, &t_2);
	printf("Difference between t_1 and t_2 is [ %d ] secs", diff_secs);
	printf("\n\n");

	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");

	Time times[NUM_TIMES]; // 배열 선언
	times[0] = inputDATA_2(23, 59, 59); // 입력
	times[1] = inputDATA_2(9, 0, 5);
	times[2] = inputDATA_2(13, 30, 0);
	times[3] = inputDATA_2(3, 59, 59);
	times[4] = inputDATA_2(0, 0, 0);
	
	printf("\nBefore sorting times : \n"); // 정렬 전 출력
	for (int i = 0; i < 5; i++)
	{
		printf("times[%d] = ", i); 
		outputDATA(&times[i]);
		printf("\n");
	}

	printf("\n");
	printf("After sorting times : \n"); // 정렬 후 출력
	selectionSortTime(times, NUM_TIMES);
	for (int i = 0; i < 5; i++)
	{
		printf("times[%d] = ", i);
		outputDATA(&times[i]);
		printf("\n");
	}
}


