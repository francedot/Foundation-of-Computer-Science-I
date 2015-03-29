//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "element.h"

//tale vettore sia ordinato in maniera crescente in base al codice identificativo
//del cliente; in caso di parità di codice identificativo, si consideri il nome del prodotto e si utilizzi il criterio
//lessicografico (ancora in senso crescente).
int compareAcquisti(Acquisto a1, Acquisto a2)
{
	int result = a1.idCliente - a2.idCliente;

	if (result == 0)
		result = strcmp(a1.nomeProdotto, a2.nomeProdotto);

	return result;
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
	printf("%s %d\n", el.nomeProdotto, el.puntiProdotto);
}