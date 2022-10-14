/*

���ϸ� : PRACTICE_23

���α׷��� ���� �� �⺻��� : call-by-value / call-by-pointer / call-by-reference ��� ��

���α׷� �ۼ��� : ������

���α׷� �ۼ����� :
  2022�� 04�� 15�� _ ������Ʈ �ϼ�

*/

#include "Code.h"


void main()
{

	double x, y;
	double result_1, result_2, result_3;

	srand(time(0));
	x = rand() % 100;
	y = rand() % 100;
	printf("���� X �� ���� = %.2lf �Դϴ�.\n", x);
	printf("���� Y �� ���� = %.2lf �Դϴ�.\n\n", y);

	printf(" < X�� Y�� ��� ���� ? > \n");

	result_1 = average_value(x, y);
	printf("1. call-by-average = %.2lf\n", result_1);

	result_2 = average_pointer(&x, &y);
	printf("2. call-by-pointer = %.2lf\n", result_2);

	average_reference(x, y, result_3);
	printf("3. call-by-reference = %.2lf\n", result_3);


}