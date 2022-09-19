#ifndef BIG_ARRAY_SORTINGS_H
#define BIG_ARRAY_SORTINGS_H

#include "BigArray_Algorithms.h"


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



// 하이브리드정렬 (선택+퀵)
#define QUICK_SELECTION_THRESHOLD 50 // 하이브리드 전환 구간 설정값
void hybridQuickSelectionSort(int* bigArray, int sise);
void _hybridQuickSelectionSort(int* bigArray, int left, int right);
void hy_selectionSort(int* array, int size, int left, int right);


#endif