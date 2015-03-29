//Bonacci Francesco 0900050944

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