/*

파일명 : PL22_HW10_2_21912240_이현성

프로그램의 목적 및 기본기능 : 영문자를 처리하는 프로그램

프로그램 작성자 : 이현성

프로그램 작성일지 :
  2022년 05월 17일 _ 프로젝트 이해 및 공부 및 계획
  2022년 05월 18일 _ 프로그램 완성

*/


#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

#define MAX_HEX_STR_LEN 100
#define SIZE 15


int atox(char* str); // 16진수로 변환하여 정수형으로 반환하는 함수
void xtoa(unsigned int hxd, char* str); // 16진수의 아스키코드로 변환하는 함수


