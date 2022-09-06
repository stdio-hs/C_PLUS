#ifndef BIG_ARRAY_H 
#define BIG_ARRAY_H

#define Data_Input_File "Data_input.txt"
#define Data_Output_File "Data_output.txt"

#define ESC 0x1B
#define NUM_LINE 3
#define LINE_SIZE 10
#define MAX_SIZE 100

#include <stdio.h> 
#include <math.h> // ���п��� 
#include <stdlib.h> // rand()
#include <time.h> // �ð�Ȱ�� ����
#include <conio.h> // getch()





void printArray(int* array, int size, int line_size); // (����â) �迭 ���
void fprintArray(FILE* fout, int* array, int size, int line_size); // (����) �迭 ���



void getArrayStatistics(int data_array[], int num_data); // (����â) ��갪 ���
void fgetArrayStatistics(FILE* fout, int data_array[], int num_data); // (����) ��갪 ���


void printBigArraySample(int* array, int size, int line_size, int num_line); // (����â) ū �迭 ���
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_line); // (����) ū �迭 ���


void getBigRandArray(int* array, int bigRandSize); // ���� ���� ������ _ �������


#endif