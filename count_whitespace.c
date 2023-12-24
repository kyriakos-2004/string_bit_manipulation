#include <ctype.h>
#include <stdio.h>

/* Whitespace characters are considered the following:
 * ‘ ‘ – Space
 * ‘\t’ – Horizontal tab
 * ‘\n’ – Newline
 * ‘\v’ – Vertical tab
 * ‘\f’ – Feed
 * ‘\r’ – Carriage return
*/

void main()
{
	int white_space = 0, i = 0;
	char the_string[100] = "My name is Kyriakos but they   call me Koulis.	Gaming and coding are parts of my daily			life";
	char st = the_string[0];
	while(st != '\0') 
	{
    		st = the_string[i];

		if(st ==' ' || st == '\n' || st =='\t' || st == '\v' || st == '\f' || st == '\r') 
		{
      			white_space++;
		}
		i++;
  	}

	printf("Number of spaces that exist in the given sentence: %d\n", white_space);
}
