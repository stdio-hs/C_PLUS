/*

���ϸ� : PRACTICE_30

���α׷��� ���� �� �⺻��� : Hexadecimal to Decimal

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 12/02


*/

#include "hexadecimal.h"


void main()
{
	char* hexStr;
	char* hexConvertStr;
	unsigned int value_int;


	while (1)
	{
		// �����޸��Ҵ�
		hexStr = (char*)calloc(MAX_HEX_STR_LEN, sizeof(char)); // hexStr �����޸��Ҵ�
		hexConvertStr = (char*)calloc(MAX_HEX_STR_LEN, sizeof(char)); // hexConvertStr �����޸��Ҵ�


		// 16���� �Է�
		printf("input hexadecimal number : ");
		scanf("%s", hexStr);
		if (strcmp(hexStr, ".") == 0)
			break;


		// 16���� >> 10����
		value_int = atox(hexStr);
		printf("hexadecimal (%s) = %d (decimal)\n", hexStr, value_int);
		

		// 16���� >> 10���� >> 16����
		xtoa(value_int, hexConvertStr); // 10���� >> 16����
		printf("hexadecimal (%s) = %d (decimal) = %#0X (hexadecimal) = re-converted hexadecimal string (%s)\n", hexStr, value_int, value_int, hexConvertStr); // 16���� / (16����>10����) / 10���� / (10����>16����) 
	}
}
