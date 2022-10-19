#include "Student.h"


// - - - - - - - - - - - - - - - - - - - [ 정보 ] - - - - - - - - - - - - - - - - - - - 


// 학생정보 ( ID / NAME / 생년월일 / 번호 / 점수 ) 
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

// 학생정보 순서섞기
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


// - - - - - - - - - - - - - - - - - - - [ 정보출력 ] - - - - - - - - - - - - - - - - - - - 


// 구조체 포인터를 활용하여 학생 정보 출력 ( 한명 )
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

// 구조체 배열 출력
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


// - - - - - - - - - - - - - - - - - - - [ 최대 / 최소 / 평균 ] - - - - - - - - - - - - - - - - - - - 


// 성적 ( 최대 / 최소 / 평균 ) 출력 
void statisticsGPA(STUDENT students[], int num_students)
{
	STUDENT* pST, * pST_max, * pST_min; // 해당 배열 포인터로 위치파악
	pST_max = pST_min = pST = students; // 초기 위치 값은 &students[0] 으로 초기화

	double GPA_max, GPA_min, GPA_avg, GPA_sum = 0.0; // 해당 배열 값
	GPA_max = GPA_min = GPA_sum = pST->GPA; // 초기 배열 값은 GPA[0] 으로 초기화 

	for (int i = 1; i < num_students; i++)
	{
		pST = &students[i];

		if (pST->GPA > GPA_max) // 최대값
		{
			GPA_max = pST->GPA;
		}
		if (pST->GPA < GPA_min) // 최소값
		{
			GPA_min = pST->GPA;
		}
			GPA_sum += pST->GPA; // 전체 합
	}

	GPA_avg = GPA_sum / (double)num_students; // 평균 값
	printf("GPA_max (%5.2lf), GPA_min (%5.2lf), GPA_avg (%5.2lf)\n",GPA_max, GPA_min, GPA_avg);
}

// 성적(최고) 배열 위치 파악
STUDENT* searchBestGPAStudent(STUDENT students[], int num_students)
{
	STUDENT* pST, * pST_max; // 해당 배열 포인터로 위치파악
	pST_max = pST = students; // 초기 위치 값은 &students[0] 으로 초기화

	double GPA_max = pST->GPA; // 해당 배열 값 ( 초기 배열 값은 GPA[0] 으로 초기화 )

	for (int i = 1; i < num_students; i++)
	{
		pST = &students[i];

		if (pST->GPA > GPA_max) // 최대값
		{
			GPA_max = pST->GPA; // 최대값 비교를 위해서 값 저장
			pST_max = pST; // 최대값 위치 저장
		}
	}
	return pST_max;
}

// 성적(최하) 배열 위치 파악
STUDENT* searchWorstGPAStudent(STUDENT students[], int num_students)
{
	STUDENT* pST, * pST_min; // 해당 배열 포인터로 위치파악
	pST_min = pST = students; // 초기 위치 값은 &students[0] 으로 초기화

	double GPA_min = pST->GPA; // 해당 배열 값 ( 초기 배열 값은 GPA[0] 으로 초기화 )

	for (int i = 1; i < num_students; i++)
	{
		pST = &students[i];

		if (pST->GPA < GPA_min) // 최소값
		{
			GPA_min = pST->GPA; // 최소값 비교를 위해서 값 저장
			pST_min = pST; // 최소값 위치 저장
		}
	}
	return pST_min;
}


// - - - - - - - - - - - - - - - - - - - [ 정렬 ] - - - - - - - - - - - - - - - - - - - 


// [ 자체적 응용 ] 내림차순을 위한 출력 ( 출력 역순 )
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
	STUDENT* pST, * pST_min; // 해당 배열 포인터로 위치파악
	STUDENT temp;
	int index_min;

	for (int a = 0; a < num_studnets; a++) // array[0] 부터 array[size] 까지 하나하나 비교 + 대입.
	{
		pST_min = &students[a];
		index_min = a; // 순차적으로 선택정렬을 할 때, 가장 왼쪽인 부분을 마킹해놓는다.

		for (int b = a + 1; b < num_studnets; b++) // < 마킹한 곳 다음 것.> ~ < size(끝까지) > 하나하나 비교한다. 
		{
			pST = &students[b];
				if (compareStudents(pST, pST_min, sort_key) < 0)
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
// ID _ 정렬 (예시)
void sortStudents_by_ST_ID(STUDENT Students[], int num_studnets)
{
	STUDENT* pST, * pST_min; // 해당 배열 포인터로 위치파악
	STUDENT temp;
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
*/
