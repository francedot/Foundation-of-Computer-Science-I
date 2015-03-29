//Bonacci Francesco 0900050944 Prova6A

#ifndef ESAME_H
#define ESAME_H

#include "list.h"
//#include "utility.h"


//ES.1

Volo * leggiVoli(char * nomeFile, int * dim);
void stampaVoli(Volo * lista, int dim);
int equals(Volo v1, Volo v2);


//ES.2

void scambia(Volo *a, Volo *b);
void bubbleSort(Volo v[], int n);
Volo * filtra(Volo * elenco, int dimV, char * partenza, int * dimR);
boolean contains(list l, element el);
list selCliente(Volo * v, int dim, char * cliente);


//ES.3

void freq(Volo * v, int dim, char * partenza);


#endif