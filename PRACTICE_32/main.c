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
		// �޴� ���� ���
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
		printf(" 1. Test selection sort for words\n");
		printf(" 2. Test random access file for students records\n");
		printf(" 3. Test binary file dump\n");
		printf(" 4. Test cipher text\n");
		printf(" 0. Quit\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

		// �޴� ���� �Է�
		printf("Input menu : ");
		scanf_s("%d", &menu);
		printf("\n");

		// SWITCH�� Ȱ��
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

		
		// Enter ������ ȭ�� �ʱ�ȭ �� �ݺ��� �����
		system("pause");
		system("cls");
	}
}


void test_SelectionSortWords()
{
	// ���� �������� ( 1. ������ ���� / 2. ���� ��� ���� )
	FILE* fin, * fout;
	if ((fin = fopen("words.txt", "r")) == NULL)
	{
		printf("words.txt ���� ����!\n");
		return;
	}
	if ((fout = fopen("words_sorted.txt", "w")) == NULL)
	{
		printf("sorted_words.txt ����� ����!\n");
		return;
	}

	// �����޸��Ҵ�
	char** word_array = calloc(MAX_NUM_WORDS, sizeof(char*));
	for (int i = 0; i < MAX_NUM_WORDS; i++)
		word_array[i] = calloc(MAX_WORD_LEN, sizeof(char));


	//���Ϸκ��� ������ ��������
	int DATA_NUMBER = 0;
	while (fscanf(fin, "%20s", word_array[DATA_NUMBER]) != EOF)
		DATA_NUMBER++; // DATA_NUMBER�� ���߾� �ݺ��� + DATA ������ ���ϱ�


	// ����
	selectionSortWords(word_array, DATA_NUMBER);


	// �ؽ�Ʈ���� ���
	for (int i = 0; i < DATA_NUMBER; i++)
	{
		fprintf(fout, "%30s", word_array[i]);
		if (i % 10 == 9) // [X0] ~ [X9] ���� ����ϸ� �ٹٲ�
			fprintf(fout, "\n");
	}
	printf("words.txt ���� ������ �����͸� �����Ͽ� sorted_words.txt �� �����Ͽ����ϴ�..\n");

	// ���� _ �ܼ� ���
	/* 
	for (int i = 0; i < DATA_NUMBER; i++)
	{
		printf("%30s", word_array[i]);
		if (i % 10 == 9) // [X0] ~ [X9] ���� ����ϸ� �ٹٲ�
			printf("\n");
	}
	*/

	// ����� �޸� �� ���� ��ȯ
	for (int i = 0; i < 1000; i++)
		free(word_array[i]);
	free(word_array);
	fclose(fin);
	fclose(fout);
}

void test_RandomFileAccess_Student()
{
	int num_students = 0;
	extern STUDENT_ students[]; // �ܺ� ���� ����
	for (int i = 0; i < 100; i++) // �迭 �� ���� �ľ�
	{
		if (students[i].st_id == -1)
			break;
		else
			num_students++;
	}

	// �������� ����
	FILE* fout;

	if ((fout = fopen("students_sorted.txt", "w")) == NULL)
	{
		printf("students_sorted.txt (������) ���� ����!\n");
		return;
	}

	// ���� �� ���
	printf("Array of students at initialization : \n");
	printStudents(students, num_students);
	printf("\n");

	// ���� �� ���
	sortStudents_by_ST_ID(students, num_students);
	printf("Storing sorted students by increasing order of student ID : \n");
	printStudents(students, num_students);
	printf(" << + into SortedStudent.txt..... >>\n");
	fprintStudents(fout, students, num_students);
	fclose(fout);
	


	// ���⼭���� random file access ����� ����Ͽ� �ؽ�Ʈ���Ͽ� �����Ų �л��� ������ ���� �������� ����ϱ�.
#define MAX_STRING_LEN 512

	int cur_pos;
	int record_len;
	char student_record[MAX_STRING_LEN] = { 0 };

	// �б����� ����
	FILE* fin;
	if ((fin = fopen("students_sorted.txt", "r")) == NULL)
	{
		printf("students_sorted.txt (�б���) ���� ����!\n");
		return;
	}

	fgets(student_record, MAX_STRING_LEN, fin); // fgets �� ����Ͽ� �ؽ�Ʈ���Ϸκ��� �л������� ���ڿ��� �ޱ�.
	record_len = strlen(student_record); // ���ڿ� ���� ����.
	rewind(fin); // rewind() = ���� �����͸� ������ ���� ��ġ�� �̵�.
	printf("\n\nRandom access to students_sorted.txt file (Student record length : %d) ...\n", record_len);
	for (int i = num_students - 1; i >= 0; i--)
	{
		fseek(fin, (record_len + 1) * i, SEEK_SET); 
		// fseek() = SEEK_SET(������ ó��) ���� ������ offset(���ڿ�����+1) ��ŭ �̵�
		cur_pos = ftell(fin); // ftell() = ���� �������� ���� ��ġ�� ��ȯ
		printf("Current file_position : %3d\n", cur_pos); // ��ȯ ���� ���� �������� ������ġ ���
		fgets(student_record, MAX_STRING_LEN, fin); // ������ġ�� fgets �� ����Ͽ� �ؽ�Ʈ���Ϸκ��� �л������� ���ڿ��� �ٽ� �ޱ�.
		printf("Student (%2d): %s", i, student_record);
	}
	printf("\n");
	fclose(fin);


}

void test_BinaryFileDump()
{
	FILE* fin, * fout;
	char* INPUT = "students_sorted.txt"; // �������Է�
	char* OUTPUT = "dumpbinary.txt"; // ���������_�ؽ�Ʈ����

	// ���� ����
	if ((fin = fopen(INPUT, "rb")) == NULL)
	{
		printf("%s ���� ����!\n", INPUT);
		exit;
	}
	if ((fout = fopen(OUTPUT, "w")) == NULL)
	{
		printf("%s ���� ����!\n", OUTPUT);
		exit;
	}

	// DUMP BINARY
	dumpBinaryFile(fin, fout);


	// ���� ��ȯ
	fclose(fin);
	fclose(fout);
}

void test_SimpleCipherText()
{
	// <<< ��ȣȭ >>>
	// ���� ����
	FILE* fp_msg, * fp_cip, * fp_decip;
	if ((fp_msg = fopen("Message.txt", "r")) == NULL)
	{
		printf("Message.txt ���� ����!\n");
		return;
	}
	if ((fp_cip = fopen("Ciphered.txt", "w")) == NULL)
	{
		printf("Ciphered.txt ����� ����!\n");
		return;
	}

	// ��ȣȭ ���
	printf("Message.txt �� Ciphered.txt ��ȣȭ (��ȣ �ڵ�: 0x%02x)...\n", Cipher_Code);
	cipherText(fp_msg, fp_cip, Cipher_Code);
	
	// ���� �ݱ�
	fclose(fp_msg);
	fclose(fp_cip);



	// <<< ��ȣȭ >>>
	// ���� ����
	if ((fp_cip = fopen("Ciphered.txt", "r")) == NULL)
	{
		printf("Ciphered.txt ���� ����!\n");
		return;
	}
	if ((fp_decip = fopen("Deciphered.txt", "w")) == NULL)
	{
		printf("Deciphered.txt ����� ����!\n");
		return;
	}

	// ��ȣȭ ���
	printf("\n\nCiphered.txt �� Deciphered.txt ��ȣȭ (��ȣ �ڵ�: 0x%02x)...\n", Cipher_Code);
	deCipherText(fp_cip, fp_decip, Cipher_Code);
	printf("\n");

	// ���� �ݱ�
	fclose(fp_cip);
	fclose(fp_decip);
}