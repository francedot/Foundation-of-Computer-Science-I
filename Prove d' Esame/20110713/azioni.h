//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#ifndef AZIONI_H
#define AZIONI_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
Vendita * leggiVendite(char* fileName, int *dim);
void ordina(Vendita * v, int dim);
void stampaVendite(Vendita * v, int dim);

//ES.2
void speculazioni(Vendita * v, int dim);

//ES.3
list selezionaVenditeMaggiori(Vendita * v, int dim);
void stampaListaVendite(list l);


#endif