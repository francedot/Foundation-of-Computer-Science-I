//Bonacci Francesco 0900050944 Prova 5A

#ifndef MISURE_H
#define MISURE_H

#include "list.h"
//#include "utility.h"

typedef struct {

	int giorno;
	list rilevazioni;

} Giornaliero;


//ES.1
Giornaliero leggiSingoloGiorno(FILE* fp);
void stampaSingoloGiorno(Giornaliero m);

//ES.2
Giornaliero * leggiTuttiGiorni(char * fileName, int * dim);

//ES.3
int * frequenze();

#endif