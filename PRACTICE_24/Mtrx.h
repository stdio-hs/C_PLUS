#ifndef MTRX
#define MTRX


void addMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // µ¡¼À ( + )
void subMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // –E¼À ( - )
void multiplyMtrx(double** mA, double** mB, double** mR, int row_size, int col_size, int k_size); // °ö¼À ( * )


#endif // !MTRX
