#include "HandlingBinaryFile.h"

void dumpBinaryFile(FILE* fin, FILE* fout)
{
	int nbytes;
	unsigned char buffer[BUFFER_LEN] = { '\0' };

	for (int addr = 0; addr < MAX_FILE_SIZE; addr += BUFFER_LEN)
	{
		nbytes = fread(buffer, sizeof(unsigned char), BUFFER_LEN, fin);
		// nbytes = 한 줄에 저장시킬 데이터 길이
		// fread() = 파일로부터 BUFFER_LEN 만큼 읽고, 저장한다.
		
		if (nbytes <= 0) // 줄길이가 없을경우 = 파일로부터 더이상 데이터를 불러올 것이 없다.
			break;



		// 텍스트파일 출력
		fprintf(fout, "%08X: ", addr); // 주소출력 ex) _______0 (8자리)

		for (int i = 0; i < nbytes; i++)
		{
			if (i == (BUFFER_LEN / 2)) // 16진수를 8자리/8자리 출력
				fprintf(fout, " ");
			fprintf(fout, "%02X ", buffer[i]); 
		}
		fprintf(fout, " ");


		for (int i = 0; i < nbytes; i++)
		{
			if (isprint(buffer[i])) // isprint(A) = A가 출력가능한 문자인가?
				fprintf(fout, "%c", buffer[i]); // 가능할 경우, 출력.
			else
				fprintf(fout, "."); // 불가능할 경우, 출력 X.
		}
		fprintf(fout, "\n");



		// 실행파일 출력
		printf("%08X: ", addr); // 주소출력 ex) _______0 (8자리)

		for (int i = 0; i < nbytes; i++)
		{
			if (i == (BUFFER_LEN / 2)) // 16진수를 8자리/8자리 출력
				printf(" ");
			printf("%02X ", buffer[i]);
		}
		printf(" ");


		for (int i = 0; i < nbytes; i++)
		{
			if (isprint(buffer[i])) // isprint(A) = A가 출력가능한 문자인가?
				printf("% c", buffer[i]); // 가능할 경우, 출력.
			else
				printf("."); // 불가능할 경우, 출력 X.
		}
		printf("\n");
	}
}