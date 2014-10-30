/*
 *encrypts message[] of abitrary length with caesar cipher
 *using given key.  only encrypts letters
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hw06.h"

void caesar (int key, char message[])
{
	//allocate an array of chars as long as the message + 1
	int messlen = strlen(message);
	char *buff = (char *) (malloc(sizeof(char) * messlen + 1));

	//check memory
	if (buff == NULL)
	{
		fprintf(stderr, "caesar: ERROR, out of memory\n");
		exit(1);
	}

	//check "key" is in "KEYSPACE" 
	if ((key <= 0) || (key > KEYSPACE))
	{
		fprintf(stderr,"ceasar: key must be integer, 1 <= key <= %2d\n", KEYSPACE);
		exit(1);
	}

	//copy what "message" points to (message text), to array that "buff" points to,
	//number of chars to be copied is the length of the message plus a terminator
	strncpy(buff, message, messlen + 1);

	//implement cispher
	char c;
	int linebreak = 0;
	for (int i = 0; i <= messlen ; i++)
	{
		c = buff[i];
		if (islower(c))
		{
			c = 'a' + (c - 'a' + key) %KEYSPACE;
		}
		else if (isupper(c))
		{
			c = 'A' + (c - 'A' + key) %KEYSPACE;
		}
		//linebreak when on space and more than 50 chars since last linebreak
		//if true set new linebreak, newline, tab, and 2 spaces to line up txt
		else if (buff[i] == ' ' && i - linebreak > 50)
		{
			linebreak = i;
			printf("\n\t  ");
		}

		//print encrypted char	
		printf("%c", c);
	}
	printf("\n\n");

	//deallocate memory
	free (buff);
}
