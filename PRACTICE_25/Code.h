#ifndef CODE

#define CODE

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define WRITE_FILE "write_FILE.txt"
#define WRITE_FILE_2 "write_FILE_2.txt"
#define SIZE 5



//ㅡㅡㅡㅡㅡ--ㅡㅡㅡ--ㅡㅡㅡㅡ----ㅡ--ㅡㅡ [ 동적메모리할당 주소위치 확인 함수 ] ㅡㅡㅡㅡㅡㅡㅡㅡㅡ--ㅡ--ㅡ--ㅡㅡㅡ----ㅡ


void checkAddress_2DArray(double** dM, int row_size, int col_size); // 해당 동적메모리할당 주소위치 확인 함수


//ㅡㅡㅡㅡㅡ--ㅡㅡㅡ--ㅡㅡㅡㅡ----ㅡ--ㅡㅡ [ 2차원실수배열 관련 함수 ] ㅡㅡㅡㅡㅡㅡㅡㅡㅡ--ㅡ--ㅡ--ㅡㅡㅡ----ㅡ


double** createDoubleMtrx(int row_size, int col_size); // 2차원실수배열의 동적 생성 함수 _ ( 행/열 >> dM[] )
void deleteDoubleMtrx(double** dM, int row_size); // 2차원실수배열을 파일로부터 입력받아오기 함수 _ ( 행/열 >> dM[] )
double** fgetDoubleMtrx(FILE* fp, int row_size, int col_size); // 2차원실수배열의 동적 반환 함수
void printMtrx(double** dM, int row_size, int col_size); // 2차원실수배열의 실행창 출력
// void fprintMtrx(double** dM, int size_row, int size_col);


//ㅡㅡㅡㅡㅡ--ㅡㅡㅡ--ㅡㅡㅡㅡ----ㅡ--ㅡㅡ [ 2차원실수배열(행렬) 연산 함수 ] ㅡㅡㅡㅡㅡㅡㅡㅡㅡ--ㅡ--ㅡ--ㅡㅡㅡ----ㅡ


void addMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // 덧셈 ( + )
void subMtrx(double** mA, double** mB, double** mR, int row_size, int col_size); // 뺼셈 ( - )
void multiplyMtrx(double** mA, double** mB, double** mR, int row_size, int col_size, int k_size); // 곱셈 ( * )


double** getStatisticsMtrx(double** dM, int row_size, int col_size); // 행 & 열 평균 계산 + 출력





#endif // !CODE
