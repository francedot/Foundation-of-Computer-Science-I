//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "azioni.h"

int main()
{
	//TEST ES.1

	/*Vendita *venditeLette;
	int dimVenditeLette;

	venditeLette = leggiVendite("log.txt", &dimVenditeLette);
	stampaVendite(venditeLette, dimVenditeLette);

	printf("\n");

	ordina(venditeLette, dimVenditeLette);
	stampaVendite(venditeLette, dimVenditeLette);

	free(venditeLette);*/


	//TEST ES.2

	/*Vendita *venditeLette;
	int dimVenditeLette;

	venditeLette = leggiVendite("log.txt", &dimVenditeLette);
	ordina(venditeLette, dimVenditeLette);
	
	speculazioni(venditeLette, dimVenditeLette);
	free(venditeLette);*/


	//TEST ES.3

	/*list venditeMaggiori;
	Vendita *venditeLette;
	int dimVenditeLette;

	venditeLette = leggiVendite("log.txt", &dimVenditeLette);
	ordina(venditeLette, dimVenditeLette);
	
	venditeMaggiori = selezionaVenditeMaggiori(venditeLette, dimVenditeLette);
	free(venditeLette);

	stampaListaVendite(venditeMaggiori);
	freeList(venditeMaggiori);*/


	//PROGRAMMA PRINCIPALE

	list venditeMaggiori;
	Vendita *venditeLette;
	int dimVenditeLette;

	venditeLette = leggiVendite("log1.txt", &dimVenditeLette);
	ordina(venditeLette, dimVenditeLette);
	
	venditeMaggiori = selezionaVenditeMaggiori(venditeLette, dimVenditeLette);
	
	printf("Vendite di importo maggiore per titolo azionario: \n");
	stampaListaVendite(venditeMaggiori);
	freeList(venditeMaggiori);

	printf("\nNomi titoli soggetti a speculazioni: \n");
	speculazioni(venditeLette, dimVenditeLette);
	free(venditeLette);	

	printf("\n");

	system("pause");
	return 0;
}