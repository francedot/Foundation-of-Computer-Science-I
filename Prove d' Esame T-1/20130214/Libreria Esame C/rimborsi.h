//Bonacci Francesco 0900050944 Prova 3A

#ifndef RIMBORSI_H
#define RIMBOSI_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
void scriviSpese(char * nomeFile);
Spesa * leggiSpese(char * nomeFile, int * dim);

//ES.2
void ordina(Spesa * v, int dim);
Spesa * eliminaDuplicati(Spesa * v, int dim, int * dimNew);

//ES.3
list creaRimborsi(Spesa * v, int dim);


#endif