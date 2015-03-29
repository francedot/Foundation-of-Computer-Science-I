//Bonacci Francesco 0900050944
#include "element.h"
#include "list.h"

Fattura leggiUnaFattura(FILE * fp);
list leggiDaTastiera();
void salvaFatture(char * fileName, list elenco);
Fattura* leggiDaFile(char * fileName, int * dim);
void ordina(Fattura * elenco, int dim);
void quickSortR(Fattura *elenco, int inizio, int fine);
Fattura * ripetuti(Fattura * elenco, int dim, int * newDim);
float totali(Fattura * elenco, int dim, char * sub);