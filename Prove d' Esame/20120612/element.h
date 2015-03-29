//Bonacci Francesco 0900050944 Prova 4A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_COGNOME 256
#define DIM_NOME 256
#define DIM_NOME_FILE 13
#define DIM_DESCR_SPESA 256

typedef struct {

	char cognome[DIM_COGNOME];
	char nome[DIM_NOME];
	char nomeFile[DIM_NOME_FILE];
	int redditoAnnuale;

} Cliente;

typedef struct {

	int importo;
	char descrizione[DIM_DESCR_SPESA];
	char detraibilile;

} Spesa;

typedef Cliente element;

typedef char StringaNomeFile[DIM_NOME_FILE];

typedef int boolean;

int compareSpese(Spesa sp1, Spesa sp2);
//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif