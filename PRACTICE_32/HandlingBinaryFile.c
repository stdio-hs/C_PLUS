#include "HandlingBinaryFile.h"

void dumpBinaryFile(FILE* fin, FILE* fout)
{
	int nbytes;
	unsigned char buffer[BUFFER_LEN] = { '\0' };

	for (int addr = 0; addr < MAX_FILE_SIZE; addr += BUFFER_LEN)
	{
		nbytes = fread(buffer, sizeof(unsigned char), BUFFER_LEN, fin);
		// nbytes = �� �ٿ� �����ų ������ ����
		// fread() = ���Ϸκ��� BUFFER_LEN ��ŭ �а�, �����Ѵ�.
		
		if (nbytes <= 0) // �ٱ��̰� ������� = ���Ϸκ��� ���̻� �����͸� �ҷ��� ���� ����.
			break;



		// �ؽ�Ʈ���� ���
		fprintf(fout, "%08X: ", addr); // �ּ���� ex) _______0 (8�ڸ�)

		for (int i = 0; i < nbytes; i++)
		{
			if (i == (BUFFER_LEN / 2)) // 16������ 8�ڸ�/8�ڸ� ���
				fprintf(fout, " ");
			fprintf(fout, "%02X ", buffer[i]); 
		}
		fprintf(fout, " ");


		for (int i = 0; i < nbytes; i++)
		{
			if (isprint(buffer[i])) // isprint(A) = A�� ��°����� �����ΰ�?
				fprintf(fout, "%c", buffer[i]); // ������ ���, ���.
			else
				fprintf(fout, "."); // �Ұ����� ���, ��� X.
		}
		fprintf(fout, "\n");



		// �������� ���
		printf("%08X: ", addr); // �ּ���� ex) _______0 (8�ڸ�)

		for (int i = 0; i < nbytes; i++)
		{
			if (i == (BUFFER_LEN / 2)) // 16������ 8�ڸ�/8�ڸ� ���
				printf(" ");
			printf("%02X ", buffer[i]);
		}
		printf(" ");


		for (int i = 0; i < nbytes; i++)
		{
			if (isprint(buffer[i])) // isprint(A) = A�� ��°����� �����ΰ�?
				printf("% c", buffer[i]); // ������ ���, ���.
			else
				printf("."); // �Ұ����� ���, ��� X.
		}
		printf("\n");
	}
}