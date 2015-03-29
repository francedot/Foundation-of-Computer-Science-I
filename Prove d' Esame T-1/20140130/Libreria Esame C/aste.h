//Bonacci Francesco 0900050944

#include "list.h"

Data leggiData(FILE *fp);
list leggiOggetti(char* fileName);
list ordinaOggetti(list elenco);
void stampaOggetti(list elenco);
Offerta * leggiOfferte(char * fileName, Oggetto target, int * dim);
void stampaOfferte(Offerta * leOfferte, int dim);
void scambia(Offerta *a, Offerta *b);
void quickSortR(Offerta a[], int iniz, int fine);
void quickSort(Offerta a[], int dim);
void ordina(Offerta * v, int dim);
Offerta * filtra(Offerta * leOfferte, int dim, Oggetto target, int * dimV);