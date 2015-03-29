//Bonacci Francesco 0900050944 Prova 1A

#ifndef PROGETTI_H
#define PROGETTI_H

#include "list.h"
#include "utility.h"

//funzioni esame

//ES.1
Progetto * leggiProgetti(char* fileName, int *dim);
list leggiValutazioni(char* fileName);

//ES.2
void merge(Progetto * v, int dim, list valutazioni);
void ordina(Progetto * v, int dim);

//ES.3
Progetto * finanziati(Progetto * v, int dimV, int * dimR, float soldi);


#endif