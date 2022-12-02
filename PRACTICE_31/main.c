/*

파일명 : PRACTICE_30

프로그램의 목적 및 기본기능 : Hexadecimal to Decimal

프로그램 작성자 : 이현성

프로그램 작성일지 : 12/02


*/

#include "hexadecimal.h"


void main()
{
	char* hexStr;
	char* hexConvertStr;
	unsigned int value_int;


	while (1)
	{
		// 동적메모리할당
		hexStr = (char*)calloc(MAX_HEX_STR_LEN, sizeof(char)); // hexStr 동적메모리할당
		hexConvertStr = (char*)calloc(MAX_HEX_STR_LEN, sizeof(char)); // hexConvertStr 동적메모리할당


		// 16진수 입력
		printf("input hexadecimal number : ");
		scanf("%s", hexStr);
		if (strcmp(hexStr, ".") == 0)
			break;


		// 16진수 >> 10진수
		value_int = atox(hexStr);
		printf("hexadecimal (%s) = %d (decimal)\n", hexStr, value_int);
		

		// 16진수 >> 10진수 >> 16진수
		xtoa(value_int, hexConvertStr); // 10진수 >> 16진수
		printf("hexadecimal (%s) = %d (decimal) = %#0X (hexadecimal) = re-converted hexadecimal string (%s)\n", hexStr, value_int, value_int, hexConvertStr); // 16진수 / (16진수>10진수) / 10진수 / (10진수>16진수) 
	}
}
