//Bonacci Francesco 0900050944 Prova 5A

#include "misure.h"

int main()
{
	//TEST ES.1

	/*FILE *fp;
	Giornaliero giornalieroLetto;

	if ((fp = fopen("staz15.txt", "rt")) == NULL) {

		perror("Errore apertura file stazione");
		system("pause");
		exit(-2);

	}

	giornalieroLetto = leggiSingoloGiorno(fp);
	stampaSingoloGiorno(giornalieroLetto);

	freeList(giornalieroLetto.rilevazioni);*/

	//TEST ES.2

	//Giornaliero *giornalieriLetti;
	//int dimGiornalieriLetti, i;

	//giornalieriLetti = leggiTuttiGiorni("staz15.txt", &dimGiornalieriLetti);

	//for (i = 0; i < dimGiornalieriLetti; i++) {
	//	stampaSingoloGiorno(giornalieriLetti[i]);
	//	freeList(giornalieriLetti[i].rilevazioni);
	//}

	//TEST ES.3

	/*int *dati;

	dati = frequenze();*/

	//PROGRAMMA PRINCIPALE

	int *dati;
	dati = frequenze();
	free(dati);

	system("pause");
	return 0;
}