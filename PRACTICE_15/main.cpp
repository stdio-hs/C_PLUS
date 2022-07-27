/*

파일명 : PRACTICE_15

프로그램의 목적 및 기본기능 : (재귀함수&반복문)구조으로 거듭제곱을 계산하며 걸린 시간 측정

프로그램 작성자 : 이현성

프로그램 작성일지 : 2022년 3월 28일

*/
#include<stdio.h> 
#include<time.h> // 추가해줘야 할 것
#include<WIndows.h> // 추가해줘야 할 것

double powerRecur(double base, int exponent); // 반복문 구조
double powerIter(double base, int exponent); // 재귀함수 구조

int main(void)
{
    time_t t_before, t_after; // 측정시작, 측정끝 _ 초
    double t_diff; // 시간 차이 
    LARGE_INTEGER freq, t1, t2; // 고성능_측정시작, 고성능_측정끝 _ 밀리초
    LONGLONG t_diff_pc; // 고성능_시간차이
    
    double t_elapse_ms; // 시간계산

    double result_i, result_r;
    double base = 1.015;

    QueryPerformanceFrequency(&freq); // 선언
    for (int expo = 1000; expo <= 4000; expo += 1000)
    {
        time(&t_before); // 측정시작
        QueryPerformanceCounter(&t1); // 고성능_측정시작
        result_i = powerIter(base, expo);
        QueryPerformanceCounter(&t2); // 고성능_측정끝
        time(&t_after); // 측정끝 
        t_diff = difftime(t_after, t_before); // 시간 차이
        t_diff_pc = t2.QuadPart - t1.QuadPart; // 고성능_시간차이
        t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 10000; // 시간계산
        printf("PowerItera(1.015, %d) by iterative = %40.5lf, took (%3f) sec, (%10.2lf) milli-second\n", expo, result_i, t_diff, t_elapse_ms); // 초, 밀리초

        time(&t_before);
        QueryPerformanceCounter(&t1);
        result_r = powerRecur(base, expo);
        QueryPerformanceCounter(&t2);
        time(&t_after);
        t_diff = difftime(t_after, t_before);
        t_diff_pc = t2.QuadPart - t1.QuadPart;
        t_elapse_ms = ((double)t_diff_pc / (double)freq.QuadPart) * 10000;
        printf("PowerRecur(1.015, %d) by recursive = %40.5lf, took (%3f) sec, (%10.2lf) milli-second\n", expo, result_r, t_diff, t_elapse_ms);
    }
    return 0;
}

double powerIter(double base, int exponent)
{
    double num = base;
    for (int i = 1; i < exponent; i++)
        num *= base;
    return num;
}
double powerRecur(double base, int exponent)
{
    double num = base;
    if (exponent > 1)
        num *= powerRecur(num, exponent - 1);
    return num;
}
