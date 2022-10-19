#include "Student.h"


// - - - - - - - - - - - - - - - - - - - [ ���� ] - - - - - - - - - - - - - - - - - - - 


// �л����� ( ID / NAME / ������� / ��ȣ / ���� ) 
STUDENT students[] =
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

// �л����� ��������
void shuffleStudents(STUDENT stArray[], int num_students)
{
	int st_1, st_2;
	STUDENT st_temp;
	srand(time(0));

	for (int i = 0; i < num_students; i++)
	{
		st_1 = rand() % num_students;
		st_2 = rand() % num_students;

		// SWAP
		st_temp = stArray[st_1];
		stArray[st_1] = stArray[st_2];
		stArray[st_2] = st_temp;
	}
}


// - - - - - - - - - - - - - - - - - - - [ ������� ] - - - - - - - - - - - - - - - - - - - 


// ����ü �����͸� Ȱ���Ͽ� �л� ���� ��� ( �Ѹ� )
void printStudent(STUDENT* pST)
{
	printf("Student [ID: %08d, %-10s", pST->st_id, pST->name);
	printf(", GPA: %5.2lf", pST->GPA);
	printf(", ");
	printDate(pST->birth_date);
	printf(", ");
	printTelephoneNumber(pST->tel_number);
	printf("]");
}

// ����ü �迭 ���
void printStudents(STUDENT* stArr, int num)
{
	STUDENT* st = stArr;
	for (int i = 0; i < num; i++)
	{
		printStudent(st);
		printf("\n");
		st++;
	}
}


// - - - - - - - - - - - - - - - - - - - [ �ִ� / �ּ� / ��� ] - - - - - - - - - - - - - - - - - - - 


// ���� ( �ִ� / �ּ� / ��� ) ��� 
void statisticsGPA(STUDENT students[], int num_students)
{
	STUDENT* pST, * pST_max, * pST_min; // �ش� �迭 �����ͷ� ��ġ�ľ�
	pST_max = pST_min = pST = students; // �ʱ� ��ġ ���� &students[0] ���� �ʱ�ȭ

	double GPA_max, GPA_min, GPA_avg, GPA_sum = 0.0; // �ش� �迭 ��
	GPA_max = GPA_min = GPA_sum = pST->GPA; // �ʱ� �迭 ���� GPA[0] ���� �ʱ�ȭ 

	for (int i = 1; i < num_students; i++)
	{
		pST = &students[i];

		if (pST->GPA > GPA_max) // �ִ밪
		{
			GPA_max = pST->GPA;
		}
		if (pST->GPA < GPA_min) // �ּҰ�
		{
			GPA_min = pST->GPA;
		}
			GPA_sum += pST->GPA; // ��ü ��
	}

	GPA_avg = GPA_sum / (double)num_students; // ��� ��
	printf("GPA_max (%5.2lf), GPA_min (%5.2lf), GPA_avg (%5.2lf)\n",GPA_max, GPA_min, GPA_avg);
}

// ����(�ְ�) �迭 ��ġ �ľ�
STUDENT* searchBestGPAStudent(STUDENT students[], int num_students)
{
	STUDENT* pST, * pST_max; // �ش� �迭 �����ͷ� ��ġ�ľ�
	pST_max = pST = students; // �ʱ� ��ġ ���� &students[0] ���� �ʱ�ȭ

	double GPA_max = pST->GPA; // �ش� �迭 �� ( �ʱ� �迭 ���� GPA[0] ���� �ʱ�ȭ )

	for (int i = 1; i < num_students; i++)
	{
		pST = &students[i];

		if (pST->GPA > GPA_max) // �ִ밪
		{
			GPA_max = pST->GPA; // �ִ밪 �񱳸� ���ؼ� �� ����
			pST_max = pST; // �ִ밪 ��ġ ����
		}
	}
	return pST_max;
}

// ����(����) �迭 ��ġ �ľ�
STUDENT* searchWorstGPAStudent(STUDENT students[], int num_students)
{
	STUDENT* pST, * pST_min; // �ش� �迭 �����ͷ� ��ġ�ľ�
	pST_min = pST = students; // �ʱ� ��ġ ���� &students[0] ���� �ʱ�ȭ

	double GPA_min = pST->GPA; // �ش� �迭 �� ( �ʱ� �迭 ���� GPA[0] ���� �ʱ�ȭ )

	for (int i = 1; i < num_students; i++)
	{
		pST = &students[i];

		if (pST->GPA < GPA_min) // �ּҰ�
		{
			GPA_min = pST->GPA; // �ּҰ� �񱳸� ���ؼ� �� ����
			pST_min = pST; // �ּҰ� ��ġ ����
		}
	}
	return pST_min;
}


// - - - - - - - - - - - - - - - - - - - [ ���� ] - - - - - - - - - - - - - - - - - - - 


// [ ��ü�� ���� ] ���������� ���� ��� ( ��� ���� )
void printStudents_2(STUDENT* stArr, int num)
{
	STUDENT* st = &stArr[num-1];
	for (int i = 0; i < num; i++)
	{
		printStudent(st);
		printf("\n");
		st--;
	}
}


void sortStudents(STUDENT Students[], int num_studnets, ST_KEY sort_key)
{
	STUDENT* pST, * pST_min; // �ش� �迭 �����ͷ� ��ġ�ľ�
	STUDENT temp;
	int index_min;

	for (int a = 0; a < num_studnets; a++) // array[0] ���� array[size] ���� �ϳ��ϳ� �� + ����.
	{
		pST_min = &students[a];
		index_min = a; // ���������� ���������� �� ��, ���� ������ �κ��� ��ŷ�س��´�.

		for (int b = a + 1; b < num_studnets; b++) // < ��ŷ�� �� ���� ��.> ~ < size(������) > �ϳ��ϳ� ���Ѵ�. 
		{
			pST = &students[b];
				if (compareStudents(pST, pST_min, sort_key) < 0)
				{
					index_min = b; // �ش� �񱳴��(b)�� ��ŷindex_min���� �ٲپ��ش�. (���� ��ŷ �Ҹ�)  
					pST_min = pST;
				}
		}

		if (index_min != a) // ( = ���縶ŷ�� ��ŷ�� �ٸ���. ) ��. �ٷ� �� for �ݺ������� �񱳴���� index_min �� �޾��� ���. 
		{
			temp = students[a]; // ����ҿ��� array[���� ��ŷ ��] �� ����ش�.
			students[a] = students[index_min]; // array[���� ��ŷ ��] ���� array[���ο� ��ŷ ��] �� ����ش�.
			students[index_min] = temp; // array[���ο� ��ŷ ��] �� �Ʊ� ����ҿ� �־�� ���� �־��ش�.
		}
	}
}

int compareStudents(STUDENT* pST1, STUDENT* pST2, ST_KEY st_key)
{
	if (st_key == ST_ID)
	{
		if (pST1->st_id < pST2->st_id)
			return -1;
		else if (pST1->st_id > pST2->st_id)
		
			return 1;
		else
			return 0;
	}
	else if (st_key == NAME)
	{
		if (strcmp(pST1->name, pST2->name) < 0)
			return -1;
		else if (strcmp(pST1->name, pST2->name) > 0)
			return 1;
		else
			return 0;
	}
	else if (st_key == GPA)
	{
		if (pST1->GPA < pST2->GPA)
			return -1;
		else if (pST1->GPA > pST2->GPA)
			return 1;
		else
			return 0;
	}
	else if (st_key == DOB)
	{
		if (compareDate(pST1->birth_date, pST2->birth_date) < 0)
			return -1;
		else if (compareDate(pST1->birth_date, pST2->birth_date) > 0)
			return 1;
		else
			return 0;
	}
	else if (st_key == TEL_NUM)
	{
		if (compareTelNumber(pST1->tel_number, pST2->tel_number) < 0)
			return -1;
		else if (compareTelNumber(pST1->tel_number, pST2->tel_number) > 0)
			return 1;
		else
			return 0;
	}
	else
	{
		printf("Sorting students with given sort_key is not defined yet !!");
		return 0;
	}
}

/*
// ID _ ���� (����)
void sortStudents_by_ST_ID(STUDENT Students[], int num_studnets)
{
	STUDENT* pST, * pST_min; // �ش� �迭 �����ͷ� ��ġ�ľ�
	STUDENT temp;
	int index_min;

	for (int a = 0; a < num_studnets; a++) // array[0] ���� array[size] ���� �ϳ��ϳ� �� + ����.
	{
		pST_min = &students[a];
		index_min = a; // ���������� ���������� �� ��, ���� ������ �κ��� ��ŷ�س��´�.

		for (int b = a + 1; b < num_studnets; b++) // < ��ŷ�� �� ���� ��.> ~ < size(������) > �ϳ��ϳ� ���Ѵ�. 
		{
			pST = &students[b];
			if (pST->st_id < pST_min->st_id) // ������ ��, ( pST[�񱳴��] < pST[�ּҰ�] ) �� ���,
			{
			    index_min = b; // �ش� �񱳴��(b)�� ��ŷindex_min���� �ٲپ��ش�. (���� ��ŷ �Ҹ�)  
				pST_min = pST;
			}
		}

		if (index_min != a) // ( = ���縶ŷ�� ��ŷ�� �ٸ���. ) ��. �ٷ� �� for �ݺ������� �񱳴���� index_min �� �޾��� ���. 
		{
			temp = students[a]; // ����ҿ��� array[���� ��ŷ ��] �� ����ش�.
			students[a] = students[index_min]; // array[���� ��ŷ ��] ���� array[���ο� ��ŷ ��] �� ����ش�.
			students[index_min] = temp; // array[���ο� ��ŷ ��] �� �Ʊ� ����ҿ� �־�� ���� �־��ش�.
		}
	}
}
*/
