/*

���ϸ� : PRACTICE_30

���α׷��� ���� �� �⺻��� : ASCII ���ڸ� �Է¹޾� 16������ ��ȯ�ϱ�

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 05�� 17�� _ ������Ʈ ���� �� ���� �� ��ȹ
  2022�� 05�� 18�� _ ���α׷� �ϼ�

*/

#include"sorted_word_list.h"

int main(void)
{
	FILE* fin, * fout;
	char** words;
	char word[MAX_WORD_NUM];
	int word_len;
	int count = 0;


	// ���ڿ� �����޸� �Ҵ� (�ִ���� 15 * �ִ� 10��)
	words = (char**)calloc(sizeof(char*), MAX_WORD_NUM);
	for (int i = 0; i < MAX_WORD_NUM; i++)
	{
		words[i] = (char*)calloc(sizeof(char), MAX_LENTH);
	}


	// ���Ͽ��� _ �б���
 	fin = fopen("words_input.txt", "r");
	if (fin == NULL)
	{
		printf("Error in opening words_input.txt file !!\n");
		return 0;
	}


	// ���Ͽ��� _ ������
	fout = fopen("words_output.txt", "w");
	if (fout == NULL)
	{
		printf("Error in opening words_output.txt file !!\n");
		return 0;
	}


	// ���Ϸκ��� ���ڿ� �о���� _ words[] ��� �迭���ٰ� �ֱ�
	while ((fscanf(fin, "%s", &word)) != EOF)
	{
		strcpy(words[count++], word);
	}


	// ��� ( ����â & ���� )
	printf("Input word list : \n");
	fprintf(fout, "Input word list : \n");
	for (int i = 0, count = 0; i < MAX_WORD_NUM; i++)
	{
		word_len = strlen(words[i]); // ���ڿ� ���� ����
		printf("(%2d)th-word : %-15s (word_length: %d)\n", count, words[i], word_len);
		fprintf(fout, "(%2d)th-word : %-15s (word_length: %d)\n", count, words[i], word_len);
		count++;
	}
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
	fprintf(fout, "\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");





	// ���� ����
	selectionSortWords(words, MAX_WORD_NUM, MAX_LENTH);


	// ���� �� �ܾ� ��� 
	printf("\nSorted word list : \n");
	fprintf(fout, "\nSorted word list : \n");
	for (int i = 0, count = 0; i < MAX_WORD_NUM; i++)
	{
		if (count == 5) // ���ٿ� 5�� ���
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
