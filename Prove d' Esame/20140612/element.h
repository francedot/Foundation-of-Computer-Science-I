#include <stdio.h>
#include <stdlib.h>
#include <string.h> //a seconda situazione compare

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_CLIENTE 256

typedef struct {

	char cliente[DIM_CLIENTE];
	int giorno, stima;

} Trasloco;

typedef Trasloco element;

int compareTrasloco(Trasloco t1, Trasloco f2);
//boolean equals(Trasloco f1, Trasloco f2);
//void scambia(Trasloco *a, Trasloco *b);

#endif