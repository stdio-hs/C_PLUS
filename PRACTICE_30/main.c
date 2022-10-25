/*

파일명 : PRACTICE_30

프로그램의 목적 및 기본기능 : ASCII 문자를 입력받아 16진수로 변환하기

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 05월 17일 _ 프로젝트 이해 및 공부 및 계획
  2022년 05월 18일 _ 프로그램 완성

*/

#include"sorted_word_list.h"

int main(void)
{
	FILE* fin, * fout;
	char** words;
	char word[MAX_WORD_NUM];
	int word_len;
	int count = 0;


	// 문자열 동적메모리 할당 (최대길이 15 * 최대 10개)
	words = (char**)calloc(sizeof(char*), MAX_WORD_NUM);
	for (int i = 0; i < MAX_WORD_NUM; i++)
	{
		words[i] = (char*)calloc(sizeof(char), MAX_LENTH);
	}


	// 파일열기 _ 읽기모드
 	fin = fopen("words_input.txt", "r");
	if (fin == NULL)
	{
		printf("Error in opening words_input.txt file !!\n");
		return 0;
	}


	// 파일열기 _ 쓰기모드
	fout = fopen("words_output.txt", "w");
	if (fout == NULL)
	{
		printf("Error in opening words_output.txt file !!\n");
		return 0;
	}


	// 파일로부터 문자열 읽어오기 _ words[] 라는 배열에다가 넣기
	while ((fscanf(fin, "%s", &word)) != EOF)
	{
		strcpy(words[count++], word);
	}


	// 출력 ( 실행창 & 파일 )
	printf("Input word list : \n");
	fprintf(fout, "Input word list : \n");
	for (int i = 0, count = 0; i < MAX_WORD_NUM; i++)
	{
		word_len = strlen(words[i]); // 문자열 길이 측정
		printf("(%2d)th-word : %-15s (word_length: %d)\n", count, words[i], word_len);
		fprintf(fout, "(%2d)th-word : %-15s (word_length: %d)\n", count, words[i], word_len);
		count++;
	}
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	fprintf(fout, "\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");





	// 선택 정렬
	selectionSortWords(words, MAX_WORD_NUM, MAX_LENTH);


	// 정렬 된 단어 출력 
	printf("\nSorted word list : \n");
	fprintf(fout, "\nSorted word list : \n");
	for (int i = 0, count = 0; i < MAX_WORD_NUM; i++)
	{
		if (count == 5) // 한줄에 5개 출력
		{
			printf("\n");
			fprintf(fout, "\n");
		}
		printf("%-15s", words[count]);
		fprintf(fout, "%-15s", words[count]);

		count++;
	}
	return 0;
}
