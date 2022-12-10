#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include "main.h"

#define U_SHORT unsigned short
#define MAX_NAME_LEN 20



// ��¥ ����ü
typedef struct
{
	int year;
	int month;
	int day;
} DATE_;

// ��ȭ��ȣ ����ü
typedef struct
{
	U_SHORT nation_code;
	U_SHORT region_no;
	U_SHORT switch_no;
	U_SHORT line_no;
} TEL_NUMBER_;

// (����) �л� ����ü 
typedef struct
{
	int st_id; // �й�
	char name[MAX_NAME_LEN]; // �̸�
	DATE_ birth_date; // ���� ���� _ ����ü�� �ҷ�����
	TEL_NUMBER_ tel_number; // ����ó _ ����ü�� �ҷ�����
	double GPA; // Grade Point Average ( ���� ���� )
} STUDENT_;


// ����
void sortStudents_by_ST_ID(STUDENT_ Students[], int num_studnets);

// ��� _ �ܼ�
void printDate(DATE_ date); // ( �л����� ��� Ү ) ��¥ ���
void printTelephoneNumber(TEL_NUMBER_ telNo); // ( �л����� ��� Ү ) ��ȣ ���
void printStudent(STUDENT_* pST); // �л����� (�Ѹ�) ���
void printStudents(STUDENT_* stArr, int num_students); // �л����� ((�Ѹ����) * ������) ���

// ��� _ �ؽ�Ʈ����
void fprintStudent(FILE* fout, STUDENT_* pST);
void fprintStudents(FILE* fout, STUDENT_* stArr, int num);
void fprintDate(FILE* fout, DATE_ date);
void fprintTelephoneNumber(FILE* fout, TEL_NUMBER_ telNo);

#endif // !main_H
