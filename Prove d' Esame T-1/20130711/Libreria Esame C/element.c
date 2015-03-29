//Bonacci Francesco 0900050944 Prova 5A

#include "element.h"

int compare(element el1, element el2)
{
	return (strcmp(el1.titoloLibro, el2.titoloLibro));
}

boolean isEqual(element el1, element el2)
{
	return (compare(el1, el2) == 0);
}

boolean isLess(element el1, element el2)
{
	return (compare(el1, el2) < 0);
}

//element getElement()
//{
//	element el;
//	scanf("%d", &el.prop);
//	return el; 
//}

//void printElement(element el)
//{
//	printf("%d", el.prop);
//}