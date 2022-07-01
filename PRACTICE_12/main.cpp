/*

파일명 : PRACTICE_12

프로그램의 목적 및 기본기능 : (입력)연 (입력)월 >> 캘린더 출력 알고리즘

프로그램 작성자 : 이현성
 
프로그램 작성일지 : 2022년 3월 16일

*/

#include <stdio.h>
#include <stdbool.h>
#define WEEKDAY_AD01Jan01 MON // the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7
#define day_1 1
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
enum MONTH { JAN = 1, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
const char* weekDayName[7] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
const char* monthName[13] = { "", "January", "February",
"March", "April","May", "June", "July", "August", "September", "October", "November", "December" };


bool isLeapYear(int year) // 윤년인지 아닌지 구하는 함수.
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	else
		return false;
}


int getDaysFromJan01AD01(int year, int month, int day) // 서기 1년 1월 1일로부터 몇 번째 날인지 구하는 함수
{
	int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysFromAD01Jan01 = 0;
	int daysInYear;
	int days = 0;
	for (int y = 1; y < year; y++) // < 입력 연을 제외한 > 전년도까지의 (연 >> 일) 계산.
	{
		daysInYear = isLeapYear(y) ? 366 : 365; // 윤년인 참으로 계산될시 366, 거짓은 365
		days += daysInYear; // days에 일 계산 값 저장
	}
	if (isLeapYear(year)) // < 2. 입력 연이 윤년 > 인지 파악 후, 그에 따른 (월 >> 일) 계산.
		daysInMonth[2] = 29;
	for (int m = 1; m < month; m++)
	{
		days += daysInMonth[m];
	}
	days += day_1;
	daysFromAD01Jan01 = days;

	return daysFromAD01Jan01;
}


void printCalender(int year, int month, int day)
{
	int x; // (입력값)년 (입력값)월 1일 _ 요일 저장 변수
	int y = 1; // 캘린더 (일) 출력할 수 있게 도와주는 변수
	int i = 0; // 요일에 맞추어 출력하기 위해 띄어쓰기 한거 카운트
	int daysFromJan01AD01_1 = 0; // < 서기 1년 1월 1일 ~~ (입력값)년 1월 1일 > 까지 일수 저장 변수
		int daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 1~12 월까지 달별 일수
		daysFromJan01AD01_1 = getDaysFromJan01AD01(year, month, day); // < 서기 1년 1월 1일~~(입력값)년 1월 1일 > 까지 일수 함수 GET
		x = daysFromJan01AD01_1 % DAYS_PER_WEEK; // < (입력값)년 (입력값)달 1일 > 이 어떤요일인지
		if (isLeapYear(year)) // (입력값)년이 윤년일 경우 => 2월(28일) >> 2월(29일)로 변경
			daysInMonth[2] = 29;
	printf(">>>>>>>>>>> %s of %d <<<<<<<<<<<<\n", monthName[month], year); // 입력값(달) >> 영어로 출력 _ enum함수 활용
		printf("=====================================\n");
	for (int wk = SUN; wk <= SAT; wk++) // enum함수 활용하여 < 일~토 > 출력
	{
		printf("%5s", weekDayName[wk]);
	}
	printf("\n-------------------------------------\n");
	for (i; i < x; i++) // 날짜에 맞는 요일부터 출력시키도록 하기.
	{
		printf("     ");
	}
	for (y; y < daysInMonth[month] + 1; y++) // 날짜 출력
	{
		printf("%3d  ", y);
		if ((y + i) % 7 == 0)
		{
			printf("\n\n");
		}
	}
	printf("\n=====================================\n\n");
}


int main()
{
	int x, y;
	for (;;)
	{
		printf("Input year (0 to quit) and month for print_calenar() : ");
		scanf_s("%d %d", &x, &y);
		if (x == 0)
		{
			break;
		}
		printf("\n");
		printCalender(x, y, day_1);
	}
	return 0;
}