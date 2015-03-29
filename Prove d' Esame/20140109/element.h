//Bonacci Francesco 0900050944 Prova1A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_NOME_RICETTA 64
#define DIM_NOME_INGREDIENTE 128
#define NUM_INGREDIENTI_MAX 10

typedef struct {

	char nomeIngrediente[DIM_NOME_INGREDIENTE];
	int quantitaIngrediente;

} Ingrediente;

typedef struct {

	char nomeRicetta[DIM_NOME_RICETTA];
	int numIngredientiUsati;
	Ingrediente ingredientiRicetta[NUM_INGREDIENTI_MAX];

} Ricetta;

typedef Ingrediente element;

typedef int boolean;

int compareRicette(Ricetta r1, Ricetta r2);

int compare(element el1, element el2);
boolean isEqual(element el1, element el2);
boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif