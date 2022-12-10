#include "main.h"

#include "word.h"
#include "StudentsRecords.h"
#include "HandlingBinaryFile.h"
#include "CipherMessage.h"

void test_SelectionSortWords();
void test_RandomFileAccess_Student();
void test_BinaryFileDump();
void test_SimpleCipherText();

int main()
{
	int menu;

	while (1)
	{
		// 메뉴 내용 출력
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf(" 1. Test selection sort for words\n");
		printf(" 2. Test random access file for students records\n");
		printf(" 3. Test binary file dump\n");
		printf(" 4. Test cipher text\n");
		printf(" 0. Quit\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

		// 메뉴 선택 입력
		printf("Input menu : ");
		scanf_s("%d", &menu);
		printf("\n");

		// SWITCH문 활용
		if (menu == 0)
			break;
		switch (menu)
		{
		case 1:
			test_SelectionSortWords();
			break;
		case 2:
			test_RandomFileAccess_Student();
			break;
		case 3:
			test_BinaryFileDump();
			break;
		case 4:
			test_SimpleCipherText();
			break;


		default:
			break;
		}
		printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

		
		// Enter 누르면 화면 초기화 및 반복문 재시작
		system("pause");
		system("cls");
	}
}


void test_SelectionSortWords()
{
	// 파일 가져오기 ( 1. 데이터 파일 / 2. 최종 출력 파일 )
	FILE* fin, * fout;
	if ((fin = fopen("words.txt", "r")) == NULL)
	{
		printf("words.txt 열기 실패!\n");
		return;
	}
	if ((fout = fopen("words_sorted.txt", "w")) == NULL)
	{
		printf("sorted_words.txt 만들기 실패!\n");
		return;
	}

	// 동적메모리할당
	char** word_array = calloc(MAX_NUM_WORDS, sizeof(char*));
	for (int i = 0; i < MAX_NUM_WORDS; i++)
		word_array[i] = calloc(MAX_WORD_LEN, sizeof(char));


	//파일로부터 데이터 가져오기
	int DATA_NUMBER = 0;
	while (fscanf(fin, "%20s", word_array[DATA_NUMBER]) != EOF)
		DATA_NUMBER++; // DATA_NUMBER에 맞추어 반복문 + DATA 사이즈 구하기


	// 정렬
	selectionSortWords(word_array, DATA_NUMBER);


	// 텍스트파일 출력
	for (int i = 0; i < DATA_NUMBER; i++)
	{
		fprintf(fout, "%30s", word_array[i]);
		if (i % 10 == 9) // [X0] ~ [X9] 까지 출력하면 줄바꿈
			fprintf(fout, "\n");
	}
	printf("words.txt 에서 가져온 데이터를 정렬하여 sorted_words.txt 에 저장하였습니다..\n");

	// 응용 _ 콘솔 출력
	/* 
	for (int i = 0; i < DATA_NUMBER; i++)
	{
		printf("%30s", word_array[i]);
		if (i % 10 == 9) // [X0] ~ [X9] 까지 출력하면 줄바꿈
			printf("\n");
	}
	*/

	// 사용한 메모리 및 파일 반환
	for (int i = 0; i < 1000; i++)
		free(word_array[i]);
	free(word_array);
	fclose(fin);
	fclose(fout);
}

void test_RandomFileAccess_Student()
{
	int num_students = 0;
	extern STUDENT_ students[]; // 외부 변수 선언
	for (int i = 0; i < 100; i++) // 배열 총 갯수 파악
	{
		if (students[i].st_id == -1)
			break;
		else
			num_students++;
	}

	// 쓰기파일 열기
	FILE* fout;

	if ((fout = fopen("students_sorted.txt", "w")) == NULL)
	{
		printf("students_sorted.txt (쓰기모드) 열기 실패!\n");
		return;
	}

	// 정렬 전 출력
	printf("Array of students at initialization : \n");
	printStudents(students, num_students);
	printf("\n");

	// 정렬 후 출력
	sortStudents_by_ST_ID(students, num_students);
	printf("Storing sorted students by increasing order of student ID : \n");
	printStudents(students, num_students);
	printf(" << + into SortedStudent.txt..... >>\n");
	fprintStudents(fout, students, num_students);
	fclose(fout);
	


	// 여기서부터 random file access 기능을 사용하여 텍스트파일에 저장시킨 학생의 정보를 내림 차순으로 출력하기.
#define MAX_STRING_LEN 512

	int cur_pos;
	int record_len;
	char student_record[MAX_STRING_LEN] = { 0 };

	// 읽기파일 열기
	FILE* fin;
	if ((fin = fopen("students_sorted.txt", "r")) == NULL)
	{
		printf("students_sorted.txt (읽기모드) 열기 실패!\n");
		return;
	}

	fgets(student_record, MAX_STRING_LEN, fin); // fgets 를 사용하여 텍스트파일로부터 학생데이터 문자열로 받기.
	record_len = strlen(student_record); // 문자열 길이 측정.
	rewind(fin); // rewind() = 파일 포인터를 파일의 시작 위치로 이동.
	printf("\n\nRandom access to students_sorted.txt file (Student record length : %d) ...\n", record_len);
	for (int i = num_students - 1; i >= 0; i--)
	{
		fseek(fin, (record_len + 1) * i, SEEK_SET); 
		// fseek() = SEEK_SET(파일의 처음) 부터 지정된 offset(문자열길이+1) 만큼 이동
		cur_pos = ftell(fin); // ftell() = 파일 포인터의 현재 위치를 반환
		printf("Current file_position : %3d\n", cur_pos); // 반환 받은 파일 포인터의 현재위치 출력
		fgets(student_record, MAX_STRING_LEN, fin); // 현재위치로 fgets 를 사용하여 텍스트파일로부터 학생데이터 문자열로 다시 받기.
		printf("Student (%2d): %s", i, student_record);
	}
	printf("\n");
	fclose(fin);


}

void test_BinaryFileDump()
{
	FILE* fin, * fout;
	char* INPUT = "students_sorted.txt"; // 데이터입력
	char* OUTPUT = "dumpbinary.txt"; // 데이터출력_텍스트파일

	// 파일 열기
	if ((fin = fopen(INPUT, "rb")) == NULL)
	{
		printf("%s 열기 실패!\n", INPUT);
		exit;
	}
	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("%s 열기 실패!\n", OUTPUT);
		exit;
	}

	// DUMP BINARY
	dumpBinaryFile(fin, fout);


	// 파일 반환
	fclose(fin);
	fclose(fout);
}

void test_SimpleCipherText()
{
	// <<< 암호화 >>>
	// 파일 열기
	FILE* fp_msg, * fp_cip, * fp_decip;
	if ((fp_msg = fopen("Message.txt", "r")) == NULL)
	{
		printf("Message.txt 열기 실패!\n");
		return;
	}
	if ((fp_cip = fopen("Ciphered.txt", "w")) == NULL)
	{
		printf("Ciphered.txt 만들기 실패!\n");
		return;
	}

	// 암호화 출력
	printf("Message.txt → Ciphered.txt 암호화 (암호 코드: 0x%02x)...\n", Cipher_Code);
	cipherText(fp_msg, fp_cip, Cipher_Code);
	
	// 파일 닫기
	fclose(fp_msg);
	fclose(fp_cip);



	// <<< 복호화 >>>
	// 파일 열기
	if ((fp_cip = fopen("Ciphered.txt", "r")) == NULL)
	{
		printf("Ciphered.txt 열기 실패!\n");
		return;
	}
	if ((fp_decip = fopen("Deciphered.txt", "w")) == NULL)
	{
		printf("Deciphered.txt 만들기 실패!\n");
		return;
	}

	// 복호화 출력
	printf("\n\nCiphered.txt → Deciphered.txt 복호화 (암호 코드: 0x%02x)...\n", Cipher_Code);
	deCipherText(fp_cip, fp_decip, Cipher_Code);
	printf("\n");

	// 파일 닫기
	fclose(fp_cip);
	fclose(fp_decip);
}