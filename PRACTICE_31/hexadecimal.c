#include "hexadecimal.h"


// [ 16���� >> 10���� ]
int atox(char* str)
{
	unsigned char uc, hexChar;
	unsigned int hexVal = 0, hexSum = 0;

	for (int i = 0; i < MAX_HEX_STR_LEN; i++)
	{
		hexChar = str[i];
		if (hexChar == NULL)
			break;
		if ((hexChar >= '0') && (hexChar <= '9')) // 0~9
			hexVal = hexChar - '0';
		else if ((hexChar >= 'A') && (hexChar <= 'F')) // A~F
			hexVal = hexChar - 'A' + 10;
		else if ((hexChar >= 'a') && (hexChar <= 'f')) // a~f
			hexVal = hexChar - 'a' + 10;
		else
		{
			printf("Error in atox() :: given hexStr (%x) is not hex code character !!\n", hexChar);
			continue;
		}
		hexSum = hexSum * 16 + hexVal; //16����
	}
	return hexSum; // ASCII�� 16������ ��ȯ
}



// [ 10���� >> 16���� ]
void xtoa(unsigned int hxd, char* str)
{
	char* hexChar = { NULL };
	char* temp = (char*)calloc(sizeof(char), MAX_HEX_STR_LEN); //�����Ҵ�
	int position = 0;
	if (temp == NULL)
	{
		printf("Error in dynamic memory allocation !!\n");
		exit(0);
	}
	while (1)
	{
		int a = hxd % 16;

		if ((a >= 0) && (a <= 9)) // 0~9
		{
			temp[position] = '0' + a; // ������
		}
		else if ((a >= 10) && (a <= 15)) // 10~15
		{
			temp[position] = 'A' + (a - 10); // ������
		}

		hxd = hxd / 16;
		position++;

		if (hxd == 0)
		{
			break;
		}
	}
	for (int i = position - 1; i >= 0; i--) // �������� ���
	{
		str[(position - 1) - i] = temp[i];
	}
	free(temp);
}