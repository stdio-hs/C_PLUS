#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Telephone_number.h"
#define MAX_NAME_LEN 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct
{
	int st_id; // �й�
	char name[MAX_NAME_LEN]; // �̸�
	DATE birth_date; // ���� ���� _ ����ü�� �ҷ�����
	TEL_NUMBER tel_number; // ����ó _ ����ü�� �ҷ�����
	double GPA; // Grade Point Average ( ���� ���� )
} STUDENT;


enum ST_KEY { ST_ID, NAME, GPA, DOB, TEL_NUM };


void printStudent(STUDENT* pST);
void printStudents(STUDENT* stArr, int num_students);
void printStudents_2(STUDENT* stArr, int num);


void shuffleStudents(STUDENT students[], int num_students);
void statisticsGPA(STUDENT students[], int num_students);
STUDENT* searchBestGPAStudent(STUDENT students[], int num_students);
STUDENT* searchWorstGPAStudent(STUDENT students[], int num_students);

void sortStudents(STUDENT Students[], int num_studnets, ST_KEY sort_key);
int compareStudents(STUDENT* pST1, STUDENT* pST2, ST_KEY st_key);


#endif // !STUDENT_H
