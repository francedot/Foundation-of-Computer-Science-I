//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#ifndef CLIENTI_H
#define CLIENTI_H

#include "list.h"
#include "utility.h"

//funzioni esame

//ES.1
Cliente * leggiClienti(char* fileName, int * dim);
void stampaClienti(Cliente * v, int dim);

//ES.2
list leggiPref(char * fileName);
void stampaPref(list l);

//ES.3
int cerca(list l, int id, char * keyword);
int isEqual(Pref p1, Pref p2);


#endif