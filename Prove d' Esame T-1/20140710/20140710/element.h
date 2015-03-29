//Bonacci Francesco 0900050944
#include <stdio.h>
#include <stdlib.h>

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define MAX_DESC 2048

typedef struct {

	int identificatore;
	float importo;
	char descrizione[MAX_DESC];

} Fattura;

typedef Fattura element;

typedef enum {
	TRUE, FALSE
} Boolean;

int compareFattura(Fattura f1, Fattura f2);
Boolean equals(Fattura f1, Fattura f2);
void scambia(Fattura *a, Fattura *b);

#endif