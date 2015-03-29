//Bonacci Francesco 0900050944 Prova 6A

#include "element.h"

//in base al codice identificativo unico del paziente, poi in base al nome dell’esame clinico (in ordine
//lessicografico), ed infine in base all’anno in cui l’esame è stato effettuato (in senso crescente).
int compareEsami(Esame es1, Esame es2)
{
	int result = es1.idPaziente - es2.idPaziente;

	if (result == 0) {

		result = strcmp(es1.nomeEsame, es2.nomeEsame);

		if (result == 0)
			result = es1.annoEsame - es2.annoEsame;

	}

	return result;
}

int compare(element el1, element el2)
{
	int result = strcmp(el1.cognomePaziente, el2.cognomePaziente);

	if (result == 0)
		result = strcmp(el1.nomePaziente, el2.nomePaziente);

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
	printf("%s %s %d\n", el.nomePaziente, el.cognomePaziente, el.idPaziente);
}