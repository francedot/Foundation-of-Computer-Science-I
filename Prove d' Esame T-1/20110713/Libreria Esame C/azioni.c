//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "azioni.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo contenente le vendite di azioni, restituisca un array di
//strutture dati di tipo Vendita allocato dinamicamente (della dimensione minima necessaria), contenente
//tutte le vendite presenti nel file indicato come parametro. Tramite il parametro dim la funzione deve
//restituire la dimensione del vettore. Si presti attenzione al fatto che può accadere (a causa di un bug
//software) che l’ultima riga del file contenga solo parte delle informazioni relative ad una vendita: in tal caso,
//tale vendita deve essere scartata e non deve comparire nel vettore restituito come risultato.
Vendita * leggiVendite(char* fileName, int *dim)
{
	FILE *fp;
	Vendita *venditeLette, temp;
	int i = 0;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		printf("Errore apertura file %s.\n", fileName);
		system("pause");
		exit(-1);

	} else {

		*dim = 0;

		while (fscanf(fp, "%s %d %d %d %d %d\n", temp.idAzione, 
					&temp.prezzoAzione, &temp.numAzioniVendute, &temp.dataOperazione.giorno, 
						&temp.dataOperazione.mese, &temp.dataOperazione.anno) == 6)
			(*dim)++;

		venditeLette = (Vendita *) malloc(sizeof(Vendita) * (*dim));
		rewind(fp);

		while (fscanf(fp, "%s %d %d %d %d %d\n", temp.idAzione, 
					&temp.prezzoAzione, &temp.numAzioniVendute, &temp.dataOperazione.giorno, 
						&temp.dataOperazione.mese, &temp.dataOperazione.anno) == 6)
			venditeLette[i++] = temp;
		
		fclose(fp);
		return venditeLette;

	}
}

//riceva in ingresso un vettore di strutture dati di tipo Vendita e la dimensione di tale vettore, e ordini il
//vettore secondo un ordine lessicografico sul nome del titolo azionario. A parità di nome, le vendite devono
//essere ordinate in base alla data in cui sono state eseguite, in ordine crescente. Si usi a tal scopo un
//algoritmo di ordinamento a scelta tra quelli visti a lezione.
void scambia(Vendita *a, Vendita *b)
{
	Vendita tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Vendita a[], int iniz, int fine)
{
	Vendita pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compare(a[i], pivot) <= 0) 
				i++;
			while (j > i && compare(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compare(a[i], a[iPivot]) != 0)
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
void quickSort(Vendita a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Vendita * v, int dim)
{
	quickSort(v, dim);
}

//ricevuta in ingresso un vettore di strutture dati di tipo Vendita, e la sua dimensione, stampi a video il
//contenuto di tale vettore.
void stampaVendite(Vendita * v, int dim)
{
	int i;
	for (i = 0; i < dim; i++)
		printElement(v[i]);
	return;
}


//ES.2

//ricevuta come parametro un vettore di strutture dati di tipo Vendita ordinato come specificato
//nell’esercizio 1, e la sua dimensione dim, stampi a video il nome dei titoli che sono stati oggetto di
//speculazione. Un titolo è stato oggetto di speculazione se, nello stesso mese, è stato oggetto di almeno 3
//vendite. Ad esempio, considerando il file fornito nello StartKit, risulta che il titolo di nome “Unicredit” è stato
//oggetto di speculazione, poiché nel mese di luglio 2011 è stato venduto 5 volte.
void speculazioni(Vendita * v, int dim)
{
	int i = 0, j, numVenditePerTitolo;

	while (i < dim) {

		j = i+1;
		numVenditePerTitolo = 1;
		while (strcmp(v[i].idAzione, v[j].idAzione) == 0 &&
					v[i].dataOperazione.mese == v[j].dataOperazione.mese &&
						v[i].dataOperazione.anno == v[j].dataOperazione.anno) {

			numVenditePerTitolo++;
			i++, j++;
		}

		if (numVenditePerTitolo >= 3)
			printf("%s\n", v[i].idAzione); //v[i] è ancora la vendita desiderata
		else if (numVenditePerTitolo == 1)
			i++;

	}
}


//ES.3

//ricevuto in ingresso un vettore v di strutture dati di tipo Vendita, ordinate secondo quanto richiesto
//nell’esercizio 1, e la dimensione dim di tale vettore, restituisca una lista di strutture dati di tipo Vendita. In
//particolare, la lista dovrà contenere, per ogni titolo azionario presente nel vettore v, la vendita di importo
//risultante maggiore. L’importo della vendita è definito come il prodotto del prezzo di ogni singola azione per
//il numero di azioni vendute.
list selezionaVenditeMaggiori(Vendita * v, int dim)
{
	list venditeMaggiori = emptyList();
	Vendita venditaTitoloMaggiore;
	int i = 0, j;

	while (i < dim) {

		venditaTitoloMaggiore = v[i];

		j = i+1;
		while (strcmp(v[i].idAzione, v[j].idAzione) == 0 && j < dim) {

			if ( (v[j].prezzoAzione * v[j].numAzioniVendute) > 
					(venditaTitoloMaggiore.prezzoAzione * venditaTitoloMaggiore.numAzioniVendute) ) {

				venditaTitoloMaggiore = v[j];

			}

			i++, j++;
		}

		venditeMaggiori = cons(venditaTitoloMaggiore, venditeMaggiori);

		i = j; //incremento

	}

	return venditeMaggiori;
}

//ricevuta in ingresso una lista di strutture dati di tipo Vendita, stampi a video il contenuto di tale lista.
void stampaListaVendite(list l)
{
	if (!empty(l)) {

		printElement(head(l));
		stampaListaVendite(tail(l));

	}
}