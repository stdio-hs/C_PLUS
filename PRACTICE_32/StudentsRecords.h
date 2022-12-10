#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include "main.h"

#define U_SHORT unsigned short
#define MAX_NAME_LEN 20



// 날짜 구조체
typedef struct
{
	int year;
	int month;
	int day;
} DATE_;

// 전화번호 구조체
typedef struct
{
	U_SHORT nation_code;
	U_SHORT region_no;
	U_SHORT switch_no;
	U_SHORT line_no;
} TEL_NUMBER_;

// (메인) 학생 구조체 
typedef struct
{
	int st_id; // 학번
	char name[MAX_NAME_LEN]; // 이름
	DATE_ birth_date; // 생일 월일 _ 구조체를 불러오기
	TEL_NUMBER_ tel_number; // 연락처 _ 구조체를 불러오기
	double GPA; // Grade Point Average ( 성적 평점 )
} STUDENT_;


// 정렬
void sortStudents_by_ST_ID(STUDENT_ Students[], int num_studnets);

// 출력 _ 콘솔
void printDate(DATE_ date); // ( 학생정보 출력 內 ) 날짜 출력
void printTelephoneNumber(TEL_NUMBER_ telNo); // ( 학생정보 출력 內 ) 번호 출력
void printStudent(STUDENT_* pST); // 학생정보 (한명) 출력
void printStudents(STUDENT_* stArr, int num_students); // 학생정보 ((한명출력) * 여러명) 출력

// 출력 _ 텍스트파일
void fprintStudent(FILE* fout, STUDENT_* pST);
void fprintStudents(FILE* fout, STUDENT_* stArr, int num);
void fprintDate(FILE* fout, DATE_ date);
void fprintTelephoneNumber(FILE* fout, TEL_NUMBER_ telNo);

#endif // !main_H
