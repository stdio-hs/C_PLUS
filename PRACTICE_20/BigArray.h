#ifndef BIG_ARRAY_H 
#define BIG_ARRAY_H

#define Data_Input_File "Data_input.txt"
#define Data_Output_File "Data_output.txt"

#define ESC 0x1B
#define NUM_LINE 3
#define LINE_SIZE 10
#define MAX_SIZE 100

#include <stdio.h> 
#include <math.h> // 수학연산 
#include <stdlib.h> // rand()
#include <time.h> // 시간활용 난수
#include <conio.h> // getch()





void printArray(int* array, int size, int line_size); // (실행창) 배열 출력
void fprintArray(FILE* fout, int* array, int size, int line_size); // (파일) 배열 출력



void getArrayStatistics(int data_array[], int num_data); // (실행창) 계산값 출력
void fgetArrayStatistics(FILE* fout, int data_array[], int num_data); // (파일) 계산값 출력


void printBigArraySample(int* array, int size, int line_size, int num_line); // (실행창) 큰 배열 출력
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_line); // (파일) 큰 배열 출력


void getBigRandArray(int* array, int bigRandSize); // 랜덤 숫자 생성기 _ 동적사용


#endif