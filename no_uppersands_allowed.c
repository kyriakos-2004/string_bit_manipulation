/* This exercise is meant to show that we can replace the &&
 * and the || with something else. I figured out two ways;
 * the first way is to pass it to the pre-processor and the
 * second way is to replace it with if statements
 */


==============================================================
/* First way */
==============================================================
#include <stdio.h>

#define MAXLINE 100 
#define AND &&
#define OR ||

int theInput(char [], int);

// This function reads a line and retunrs its length
int theInput(char s[], int upperbound)
{
	int c, i, halt;

	halt = 0;

	for (i=0; i < upperbound-1 AND (c=getchar()) != ’\n’ AND c != EOF; i++)
	{
		s[i] = c;
	}
	
	if (c == '\n' OR c == '$')
	{
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}

void main(void)
{
	char line[MAXLINE];

	while (theInput(line, MAXLINE) > 0)
	{
		printf("%s", line);
	}
}


==============================================================
/* Second way */
==============================================================
/*
#include <stdio.h>

#define MAXLINE 100

int theInput(char [], int);*/

// This function reads a line and returns its length 
/*int theInput(char s[], int upperbound)
{
	int c, i, halt;

	halt = 0;
	for (i = 0; !halt; ++i) 
	{
		if (i > upperbound - 1)
		{
			halt = 1;
		}
		else if ((c = getchar()) == '\n')
		{
			halt = 1;
		}
		else if (c == EOF)
		{
			halt = 1;
		}
		else
		{
			s[i] = c;
		}
	}
	i--;

	if (c == '\n')
	{
		s[i++] = c;
	}

	if (c == '$')
	{
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}

void main(void)
{
	char line[MAXLINE];

	while (theInput(line, MAXLINE) > 0)
	{
		printf("%s", line);
	}
}*/
