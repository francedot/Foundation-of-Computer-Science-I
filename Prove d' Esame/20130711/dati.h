//Bonacci Francesco 0900050944 Prova 5A

#ifndef DATI_H
#define DATI_H

#include "list.h"
#include "utility.h"

//funzioni esame

//ES.1
list leggiT(char * nomeFile);
void showlist(list l1);

//ES.2
list ordina(list t, char * nome, int * dim);
void scambia(int *a, int *b);
int trovaPosMax(int v[], int n);
void naiveSort(int v[], int n);
int * elenca(list t, int dim);

//ES.3
void truffe(list t);


#endif