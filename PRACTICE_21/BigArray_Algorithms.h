#ifndef BIGARRAY_ALGORITHMS
#define BIGARRAY_ALGORITHMS

#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h> // �ð�����
#include <Windows.h> // �ð�����(����)


void genBigRandArray(int* bigRandArray, int size, int offset); // ���� ���� ������

// void suffleArray(int* array, int size); // ����


void printBigArraySample(int* bigArray, int size, int items_per_line, int num_smaple_lines); // (����â) ū �迭 ���
void fprintBigArraySample(FILE *fout, int* bigArray, int size, int items_per_line, int num_smaple_lines); // (�ؽ�Ʈ����) ū �迭 ���



#endif // !BIGARRAY_ALGORITHMS
