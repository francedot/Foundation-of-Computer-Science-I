//Bonacci Francesco 0900050944 Prova 2A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_NOME_PROVINCIA 3
#define DIM_NOME_DISTR 256
#define DIM_NOME_REGIONE 256

typedef struct {

	char provincia[DIM_NOME_PROVINCIA];
	char nome[DIM_NOME_DISTR];
	int prezzoBenzina, prezzoGasolio;

} Distributore;

typedef struct {

	char nome[DIM_NOME_PROVINCIA];

} Provincia;	//da rimappare (modificare nome Elemento --> Non element)

typedef Provincia element;

typedef int boolean;

//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
//void printElement(element el);


#endif