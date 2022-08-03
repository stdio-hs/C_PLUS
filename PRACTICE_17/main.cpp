/*

���ϸ� : PRACTICE_17

���α׷��� ���� �� �⺻��� : Ű���� �ǾƳ� // SWITCH

���α׷� �ۼ��� : ������
  m
���α׷� �ۼ����� : 2022�� 3�� 23��

*/

#include <stdio.h> 
#include <conio.h> // _getch() �Լ��� ���� ���Ͽ�.
#include <Windows.h>


int mappingKey_to_Freq(char key, char alt_on); // (int main �Ʒ��ʿ� �ִ� �Լ�) �̸� ���� 


int main()
{
	char ch = 0; // _getch
	char alt_on = 0; // alt�� ���� �������� Ȯ��
	int freq;
	int duration = 100;


	printf("- - - - - - - - - - - - - - - - - - - - - - - - \n");
	printf("\n    <<< Simple Electric Piano !! >>>\n\n");
	printf("��A��~ ��J�� : octave 8 �� �� �� �� �� �� �� \n");
	printf("��Z��~ ��M�� : octave 7 �� �� �� �� �� �� �� \n");
	printf("��q��~ ��u�� : octave 6 �� �� �� �� �� �� �� \n");
	printf("��a��~ ��j�� : octave 5 �� �� �� �� �� �� �� \n");
	printf("��z��~ ��m�� : octave 4 �� �� �� �� �� �� �� \n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - \n"); // �Է� ���þ� ���

	printf("input next key :\n"); // �Է¹ޱ�
	while ((ch = _getch()) != VK_ESCAPE) // ESC �� �ƴ� ���, ���α׷� ����.
		// getchar >> ���۸� ����ϸ�, �Էµ� �ϳ��� ���ڸ� int ������ ������ ��ȯ.
		// _getch >> ���۸� ������� �ʰ�, �Էµ� �ϳ��� ���ڸ� �о� ��ȯ (ȭ�鿡 ǥ�� X)
		// _getche >> ���۸� ������� �ʰ�, �Էµ� �ϳ��� ���ڸ� �о� ��ȯ (ȭ�鿡 ǥ�� O)


	{
		alt_on = 0; // alt_on �� 1�� �ٲ��, �ݺ����� Ÿ�� ������ ��, �ٽ� 0���� �ʱ�ȭ.
		if (GetAsyncKeyState(VK_MENU) & 0x8000) // ������ Ű ���¸� �˾ƿ��� �Լ� (���� ����)�� �����Ѵ�.
			alt_on = 1; // alt�� ���� ���¶��, alt_on�� 1�� ���Խ�Ų��.

			// GetAsyncKeyState �Լ�
			// 0x0000 >> ������ ���� ���� ���� ȣ�� �������� �������� ���� ����
			// 0x0001 >> ������ ���� ���� �ְ� ȣ�� �������� �������� ���� ����
			// [[ 0x8000 >> ������ ���� ���� ���� ȣ�� �������� �����ִ� ���� ]]
			// 0x8001 >> ������ ���� ���� �ְ� ȣ�� �������� �����ִ� ����

		freq = mappingKey_to_Freq(ch, alt_on); // ��Ÿ��� ��(���ļ�) �� ã�� �����ϴ� �Լ�

		if (freq != -1) // wrong key �� �ƴ� ���, 
		{
			printf("input key (%c) : freq(%3d)\n", ch, freq); // �ش� Ű�� ���ļ� ���
			Beep(freq, duration); // �ش� Ű�� ���� ��(���ļ�) SOUND
		}
		else
		{
			printf("input key (%c) is wrong key input..\n", ch); // wrong key �� ��� ���.
		}
	}
}

int mappingKey_to_Freq(char key, char alt_on) // ��Ÿ��� ��(���ļ�) �� ã�� ����ϴ� �Լ�
{
	int freq;

	switch (key) // switch �� Ȱ��
	{
		// Ű���� �Ʒ��� _ �ҹ��� (z~m) >> ��Ÿ�� 4 �� (��,��,��,��,��,��,��)
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



		// Ű���� �߰��� _ �ҹ��� (a~j) >> ��Ÿ�� 5 �� (��,��,��,��,��,��,��)
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



		// Ű���� ���� _ �ҹ��� (q~u) >> ��Ÿ�� 6 �� (��,��,��,��,��,��,��)
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



		// Ű���� �Ʒ��� _ �빮�� (Z~M) >> ��Ÿ�� 7 �� (��,��,��,��,��,��,��)
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



		// Ű���� �߰��� _ �빮�� (A~J) >> ��Ÿ�� 8 �� (��,��,��,��,��,��,��)
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
		freq = -1; // �߸��� �Է� ��.
		break;
	}

	return freq;
}