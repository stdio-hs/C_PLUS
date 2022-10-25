#ifndef SORTEDWORDLIST
#define SORTEDWORDLIST

#pragma warning(disable: 4996)

#define MAX_WORD_NUM  10
#define MAX_LENTH 15

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

void selectionSortWords(char** words, int num_words, int max_word_len); //선택정렬

#endif
