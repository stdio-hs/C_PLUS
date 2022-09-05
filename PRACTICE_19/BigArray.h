#ifndef BIG_ARRAY_H 
#define BIG_ARRAY_H

#define Output_File "output.txt"
#define LINE_SIZE 10
#define NUM_LINE 3

#include <stdio.h> 
#include <stdlib.h> // rand()
#include <time.h> // 시간활용 난수



void getBigRandArray(int* array, int bigRandSize); // 랜덤 숫자 생성기 _ 동적사용

void printBigArraySample(int* array, int size, int line_size); // (실행창) 큰 배열 출력
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_line); // (파일) 큰 배열 출력



#endif