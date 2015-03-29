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

int compare(element el1, element el2)
{
	int result = strcmp(el1.idAzione, el2.idAzione);

	if (result == 0)
		result = compareDate(el1.dataOperazione, el2.dataOperazione);

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

void printElement(element el)
{
	printf("%s %d %d %d %d %d\n", el.idAzione, 
				el.prezzoAzione, el.numAzioniVendute, 
					el.dataOperazione.giorno, el.dataOperazione.mese, 
						el.dataOperazione.anno);
}