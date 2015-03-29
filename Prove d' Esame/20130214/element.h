//Bonacci Francesco 0900050944 Prova 3A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_TIPO_SPESA 1024
#define DIM_MATRICOLA 8

typedef struct {

	int idSpesa;
	char tipoSpesa[DIM_TIPO_SPESA];
	float importoSpesa;

} Spesa;

typedef struct {

	int idRimborso;
	Spesa *speseViaggio;
	int numSpeseViaggio;

} Rimborso;	//da rimappare (modificare nome Elemento --> Non element)

typedef Rimborso element;

typedef int boolean;

int compareSpese(Spesa sp1, Spesa sp2);
int compare(element el1, element el2);
boolean isEqual(element el1, element el2);
boolean isLess(element el1, element el2);
//element getElement();
//void printElement(element el);


#endif