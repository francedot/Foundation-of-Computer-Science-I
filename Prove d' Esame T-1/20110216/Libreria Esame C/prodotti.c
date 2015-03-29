//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "prodotti.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo contenente i punteggi relativi ad un prodotto, restituisca
//una lista di strutture dati di tipo Prodotto.
list leggiProdotti(char* fileName)
{
	FILE *fp;
	list prodottiLetti = emptyList();
	element temp;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		printf("Errore apertura file %s.\n", fileName);
		system("pause");
		exit(-1);

	} else {

		while (fscanf(fp, "%s %d", temp.nomeProdotto, &temp.puntiProdotto) == 2) {

			prodottiLetti = cons(temp, prodottiLetti);

		}

		fclose(fp);
		return prodottiLetti;
	}
}

//ricevuta in ingresso una lista di strutture dati di tipo Prodotto, stampi a video il contenuto di tale lista.
void stampaProdotti(list l)
{
	if (l != NULL) {

		printElement(head(l));
		stampaProdotti(tail(l));
	}
}

//ricevuti in ingresso una lista di strutture dati di tipo Prodotto ed il nome di un prodotto, restituisca il
//punteggio assegnato al prodotto. Qualora il prodotto non sia presente in lista, la funzione restituisca il valore 0.
int punteggio(list l, char * nome)
{
	int punteggio = 0;

	while (!empty(l)) {

		if (strcmp(head(l).nomeProdotto, nome) == 0)
			punteggio = head(l).puntiProdotto;

		l = tail(l);

	}

	return punteggio;
}


//ES.2

//ricevuto in ingresso il nome di un file contenente tutti gli acquisti effettuati, legga da tale file le
//informazioni e le memorizzi in un’area di memoria allocata dinamicamente. La funzione deve restituire un
//array di elementi di tipo Acquisto, e tramite il parametro dim la dimensione di tale array.
Acquisto * leggiAcquisti(char * fileName, int * dim)
{
	FILE *fp;
	Acquisto *acquistiLetti, temp;
	int i;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		printf("Errore apertura file %s.\n", fileName);
		system("pause");
		exit(-2);

	} else {

		*dim = 0;
		while (fscanf(fp, "%d %s %d", &temp.idCliente, temp.nomeProdotto, &temp.numAcquisti) == 3)
				(*dim)++;

		acquistiLetti = (Acquisto *) malloc(sizeof(Acquisto) * (*dim));
		rewind(fp);

		i = 0;
		while (fscanf(fp, "%d %s %d", &temp.idCliente, temp.nomeProdotto, &temp.numAcquisti) == 3)
				acquistiLetti[i++] = temp;


		fclose(fp);
		return acquistiLetti;
	}
}

//stampi a video le strutture dati di tipo Acquisto contenute nel vettore v passato come parametro, di
//dimensione dim.
void stampaAcquisti(Acquisto * v, int dim)
{
	int i;
	
	for (i = 0; i < dim; i++)
		printf("%d %s %d\n", v[i].idCliente, v[i].nomeProdotto, v[i].numAcquisti);
	
	return;
}


//ES.3

//ricevuti in ingresso un array v di strutture dati di tipo Acquisto e la sua dimensione dim, restituisca un
//nuovo vettore di strutture dati di tipo Acquisto, contenente i dati originali contenuti in v, esclusi gli
//acquisti con numero di oggetti pari a zero. Inoltre, la funzione restituisca tramite il parametro dimResult la
//dimensione del nuovo vettore; tale vettore sia ordinato in maniera crescente in base al codice identificativo
//del cliente; in caso di parità di codice identificativo, si consideri il nome del prodotto e si utilizzi il criterio
//lessicografico (ancora in senso crescente). Non è necessario che il vettore restituito sia della minima
//dimensione necessaria; si suggerisce di creare tale vettore e di riempirlo con i dati “corretti”, e poi di
//ordinarlo in un secondo momento.
void scambia(Acquisto *a, Acquisto *b)
{
	Acquisto tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Acquisto a[], int iniz, int fine)
{
	Acquisto pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareAcquisti(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareAcquisti(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareAcquisti(a[i], a[iPivot]) != 0)
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
void quickSort(Acquisto a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
Acquisto * filtraEOrdina(Acquisto * v, int dim, int *dimResult)
{
	Acquisto *acquistiFiltrati;
	int i;

	acquistiFiltrati = (Acquisto *) malloc(sizeof(Acquisto) * dim); //no dim minima
	*dimResult = 0;

	for (i = 0; i < dim; i++) {

		if (v[i].numAcquisti != 0)
			acquistiFiltrati[(*dimResult)++] = v[i];

	}

	quickSort(acquistiFiltrati, *dimResult);

	return acquistiFiltrati;
}