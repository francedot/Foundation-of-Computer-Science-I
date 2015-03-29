//Bonacci Francesco 0900050944 Prova 2A

#ifndef MAGAZZINO_H
#define MAGAZZINO_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
Farmaco * leggiMagazzino(char* fileName, int *dim);
void scriviMagazzino(char* fileName, Farmaco * v, int dim);
int ordina(Farmaco * v, int dim);

//ES.2
list leggiRicetta(char * fileName);
int disponibile(Farmaco * v, int dim, Prescrizione p);

//ES.3
int trovaGenerico(Farmaco * v, int dim, Prescrizione p);
int accettabile(Farmaco * v, int dim, list ricetta);


#endif