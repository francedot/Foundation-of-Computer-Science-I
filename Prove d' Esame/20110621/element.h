//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_ID_SCOMMESSA 16
#define DIM_NOME_CLIENTE 24
#define DIM_COGNOME_CLIENTE 24

typedef struct {

	int anno, mese, giorno;

} Data;

typedef struct {

	int idCliente;
	char idScommessa[DIM_ID_SCOMMESSA];
	float importoScommessa;
	Data dataScommessa;

} Scommessa;

typedef struct {

	char nomeCliente[DIM_NOME_CLIENTE];
	char cognomeCliente[DIM_COGNOME_CLIENTE];
	int idCliente;
	Scommessa *scommesseCliente;
	int dimScommesseCliente;

} Cliente;

typedef Cliente element;

typedef int boolean;

int compareDate(Data d1, Data d2);
int compareScommesse(Scommessa s1, Scommessa s2);
//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif