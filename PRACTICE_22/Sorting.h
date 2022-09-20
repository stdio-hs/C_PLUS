#ifndef SORTING
#define SORTING

#include "Algorithms.h"

// SWAP 함수
void Swap(int arr[], int a, int b);



// 선택정렬
void selectionSort(int* array, int size);



// 병합정렬
void mergeSort(int* array, int size);
void _mergeSort(int* array, int* tmp_array, int left, int right);



// 퀵정렬
void quickSort(int* array, int size);
void _quickSort(int* array, int left, int right);
int _partition(int* array, int left, int right);



#endif // !SORTING