//Bonacci Francesco 0900050944

#include <stdio.h>
#include <stdlib.h>

#ifndef _ELEMENT_H
#define _ELEMENT_H

#define DIM_DESC_OGGETTO 256

typedef struct {

	int anno, mese, giorno;

} Data;	//da rimappare (modificare nome Elemento --> Non element)

typedef struct {

	int idOggetto;
	Data dataChiusura;
	char descrizioneOggetto[DIM_DESC_OGGETTO];

} Oggetto;

typedef struct {

	int idCliente, idOggetto;
	Data dataEffettuata;
	float importo;

} Offerta;

typedef Oggetto element;

typedef int boolean;

int compareDate(Data d1, Data d2);
int compareOfferte(Offerta of1, Offerta of2);
int compareOggetti(element el1, element el2);
//boolean isEqual(element el1, element el2);
//boolean isLess(element el1, element el2);
//element getElement();
void printOggetto(Oggetto og);
void printOfferta(Offerta of);


#endif