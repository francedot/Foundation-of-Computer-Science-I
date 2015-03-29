//Bonacci Francesco 0900050944 Prova6A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_CODICE_CLIENTE 7
#define DIM_SIGLA_AEREOPORTO 4
#define DIM_CODICE_VOLO 6

typedef struct {

	char codiceCliente[DIM_CODICE_CLIENTE];
	char siglaAereoportoP[DIM_SIGLA_AEREOPORTO];
	char siglaAereoportoA[DIM_SIGLA_AEREOPORTO];
	int giornoPartenza;
	char codiceVolo[DIM_CODICE_VOLO];

} Volo;	//da rimappare (modificare nome Elemento --> Non element)

typedef Volo element;

typedef char String[7];
typedef int boolean;

int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
//void printElement(element el);


#endif