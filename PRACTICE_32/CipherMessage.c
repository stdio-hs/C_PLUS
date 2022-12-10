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
		if (fgets(temp, 128, fp_input) == NULL) //한 줄 가져오기
			break; //실패 시 중단
		for (int i = 0; i < 128; i++)
		{
			if (temp[i] == '\0')
				break; //한 줄의 끝인지 검사
			char upper, lower;
			unsigned char encrypted = temp[i] ^ cipher_code; //암호화된 byte를 encrypted에 저장
			cipherChar(encrypted, &upper, &lower); //암호화된 byte를 상위 하위 4bit로 분리
			fprintf(fp_output, "%c%c", upper, lower); // 텍스트파일
			printf(" % c % c", upper, lower); // 콘솔출력
		}
		fprintf(fp_output, "\n"); // 텍스트파일 출력
		printf("\n"); // 콘솔출력
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
		if (fscanf(fp_input, "%c", &upper) == EOF) //상위 4bit 가져오기
			break; //파일 끝일 시 중단
		if (upper == '\n')
			continue; //줄바꿈 문자 예외 처리
		fscanf(fp_input, "%c", &lower); //하위 4bit 가져오기
		deciped = deCipherChar(upper, lower); //암호화된 1byte를 deciped에 저장
		decrypted = deciped ^ cipher_code; //복호화된 1byte를 decrypted에 저장
		fprintf(fp_output, "%c", decrypted);
		printf("%c", decrypted);
	}
}