/**

파일명: PRACTICE_09

프로그램의 목적 및 기본기능 : 16진수 데이터의 10진수, 8진수, 2진수 표현과 Bit-wise 계산

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 03월 10일

**/

#include<stdio.h>
#define BIT_MASK 0x01
#define NUM_BITS_INT 32
enum BinOp_Type { BIT_AND, BIT_OR, BIT_XOR, BIT_SL, BIT_SR, BIT_NOT };
const char* bop_sign[] = { "&", "|", "^", "<<", ">>", "~" };
void  printInt_Bits(int d);

void printIntOper_Bits(BinOp_Type bop, int x, int y, int z) // enum함수를 이용한 32진수 출력 _ 실제 덧셈이 아닌, PrintInt_Bit 함수 활용하여 출력
{
	if (bop != BIT_NOT) // BIT_NOT 은 출력 양식이 다르기 때문에 IF ``		 문을 활용하여 BIT_NOT 제외,
	{
		printf("    "); printInt_Bits(x); printf("\n");
		printf(" %2s ", bop_sign[bop]); printInt_Bits(y); printf("\n");
		printf(" -----------------------------------------------------------------------\n");
		printf("    "); printInt_Bits(z); printf("\n");

	}
	else // BIT_NOT을 위한 양식
	{
		printf(" %2s ", bop_sign[bop]); printInt_Bits(y); printf("\n");
		printf(" -----------------------------------------------------------------------\n");
		printf("    "); printInt_Bits(z); printf("\n");
	}

}

void printInt_Bits(int d) // 직접 만들어 본 응용 CODE
{
	unsigned long bit;

	for (int n = (NUM_BITS_INT - 1); n >= 0; n--)
	{
		bit = (d & (BIT_MASK << n)) && 1; // 입력값을 이동시키는 것이 아닌, BIT_MASK 를 이동시켜 && 함수 활용
		printf("%d", bit);

		if ((n % 8) == 0)
			printf(" ");
	}
}

int main()
{
	int x_1, x_2; // 16진수 정수형 입력값
	int c; // calculated _ 계산 결과 값

	printf("Input first hexadecimal numbers in (0x00000 ~ 0xFFFFF) : ");
	scanf_s("%x", &x_1); //16진수 정수형 입력값 _ 첫번째
	printf(" x_1 = %#010x = ( in decimal ) %#10d = ( in octal ) %o \n   =", x_1, x_1, x_1, x_1);
	printInt_Bits(x_1); printf("\n");
	printf("\n");

	printf("Input second hexadecimal numbers in (0x00000 ~ 0xFFFFF) : ");
	scanf_s("%x", &x_2); //16진수 정수형 입력값 _ 두번째
	printf(" x_2 = %#010x = ( in decimal ) %#10d = ( in octal ) %o \n   =", x_2, x_2, x_2, x_2);
	printInt_Bits(x_2); printf("\n\n");


	c = x_1 & x_2;
	printf("\nBitwise AND : %#010X & %#010X => %#010X\n", x_1, x_2, c);
	printIntOper_Bits(BIT_AND, x_1, x_2, c);

	c = x_1 | x_2;
	printf("\nBitwise OR : %#010X | %#010X => %#010X\n", x_1, x_2, c);
	printIntOper_Bits(BIT_OR, x_1, x_2, c);


	c = x_1 ^ x_2;
	printf("\nBitwise XOR : %#010X ^ %#010X => %#010X\n", x_1, x_2, c);
	printIntOper_Bits(BIT_XOR, x_1, x_2, c);

	c = x_1 << 3;
	printf("\nBitwise Shift Left : %#010X << %#010x => %#010X\n", x_1, 3, c);
	printIntOper_Bits(BIT_SL, x_1, 0x3, c);

	c = x_2 >> 3;
	printf("\nBitwise Shift Right : %#010X >> %#010x => %#010X\n", x_1, 3, c);
	printIntOper_Bits(BIT_SR, x_2, 3, c);

	c = ~x_2;
	printf("\nBitwise NOT : ~ %#010X => %#010X\n", x_2, c);
	printIntOper_Bits(BIT_NOT, x_2, x_2, c);
}
