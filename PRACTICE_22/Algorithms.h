#ifndef ALGORITHMS
#define ALGORITHMS

#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h> // 시간측정
#include <Windows.h> // 시간측정(정밀)



void genBigRandArray(int* bigRandArray, int size, int offset); // 랜덤 숫자 생성기

void printBigArraySample(int* bigArray, int size, int items_per_line, int num_smaple_lines); // (실행창) 큰 배열 출력



// 셔플함수 _ 셔플함수를 각 측정마다 넣을 경우, 측정비교가 무의미해지므로 자체적으로 생략함.
// void suffleArray(int* array, int size); 

#endif // !ALGORITHMS