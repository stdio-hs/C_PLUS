#ifndef CODE
#define CODE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define WRITE_FILE "write_FILE.txt" // 2차원배열 3개를 담고 있는 .txt 파일



double** createDoubleMtrx(int row_size, int col_size); // 2차원실수배열의 동적 생성 함수 _ ( 행/열 >> dM[] )
double** fgetMtrx(FILE* fp, int row_size, int col_size); // 2차원실수배열의 동적 반환 함수

void deleteMtrx(double** dM, int row_size); // 2차원실수배열을 파일로부터 입력받아오기 함수 _ ( 행/열 >> dM[] )
void printMtrx(double** dM, int row_size, int col_size); // 2차원실수배열의 실행창 출력



#endif // !CODE
