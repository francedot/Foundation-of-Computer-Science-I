//Bonacci Francesco 0900050944

#include "beni.h"
#include <string.h>

#define DIM_KEY 20

int main()
{

	//TEST ES.1

	//list beniLetti, beniOrdinati;
	//Bene *arrayBeni, beneEffettivo;
	//int dimArray, i;

	//beniLetti = leggiBeni("forniture.txt");

	//beniOrdinati = ordinaBeni(beniLetti);

	//showList(beniOrdinati);

	//TEST ES.2

	/*arrayBeni = estrai(beniOrdinati, "carta", &dimArray);

	ordina(arrayBeni, dimArray);

	stampaVettBeni(arrayBeni, dimArray);*/

	//TEST ES.3

	/*beneEffettivo = effettivo(beniOrdinati, "carta", 30, 1000.0f);*/

	//PROGRAMMA PRINCIPALE
	
	char keyword[DIM_KEY];
	int numPezzi;
	float budget;
	list beniLetti;
	Bene beneEffettivo;

	printf("Specifichi una parola chiave: ");
	scanf("%s", keyword);

	printf("Specifichi il numero di pezzi da acquistare: ");
	scanf("%d", &numPezzi);
	
	printf("Specifichi il budget disponibile: ");
	scanf("%f", &budget);

	beniLetti = leggiBeni("forniture.txt");
	beneEffettivo = effettivo(beniLetti, keyword, numPezzi, budget);

	if (!strcmp(beneEffettivo.id, "NULL")) {

		printf("Nessun bene trovato\n");
	} else {

		printElement(beneEffettivo);
	}

	system("pause");

	freeList(beniLetti);
	return 0;
}