#ifndef CODE

#define CODE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define WRITE_FILE "write_FILE.txt"
#define WRITE_FILE_2 "write_FILE_2.txt"
#define SIZE 5



//�ѤѤѤѤ�--�ѤѤ�--�ѤѤѤ�----��--�Ѥ� [ �����޸��Ҵ� �ּ���ġ Ȯ�� �Լ� ] �ѤѤѤѤѤѤѤѤ�--��--��--�ѤѤ�----��


void checkAddress_2DArray(double** dM, int row_size, int col_size); // �ش� �����޸��Ҵ� �ּ���ġ Ȯ�� �Լ�


//�ѤѤѤѤ�--�ѤѤ�--�ѤѤѤ�----��--�Ѥ� [ 2�����Ǽ��迭 ���� �Լ� ] �ѤѤѤѤѤѤѤѤ�--��--��--�ѤѤ�----��


double** createDoubleMtrx(int row_size, int col_size); // 2�����Ǽ��迭�� ���� ���� �Լ� _ ( ��/�� >> dM[] )
void deleteDoubleMtrx(double** dM, int row_size); // 2�����Ǽ��迭�� ���Ϸκ��� �Է¹޾ƿ��� �Լ� _ ( ��/�� >> dM[] )
double** fgetDoubleMtrx(FILE* fp, int row_size, int col_size); // 2�����Ǽ��迭�� ���� ��ȯ �Լ�
void printMtrx(double** dM, int row_size, int col_size); // 2�����Ǽ��迭�� ����â ���
// void fprintMtrx(double** dM, int size_row, int size_col);


//�ѤѤѤѤ�--�ѤѤ�--�ѤѤѤ�----��--�Ѥ� [ 2�����Ǽ��迭(���) ���� �Լ� ] �ѤѤѤѤѤѤѤѤ�--��--��--�ѤѤ�----��


void addMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // ���� ( + )
void subMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // �E�� ( - )
void multiplyMtrx(double** mA, double** mB, double** mR, int row_size, int col_size, int k_size); // ���� ( * )


double** getStatisticsMtrx(double** dM, int row_size, int col_size); // �� & �� ��� ��� + ���





#endif // !CODE
