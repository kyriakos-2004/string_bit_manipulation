#include <stdio.h>

unsigned rightrot(unsigned, int);
size_t int_size();

// depending on the architecture of the machine running this
// we are determining the size of the integer
size_t int_size()
{
	int x = ~0;
	size_t i = 0;

	while (x != 0) 
	{
		x <<= 1;
		++i;
	}

	return i;
}

unsigned rightrot(unsigned x, int n)
{
	unsigned size, bits;
	
	size = int_size();     
	n = n % size;             // modulo with size to make sure we are within range
	bits = x & ~(~0 << n);	  // determine the bits that are to be rotated

	return (x >> n) | bits << (size - n);
}

int main(void)
{
	unsigned x = 0X123ABC4F;
	int n = 8;

	printf("%x\n", rightrot(x, n));

	return 0;
}
