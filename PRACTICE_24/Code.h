#ifndef CODE
#define CODE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define WRITE_FILE "write_FILE.txt" // 2�����迭 3���� ��� �ִ� .txt ����



double** createDoubleMtrx(int row_size, int col_size); // 2�����Ǽ��迭�� ���� ���� �Լ� _ ( ��/�� >> dM[] )
double** fgetMtrx(FILE* fp, int row_size, int col_size); // 2�����Ǽ��迭�� ���� ��ȯ �Լ�

void deleteMtrx(double** dM, int row_size); // 2�����Ǽ��迭�� ���Ϸκ��� �Է¹޾ƿ��� �Լ� _ ( ��/�� >> dM[] )
void printMtrx(double** dM, int row_size, int col_size); // 2�����Ǽ��迭�� ����â ���



#endif // !CODE
