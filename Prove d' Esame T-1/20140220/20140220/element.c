//Bonacci Francesco 0900050944

#include "element.h"
#include <string.h>

int compare(element el1, element el2)
{

	if (strcmp(el1.descrizione, el2.descrizione) == 0) {

		if (el1.prezzo < el2.prezzo)
			return -1;
		else if (el1.prezzo > el2.prezzo)
			return 1;
		else 
			return 0;

	} else {

		return (strcmp(el1.descrizione, el2.descrizione));
	}

}

boolean isEqual(element el1, element el2)
{
	return (compare(el1, el2) == 0);
}

boolean isLess(element el1, element el2)
{
	return (compare(el1, el2) < 0);
}

void printElement(element el) 
{
	printf("%s %f %d %s\n", el.id, 
				el.prezzo, el.numMinimo, el.descrizione);
}