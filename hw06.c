/*
 *lists ciphertxts for each key in keyspace of Caesar's cipher
 *encrypts first argumement txt or, without argument, Hw6 txt
 *encrypts only letters, leaves everything else anlone
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw06.h"

int main (int argc, char *argv[])
{
	//check usage
	if (argc >= 3)
	{
		fprintf(stderr,"Usage: %s \"text\"\n", argv[0]);
		exit(1);
	}

	//if no arguments, use text from homework #6
	else if (argc == 1)
	{
		char message[] = "Libi imycibqwvm ycwbkcvycm ntcmvbma ycivbqbibma"
    				 " qvdwtdmvbm, ntcfqwvma qvdmvqzm: mb dqkm dmzai";
		for (int i = 1; i <= KEYSPACE; i++)
		{
			printf("key %2d\nciphertxt: ", i);
			caesar(i, message);
		}
		printf("\"key = 18 looks Latin to me\"\n\n");
	}

	//if present, use first argument as text 
	else if (argc == 2)
	{
		for (int i = 1; i <= KEYSPACE; i++)
		{
			printf("key %2d\nciphertxt: ", i);
			caesar(i, argv[1]);
		}
	}
	return 0;
}


