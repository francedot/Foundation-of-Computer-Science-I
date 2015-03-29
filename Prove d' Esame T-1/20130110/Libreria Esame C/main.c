//Bonacci Francesco 0900050944 Prova 1A

#include "progetti.h"

int main()
{
	//TEST ES.1

	//Progetto *progettiLetti;
	//list valutazioniLette;
	//int dimProgettiLetti, i;

	//progettiLetti = leggiProgetti("progetti.txt", &dimProgettiLetti);

	//for (i = 0; i < dimProgettiLetti; i++) {

	//	printf("%d %.2f %s\n", progettiLetti[i].id, 
	//		progettiLetti[i].finanziamentoRichiesto, progettiLetti[i].titolo);

	//}
	//free(progettiLetti);

	//valutazioniLette = leggiValutazioni("valutazioni.txt");

	//showList(valutazioniLette);
	//freeList(valutazioniLette);


	//TEST ES.2

	//Progetto *progettiLetti;
	//list valutazioniLette;
	//int dimProgettiLetti, i, j;

	//progettiLetti = leggiProgetti("progetti.txt", &dimProgettiLetti);
	//valutazioniLette = leggiValutazioni("valutazioni.txt");

	//merge(progettiLetti, dimProgettiLetti, valutazioniLette);
	//freeList(valutazioniLette);

	//for (i = 0; i < dimProgettiLetti; i++) {

	//	printf("%d %.2f %s\n", progettiLetti[i].id, progettiLetti[i].finanziamentoRichiesto, progettiLetti[i].titolo);
	//	
	//	for (j = 0; j < NUM_VOTI; j++)
	//		printf("%d\n", progettiLetti[i].voti[j]);

	//}

	//ordina(progettiLetti, dimProgettiLetti);
	//printf("\n");
	//for (i = 0; i < dimProgettiLetti; i++) {

	//	printf("%d %.2f %s\n", progettiLetti[i].id, progettiLetti[i].finanziamentoRichiesto, progettiLetti[i].titolo);
	//	
	//	for (j = 0; j < NUM_VOTI; j++)
	//		printf("%d\n", progettiLetti[i].voti[j]);

	//}
	//free(progettiLetti);


	//TEST ES.3

	//list valutazioniLette;
	//Progetto *progettiLetti, *progettiFinanziati;
	//int dimProgettiLetti, dimProgettiFinanziati, i;

	//progettiLetti = leggiProgetti("progetti.txt", &dimProgettiLetti);
	//valutazioniLette = leggiValutazioni("valutazioni.txt");
	//
	//merge(progettiLetti, dimProgettiLetti, valutazioniLette);
	//freeList(valutazioniLette);

	//progettiFinanziati = finanziati(progettiLetti, dimProgettiLetti, &dimProgettiFinanziati, 5000000);
	//free(progettiLetti);

	//for (i = 0; i < dimProgettiFinanziati; i++) {

	//	printf("%d %.2f %s\n", progettiFinanziati[i].id, progettiFinanziati[i].finanziamentoRichiesto, progettiFinanziati[i].titolo);

	//}
	//free(progettiFinanziati);


	//PROGRAMMA PRINCIPALE

	list valutazioniLette;
	Progetto *progettiLetti, *progettiFinanziati;
	int dimProgettiLetti, dimProgettiFinanziati, i;
	float soldi;

	printf("Fornisca l' ammontare di finanziamento disponbile: ");
	scanf("%f%*c", &soldi);

	progettiLetti = leggiProgetti("progetti.txt", &dimProgettiLetti);
	valutazioniLette = leggiValutazioni("valutazioni.txt");
	
	merge(progettiLetti, dimProgettiLetti, valutazioniLette);
	freeList(valutazioniLette);

	progettiFinanziati = finanziati(progettiLetti, dimProgettiLetti, &dimProgettiFinanziati, soldi);
	free(progettiLetti);

	printf("Progetti finanziabili: \n");

	for (i = 0; i < dimProgettiFinanziati; i++) {

		printf("%d %.2f %s\n", progettiFinanziati[i].id, progettiFinanziati[i].finanziamentoRichiesto, progettiFinanziati[i].titolo);

	}
	free(progettiFinanziati);

	system("pause");
	return 0;
}