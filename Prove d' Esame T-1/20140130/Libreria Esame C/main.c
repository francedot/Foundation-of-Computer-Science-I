//Bonacci Francesco 0900050944

#include "aste.h"
#include <string.h>

int main()
{
	//scanf ' ' 

	//TEST ES.1
	/*list oggettiLetti, oggettiOrdinati;

	oggettiLetti = leggiOggetti("oggetti.txt");

	oggettiOrdinati = sortList(oggettiLetti);

	showList(oggettiOrdinati);*/

	//TEST ES.2

	//Offerta *offerteLette;
	//Oggetto og;
	//int dimLogica;

	//offerteLette = leggiOfferte("offerte.txt", og, &dimLogica);
	//stampaOfferte(offerteLette, dimLogica);

	//ordina(offerteLette, dimLogica);
	//stampaOfferte(offerteLette, dimLogica);

	//TEST ES.3

	/*Offerta *offerteFiltrate, *offerteLette;
	Oggetto og;
	int dim, *dimV;

	og.idOggetto = 57;
	og.dataChiusura.anno = 2014;
	og.dataChiusura.mese = 2;
	og.dataChiusura.giorno = 15;
	strcpy(og.descrizioneOggetto, "Pentola usata con calcare e manico rotto");

	offerteLette = leggiOfferte("offerte.txt", og, &dim);

	offerteFiltrate = filtra(offerteLette, dim, og, &dimV);*/

	//PROGRAMMA PRINCIPALE

	list oggettiLetti, oggettiOrdinati;
	Offerta *offerteLette, *offerteFiltrate, offertaVincitrice;
	int dimOfferteLette, dimOfferteFiltrate, i;
	float importoVincita;

	oggettiLetti = leggiOggetti("oggetti.txt");
	oggettiOrdinati = ordinaOggetti(oggettiLetti);

	while (!empty(oggettiOrdinati)) {

		offerteLette = leggiOfferte("offerte.txt", head(oggettiOrdinati), &dimOfferteLette);
		offerteFiltrate = filtra(offerteLette, dimOfferteLette, head(oggettiOrdinati), &dimOfferteFiltrate);

		if (dimOfferteFiltrate == 0) {

			printf("Nessuna offerta per l' oggetto n. %d\n", head(oggettiOrdinati).idOggetto);

		} else {

			importoVincita = 0.0f;

			for (i = 0; i < dimOfferteFiltrate; i++) {

				if (offerteFiltrate[i].importo > importoVincita) {

					offertaVincitrice = offerteFiltrate[i];

				}

			}

			printOfferta(offertaVincitrice);

		}

		oggettiOrdinati = tail(oggettiOrdinati);

	}

	freeList(oggettiLetti), freeList(oggettiOrdinati);
	free(offerteLette), free(offerteFiltrate);

	system("pause");

	return 0;
}