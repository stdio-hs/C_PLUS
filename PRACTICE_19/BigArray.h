#ifndef BIG_ARRAY_H 
#define BIG_ARRAY_H

#define Output_File "output.txt"
#define LINE_SIZE 10
#define NUM_LINE 3

#include <stdio.h> 
#include <stdlib.h> // rand()
#include <time.h> // �ð�Ȱ�� ����



void getBigRandArray(int* array, int bigRandSize); // ���� ���� ������ _ �������

void printBigArraySample(int* array, int size, int line_size); // (����â) ū �迭 ���
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_line); // (����) ū �迭 ���



#endif