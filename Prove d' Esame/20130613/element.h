//Bonacci Francesco 0900050944 Prova4A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//inclusioni base

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_CAUSALE 256

typedef struct {

	int idCliente;
	int idPagamento;
	float importoPagamento;
	char causalePagamento[DIM_CAUSALE];

} Pagamento;	//da rimappare (modificare nome Elemento --> Non element)

typedef Pagamento element;

typedef int boolean;

int compare(element el1, element el2);
boolean isEqual(element el1, element el2);
boolean isLess(element el1, element el2);
//element getElement();
//void printElement(element el);


#endif