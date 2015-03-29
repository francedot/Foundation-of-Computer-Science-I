//Bonacci Francesco 0900050944 Prova 1A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_NOME_AUTORE 64
#define NUM_MAX_TAG 10
#define DIM_DESCR 64


typedef struct {

	int idTag;
	char descrizione[DIM_DESCR];

} Tag;

typedef struct {

	int idFoto;
	char nomeAutoreFoto[DIM_NOME_AUTORE];
	int idTag[NUM_MAX_TAG];
	int numTag;

} Foto;

typedef Tag element;

typedef int boolean;

int compareFoto(Foto f1, Foto f2);
//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
//void printElement(element el);


#endif