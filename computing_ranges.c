/* Note that the size of certain variables such as short int
 * are dependant on the compiler; i.e. if the compiler is 32 bit
 * the size of the long int would be 32 bits while if it is 64 bits
 * then the size of the long int would be 64 bits
 */

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>

void calc_ranges(void);
void lib_macros(void);

void calc_ranges(void)
{
	long long unsigned int max;

	// Characters
	signed char ch;

	for (ch = max = 1; ch > 0; ch *= 2)
	{
		max *= 2;
	}
	printf("signed char\t\t%i\t\t\t%llu\n", ch, max - 1);

	unsigned char uch;

	for (uch = -1; uch < 0; uch *= 2)
	{
		max *= 2; 
	}
	printf("unsigned char\t\t%2i\t\t\t%u\n", 0, uch);

	// Integers 
	signed short  sh_int;

	for (sh_int = max = 1; sh_int > 0; sh_int *= 2)
	{
		max *= 2;
	}
	printf("signed short\t\t%i\t\t\t%llu\n", sh_int, max - 1);

	unsigned short unsh_int;

	for (unsh_int = -1; unsh_int < 0; unsh_int *= 2)
	{
		max += unsh_int;
	}
	printf("unsigned short\t\t%2i\t\t\t%u\n", 0, unsh_int);

	signed int i;

	for (i = max = 1; i > 0; i *= 2)
	{
		max *= 2;
	}
	printf("signed int\t\t%i\t\t%llu\n", i, max - 1);

	unsigned int ui;

	for (ui = -1; ui < 0; ui *= 2)
	{
		;
	}
	printf("unsigned int\t\t%2u\t\t\t%u\n", 0, ui);

	signed long int li;

	for (li = max = 1; li > 0; li *= 2)
	{
		max *= 2;
	}
	printf("signed long\t\t%li\t%llu\n", li, max - 1);

	unsigned long int uli;

	for (uli = -1; uli < 0; uli *= 2)
	{
		;
	}
	printf("unsigned long\t\t%2u\t\t\t%lu\n", 0, uli);

	signed long long lli;

	for (lli = max = 1; lli > 0; lli *= 2)
	{
		max *= 2;
	}
	printf("signed long long\t%lli\t%llu\n", lli, max - 1);

	unsigned long long   ulli;
	for (ulli =  -1; ulli < 0; ulli *= 2)
	{
		;
	}
	printf("unsigned long long\t%2i\t\t\t%llu\n", 0, ulli);

	// Floating Points
	float fMin, fMax;
	double dMin, dMax, mantissa, exponent;
	
	mantissa = 1.0;
	exponent = 1.0;
	for (i = 0; i < 23; ++i)
	{
		mantissa /= 2;
	}
	
	for (i = 0; i < 127; ++i)
	{
		exponent *= 2;
	}

	fMin = (2 - mantissa) / exponent;
	fMax = (2 - mantissa) * exponent;
	printf("float\t\t\t%g\t\t%g\n", fMin, fMax);

	mantissa = 1.0;
	for (i = 0; i < 52; ++i)
	{
		mantissa /= 2;
	}

	exponent = pow(2, 1023);  
	dMin = (2 - mantissa) / exponent;
	dMax = (2 - mantissa) * exponent;
	printf("double\t\t\t%g\t\t%g\n", dMin, dMax);
}

void lib_macros(void)
{
	// Characters
	printf("signed char\t\t%i\t\t\t%i\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char\t\t%2i\t\t\t%u\n", 0, UCHAR_MAX);
	
	// Integers
	printf("signed short\t\t%i\t\t\t%i\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short\t\t%2i\t\t\t%u\n", 0, USHRT_MAX);
	printf("signed int\t\t%i\t\t%i\n", INT_MIN, INT_MAX);
	printf("unsigned int\t\t%2i\t\t\t%u\n", 0, UINT_MAX);
	printf("signed long\t\t%li\t%li\n", LONG_MIN, LONG_MAX);
	printf("unsigned long\t\t%2i\t\t\t%lu\n", 0, ULONG_MAX);
	printf("signed long long\t%lli\t%lli\n", LLONG_MIN, LLONG_MAX);
	printf("unsigned long long\t%2i\t\t\t%llu\n", 0, ULLONG_MAX);

	// Floating Points
	printf("float\t\t\t%g\t\t%g\n", FLT_MIN, FLT_MAX);
	printf("double\t\t\t%lg\t\t%lg\n", DBL_MIN, DBL_MAX);
	printf("long double\t\t%Lg\t\t%Lg\n", LDBL_MIN, LDBL_MAX);
}

void lib_ranges()
{
	// Integers & Characters 
	printf("signed char\t\t%.0f\t\t\t%.0f\n",
		pow(2, (sizeof(char) * 8 - 1)) * -1,
		pow(2, (sizeof(char) * 8) - 1) - 1);
	
	printf("unsigned char\t\t%2i\t\t\t%.0f\n", 0,
		pow(2, sizeof(unsigned char) * 8) - 1);

	printf("signed short\t\t%.0f\t\t\t%.0f\n",
		pow(2, (sizeof(short) * 8 - 1)) * -1,
		pow(2, (sizeof(short) * 8) - 1) - 1);
	
	printf("unsigned short\t\t%2i\t\t\t%0.f\n", 0,
		pow(2, sizeof(unsigned short) * 8) - 1);

	printf("signed int\t\t%.0f\t\t%.0f\n",
		pow(2, (sizeof(int) * 8 - 1)) * -1,
		pow(2, (sizeof(int) * 8) - 1) - 1);
	
	printf("unsigned int\t\t%2i\t\t\t%0.f\n", 0,
		pow(2, sizeof(unsigned int) * 8) - 1);

	printf("signed long\t\t%.0f\t%.0Lf\n",
		pow(2, (sizeof(long) * 8 - 1)) * -1,
		(long double) pow(2, (sizeof(long) * 8) - 1) - 1);
	
	printf("unsigned long\t\t%2i\t\t\t%0.Lf\n", 0,
		(long double)  pow(2, sizeof(unsigned long) * 8) - 1);

	printf("signed long long\t%.0f\t%.0Lf\n",
		pow(2, (sizeof(long long) * 8 - 1)) * -1,
		(long double) pow(2, (sizeof(long long) * 8) - 1) - 1);
	
	printf("unsigned long long\t%2i\t\t\t%0.Lf\n", 0,
		(long double) pow(2, sizeof(unsigned long long) * 8) - 1);

	// Floating points
	printf("float\t\t\t%g\t\t%g\n",
		(2 - pow(2, -23)) / pow(2, 127),(2 - pow(2, -23)) * pow(2, 127));
	
	printf("double\t\t\t%lg\t\t%lg\n\n",
		(2 - pow(2, -52)) / pow(2, 1023), (2 - pow(2, -52)) * pow(2, 1023));
}

void main(void)
{
	printf("\n\t=== === Manually Computed Values === ===\n");
	calc_ranges();

	printf("\n\t=== Values Computed Using Library Macros ===\n");
	lib_macros();
	
	printf("\n\t=== Values Computed Using Library Functions ===\n");
	lib_ranges();
}
