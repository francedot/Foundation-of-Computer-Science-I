//Bonacci Francesco 0900050944
#include "list.h"

list leggiBeni(char* fileName);
list ordinaBeni(list elenco);
void stampaBeni(list elenco);
Bene * estrai(list elenco, char * keyword, int * dim);
void merge(Bene v[], int i1, int i2, int fine, Bene vout[]);
void mergeSort(Bene v[], int first, int last, Bene vout[]);
void ordina(Bene * v, int dim);
void stampaVettBeni(Bene * iBeni, int dim);
boolean isValid(Bene bene, int num, float budget);
Bene effettivo(list elenco, char * keyword, int num, float budget);