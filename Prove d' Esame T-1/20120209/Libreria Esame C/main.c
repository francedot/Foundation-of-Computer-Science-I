//Bonacci Francesco 0900050944 Prova 6A

#include "paz.h"

int main()
{
	//TEST ES.1

	/*list pazientiLetti;

	pazientiLetti = leggiPazienti("nomi.txt");
	stampaLista(pazientiLetti);
	freeList(pazientiLetti);*/


	//TEST ES.2

	/*Esame *esamiLetti;
	int dimEsamiLetti, i;
	
	esamiLetti = leggiEsami("esami.txt", &dimEsamiLetti);
	for (i = 0; i < dimEsamiLetti; i++)
		printf("%d %s %d\n", esamiLetti[i].idPaziente,
				esamiLetti[i].nomeEsame, esamiLetti[i].annoEsame);

	printf("\n");

	ordina(esamiLetti, dimEsamiLetti);
	for (i = 0; i < dimEsamiLetti; i++)
		printf("%d %s %d\n", esamiLetti[i].idPaziente,
				esamiLetti[i].nomeEsame, esamiLetti[i].annoEsame);

	free(esamiLetti);*/


	//TEST ES.3

	//list pazientiLetti;
	//Esame *esamiLetti;
	//int dimEsamiLetti;
	//
	//esamiLetti = leggiEsami("esami.txt", &dimEsamiLetti);
	//pazientiLetti = leggiPazienti("nomi.txt");

	//ripetuti(pazientiLetti, esamiLetti, dimEsamiLetti);
	//freeList(pazientiLetti), free(esamiLetti);


	//PROGRAMMA PRINCIPALE

	list pazientiLetti;
	Esame *esamiLetti;
	int dimEsamiLetti;
	
	esamiLetti = leggiEsami("esami.txt", &dimEsamiLetti);
	pazientiLetti = leggiPazienti("nomi.txt");

	ripetuti(pazientiLetti, esamiLetti, dimEsamiLetti);
	freeList(pazientiLetti), free(esamiLetti);

	printf("\n");

	system("pause");
	return 0;
}