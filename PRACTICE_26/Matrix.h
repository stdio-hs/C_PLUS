#ifndef MATRIX
#define MATRIX

#define EPSILON 0.000001
#pragma warning(disable: 4996) // scanf오류 안뜨게 하는 pragma정의 




#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// = = = = = = = = = = = = = = = = = = = [ MTRX 기본 ] = = = = = = = = = = = = = = = = = = = 


double** fGetMtrx(FILE* fin, int* pRow_size, int* pCol_size); // 2차원 배열을 동적으로 생성한 후, 해당 배열에 fscanf를 사용하여 파일로부터 배열 받아 저장.
void deleteMtrx(double** dM, int row_size, int col_size); // 동적으로 생성된 2차원 배열을 삭제하고 메모리 반환.
void printMtrx(double** dM, int size_row, int size_col); // 2차원 배열을 화면에 출력
void fprintMtrx(FILE* fout, double** dM, int row_size, int col_size); // 2차원 배열을 텍스트파일에 출력


// = = = = = = = = = = = = = = = = = = = [ MTRX 연산 ] = = = = = = = = = = = = = = = = = = = 


double** addMtrx(double** A, double** B, int row_size, int col_size); // 덧셈
double** subMtrx(double** A, double** B, int row_size, int col_size); // 뺄셈
double** mulMtrx(double** A, double** B, int row_size, int k_size, int col_size); // 곱셈


void invMtrxGaussJordanElim_FileOut(double** mA, double** inv_A, int size_N);





#endif // !MATRIX