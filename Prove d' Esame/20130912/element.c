//Bonacci Francesco 0900050944 Prova6A

#include "element.h"

int compare(element el1, element el2)
{
	int result = el1.giornoPartenza - el2.giornoPartenza;

	if (result == 0) {

		result = strcmp(el1.codiceVolo, el2.codiceVolo);

	}

	return result;
}

//boolean isEqual(element el1, element el2)
//{
//	return (compare(el1, el2) == 0);
//}

//boolean isLess(element el1, element el2)
//{
//	return (compare(el1, el2) < 0);
//}

//element getElement()
//{
//	element el;
//	scanf("%d", &el.prop);
//	return el; 
//}

//void printElement(element el)
//{
//	printf("d");
//}