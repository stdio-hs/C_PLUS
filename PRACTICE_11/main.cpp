/**

파일명: PRACTICE_11

프로그램의 목적 및 기본기능 : ASCII code를 입력받고, 그 ASCII code가 문자/숫자/자음/모음/기호 인지 판별하는 프로그램

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 03월 22일

**/
 

#include <stdio.h>
int main()
{
	char ch;


	while (1)
	{
		printf("\nInput a character: ");
		scanf_s(" %c", &ch);
	


		if (ch == '.')
			break;

		else if ('0' <= ch && ch <= '9')
			printf("  => decimal number\n");
		else if ('A' <= ch && ch <= 'Z')
			switch (ch)
			{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				printf("  => alphabet upper-case, vowel\n");
				break;
			default:
				printf("  => alphabet upper-case, consonant\n");
				break;
			}
		else if ('a' <= ch && ch <= 'z')
			switch (ch)
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				printf("  => alphabet lower-case, vowel\n");
				break;
			default:
				printf("  => alphabet lower-case, consonant\n");
				break;
			}

		else
		{
			printf("  => symbol (not decimal number, not alphabet\n");
		}
			

		
	}
}
