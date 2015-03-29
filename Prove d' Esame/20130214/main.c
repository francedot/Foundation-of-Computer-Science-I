//Bonacci Francesco 0900050944 Prova 3A

#include "rimborsi.h"

float calcImporto(Rimborso r);

int main()
{

	//TEST ES.1

	/*char nomeFile[DIM_MATRICOLA + 4];
	int dimSpeseLette, i;
	Spesa *speseLette;

	scriviSpese(nomeFile);

	speseLette = leggiSpese(nomeFile, &dimSpeseLette); 

	for (i = 0; i < dimSpeseLette; i++) {

		printf("%d %s %f.2%\n", speseLette[i].idSpesa, 
			speseLette[i].tipoSpesa, speseLette[i].importoSpesa);

	}
	free(speseLette);*/


	//TEST ES.2

	/*Spesa spese[4], sp1, sp2, sp3, sp4, *speseSingle;
	int newDim, i;

	sp1.idSpesa = 2;
	sp1.importoSpesa = 3.4f;
	strcpy(sp1.tipoSpesa, "tipo1");

	sp2.idSpesa = 2;
	sp2.importoSpesa = 3.4f;
	strcpy(sp2.tipoSpesa, "tipo2");

	sp3.idSpesa = 2;
	sp3.importoSpesa = 3.4f;
	strcpy(sp3.tipoSpesa, "tipo1");

	sp4.idSpesa = 1;
	sp4.importoSpesa = 3.4f;
	strcpy(sp4.tipoSpesa, "tipo1");

	spese[0] = sp1, spese[1] = sp2, spese[2] = sp3, spese[3] = sp4;

	ordina(spese, 4);
	speseSingle = eliminaDuplicati(spese, 4, &newDim);
	
	for (i = 0; i < newDim; i++) {

		printf("%d %s %.2f%\n", speseSingle[i].idSpesa, 
			speseSingle[i].tipoSpesa, speseSingle[i].importoSpesa);

	}
	free(speseSingle);*/

	//TEST ES.3

	/*list rimborsi;
	Spesa spese[5], sp1, sp2, sp3, sp4, sp5;

	sp1.idSpesa = 2;
	sp1.importoSpesa = 3.4f;
	strcpy(sp1.tipoSpesa, "tipo1");

	sp2.idSpesa = 2;
	sp2.importoSpesa = 3.4f;
	strcpy(sp2.tipoSpesa, "tipo2");

	sp3.idSpesa = 2;
	sp3.importoSpesa = 3.4f;
	strcpy(sp3.tipoSpesa, "tipo1");

	sp4.idSpesa = 1;
	sp4.importoSpesa = 3.4f;
	strcpy(sp4.tipoSpesa, "tipo1");

	sp5.idSpesa = 1;
	sp5.importoSpesa = 3.4f;
	strcpy(sp5.tipoSpesa, "tir1");

	spese[0] = sp1, spese[1] = sp2, spese[2] = sp3, spese[3] = sp4, spese[4] = sp5;

	rimborsi = creaRimborsi(spese, 5);*/

	//PROGRAMMA PRINCIPALE

	char nomeFile[DIM_MATRICOLA + 4];
	int dimSpeseLette, dimSpeseSingle;
	list rimborsi, temp;
	float importoTotale = 0.0f, importoRimborso;
	Spesa *speseLette, *speseSingle;

	scriviSpese(nomeFile);
	speseLette = leggiSpese(nomeFile, &dimSpeseLette);

	speseSingle = eliminaDuplicati(speseLette, dimSpeseLette, &dimSpeseSingle);
	free(speseLette);

	rimborsi = creaRimborsi(speseSingle, dimSpeseSingle);
	free(speseSingle);

	temp = rimborsi; //per successiva distruzione

	while (!empty(rimborsi)) {

		importoRimborso = calcImporto(head(rimborsi));
		importoTotale += importoRimborso;

		printf("Rimborso id. %d. Importo: %.2f\n", 
			head(rimborsi).idRimborso, importoRimborso);

		rimborsi = tail(rimborsi);

	}

	printf("\nImporto Totale: %.2f\n", importoTotale);

	freeList(temp);

	system("pause");
	return 0;
}

float calcImporto(Rimborso r) 
{
	int i;
	float importoRimborso = 0.0f;

	for (i = 0; i < r.numSpeseViaggio; i++) {

		importoRimborso += r.speseViaggio[i].importoSpesa;

	}

	return importoRimborso;
}