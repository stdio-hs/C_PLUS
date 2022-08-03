/*

파일명 : PRACTICE_17

프로그램의 목적 및 기본기능 : 키보드 피아노 // SWITCH

프로그램 작성자 : 이현성
  m
프로그램 작성일지 : 2022년 3월 23일

*/

#include <stdio.h> 
#include <conio.h> // _getch() 함수를 쓰기 위하여.
#include <Windows.h>


int mappingKey_to_Freq(char key, char alt_on); // (int main 아래쪽에 있는 함수) 미리 선언 


int main()
{
	char ch = 0; // _getch
	char alt_on = 0; // alt가 눌린 상태인지 확인
	int freq;
	int duration = 100;


	printf("- - - - - - - - - - - - - - - - - - - - - - - - \n");
	printf("\n    <<< Simple Electric Piano !! >>>\n\n");
	printf("‘A’~ ‘J’ : octave 8 도 레 미 파 솔 라 시 \n");
	printf("‘Z’~ ‘M’ : octave 7 도 레 미 파 솔 라 시 \n");
	printf("‘q’~ ‘u’ : octave 6 도 레 미 파 솔 라 시 \n");
	printf("‘a’~ ‘j’ : octave 5 도 레 미 파 솔 라 시 \n");
	printf("‘z’~ ‘m’ : octave 4 도 레 미 파 솔 라 시 \n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - \n"); // 입력 예시안 출력

	printf("input next key :\n"); // 입력받기
	while ((ch = _getch()) != VK_ESCAPE) // ESC 가 아닐 경우, 프로그램 진행.
		// getchar >> 버퍼를 사용하며, 입력된 하나의 문자를 int 데이터 형으로 반환.
		// _getch >> 버퍼를 사용하지 않고, 입력된 하나의 문자를 읽어 반환 (화면에 표시 X)
		// _getche >> 버퍼를 사용하지 않고, 입력된 하나의 문자를 읽어 반환 (화면에 표시 O)


	{
		alt_on = 0; // alt_on 이 1로 바뀌고, 반복문을 타고 들어왔을 때, 다시 0으로 초기화.
		if (GetAsyncKeyState(VK_MENU) & 0x8000) // 현재의 키 상태를 알아오는 함수 (놓음 누름)을 감지한다.
			alt_on = 1; // alt가 눌린 상태라면, alt_on에 1을 대입시킨다.

			// GetAsyncKeyState 함수
			// 0x0000 >> 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
			// 0x0001 >> 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
			// [[ 0x8000 >> 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태 ]]
			// 0x8001 >> 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태

		freq = mappingKey_to_Freq(ch, alt_on); // 옥타브와 음(주파수) 를 찾아 츌력하는 함수

		if (freq != -1) // wrong key 가 아닐 경우, 
		{
			printf("input key (%c) : freq(%3d)\n", ch, freq); // 해당 키와 주파수 출력
			Beep(freq, duration); // 해당 키에 따른 음(주파수) SOUND
		}
		else
		{
			printf("input key (%c) is wrong key input..\n", ch); // wrong key 일 경우 출력.
		}
	}
}

int mappingKey_to_Freq(char key, char alt_on) // 옥타브와 음(주파수) 를 찾아 출력하는 함수
{
	int freq;

	switch (key) // switch 문 활용
	{
		// 키보드 아래줄 _ 소문자 (z~m) >> 옥타브 4 의 (도,레,미,파,솔,라,시)
	case ('z'):
		if (alt_on == 0)
			freq = 262;
		else
			freq = 277;
		break;

	case ('x'):
		if (alt_on == 0)
			freq = 294;
		else
			freq = 311;
		break;

	case ('c'):
		if (alt_on == 0)
			freq = 330;
		else
			freq = 330;
		break;

	case ('v'):
		if (alt_on == 0)
			freq = 349;
		else
			freq = 370;
		break;

	case ('b'):
		if (alt_on == 0)
			freq = 392;
		else
			freq = 415;
		break;

	case ('n'):
		if (alt_on == 0)
			freq = 440;
		else
			freq = 466;
		break;

	case ('m'):
		if (alt_on == 0)
			freq = 494;
		else
			freq = 494;
		break;



		// 키보드 중간줄 _ 소문자 (a~j) >> 옥타브 5 의 (도,레,미,파,솔,라,시)
	case ('a'):
		if (alt_on == 0)
			freq = 523;
		else
			freq = 554;
		break;

	case ('s'):
		if (alt_on == 0)
			freq = 588;
		else
			freq = 622;
		break;

	case ('d'):
		if (alt_on == 0)
			freq = 660;
		else
			freq = 660;
		break;

	case ('f'):
		if (alt_on == 0)
			freq = 698;
		else
			freq = 740;
		break;

	case ('g'):
		if (alt_on == 0)
			freq = 784;
		else
			freq = 830;
		break;

	case ('h'):
		if (alt_on == 0)
			freq = 880;
		else
			freq = 932;
		break;

	case ('j'):
		if (alt_on == 0)
			freq = 988;
		else
			freq = 988;
		break;



		// 키보드 윗줄 _ 소문자 (q~u) >> 옥타브 6 의 (도,레,미,파,솔,라,시)
	case ('q'):
		if (alt_on == 0)
			freq = 1048;
		else
			freq = 1109;
		break;

	case ('w'):
		if (alt_on == 0)
			freq = 1176;
		else
			freq = 1245;
		break;

	case ('e'):
		if (alt_on == 0)
			freq = 1323;
		else
			freq = 1323;
		break;

	case ('r'):
		if (alt_on == 0)
			freq = 1396;
		else
			freq = 1480;
		break;

	case ('t'):
		if (alt_on == 0)
			freq = 1568;
		else
			freq = 1661;
		break;

	case ('y'):
		if (alt_on == 0)
			freq = 1760;
		else
			freq = 1865;
		break;

	case ('u'):
		if (alt_on == 0)
			freq = 1976;
		else
			freq = 1976;
		break;



		// 키보드 아래줄 _ 대문자 (Z~M) >> 옥타브 7 의 (도,레,미,파,솔,라,시)
	case ('Z'):
		if (alt_on == 0)
			freq = 2093;
		else
			freq = 2217;
		break;

	case ('X'):
		if (alt_on == 0)
			freq = 2349;
		else
			freq = 2489;
		break;

	case ('C'):
		if (alt_on == 0)
			freq = 2637;
		else
			freq = 2637;
		break;

	case ('V'):
		if (alt_on == 0)
			freq = 2794;
		else
			freq = 2960;
		break;

	case ('B'):
		if (alt_on == 0)
			freq = 3136;
		else
			freq = 3322;
		break;

	case ('N'):
		if (alt_on == 0)
			freq = 3520;
		else
			freq = 3729;
		break;

	case ('M'):
		if (alt_on == 0)
			freq = 3951;
		else
			freq = 3951;
		break;



		// 키보드 중간줄 _ 대문자 (A~J) >> 옥타브 8 의 (도,레,미,파,솔,라,시)
	case ('A'):
		if (alt_on == 0)
			freq = 4186;
		else
			freq = 4435;
		break;

	case ('S'):
		if (alt_on == 0)
			freq = 4699;
		else
			freq = 4978;
		break;

	case ('D'):
		if (alt_on == 0)
			freq = 5274;
		else
			freq = 5274;
		break;

	case ('F'):
		if (alt_on == 0)
			freq = 5588;
		else
			freq = 5920;
		break;

	case ('G'):
		if (alt_on == 0)
			freq = 6272;
		else
			freq = 6645;
		break;

	case ('H'):
		if (alt_on == 0)
			freq = 7040;
		else
			freq = 7459;
		break;

	case ('J'):
		if (alt_on == 0)
			freq = 7902;
		else
			freq = 7902;
		break;

	default:
		freq = -1; // 잘못된 입력 값.
		break;
	}

	return freq;
}