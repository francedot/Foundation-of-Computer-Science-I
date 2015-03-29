//Bonacci Francesco 0900050944 Prova4A

#include "element.h"

int compare(element el1, element el2)
{
	float result = el1.importoPagamento - el2.importoPagamento;

	if (result == 0.0f)
		return strcmp(el1.causalePagamento, el2.causalePagamento);
	else 
		return ((result < 0.0f) ? 1 : -1);
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