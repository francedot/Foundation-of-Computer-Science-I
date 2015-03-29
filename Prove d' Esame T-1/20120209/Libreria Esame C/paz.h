//Bonacci Francesco 0900050944 Prova 6A

#ifndef PAZ_H
#define PAZ_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
list leggiPazienti(char* fileName);
void stampaLista(list v);

//ES.2
Esame * leggiEsami(char * fileName, int * dim);
void ordina(Esame * v, int dim);

//ES.3
void ripetuti(list pazienti, Esame * vEsame, int dim);


#endif