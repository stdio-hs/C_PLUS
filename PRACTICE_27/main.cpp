/*

���ϸ� : PRACTICE_27

���α׷��� ���� �� �⺻��� : ����ü

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 05�� 03�� _ ������Ʈ �ϼ� / sorting�� compare�� ������� �ʰ� ������ ������� _ ���� �ʿ�
  2022�� 05�� 04�� _ compare �Լ��� ����Ͽ� sorting �Լ� �Ѱ��� ��Ȱ�� �����ϰ� ��.
  2022�� 05�� 05�� _ [ ���� ] ( 1. �������� / 2. �������� ) ������ �� �ְ� �������.
  2022�� 05�� 06�� _ [ ���� ] ����Ž�� Ȱ�� / �й��˻� > ������� 

*/

#pragma warning(disable: 4996) // scanf���� �ȶ߰� �ϴ� pragma���� 
#include "Student.h"


void main()
{
	int num_students = 0;
	int menu;
	int sort_choice;
	STUDENT* pST_GPA_max, * pST_GPA_min; // CASE 3 �� ���ؼ� �̸� ����.
	

	extern STUDENT students[]; // �ܺ� ���� ����
	for (int i = 0; i < 100; i++) // �迭 �� ���� �ľ�
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
			pST_GPA_max = searchBestGPAStudent(students, num_students); // ���� (�ִ�) �迭 ��ġ�ľ�
			pST_GPA_min = searchWorstGPAStudent(students, num_students); // ����  (�ּ�) �迭 ��ġ�ľ�
			printf("Student with best GPA : ");
			printStudent(pST_GPA_max);
			printf("\n");
			printf("Student with worst GPA : ");
			printStudent(pST_GPA_min);
			printf("\n");
			break;

		case 4:
			sortStudents(students, num_students, ST_ID);
			
			printf(" < ���Ͻô� ������ �����Ͻÿ�. >\n");
			printf("  ( 1. ��������   2. �������� )\n");
			printf("  �Է� �� : ");
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
				printf(" <<< �߸��� �� �Դϴ�. >>>\n");
				break;
			}
			break;


		case 5:
			sortStudents(students, num_students, GPA);

			printf(" < ���Ͻô� ������ �����Ͻÿ�. >\n");
			printf("  ( 1. ��������   2. �������� )\n");
			printf("  �Է� �� : ");
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
				printf(" <<< �߸��� �� �Դϴ�. >>>\n");
				break;
			}
			break;


		case 6:
			sortStudents(students, num_students, NAME);

			printf(" < ���Ͻô� ������ �����Ͻÿ�. >\n");
			printf("  ( 1. ��������   2. �������� )\n");
			printf("  �Է� �� : ");
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
				printf(" <<< �߸��� �� �Դϴ�. >>>\n");
				break;
			}
			break;


		case 7:
			sortStudents(students, num_students, DOB);

			printf(" < ���Ͻô� ������ �����Ͻÿ�. >\n");
			printf("  ( 1. ��������   2. �������� )\n");
			printf("  �Է� �� : ");
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
				printf(" <<< �߸��� �� �Դϴ�. >>>\n");
				break;
			}
			break;


		case 8:
			sortStudents(students, num_students, TEL_NUM);

			printf(" < ���Ͻô� ������ �����Ͻÿ�. >\n");
			printf("  ( 1. ��������   2. �������� )\n");
			printf("  �Է� �� : ");
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
				printf(" <<< �߸��� �� �Դϴ�. >>>\n");
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