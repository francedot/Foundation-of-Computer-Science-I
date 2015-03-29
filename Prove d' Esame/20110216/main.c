//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "prodotti.h"

int main()
{
	//TEST ES.1

	/*list prodottiLetti;
	int punteggioProdotto;
	char nomeProdotto[DIM_NOME_PRODOTTO];

	printf("Tutti i Prodotti: \n");
	prodottiLetti = leggiProdotti("punteggi.txt");
	stampaProdotti(prodottiLetti);

	printf("\nInserisca il nome di un prodotto: ");
	scanf("%s", nomeProdotto);

	punteggioProdotto = punteggio(prodottiLetti, nomeProdotto);
	printf("Punteggio Relativo al prodotto: %d\n", punteggioProdotto);
	freeList(prodottiLetti);*/


	//TEST ES.2

	/*Acquisto *acquistiLetti;
	int dimAcquistiLetti;

	acquistiLetti = leggiAcquisti("registro.txt", &dimAcquistiLetti);
	
	stampaAcquisti(acquistiLetti, dimAcquistiLetti);
	free(acquistiLetti);*/


	//TEST ES.3

	/*Acquisto *acquistiLetti, *acquistiFiltrati;
	int dimAcquistiLetti, dimAcquistiFiltrati;

	acquistiLetti = leggiAcquisti("registro.txt", &dimAcquistiLetti);
	acquistiFiltrati = filtraEOrdina(acquistiLetti, dimAcquistiLetti, &dimAcquistiFiltrati);
	free(acquistiLetti);
	
	stampaAcquisti(acquistiFiltrati, dimAcquistiFiltrati);
	free(acquistiFiltrati);*/


	//PROGRAMMA PRINCIPALE

	//Il candidato realizzi nella funzione main(…) un programma che, usando le informazioni fornite tramite i file
	//“punteggi.txt” e “registro.txt”, stampi a video, per ogni cliente presente nel file “registro.txt”, il
	//punteggio totale ottenuto da tale cliente tramite tutti i suoi acquisti registrati. A tal proposito, si ricorda che
	//ogni prodotto acquistato contribuisce con un punteggio specifico, che deve essere moltiplicato per il numero
	//di prodotti di quel tipo acquistati dal cliente. Si suggerisce di usare le funzioni sviluppate negli esercizi
	//precedenti.

	list prodottiLetti;
	Acquisto *acquistiLetti, *acquistiFiltrati;
	int dimAcquistiLetti, dimAcquistiFiltrati, i, puntiCliente, puntiProdotto, currentiId;

	acquistiLetti = leggiAcquisti("registro.txt", &dimAcquistiLetti);
	acquistiFiltrati = filtraEOrdina(acquistiLetti, dimAcquistiLetti, &dimAcquistiFiltrati);
	free(acquistiLetti);
	prodottiLetti = leggiProdotti("punteggi.txt");
	
	//scorro gli acquisti filtrati, accumulo il totale dei punteggi per acquisto (punteggio())
	
	i = 0;

	if (dimAcquistiFiltrati > 0) { //procedo solo in questo caso

		currentiId = acquistiFiltrati[0].idCliente;
		puntiCliente = 0;

		for (i = 0; i < dimAcquistiFiltrati; i++) {

			if (currentiId == acquistiFiltrati[i].idCliente) {

				puntiProdotto = punteggio(prodottiLetti, acquistiFiltrati[i].nomeProdotto);
				puntiCliente += puntiProdotto * acquistiFiltrati[i].numAcquisti;

			} 
			
			if (currentiId != acquistiFiltrati[i].idCliente || i == dimAcquistiFiltrati - 1) {

				printf("Cliente %d. Punti accumulati: %d.\n", currentiId, puntiCliente);
				currentiId = acquistiFiltrati[i].idCliente;
				puntiCliente = acquistiFiltrati[i].numAcquisti * punteggio(prodottiLetti, acquistiFiltrati[i].nomeProdotto);

			}
		} 
	}

	free(acquistiFiltrati), freeList(prodottiLetti);

	system("pause");
	return 0;
}

//while (i < dimAcquistiFiltrati) {
//
//		puntiCliente = 0;
//
//		j = i;
//		while (acquistiFiltrati[i].idCliente == acquistiFiltrati[j].idCliente && j < dimAcquistiFiltrati) {
//
//			puntiProdotto = punteggio(prodottiLetti, acquistiFiltrati[j].nomeProdotto);
//			puntiCliente += puntiProdotto * acquistiFiltrati[j].numAcquisti;
//
//			j++;
//		}
//
//		//stampaPunti
//		printf("Cliente %d. Punti accumulati: %d.\n", acquistiFiltrati[i].idCliente, puntiCliente);
//
//		if (puntiCliente == puntiProdotto * acquistiFiltrati[i].numAcquisti) //solo un prodotto
//			i++;
//		else i = j;
//	}