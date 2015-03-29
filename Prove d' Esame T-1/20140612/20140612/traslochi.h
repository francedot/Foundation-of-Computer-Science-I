#include "list.h"

#define MAX_ORE 8

list leggiTraslochi(char* fileName);
void stampaTraslochi(list elenco);
list ordina(list elenco);
list filtra(list elenco, int giorno);
int * giorni(list elenco, int * dim);
void scambia(int *a, int *b);
void bubbleSort(int v[], int n);
list diff(list l1, list l2);
list elimina(list elenco);