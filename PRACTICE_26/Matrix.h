#ifndef MATRIX
#define MATRIX

#define EPSILON 0.000001
#pragma warning(disable: 4996) // scanf���� �ȶ߰� �ϴ� pragma���� 




#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// = = = = = = = = = = = = = = = = = = = [ MTRX �⺻ ] = = = = = = = = = = = = = = = = = = = 


double** fGetMtrx(FILE* fin, int* pRow_size, int* pCol_size); // 2���� �迭�� �������� ������ ��, �ش� �迭�� fscanf�� ����Ͽ� ���Ϸκ��� �迭 �޾� ����.
void deleteMtrx(double** dM, int row_size, int col_size); // �������� ������ 2���� �迭�� �����ϰ� �޸� ��ȯ.
void printMtrx(double** dM, int size_row, int size_col); // 2���� �迭�� ȭ�鿡 ���
void fprintMtrx(FILE* fout, double** dM, int row_size, int col_size); // 2���� �迭�� �ؽ�Ʈ���Ͽ� ���


// = = = = = = = = = = = = = = = = = = = [ MTRX ���� ] = = = = = = = = = = = = = = = = = = = 


double** addMtrx(double** A, double** B, int row_size, int col_size); // ����
double** subMtrx(double** A, double** B, int row_size, int col_size); // ����
double** mulMtrx(double** A, double** B, int row_size, int k_size, int col_size); // ����


void invMtrxGaussJordanElim_FileOut(double** mA, double** inv_A, int size_N);





#endif // !MATRIX