//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "scommesse.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo contenente le scommesse, restituisca un array di strutture
//dati di tipo Scommessa allocato dinamicamente (non necessariamente della dimensione minima),
//contenente tutte le scommesse presenti nel file indicato come parametro. Tramite il parametro dim, la
//funzione deve restituire la dimensione del vettore. Siccome per errore ogni tanto vengono inserite due
//scommesse con lo stesso codice identificativo di scommessa, la funzione deve avere cura di scartare tali
//ripetizioni. Ai fini della lettura quindi la funzione deve effettivamente memorizzare ogni “prima” scommessa,
//e scartare eventuali ripetizioni. A tal scopo, il candidato definisca una funzione:
Scommessa * leggiScommesse(char* fileName, int *dim)
{
	FILE *fp;
	Scommessa *scommesseLette, temp;
	int i, dimRawLette = 0;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		printf("Errore apertura file %s.\n", fileName);
		system("pause");
		exit(-1);

	} else {

		while (fscanf(fp, "%d %s %f %d %d %d\n", &temp.idCliente,
					temp.idScommessa, &temp.importoScommessa, 
						&temp.dataScommessa.giorno, &temp.dataScommessa.mese, 
							&temp.dataScommessa.anno) == 6) {

			dimRawLette++;

		}

		scommesseLette = (Scommessa *) malloc(sizeof(Scommessa) * (dimRawLette));
		rewind(fp);
		*dim = 0; //dimensione logica minima senza doppioni delle scommesse lette

		for (i = 0; i < dimRawLette; i++) {

			fscanf(fp, "%d %s %f %d %d %d\n", &temp.idCliente,
					temp.idScommessa, &temp.importoScommessa, 
						&temp.dataScommessa.giorno, &temp.dataScommessa.mese, 
							&temp.dataScommessa.anno);

			if (! giaPresente(scommesseLette, *dim, temp))
				scommesseLette[(*dim)++] = temp;

		}
		
		fclose(fp);
		return scommesseLette;
	}
}

//riceva in ingresso un vettore di strutture dati di tipo Scommessa e la dimensione di tale vettore, ed una
//scommessa particolare s. La funzione deve restituire un valore interpretabile come “vero” se la scommessa s
//è già presente nel vettore, falso altrimenti.
int giaPresente(Scommessa * v, int dim, Scommessa s)
{
	int i, presente = 0;

	for (i = 0; i < dim; i++) {

		if (strcmp(v[i].idScommessa, s.idScommessa) == 0)
			presente = 1;

	}

	return presente;
}

//ricevuta in ingresso un vettore di strutture dati di tipo Scommessa, e la sua dimensione, stampi a video
//il contenuto di tale vettore.
void stampaScommesse(Scommessa * v, int dim)
{
	int i;

	for (i = 0; i < dim; i++) {

		printf("%d %s %.2f %02d %02d %04d\n", v[i].idCliente,
					v[i].idScommessa, v[i].importoScommessa, 
						v[i].dataScommessa.giorno, v[i].dataScommessa.mese, 
							v[i].dataScommessa.anno);

	}

	return;
}


//ES.2

//ricevuti in ingresso un vettore di strutture dati di tipo Scommessa, la sua dimensione dim, e il codice
//identificativo del cliente, restituisca un nuovo vettore allocato dinamicamente (della dimensione minima
//necessaria) contenente tutte e sole le scommesse in v ed effettuate dal cliente indicato. Tramite il
//parametro dimRes la funzione deve restituire la dimensione del nuovo vettore. Il vettore restituito inoltre
//dovrà presentare le scommesse ordinate in maniera crescente secondo la data.
void scambia(Scommessa *a, Scommessa *b)
{
	Scommessa tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Scommessa a[], int iniz, int fine)
{
	Scommessa pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareScommesse(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareScommesse(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareScommesse(a[i], a[iPivot]) != 0)
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
void quickSort(Scommessa a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
Scommessa * seleziona(Scommessa v[], int dim, int codCliente, int *dimRes)
{
	Scommessa *scommesseSelezionate;
	int i, j = 0;

	*dimRes = 0;
	for (i = 0; i < dim; i++) {

		if (v[i].idCliente == codCliente)
			(*dimRes)++;

	}

	scommesseSelezionate = (Scommessa *) malloc(sizeof(Scommessa) * (*dimRes));

	for (i = 0; i < dim; i++) {

		if (v[i].idCliente == codCliente)
			scommesseSelezionate[j++] = v[i];

	}
	quickSort(scommesseSelezionate, *dimRes);

	return scommesseSelezionate;
}

//ricevuto in ingresso il nome di un file contenente l’elenco dei clienti, un vettore v contenente tutte le
//scommesse effettuate, e la dimensione dim di tale vettore, restituisca una lista contenente strutture dati di
//tipo Cliente. Al fine di determinare le scommesse effettuate dal singolo cliente, il candidato utilizzi le
//funzioni di cui all’esercizio 1 per leggere tutte le scommesse effettuate, e la funzione sopra descritta per
//determinare le scommesse effettuate dal singolo cliente.
list leggiClienti(char * fileName, Scommessa v[], int dim)
{
	//comincio la lettura, leggo il singolo cliente, prendo l' array di scommesse per quel cliente (seleziona)
	//lo metto dentro il cliente --> aggiungo il cliente alla lista

	FILE *fp;
	list clientiLetti = emptyList();
	element temp;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		printf("Errore apertura file %s.\n", fileName);
		system("pause");
		exit(-2);

	} else {

		while (fscanf(fp, "%s %s %d\n", temp.nomeCliente, temp.cognomeCliente, &temp.idCliente) == 3) {

			temp.scommesseCliente = seleziona(v, dim, temp.idCliente, &temp.dimScommesseCliente);

			clientiLetti = cons(temp, clientiLetti);

		}

		fclose(fp);
		return clientiLetti;
	}
}


//ES.3

//ricevuta come parametro una lista di strutture dati di tipo Cliente, stampi a video tutti i dati
//riguardanti i clienti che sono giocatori “assidui”. Un cliente è da considerarsi “giocatore assiduo” se in uno
//stesso anno solare questi ha effettuato almeno 3 scommesse. Ad esempio, considerando i file forniti nello
//StartKit, risulta che l’unico giocatore assiduo è il giocatore con codice identificativo cliente “12”, che nel
//2011 ha effettuato tre scommesse.
boolean isAssiduo(Cliente c)
{
	//scorro le scommesse in cliente, se ci sono almeno 3 scommesse per lo stesso anno restituisco true
	int i = 0, j, assiduo = 0, numScommesseAnno;

	while (i < c.dimScommesseCliente && !assiduo) {

		numScommesseAnno = 1;

		j = i+1;
		while (c.scommesseCliente[i].dataScommessa.anno ==
					c.scommesseCliente[j].dataScommessa.anno &&
						j < c.dimScommesseCliente) {

			numScommesseAnno++;
			j++;

		}

		if (numScommesseAnno >= 3)
			assiduo = 1;

		i = j;

	}

	return assiduo;
}
void stampaAssidui(list l)
{
	//scorro i clienti in l --> se il giocatore è assiduo (isAssiduo) lo prendo

	while (!empty(l)) {

		if (isAssiduo(head(l)))
			printElement(head(l));

		l = tail(l);
	}
}