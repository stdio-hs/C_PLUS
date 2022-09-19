#ifndef BIGARRAY_ALGORITHMS
#define BIGARRAY_ALGORITHMS

#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h> // 시간측정
#include <Windows.h> // 시간측정(정밀)


void genBigRandArray(int* bigRandArray, int size, int offset); // 랜덤 숫자 생성기

// void suffleArray(int* array, int size); // 셔플


void printBigArraySample(int* bigArray, int size, int items_per_line, int num_smaple_lines); // (실행창) 큰 배열 출력
void fprintBigArraySample(FILE *fout, int* bigArray, int size, int items_per_line, int num_smaple_lines); // (텍스트파일) 큰 배열 출력



#endif // !BIGARRAY_ALGORITHMS
