//Bonacci Francesco 0900050944 Prova 5A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_TITOLO 1024
#define DIM_NOMECOGNOME 1024
#define JOLLY ';'

typedef struct {

	int idTransazione;
	char titoloLibro[DIM_TITOLO];
	char nomeCognome[DIM_NOMECOGNOME];
	char stato;

} Transazione;

typedef Transazione element;

typedef char StringaNomeCognome[DIM_NOMECOGNOME];
typedef int boolean;

int compare(element el1, element el2);
boolean isEqual(element el1, element el2);
boolean isLess(element el1, element el2);
//element getElement();
//void printElement(element el);


#endif