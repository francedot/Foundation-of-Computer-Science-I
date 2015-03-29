//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_NOME_PRODOTTO 36

typedef struct {

	char nomeProdotto[DIM_NOME_PRODOTTO];
	int puntiProdotto;

} Prodotto;

typedef struct {

	int idCliente;
	char nomeProdotto[DIM_NOME_PRODOTTO];
	int numAcquisti;

} Acquisto;

typedef Prodotto element;

typedef int boolean;

int compareAcquisti(Acquisto a1, Acquisto a2);
//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif