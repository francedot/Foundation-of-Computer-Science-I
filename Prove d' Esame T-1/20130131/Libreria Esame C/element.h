//Bonacci Francesco 0900050944 Prova 2A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_NOME_FARMACO 256
#define DIM_NOME_PRINCIPIO 256

typedef struct {

	char nome[DIM_NOME_FARMACO];
	char nomePrincipio[DIM_NOME_PRINCIPIO];
	int quantitaPrincipio;
	int numConfezioni;

} Farmaco;

typedef struct {

	char nomeFarmaco[DIM_NOME_FARMACO];
	int numConfezioni;

} Prescrizione;

typedef Prescrizione element;

typedef int boolean;

int compareFarmaco(Farmaco f1, Farmaco f2);
//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif