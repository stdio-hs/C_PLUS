#include "Cmplx.h"

// ±âº»ÀÔ·Â
Cmplx inputCmplx()
{
	Cmplx c;
	printf("Input complex number (rrr.ddd iii.ddd) : ");
	scanf_s("%lf %lf", &c.real, &c.imaginary);
	c.magnitude = sqrt(c.real * c.real + c.imaginary * c.imaginary);
	return c;
}

// ±âº»Ãâ·Â
void printCmplx(const Cmplx c)
{
	printf("( %.3f", c.real);
	if (c.imaginary < 0)
		printf(" - ");
	else
		printf(" + ");
	printf(" j%.3f (magnitude %.3f) )", fabs(c.imaginary), c.magnitude);
}

// µ¡¼À
Cmplx addCmplx(const Cmplx c1, const Cmplx c2)
{
	Cmplx c;
	c.real = c1.real + c2.real;
	c.imaginary = c1.imaginary + c2.imaginary;
	c.magnitude = sqrt(c.real * c.real + c.imaginary * c.imaginary);
	return c;
}

// »¬¼À
Cmplx subtractCmplx(const Cmplx c1, const Cmplx c2)
{
	Cmplx c;
	c.real = c1.real - c2.real;
	c.imaginary = c1.imaginary - c2.imaginary;
	c.magnitude = sqrt(c.real * c.real + c.imaginary * c.imaginary);
	return c;
}

// °ö¼À
Cmplx multiplyCmplx(const Cmplx c1, const Cmplx c2)
{
	Cmplx c;
	c.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
	c.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
	c.magnitude = sqrt(c.real * c.real + c.imaginary * c.imaginary);
	return c;
}

// ³ª´°¼À
Cmplx divideCmplx(const Cmplx c1, const Cmplx c2)
{
	Cmplx c2bar = { c2.real,-c2.imaginary };
	Cmplx c = multiplyCmplx(c1, c2bar);
	c.real /= multiplyCmplx(c2, c2bar).real;
	c.imaginary /= multiplyCmplx(c2, c2bar).real;
	c.magnitude = sqrt(c.real * c.real + c.imaginary * c.imaginary);
	return c;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

double compareCmplx(const Cmplx c1, const Cmplx c2)
{
	return c1.magnitude - c2.magnitude;
}

void quickSortCmplx(Cmplx c[], const int size)
{
	_quickSortCmplx(c, 0, size - 1);
}

void _quickSortCmplx(Cmplx c[], int min, int max)
{
	int min_low = min, max_low, min_high, max_high = max;
	int pI = min_low + (max_high - min_low) / 2;
	double pV = c[pI].magnitude;

	while (min <= max)
	{ 
		while (c[min].magnitude < pV) // µ¥ÀÌÅÍ < ÇÇº¿°ª
			min++; 
		while (c[max].magnitude > pV)
			max--; // µ¥ÀÌÅÍ > ÇÇº¿°ª

		// SWAP
		if (min <= max) 
		{ 
			Cmplx temp = c[min];
			c[min] = c[max];
			c[max] = temp;
			min++; // min ¿À¸¥ÂÊÀ¸·Î
			max--; // max ¿ÞÂÊÀ¸·Î
		}
	} // ÁÂ ( ÇÇº¿°ª ÀÌÇÏ ) & ¿ì ( ÇÇº¿°ª ÀÌ»ó)
	
	min_high = min;
	max_low = min_high - 1;

	if ((max_low - min_low) > 0)
		_quickSortCmplx(c, min_low, max_low);
	if ((max_high - min_high) > 0)
		_quickSortCmplx(c, min_high, max_high);
}