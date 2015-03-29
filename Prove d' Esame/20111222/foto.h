//Bonacci Francesco 0900050944 Prova 1A

#ifndef FOTO_H
#define FOTO_H

#include "list.h"

//funzioni esame

//ES.1
Foto * leggiFoto(char* fileName, int *dim);
list leggiTag(char* fileName);

//ES.2
void ordina(Foto * v, int dim);
void stampa(Foto * v, int dim, list tagList);

//ES.3
Foto * duplicati(Foto * v, int dimV, int * dimR);


#endif