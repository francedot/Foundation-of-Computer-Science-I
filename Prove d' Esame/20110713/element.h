//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_ID 24

typedef struct {

	int giorno, mese, anno;

} Data;

typedef struct {

	char idAzione[DIM_ID];
	int prezzoAzione;
	int numAzioniVendute;
	Data dataOperazione;

} Vendita;

typedef Vendita element;

typedef int boolean;

int compareDate(Data d1, Data d2);
int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif