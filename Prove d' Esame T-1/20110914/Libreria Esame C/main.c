//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "info.h"

int main()
{
	//TEST ES.1

	/*Record *recordLetti;
	Cliente *clientiLetti;
	int dimRecordLetti, dimClientiLetti, i;

	recordLetti = leggiRecord("info.txt", &dimRecordLetti);
	
	for (i = 0; i < dimRecordLetti; i++) {

		printf("%s %d %s\n", recordLetti[i].seriale, recordLetti[i].istante, recordLetti[i].ip);

	}

	printf("\n");

	ordina(recordLetti, dimRecordLetti);

	for (i = 0; i < dimRecordLetti; i++) {

		printf("%s %d %s\n", recordLetti[i].seriale, recordLetti[i].istante, recordLetti[i].ip);

	}
	free(recordLetti);

	clientiLetti = leggiClienti("archivio.txt", &dimClientiLetti);

	printf("\n");

	for (i = 0; i < dimClientiLetti; i++) {

		printf("%s %s %s\n", clientiLetti[i].seriale, clientiLetti[i].nome, clientiLetti[i].cognome);

	}
	free(clientiLetti);*/


	//TEST ES.2

	/*list listaClienti;
	Record *recordLetti;
	Cliente *clientiLetti;
	int dimRecordLetti, dimClientiLetti;

	recordLetti = leggiRecord("info.txt", &dimRecordLetti);
	clientiLetti = leggiClienti("archivio.txt", &dimClientiLetti);
	ordina(recordLetti, dimRecordLetti);

	listaClienti = clientiAttivi(recordLetti, dimRecordLetti, clientiLetti, dimClientiLetti);
	free(recordLetti), free(clientiLetti);

	stampaListaClienti(listaClienti);
	freeList(listaClienti);*/


	//TEST ES.3

	/*list listaClientiIlleciti;
	Record *recordLetti;
	Cliente *clientiLetti;
	int dimRecordLetti, dimClientiLetti;

	recordLetti = leggiRecord("info.txt", &dimRecordLetti);
	clientiLetti = leggiClienti("archivio.txt", &dimClientiLetti);
	ordina(recordLetti, dimRecordLetti);

	listaClientiIlleciti = illeciti(recordLetti, dimRecordLetti, clientiLetti, dimClientiLetti);
	free(recordLetti), free(clientiLetti);

	stampaListaClienti(listaClientiIlleciti);
	freeList(listaClientiIlleciti);*/

	//PROGRAMMA PRINCIPALE

	list listaClientiIlleciti;
	list listaClientiAttivi;
	Record *recordLetti;
	Cliente *clientiLetti;
	int dimRecordLetti, dimClientiLetti;

	recordLetti = leggiRecord("info.txt", &dimRecordLetti);
	clientiLetti = leggiClienti("archivio.txt", &dimClientiLetti);
	ordina(recordLetti, dimRecordLetti);

	listaClientiAttivi = clientiAttivi(recordLetti, dimRecordLetti, clientiLetti, dimClientiLetti);
	listaClientiIlleciti = illeciti(recordLetti, dimRecordLetti, clientiLetti, dimClientiLetti);
	free(recordLetti);
	free(clientiLetti);

	printf("Clienti Attivi: \n");
	stampaListaClienti(listaClientiAttivi);

	printf("\n");

	printf("Clienti Illeciti: \n");
	stampaListaClienti(listaClientiIlleciti);

	freeList(listaClientiIlleciti);
	freeList(listaClientiAttivi);

	system("pause");
	return 0;
}