#ifndef SORTING
#define SORTING

#include "Algorithms.h"

// SWAP �Լ�
void Swap(int arr[], int a, int b);



// ��������
void selectionSort(int* array, int size);



// ��������
void mergeSort(int* array, int size);
void _mergeSort(int* array, int* tmp_array, int left, int right);



// ������
void quickSort(int* array, int size);
void _quickSort(int* array, int left, int right);
int _partition(int* array, int left, int right);



#endif // !SORTING