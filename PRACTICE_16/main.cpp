/*

파일명 : PRACTICE_16

프로그램의 목적 및 기본기능 : 키보드 피아노 // 3차원 배열

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

		freq = mappingKey_to_Freq(ch, alt_on); // 옥타브와 음(주파수) 를 찾아 계산하는 함수

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


int mappingKey_to_Freq(char key, char alt_on) // 옥타브와 음(주파수) 를 찾아 계산하는 함수
{
	int shift_on = 0;
	int ch_index;


	if ((key >= 'a') && (key <= 'z')) // 입력값이 소문자일 경우,
	{
		shift_on = 0; // shift가 눌리지 않았다. = 0
		ch_index = key - 'a'; // index: 0~25 
	}
	else if ((key >= 'A') && (key <= 'Z')) // 입력값이 대문자일 경우,
	{
		shift_on = 1; // shift가 눌렸다. = 1
		ch_index = key - 'A'; // index: 0~25
	}
	else
	{
		return -1; // wrong key
	}
	
	// 여기까지는 key(입력값) 을 가지고 [ 소문자 or 대문자 or 잘못된값 ] 인지 판별.
	// main 함수에서 alt_on 눌림 유무 까지 총 3가지를 3차원 배열에 대입. 

	int Key_to_Freq[2][2][26] = // [2][2][26] = [Alt][shift][ASCII]
	{
		{ // alt_on 이 [ 0 ] 일 경우.

			{523, 392, 330, 660, 1323, 698, 784, 880, -1, 988, -1, -1, 494,
			 440, -1, -1, 1048, 1396, 588, 1568, 1976, 349, 1176, 294, 1760, 262},

			  {4186, 3136, 2637, 5274, -1, 5588, 6272, 7040, -1, 7902, -1, -1, 3951,
			  3520, -1, -1, -1, -1, 4699, -1, -1, 2794, -1, 2349, -1, 2093} 
		  },


		{ // alt_on 이 [ 1 ] 일 경우.

			{554, 415, 330, 660, 1323, 740, 830, 932, -1, 988, -1, -1, 494,
			 466, -1, -1, 1109, 1480, 622, 1661, 1976, 370, 1245, 311, 1865, 277}, 

			 {4435, 3322, 2637, 5274, -1, 5920, 6645, 7459, -1, 7902, -1, -1, 3951,
			  3729, -1, -1, -1, -1, 4978, -1, -1, 2960, -1, 2489, -1, 2217} 
		  }
		// A B C D E F G H I J K L M 
		// N O P Q R S T U V W X Y Z
	};

	return Key_to_Freq[alt_on][shift_on][ch_index];
}