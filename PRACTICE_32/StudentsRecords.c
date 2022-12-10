#include "StudentsRecords.h"



// - - - - - - - - - - - - - - - - - - - [ 데이터 ] - - - - - - - - - - - - - - - - - - - 


// 학생정보 ( ID / NAME / 생년월일 / 번호 / 점수 ) 
STUDENT_ students[] =
{
{ 21911000, "Kim, G-M", { 1990, 10, 5 }, { 82, 53, 805, 1234 }, 3.57 },
{ 21822075, "Yoon, S-M", { 1990, 4, 5 }, { 82, 53, 811, 1550 }, 4.37 },
{ 21433015, "Hwang, S-S", { 1989, 1, 10 }, { 82, 53, 817, 1005 }, 2.72 },
{ 21644054, "Lee, K-M", { 1991, 5, 15 }, { 82, 10, 9112, 9876 }, 3.35 },
{ 21255340, "Hong, G-M", { 1990, 2, 5 }, { 82, 55, 810, 5678 }, 3.57 },
{ 21766056, "Zang, S-M", { 1990, 3, 15 }, { 82, 10, 9112, 1600 }, 4.45 },
{ 21177017, "Park, S-S", { 1989, 7, 10 }, { 82, 34, 817, 1098 }, 4.12 },
{ 21588053, "Choi, Y-H", { 1992, 9, 25 }, { 82, 53, 845, 5764 }, 3.85 },
{ 21399019, "Ahn, D-J", { 1988, 10, 3 }, { 82, 31, 817, 1038 }, 3.21 },
{ 21010053, "Kwak, S-B", { 1994, 11, 15 }, { 82, 2, 897, 8778 }, 4.43 },
{ 21021053, "Song, W-B", { 1993, 5, 15 }, { 82, 34, 345, 1234 }, 4.47 },
{ 21133053, "Gong, G-W", { 1992, 6, 25 }, { 82, 55, 543, 4321 }, 2.35 },
{ 20911042, "Bhang, S-H", { 1987, 12, 25 }, { 82, 2, 123, 4567 }, 3.75 },
{-1}
};


// - - - - - - - - - - - - - - - - - - - [ 정보출력 _ 콘솔 ] - - - - - - - - - - - - - - - - - - - 


 // 학생정보 (한명) 출력
void printStudent(STUDENT_* pST)
{
	printf("Student [ID: %08d, %-10s", pST->st_id, pST->name);
	printf(", ");
	printDate(pST->birth_date);
	printf(", ");
	printTelephoneNumber(pST->tel_number);
	printf(", ");
	printf("GPA: %5.2lf", pST->GPA);
	printf("]");
}

// 학생정보 ((한명출력) * 여러명) 출력
void printStudents(STUDENT_* stArr, int num)
{
	STUDENT_* st = stArr;
	for (int i = 0; i < num; i++)
	{
		printStudent(st);
		printf("\n");
		st++;
	}
}

// ( 학생정보 출력 內 ) 날짜 출력
void printDate(DATE_ date)
{
	printf("(%04d, %2d, %2d)", date.year, date.month, date.day);
}

// ( 학생정보 출력 內 ) 번호 출력
void printTelephoneNumber(TEL_NUMBER_ telNo)
{
	printf("(tel: +%d-", telNo.nation_code);
	printf("%03d-%04d-%04d)", telNo.region_no, telNo.switch_no, telNo.line_no);
}


// - - - - - - - - - - - - - - - - - - - [ 정보출력 _ 텍스트 ] - - - - - - - - - - - - - - - - - - - 


 // 학생정보 (한명) 출력
void fprintStudent(FILE*fout, STUDENT_* pST)
{
	fprintf(fout, "Student [ID: %08d, %-10s", pST->st_id, pST->name);
	fprintf(fout, ", ");
	fprintDate(fout, pST->birth_date);
	fprintf(fout, ", ");
	fprintTelephoneNumber(fout, pST->tel_number);
	fprintf(fout, ", ");
	fprintf(fout, "GPA: %5.2lf", pST->GPA);
	fprintf(fout, "]");
}

// 학생정보 ((한명출력) * 여러명) 출력
void fprintStudents(FILE* fout, STUDENT_* stArr, int num)
{
	STUDENT_* st = stArr;
	for (int i = 0; i < num; i++)
	{
		fprintStudent(fout, st);
		fprintf(fout, "\n");
		st++;
	}
}

// ( 학생정보 출력 內 ) 날짜 출력
void fprintDate(FILE* fout, DATE_ date)
{
	fprintf(fout, "(%04d, %2d, %2d)", date.year, date.month, date.day);
}

// ( 학생정보 출력 內 ) 번호 출력
void fprintTelephoneNumber(FILE* fout, TEL_NUMBER_ telNo)
{
	fprintf(fout, "(tel: +%d-", telNo.nation_code);
	fprintf(fout, "%03d-%04d-%04d)", telNo.region_no, telNo.switch_no, telNo.line_no);
}


// - - - - - - - - - - - - - - - - - - - [ 정렬 ] - - - - - - - - - - - - - - - - - - - 


// 정렬 _ ID
void sortStudents_by_ST_ID(STUDENT_ Students[], int num_studnets)
{
	STUDENT_* pST, * pST_min; // 해당 배열 포인터로 위치파악
	STUDENT_ temp;
	int index_min;

	for (int a = 0; a < num_studnets; a++) // array[0] 부터 array[size] 까지 하나하나 비교 + 대입.
	{
		pST_min = &students[a];
		index_min = a; // 순차적으로 선택정렬을 할 때, 가장 왼쪽인 부분을 마킹해놓는다.

		for (int b = a + 1; b < num_studnets; b++) // < 마킹한 곳 다음 것.> ~ < size(끝까지) > 하나하나 비교한다. 
		{
			pST = &students[b];
			if (pST->st_id < pST_min->st_id) // 비교했을 때, ( pST[비교대상] < pST[최소값] ) 일 경우,
			{
				index_min = b; // 해당 비교대상(b)을 마킹index_min으로 바꾸어준다. (기존 마킹 소멸)  
				pST_min = pST;
			}
		}

		if (index_min != a) // ( = 현재마킹과 마킹이 다르다. ) 즉. 바로 위 for 반복문에서 비교대상이 index_min 을 받았을 경우. 
		{
			temp = students[a]; // 저장소에는 array[기존 마킹 값] 을 담아준다.
			students[a] = students[index_min]; // array[기존 마킹 값] 에는 array[새로운 마킹 값] 을 담아준다.
			students[index_min] = temp; // array[새로운 마킹 값] 에 아까 저장소에 넣어둔 값을 넣어준다.
		}
	}
}

