#ifndef MTRX
#define MTRX


void addMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // ���� ( + )
void subMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // �E�� ( - )
void multiplyMtrx(double** mA, double** mB, double** mR, int row_size, int col_size, int k_size); // ���� ( * )


#endif // !MTRX
