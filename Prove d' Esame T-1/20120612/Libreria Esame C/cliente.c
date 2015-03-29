//Bonacci Francesco 0900050944 Prova 4A

#include "cliente.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo rappresentante l’elenco dei clienti, restituisca una lista di
//strutture dati di tipo Cliente, contenente tutte le informazioni presenti nel file il cui nome è passato come
//parametro. Poiché i cognomi e i nomi dei clienti possono contenere spazi, per leggere tali campi si suggerisce
//l’uso della funzione readField(…) fornita nello StartKit tramite il modulo “read.h/read.c”. La funzione
//readField(char buffer[], char sep, FILE *f) legge dal file f tutti i caratteri (spazi compresi)
//fino al separatore sep, e li copia nell’array buffer; la funzione restituisce il numero di caratteri letti.
list leggiClienti(char* fileName)
{
	FILE *fr = NULL;
	list clientiLetti = emptyList();
	Cliente temp;
	char ch;

	if ((fr = fopen(fileName, "rt")) == NULL) {

		perror("Impossibile aprire file clienti in lettura");
		system("pause");
		exit(-1);

	}
	
	do {

		readField(temp.cognome, ';', fr);
		readField(temp.nome, ';', fr);
		fscanf(fr, "%s %d", temp.nomeFile, &temp.redditoAnnuale);
		clientiLetti = cons(temp, clientiLetti);

		ch = fgetc(fr);

	} while (ch == 10);

	if (fclose(fr) == EOF) {

		perror("Errore chiusura file clienti");
		system("pause");

	}

	return clientiLetti;
}

//ricevuta in ingresso una lista di strutture dati di tipo Cliente, stampi a video l’elenco dei clienti con
//tutte le informazioni relative.
void stampaLista(list v)
{
	showList(v);
}

//ES.2

//ricevuto in ingresso il nome di un file contenente le voci di spesa effettuate da un cliente, e un intero
//passato per riferimento, restituisca un vettore allocato dinamicamente (della dimensione minima
//necessaria) contenente le spese memorizzate nel file indicato come parametro. Tramite l’intero passato per
//riferimento, la funzione deve restituire la dimensione del vettore allocato dinamicamente.
Spesa * leggiSpese(char * fileName, int * dim)
{
	FILE *fr;
	Spesa *speseLette, temp;
	int i;

	if ((fr = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file spese in lettura");
		system("pause");
		exit(-2);

	}

	*dim = 0;
	while (fscanf(fr, "%d %s %c\n", &temp.importo, temp.descrizione, &temp.detraibilile) == 3)
		(*dim)++;

	speseLette = (Spesa *) malloc(sizeof(Spesa) * (*dim));
	rewind(fr);

	for (i = 0; i < *dim; i++) {

		fscanf(fr, "%d %s %c\n", &speseLette[i].importo, 
			speseLette[i].descrizione, &speseLette[i].detraibilile);

	}

	if (fclose(fr) == EOF) {

		perror("Errore chiusura file spese");
		system("pause");

	}

	return speseLette;
}

//ricevuti un vettore di strutture dati di tipo Spesa e la dimensione di tale vettore, ordini tale vettore
//ponendo prima le spese “detraibili” (indicate con la lettera ‘D’) e a seguire le spese non detraibili (indicate
//con la lettera ‘N’). Nell’ambito dello stesso tipo di spese, queste devono essere ordinate in base all’importo,
//in ordine decrescente (dagli importi maggiori agli importi minori).
void scambia(Spesa *a, Spesa *b)
{
	Spesa tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Spesa a[], int iniz, int fine)
{
	Spesa pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareSpese(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareSpese(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareSpese(a[i], a[iPivot]) != 0)
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
void quickSort(Spesa a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Spesa * v, int dim)
{
	quickSort(v, dim);
}

//ES.3

//ricevuto in ingresso una lista di strutture dati di tipo Cliente, restituisca una nuova lista dove sono
//stati eliminati tutti i clienti che avevano come riferimento lo stesso file per le spese. Ad esempio, facendo
//riferimento al file “elenco.txt” fornito nello StartKit, il terzo e il quarto cliente registrati in tale file fanno
//riferimento allo stesso file per le spese, e quindi devono essere filtrati via entrambi.
int contaRipetuti(list clienti, element cliente)
{
	int count = 0;

	while (!empty(clienti)) {

		if (strcmp(head(clienti).nomeFile, cliente.nomeFile) == 0)
			count++;

		clienti = tail(clienti);

	}

	return count;
}
list eliminaRipetuti(list c)
{
	//scorro c --> se il nome del file della testa compare più di una volta non la prendo
	list rif = c, clientiNonRipetuti = emptyList();

	while (!(empty(rif))) {

		if (contaRipetuti(c, head(rif)) == 1)
			clientiNonRipetuti = cons(head(rif), clientiNonRipetuti);

		rif = tail(rif);

	}

	return clientiNonRipetuti;
}
