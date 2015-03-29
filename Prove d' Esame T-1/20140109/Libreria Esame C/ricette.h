//Bonacci Francesco 0900050944 Prova1A

#ifndef RICETTE_H
#define RICETTE_H

#include "list.h"

Ingrediente leggiIngrediente(FILE * fp);
Ricetta * leggiRicette(char* fileName, int *dim);
void stampaRicette(Ricetta* leRicette, int dim);
list leggiDieta(char * fileName);
void stampaDieta(list laDieta);
void ordina(Ricetta * v, int dim);
int ricettaCompatibile(Ricetta r, list laDieta);
int ingredienteCompatibile(Ingrediente ing, list laDieta);
Ricetta * filtra(Ricetta * leRicette, int dim, list laDieta, int * dimR);

#endif