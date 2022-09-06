/*

���ϸ� : PRACTICE_20

���α׷��� ���� �� �⺻��� : �پ��� �迭 ���� _ �����޸�

���α׷� �ۼ��� : ������

���α׷� �ۼ����� : 2022�� 3�� 29�� ~ 2022�� 3�� 01��

*/

#include "BigArray.h"

void arrayStatistics_basicArray(FILE* fout); // �Լ� �� ������ �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_externArray(FILE* fout); // BigArray.h �� �ܺ� �ҽ����� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_fileDataArray(FILE* fout); // Data_Input.txt �� ����� �ִ� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_inputArray(FILE* fout); // �Է���ġ(Ű����)�� �Է��� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_genBigRandArray(FILE* fout); // �ߺ����� �ʴ� ���� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���


void main()
{
	int menu = 0;

	FILE* fout = NULL; // FILE ������ fout�� �����ϰ� NULL�� �ʱ�ȭ
	fout = fopen(Data_Output_File, "w"); //������ ������� ����, �ּҸ� fout�� ����

	if (fout == NULL) // ������ ���� ���� ���, ( ���� + �������� )
	{
		printf("Error in creation of Data_Output_File");
	}

	while (1)
	{
		printf("\n\n");
		printf(" \n= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =");
		printf("\n\n << Test Array Handling >> \n");
		printf(" ( 1 : data_array / 2 : extern_array / 3 : data_file / 4 : data_input / 5 : gen_BigRandArray / Esc : terminate ) : ");
		menu = _getche(); // getche() = ( �Է°� >> ȭ����� + ����X )

		if (menu == ESC) // ESC ���� ����.
			break;

		switch (menu) // switch ���� Ȱ���Ͽ�, �Լ� ���.
		{
		case '1':
			arrayStatistics_basicArray(fout); // �Լ� �� ������ �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
			break;

		case '2':
			arrayStatistics_externArray(fout); // BigArray.h �� �ܺ� �ҽ����� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
			break;

		case '3':
			arrayStatistics_fileDataArray(fout); // Data_Output_File.txt �� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
			break;

		case '4':
			arrayStatistics_inputArray(fout); // �Է���ġ(Ű����)�� �Է��� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
			break;

		case '5':
			arrayStatistics_genBigRandArray(fout); // �ߺ����� �ʴ� ���� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
			break;

		default:
			break;
		}
	}

	// ???????????????? �� �κ� ����!!!! ??????????????????
	 
		fclose(fout);
}


// �Լ� �� ������ �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_basicArray(FILE* fout)
{
	int num_data = 10;
	int data_array[MAX_SIZE] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }; // �Լ� �� ������ �迭

	printf("\n\n     ArrayStatistics_basicArray ............... \n\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_basicArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	// ��������� ����â ���

	fprintf(fout, "\n ArrayStatistics_basicArray ...............\n");
	fgetArrayStatistics(fout, data_array, num_data);
	// ��������� �޸��� ���

}

// BigArray.h �� �ܺ� �ҽ����� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_externArray(FILE* fout)
{
	int num_data = 0; // �ܺ� �ҽ����Ͽ� ����� �� �� ���⿡, �ϴ� 0���� ���� �� ������ ����.
	extern int data_array[MAX_SIZE]; // �ܺ� �ҽ����� Data_array ��������.

	for (int i = 0; ; i++)
	{
		if (data_array[i] == -1) // -1�� ���, for�� Ż��
			break;
		else
			num_data++; // ī��Ʈ ( ���� : �迭 ũ�⸦ �˱� ����. )
	}

	printf("\n\n     ArrayStatistics_externArray ............... \n\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_basicArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
	// ������� ����â ���

	fprintf(fout, "\n ArrayStatistics_externArray ............... \n");
	fgetArrayStatistics(fout, data_array, num_data);
	// ������� �޸��� ���
}

// Data_Input.txt �� ����� �ִ� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_fileDataArray(FILE* fout)
{
	int data; // .txt ���� ������ �迭(�Ѱ���) �ӽ� �����
	int num_data = 0; // �迭 ������ 
	int data_array[MAX_SIZE] = { 0 }; // .txt ���� ������ �迭 ���������

	FILE* fin; // Data_Input.txt ���� ������ ����

	fin = fopen(Data_Input_File, "r"); // Data_Input.txt ���� ��� �б���
	if (fin == NULL) // ������ �������.
	{
		printf("Error in opening input data file !!\n");
		return;
	}

	while (fscanf_s(fin, "%d", &data) != EOF)
		// << ������� >>
		// �������, �ϳ��� ����� �������� (���������� �ν�)
		// EOF(End Of File) >> ������ ���� ���. -1 ���
	{
		if (data == -1)
		{
			break;
		}

		data_array[num_data] = data; // .txt ���� �ϳ��� ������ ����� data_array[] �迭�� �ֱ�.
		num_data++;
	}
	fclose(fin); // ������ �����־�����, �ݱ�.

	printf("\n\n     ArrayStatistics_fileDataArray ............... \n\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_fileDataArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
	// �������� ����â ���

	fprintf(fout, "\nArrayStatistics_fileDataArray ............... \n");
	fgetArrayStatistics(fout, data_array, num_data);
	// ������� �޸��� ���
}

// �Է���ġ(Ű����)�� �Է��� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_inputArray(FILE* fout)
{
	int num_data, data;
	int data_array[100] = { 0 };

	printf("\n\n     ArrayStatistics_inputArray  ...............  \n\n");
	printf("Please input the number of integers (less than %d) = ", MAX_SIZE); // MAX_SIZE = 100
	scanf_s("%d", &num_data); // �迭 ũ�⸦ ����ڷκ��� �Է¹ޱ�.
	printf("Input %d  integer data : ", num_data);

	for (int i = 0; i < num_data; i++) // �Է°��� �ϳ��� data_array[] �迭�� ���.
	{
		scanf_s("%d", &data);
		data_array[i] = data;
	}

	printf("\n");
	getArrayStatistics(data_array, num_data);
	printf("\narrayStatistics_inputArray - completed. Result is also stored in output file (%s).\n", Data_Output_File);
	// ������� ����â ���

	fprintf(fout, "\nArrayStatistics_inputArray  ...............  \n");
	fgetArrayStatistics(fout, data_array, num_data);
	// ������� �޸��� ���

}

// �ߺ����� �ʴ� ���� �迭 + ( �ּ�, �ִ�, ��, ���, �л�, ǥ������ ) ���
void arrayStatistics_genBigRandArray(FILE* fout)
{
	int num_data;
	int* dyn_array = NULL;

	printf("\nArrayStatistics_genBigRandArray  ...............  \n");
	printf("Big Array Size (more than 50000) = ");
	scanf_s("%d", &num_data); // ( 50000 �̻� ) �迭 ������ ����ڷκ��� �Է� �ޱ�.
	printf("Creating big random integer array (size : %d)\n", num_data);

	dyn_array = (int*)calloc(num_data, sizeof(int)); // �����޸� (�迭) �ޱ�. _ �����(����, ������)
	if (dyn_array == NULL) // �޸𸮸� �Ҵ� ���� ���� ���.
	{
		printf("Error in dynamic creation of big_array (size = %d) !!!", num_data);
		exit(-1); // ����
	}

	getBigRandArray(dyn_array, num_data);
	getArrayStatistics(dyn_array, num_data);
	printf("\narrayStatistics_genBigRandArray - completed. Result is also stored in output file(% s).\n", Data_Output_File);
	// ������� ����â ���

	fprintf(fout, "\nArrayStatistics_genBigRandArray  ...............  \n");
	fgetArrayStatistics(fout, dyn_array, num_data);
	// ������� �޸��� ���

	free(dyn_array); // ���� �޸� ��ȯ
}
