#include"sorted_word_list.h"


// 문자열 선택정렬
void selectionSortWords(char** words, int num_words, int max_word_len)
{
	char* temp_word; int i, j, min;
	temp_word = (char*)calloc(sizeof(char), max_word_len);  // 임시저장소 _ 동적메모리할당
	if (temp_word == NULL)
	{
		printf("Error in dynamic allocation of memory for temp_word!!₩n");
		exit;
	}
	/* selection sorting of words */
	for (i = 0; i < num_words; i++)
	{
		strcpy(temp_word, words[i]);
		min = i;
		for (j = i + 1; j < num_words; j++)
		{
			if (strcmp(temp_word, words[j]) > 0)
			{
				min = j; strcpy(temp_word, words[j]);
			}
		}
		if (min != i)
		{
			/* temp_wordcontains words[min] already !!*/
			strcpy(words[min], words[i]);
			strcpy(words[i], temp_word);
		}
	}
}