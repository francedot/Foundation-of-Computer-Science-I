//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#ifndef INFO_H
#define INFO_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
Record * leggiRecord(char* fileName, int *dim);
Cliente * leggiClienti(char* fileName, int *dim);
void ordina(Record * v, int dim);

//ES.2
list clientiAttivi(Record * r, int dimR, Cliente * C, int dimC);
void stampaListaClienti(list l);

//ES.3
list illeciti(Record * r, int dimR, Cliente * c, int dimC);


#endif