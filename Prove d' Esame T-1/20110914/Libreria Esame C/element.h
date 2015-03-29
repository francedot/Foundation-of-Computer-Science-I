//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_SERIALE 16
#define DIM_IP 16
#define DIM_NOME 64
#define DIM_COGNOME 64

typedef struct {

	char seriale[DIM_SERIALE];
	int istante;
	char ip[DIM_IP];

} Record;

typedef struct {

	char seriale[DIM_SERIALE];
	char nome[DIM_NOME];
	char cognome[DIM_COGNOME];

} Cliente;

typedef Cliente element;

typedef int boolean;

int compareRecord(Record r1, Record r2);
int compare(element el1, element el2);
boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printElement(element el);


#endif