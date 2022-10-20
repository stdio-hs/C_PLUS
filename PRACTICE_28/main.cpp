#include "Cmplx.h"

int main()
{
	// 입력
	Cmplx cmplxs[7];
	cmplxs[0] = inputCmplx();
	cmplxs[1] = inputCmplx();
	printf("\n\n");

	// 출력
	// cmplxs[0]
	printf("cmplxs[0] = ");
	printCmplx(cmplxs[0]); 
	printf("\n");
	
	// cmplxs[1]
	printf("cmplxs[1] = ");
	printCmplx(cmplxs[1]);
	printf("\n");
	
	// cmplxs[2]
	cmplxs[2] = addCmplx(cmplxs[0], cmplxs[1]);
	printf("cmplxs[2] = cmplxs[0] + cmplxs[1] =\n");
	printCmplx(cmplxs[0]); 
	printf(" + ");
	printCmplx(cmplxs[1]); 
	printf(" = "); 
	printCmplx(cmplxs[2]);
	printf("\n");
	
	// cmplxs[3]
	cmplxs[3] = subtractCmplx(cmplxs[0], cmplxs[1]);
	printf("cmplxs[3] = cmplxs[0] - cmplxs[1] =\n");
	printCmplx(cmplxs[0]);
	printf(" - "); 
	printCmplx(cmplxs[1]);
	printf(" = "); 
	printCmplx(cmplxs[3]);
	printf("\n");
	
	// cmplxs[4]
	cmplxs[4] = multiplyCmplx(cmplxs[0], cmplxs[1]);
	printf("cmplxs[3] = cmplxs[0] * cmplxs[1] =\n");
	printCmplx(cmplxs[0]);
	printf(" * "); 
	printCmplx(cmplxs[1]);
	printf(" = ");
	printCmplx(cmplxs[4]);
	printf("\n");
	
	// cmplxs[5]
	cmplxs[5] = divideCmplx(cmplxs[0], cmplxs[1]);
	printf("cmplxs[3] = cmplxs[0] / cmplxs[1] =\n");
	printCmplx(cmplxs[0]); 
	printf(" / ");
	printCmplx(cmplxs[1]); 
	printf(" = "); 
	printCmplx(cmplxs[5]); 
	printf("\n");
	
	// cmplxs[6]
	cmplxs[6] = multiplyCmplx(cmplxs[1], cmplxs[5]);
	printf("cmplxs[6] = cmplxs[1] * cmplxs[5] =\n");
	printCmplx(cmplxs[1]); 
	printf(" * "); 
	printCmplx(cmplxs[5]);
	printf(" = "); 
	printCmplx(cmplxs[6]);
	printf("\n\n");

	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n");

	printf("Before sorting complexs : \n");
	for (int i = 0; i < 7; i++)
	{
		printf("cmplxs[%d] = ", i); 
		printCmplx(cmplxs[i]); 
		printf("\n");
	}
	quickSortCmplx(cmplxs, 7);
	printf("\nSorted complexs : \n");
	for (int i = 0; i < 7; i++)
	{
		printf("cmplxs[%d] = ", i);
		printCmplx(cmplxs[i]);
		printf("\n");
	}
}