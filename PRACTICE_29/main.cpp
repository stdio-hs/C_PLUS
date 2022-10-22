/*

���ϸ� : PRACTCIE_29

���α׷��� ���� �� �⺻��� : ����ü _ �ð�

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 05�� 10�� _ ������Ʈ ���� �� �ϼ�
  2022�� 05�� 11�� _ ���ܻ�Ȳ ���� _ �� �� -> 24�ð� �Ѿ�� 00�÷� �ʱ�ȭ �Ǿ� �� �񱳿��� ����� ���ܻ�Ȳ


*/

#include "Time.h"
#define NUM_TIMES 5


int main()
{
	Time t_1, t_2;
	int incr_secs, diff_secs;

	printf(" < ��, ��, �� > �� �Է��Ͻÿ�. \n");
	t_1 = t_2 = inputDATA(); // (��,��,��) �Է�
	printf("Input time t1 = "); // ���
	outputDATA(&t_1);
	printf("\n\n");

	// �ʴ��� ����
	printf("input seconds to increment < 86400 �̸� > : "); // (����) �Է� 
	scanf_s("%d", &incr_secs);
	incrementTime(&t_2, incr_secs); // ���
	printf("After incrementing %d secs / t_2 = ", incr_secs);
	outputDATA(&t_2);                               
	printf("\n\n");

	// �ð�����
	diff_secs = compareTime(&t_1, &t_2);
	printf("Difference between t_1 and t_2 is [ %d ] secs", diff_secs);
	printf("\n\n");

	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");

	Time times[NUM_TIMES]; // �迭 ����
	times[0] = inputDATA_2(23, 59, 59); // �Է�
	times[1] = inputDATA_2(9, 0, 5);
	times[2] = inputDATA_2(13, 30, 0);
	times[3] = inputDATA_2(3, 59, 59);
	times[4] = inputDATA_2(0, 0, 0);
	
	printf("\nBefore sorting times : \n"); // ���� �� ���
	for (int i = 0; i < 5; i++)
	{
		printf("times[%d] = ", i); 
		outputDATA(&times[i]);
		printf("\n");
	}

	printf("\n");
	printf("After sorting times : \n"); // ���� �� ���
	selectionSortTime(times, NUM_TIMES);
	for (int i = 0; i < 5; i++)
	{
		printf("times[%d] = ", i);
		outputDATA(&times[i]);
		printf("\n");
	}
}


