#ifndef CIPHERMESSAGE_H
#define CIPHERMESSAGE_H

#include "main.h"
#define Cipher_Code 0x69


void cipherChar(const unsigned char ch, char* pCC_u, char* pCC_l);
void cipherText(FILE* fp_input, FILE* fp_output, const unsigned char cipher_code);
unsigned char deCipherChar(char rc_u, char rc_l);
void deCipherText(FILE* fp_input, FILE* fp_output, const unsigned char cipher_code);





#endif // !CIPHERMESSAGE_H
