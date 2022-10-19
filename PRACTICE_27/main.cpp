/*

파일명 : PRACTICE_27

프로그램의 목적 및 기본기능 : 구조체

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 05월 03일 _ 프로젝트 완성 / sorting을 compare을 사용하지 않고 개별로 만들었음 _ 수정 필요
  2022년 05월 04일 _ compare 함수를 사용하여 sorting 함수 한개로 재활용 가능하게 함.
  2022년 05월 05일 _ [ 응용 ] ( 1. 오름차순 / 2. 내림차순 ) 선택할 수 있게 만들었음.
  2022년 05월 06일 _ [ 응용 ] 이진탐색 활용 / 학번검색 > 성적출력 

*/

#pragma warning(disable: 4996) // scanf오류 안뜨게 하는 pragma정의 
#include "Student.h"


void main()
{
	int num_students = 0;
	int menu;
	int sort_choice;
	STUDENT* pST_GPA_max, * pST_GPA_min; // CASE 3 을 위해서 미리 선언.
	

	extern STUDENT students[]; // 외부 변수 선언
	for (int i = 0; i < 100; i++) // 배열 총 갯수 파악
	{
		if (students[i].st_id == -1)
			break;
		else
			num_students++;
	}
	printf("Number of students = %d\n", num_students);


	while (1)
	{

		printf("\n");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		printf(" 1 : print student records\n");
		printf(" 2 : calculate statistics GPA (max, min, avg) of students' \n");
		printf(" 3 : search students of best GPA and worst GPA\n");
		printf(" 4 : sort students by student ID\n");
		printf(" 5 : sort students by GPA\n");
		printf(" 6 : sort students by name\n");
		printf(" 7 : sort students by date of birth\n");
		printf(" 8 : sort studetns by telephone number\n");
		printf(" 0 : QUIT\n");
		printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
		printf("\n");

		printf("Input menu = ");
		scanf_s("%d", &menu);
		if (menu == 0)
			break;


		switch (menu)
		{
		case 1:
			printStudents(students, num_students);
			printf("\n");
			break;

		case 2:
			statisticsGPA(students, num_students);
			printf("\n");
			break;

		case 3:
			pST_GPA_max = searchBestGPAStudent(students, num_students); // 성적 (최대) 배열 위치파악
			pST_GPA_min = searchWorstGPAStudent(students, num_students); // 성적  (최소) 배열 위치파악
			printf("Student with best GPA : ");
			printStudent(pST_GPA_max);
			printf("\n");
			printf("Student with worst GPA : ");
			printStudent(pST_GPA_min);
			printf("\n");
			break;

		case 4:
			sortStudents(students, num_students, ST_ID);
			
			printf(" < 원하시는 정렬을 선택하시오. >\n");
			printf("  ( 1. 오름차순   2. 내림차순 )\n");
			printf("  입력 값 : ");
			scanf_s("%d", &sort_choice);

			printf("\nAfter sorting students by increasing order of student ID : \n");
			if (sort_choice == 1)
			{
				printStudents(students, num_students);
				printf("\n");
			}
			else if (sort_choice == 2)
			{
				printStudents_2(students, num_students);
				printf("\n");
			}
			else
			{
				printf(" <<< 잘못된 값 입니다. >>>\n");
				break;
			}
			break;


		case 5:
			sortStudents(students, num_students, GPA);

			printf(" < 원하시는 정렬을 선택하시오. >\n");
			printf("  ( 1. 오름차순   2. 내림차순 )\n");
			printf("  입력 값 : ");
			scanf_s("%d", &sort_choice);

			printf("\nAfter sorting students by decreasing order of GPA : \n");
			if (sort_choice == 1)
			{
				printStudents(students, num_students);
				printf("\n");
			}
			else if (sort_choice == 2)
			{
				printStudents_2(students, num_students);
				printf("\n");
			}
			else
			{
				printf(" <<< 잘못된 값 입니다. >>>\n");
				break;
			}
			break;


		case 6:
			sortStudents(students, num_students, NAME);

			printf(" < 원하시는 정렬을 선택하시오. >\n");
			printf("  ( 1. 오름차순   2. 내림차순 )\n");
			printf("  입력 값 : ");
			scanf_s("%d", &sort_choice);

			printf("\nAfter sorting students by increasing order of student name : \n");
			if (sort_choice == 1)
			{
				printStudents(students, num_students);
				printf("\n");
			}
			else if (sort_choice == 2)
			{
				printStudents_2(students, num_students);
				printf("\n");
			}
			else
			{
				printf(" <<< 잘못된 값 입니다. >>>\n");
				break;
			}
			break;


		case 7:
			sortStudents(students, num_students, DOB);

			printf(" < 원하시는 정렬을 선택하시오. >\n");
			printf("  ( 1. 오름차순   2. 내림차순 )\n");
			printf("  입력 값 : ");
			scanf_s("%d", &sort_choice);

			printf("\nAfter sorting students by increasing order of student birth date : \n");
			if (sort_choice == 1)
			{
				printStudents(students, num_students);
				printf("\n");
			}
			else if (sort_choice == 2)
			{
				printStudents_2(students, num_students);
				printf("\n");
			}
			else
			{
				printf(" <<< 잘못된 값 입니다. >>>\n");
				break;
			}
			break;


		case 8:
			sortStudents(students, num_students, TEL_NUM);

			printf(" < 원하시는 정렬을 선택하시오. >\n");
			printf("  ( 1. 오름차순   2. 내림차순 )\n");
			printf("  입력 값 : ");
			scanf_s("%d", &sort_choice);

			printf("\nAfter sorting students by increasing order of student's telephone number : \n");
			if (sort_choice == 1)
			{
				printStudents(students, num_students);
				printf("\n");
			}
			else if (sort_choice == 2)
			{
				printStudents_2(students, num_students);
				printf("\n");
			}
			else
			{
				printf(" <<< 잘못된 값 입니다. >>>\n");
				break;
			}
			break;

		case 9:


		default:
			break;
		}

		shuffleStudents(students, num_students);
	}

}