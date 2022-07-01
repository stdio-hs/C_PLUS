/**

파일명: PRACTICE_10

프로그램의 목적 및 기본기능 : 정수의 최대값, 최소값, overflow, underflow

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 03월 10일

**/

#include <stdio.h>
#include <limits.h>


int main()
{
    char char_max, char_min;
    short short_max, short_min;
    int int_max, int_min;

    printf("CHAR_MAX = %d\n", CHAR_MAX);
    printf("CHAR_MIN = %d\n", CHAR_MIN);
    char_max = CHAR_MAX;
    char_min = CHAR_MIN;
    printf("CHAR_MAX (%d) + 1 = %d\n", char_max, char_max + 1);
    printf("CHAR_MIN (%d) - 1 = %d\n", char_min, char_min - 1);

    
    printf("\n");
    printf("SHRT_MAX = %d\n", SHRT_MAX);
    printf("SHRT_MIN = %d\n", SHRT_MIN);
    short_max = SHRT_MAX;
    short_min = SHRT_MIN;
    printf("SHRT_MAX (%d) + 1 = %d\n", short_max, short_max + 1);
    printf("SHRT_MIN (%d) - 1 = %d\n", short_min, short_min - 1);

    
    printf("\n");
    printf("INT_MAX = %d\n", INT_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    int_max = INT_MAX;
    int_min = INT_MIN;
    printf("INT_MAX (%d) + 1 = %d\n", int_max, int_max + 1);
    printf("INT_MIN (%d) - 1 = %d\n", int_min, int_min - 1);

    return 0;
}
