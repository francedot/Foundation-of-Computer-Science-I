//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_KEYWORD 16
#define DIM_INDIRIZZO 128

typedef struct {

	int idCliente;
	char indirizzoCliente[DIM_INDIRIZZO];
	int cap;

} Cliente;

typedef struct {

	int idCliente;
	char keyWord[DIM_KEYWORD];

} Pref;	//da rimappare (modificare nome Elemento --> Non element)

typedef Pref element;

typedef int boolean;

int compareClienti(Cliente c1, Cliente c2);
//int compare(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
//void printElement(element el);


#endif