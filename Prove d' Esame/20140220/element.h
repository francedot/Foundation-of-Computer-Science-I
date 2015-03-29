//Bonacci Francesco 0900050944

#include <stdio.h>
#include <stdlib.h>

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_ID 16
#define DIM_DESC 2048

typedef struct {

	char id[DIM_ID];
	float prezzo;
	int numMinimo;
	char descrizione[DIM_DESC];

} Bene;	

typedef Bene element;

typedef int boolean;

int compare(element el1, element el2);
boolean isEqual(element el1, element el2);
boolean isLess(element el1, element el2);
void printElement(element el);

#endif