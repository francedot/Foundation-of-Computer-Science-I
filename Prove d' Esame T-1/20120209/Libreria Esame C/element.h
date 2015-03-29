//Bonacci Francesco 0900050944 Prova 6A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_NOME_PAZIENTE 256
#define DIM_COGNOME_PAZIENTE 256
#define DIM_NOME_ESAME 256

typedef struct {

	char nomePaziente[DIM_NOME_PAZIENTE];
	char cognomePaziente[DIM_COGNOME_PAZIENTE];
	int idPaziente;

} Paziente;	

typedef struct {

	int idPaziente;
	char nomeEsame[DIM_NOME_ESAME];
	int annoEsame;

} Esame;

typedef Paziente element;

typedef int boolean;

int compareEsami(Esame es1, Esame es2);
int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif