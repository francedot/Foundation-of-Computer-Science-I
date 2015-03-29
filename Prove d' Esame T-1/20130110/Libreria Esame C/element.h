//Bonacci Francesco 0900050944 Prova 1A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_TITOLO 1024
#define DIM_NOME_VALUTATORE 24
#define NUM_VOTI 3

typedef struct {

	int id;
	float finanziamentoRichiesto;
	char titolo[DIM_TITOLO];
	int voti[NUM_VOTI];

} Progetto;

typedef struct {

	char nomeValutatore[DIM_NOME_VALUTATORE];
	int idProgetto;
	int voto;

} Valutazione;

typedef Valutazione element;

typedef int boolean;

int compareProgetti(Progetto p1, Progetto p2);
//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif