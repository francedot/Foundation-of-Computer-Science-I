//Bonacci Francesco 0900050944
#include "element.h"
#include <string.h>

//compareto ordine naturale crescente
int compareFattura(Fattura f1, Fattura f2)
{
	if (strcmp(f1.descrizione, f2.descrizione) != 0)
		return strcmp(f1.descrizione, f2.descrizione);
	else {
		if (f1.identificatore != f2.identificatore)
			return (f1.identificatore - f2.identificatore);
		else {
			if (f1.importo != f2.importo)
				return ( (f1.importo > f2.importo) ? 1 : -1 );
			else 
				return 0;
		}
	}
}

Boolean equals(Fattura f1, Fattura f2)
{
	return (compareFattura(f1, f2) == 0) ? TRUE : FALSE;
}

void scambia(Fattura *a, Fattura *b)
{
	Fattura tmp = *a;
	*a = *b;
	*b = tmp;
}