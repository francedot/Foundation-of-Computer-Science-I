//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#ifndef SCOMMESSE_H
#define SCOMMESSE_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
Scommessa * leggiScommesse(char* fileName, int *dim);
int giaPresente(Scommessa * v, int dim, Scommessa s);
void stampaScommesse(Scommessa * v, int dim);

//ES.2
Scommessa * seleziona(Scommessa v[], int dim, int codCliente, int *dimRes);
list leggiClienti(char * fileName, Scommessa v[], int dim);

//ES.3
void stampaAssidui(list l);


#endif