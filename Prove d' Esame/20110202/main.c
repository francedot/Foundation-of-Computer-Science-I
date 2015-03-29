//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "clienti.h"

Cliente getClienteFromId(Cliente *clientiLetti, int dimClientiLetti, int idCliente);
void scambia(Cliente *a, Cliente *b);
void quickSortR(Cliente a[], int iniz, int fine);
void quickSort(Cliente a[], int dim);

int main()
{
	//TEST ES.1

	/*Cliente *clientiLetti;
	int dimClientiLetti;

	clientiLetti = leggiClienti("anag.txt", &dimClientiLetti);
	stampaClienti(clientiLetti, dimClientiLetti);
	free(clientiLetti);*/


	//TEST ES.2

	/*list preferenzeLette;
	preferenzeLette = leggiPref("pref.txt");
	stampaPref(preferenzeLette);
	freeList(preferenzeLette);*/


	//TEST ES.3

	/*list preferenzeLette;
	int presente;
	
	preferenzeLette = leggiPref("pref.txt");
	
	presente = cerca(preferenzeLette, 654, "romance");
	presente = cerca(preferenzeLette, 654, "science");
	presente = cerca(preferenzeLette, 653, "romance");
	presente = cerca(preferenzeLette, 654, "meta-mathematic");

	freeList(preferenzeLette);*/


	//PROGRAMMA PRINCIPALE

	/*Il candidato realizzi nella funzione main(…) un programma che chieda all’utente di specificare una keyword
	riguardo una preferenza, e stampi a video i dati (anagrafici) relativi ai clienti che hanno interesse per
	l’argomento rappresentato da tale keyword, in ordine crescente in base al CAP. A tal scopo, dopo aver letto i
	dati dai file, si allochi dinamicamente un vettore di strutture dati di tipo Cliente (la dimensione del vettore
	non deve essere necessariamente quella minima), e si copino in tale vettore i dati relativi ai clienti che sono
	interessati all’argomento specificato dall’utente. Si provveda ad ordinare tale vettore in ordine crescente in
	base al CAP, e poi se ne stampi il contenuto a video. Si suggerisce di usare le funzioni sviluppate negli esercizi
	precedenti.*/

	list preferenzeLette;
	Cliente *clientiLetti, *clientiInteressati;
	int dimClientiLetti, dimInteressati = 0;
	char keyWord[DIM_KEYWORD];

	preferenzeLette = leggiPref("pref.txt");
	clientiLetti = leggiClienti("anag.txt", &dimClientiLetti);
	
	clientiInteressati = (Cliente *) malloc(sizeof(Cliente) * dimClientiLetti);

	printf("Specificare una keyword preferenza: ");
	scanf("%s", keyWord);

	while (!empty(preferenzeLette)) {

		if (strcmp(head(preferenzeLette).keyWord, keyWord) == 0) {

			if (cerca(preferenzeLette, head(preferenzeLette).idCliente, keyWord))
				clientiInteressati[dimInteressati++] = getClienteFromId(clientiLetti, dimClientiLetti, head(preferenzeLette).idCliente);

		}

		preferenzeLette = tail(preferenzeLette);

	}
	freeList(preferenzeLette), free(clientiLetti);

	if (dimInteressati != 0) {

		quickSort(clientiInteressati, dimInteressati);
		stampaClienti(clientiInteressati, dimInteressati);


	} else
		printf("Non compaiono clienti con i parametri desiderati.\n");

	free(clientiInteressati);

	system("pause");
	return 0;
}

Cliente getClienteFromId(Cliente *clientiLetti, int dimClientiLetti, int idCliente)
{
	Cliente desiderato;
	int i;

	for (i = 0; i < dimClientiLetti; i++) {

		if (clientiLetti[i].idCliente == idCliente)
			desiderato = clientiLetti[i];

	}

	return desiderato;
}

void scambia(Cliente *a, Cliente *b)
{
	Cliente tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSortR(Cliente a[], int iniz, int fine)
{
	Cliente pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareClienti(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareClienti(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareClienti(a[i], a[iPivot]) != 0)
		{
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(a, iPivot + 1, fine);
	} /* (iniz < fine) */
} /* quickSortR */

void quickSort(Cliente a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
