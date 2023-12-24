#include <stdio.h>
#include "setbits_invert.h"

unsigned int setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned nbits;
	nbits = ~(~0 << n); // mask that extracts the n rightmost bits

	// returns the result of an or statement
	// so that to ensure a return in case of overflow
	return (x & ~(nbits << p)) | ((y & nbits) << p); 
}

unsigned int invert(unsigned int x, int p, int n)
{
	unsigned nbits;
	
	nbits = ~(~0 << n); // mask that extracts the n rightmost bits

	// returns the result of an or statement
	// so that to ensure a return in case of overflow
	return (x & ~(nbits << p)) | (nbits & ~(x & nbits << p));
}

int main(void)
{
	unsigned x = 0X123456;
	unsigned y = 0XABCDEF;
	int p = 8;                   // starting position of bits 
	int n = 8;                   // number of bits to set 

	printf("Calling setbits...\n");
	printf("%x\n", setbits(x, p, n, y)); 
	printf("Calling invert...\n");
	printf("%x\n", invert(x, p, n)); 
	
	return 0;
}

