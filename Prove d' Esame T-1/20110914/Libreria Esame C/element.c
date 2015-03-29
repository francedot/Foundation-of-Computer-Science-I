//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "element.h"

int compareRecord(Record r1, Record r2)
{
	int result = strcmp(r1.seriale, r2.seriale);
	
	if (result == 0)
		result = r1.istante - r2.istante;
	
	return result;
}

int compare(element el1, element el2)
{
	return strcmp(el1.cognome, el2.cognome);
}	 //compare != da isEqual

boolean isEqual(element el1, element el2)
{
	return ( strcmp(el1.seriale, el2.seriale) == 0 &&	//NAND
				 strcmp(el1.nome, el2.nome) == 0 &&
					 strcmp(el1.cognome, el2.cognome) == 0 );
}

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
	printf("%s %s %s\n", el.seriale, el.nome, el.cognome);
}