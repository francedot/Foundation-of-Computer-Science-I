//Bonacci Francesco 0900050944 Prova 4A

#ifndef CLIENTE_H
#define CLIENTE_H

#include "list.h"
#include "utility.h"

//funzioni esame

//ES.1
list leggiClienti(char* fileName);
void stampaLista(list v);

//ES.2
Spesa * leggiSpese(char * fileName, int * dim);
void ordina(Spesa * v, int dim);

//ES.3
list eliminaRipetuti(list c);


#endif