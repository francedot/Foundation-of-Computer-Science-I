//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "utility.h"

int readField(char buffer[], char sep, FILE *f) //OK
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != 10 && ch != EOF)
	{
		buffer[i] = ch;
		i++;
		ch = fgetc(f);
	}

	buffer[i] = '\0';

	return i;
}