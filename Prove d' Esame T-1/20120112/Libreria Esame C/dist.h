//Bonacci Francesco 0900050944 Prova 2A

#ifndef DIST_H
#define DIST_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
Distributore * leggiDistributori(char* fileName, int *dim);
void stampaDist(Distributore * v, int dim);

//ES.2
list estrai(char * fileName, char * regione);
void ordina(Distributore * v, int dim);
void diminuisci(char * dest, char * source);

//ES.3
Distributore * economico(Distributore * v, int dimV, list elenco, int * dimR);


#endif