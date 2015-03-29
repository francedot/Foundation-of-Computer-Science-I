//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#ifndef PRODOTTI_H
#define PRODOTTI_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
list leggiProdotti(char* fileName);
void stampaProdotti(list l);
int punteggio(list l, char * nome);

//ES.2
Acquisto * leggiAcquisti(char * fileName, int * dim);
void stampaAcquisti(Acquisto * v, int dim);

//ES.3
Acquisto * filtraEOrdina(Acquisto * v, int dim, int *dimResult);


#endif