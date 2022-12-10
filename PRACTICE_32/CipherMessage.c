#include "CipherMessage.h"


void cipherChar(const unsigned char ch, char* upper, char* lower)
{
	char temp[3];
	sprintf(temp, "%02x", ch);
	*upper = temp[0];
	*lower = temp[1];
}

void cipherText(FILE* fp_input, FILE* fp_output, const unsigned char cipher_code)
{
	while (1)
	{
		char temp[128];
		if (fgets(temp, 128, fp_input) == NULL) //�� �� ��������
			break; //���� �� �ߴ�
		for (int i = 0; i < 128; i++)
		{
			if (temp[i] == '\0')
				break; //�� ���� ������ �˻�
			char upper, lower;
			unsigned char encrypted = temp[i] ^ cipher_code; //��ȣȭ�� byte�� encrypted�� ����
			cipherChar(encrypted, &upper, &lower); //��ȣȭ�� byte�� ���� ���� 4bit�� �и�
			fprintf(fp_output, "%c%c", upper, lower); // �ؽ�Ʈ����
			printf(" % c % c", upper, lower); // �ܼ����
		}
		fprintf(fp_output, "\n"); // �ؽ�Ʈ���� ���
		printf("\n"); // �ܼ����
	}
}

unsigned char deCipherChar(char rc_u, char rc_l)
{
	char temp[3];
	char deciped;
	temp[0] = rc_u;
	temp[1] = rc_l;
	temp[2] = '\0';
	sscanf(temp, "%hhx", &deciped);
	return deciped;
}

void deCipherText(FILE* fp_input, FILE* fp_output, const unsigned char cipher_code)
{
	while (1)
	{
		char upper, lower, decrypted;
		unsigned char deciped;
		if (fscanf(fp_input, "%c", &upper) == EOF) //���� 4bit ��������
			break; //���� ���� �� �ߴ�
		if (upper == '\n')
			continue; //�ٹٲ� ���� ���� ó��
		fscanf(fp_input, "%c", &lower); //���� 4bit ��������
		deciped = deCipherChar(upper, lower); //��ȣȭ�� 1byte�� deciped�� ����
		decrypted = deciped ^ cipher_code; //��ȣȭ�� 1byte�� decrypted�� ����
		fprintf(fp_output, "%c", decrypted);
		printf("%c", decrypted);
	}
}