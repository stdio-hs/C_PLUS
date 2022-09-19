#ifndef BIG_ARRAY_SORTINGS_H
#define BIG_ARRAY_SORTINGS_H

#include "BigArray_Algorithms.h"


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



// ���̺긮������ (����+��)
#define QUICK_SELECTION_THRESHOLD 50 // ���̺긮�� ��ȯ ���� ������
void hybridQuickSelectionSort(int* bigArray, int sise);
void _hybridQuickSelectionSort(int* bigArray, int left, int right);
void hy_selectionSort(int* array, int size, int left, int right);


#endif