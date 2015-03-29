//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "element.h"

int compareDate(Data d1, Data d2)
{
	int result = d1.anno - d2.anno;

	if (result == 0) {

		result = d1.mese - d2.mese;

		if (result == 0)
			result = d1.giorno - d2.giorno;

	}

	return result;
}
int compareScommesse(Scommessa s1, Scommessa s2)
{
	return compareDate(s1.dataScommessa, s2.dataScommessa);
}
//int compare(element el1, element el2)
//{
//	int result = el1.prop - el2.prop;
//
//	return result;
//}

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

void printElement(element el)
{
	printf("%s %s %d\n", el.nomeCliente, el.cognomeCliente, el.idCliente);
}