//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "info.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo contenente le informazioni, restituisca un array di
//strutture dati di tipo Record allocato dinamicamente (della dimensione minima necessaria), contenente
//tutte le informazioni presenti nel file indicato come parametro. Tramite il parametro dim la funzione deve
//restituire la dimensione del vettore.
Record * leggiRecord(char* fileName, int *dim)
{
	FILE *fp;
	Record *recordLetti = NULL, temp;
	int i;

	if ( (fp = fopen(fileName, "rt")) == NULL )  {

		perror("Errore apertura file info");
		system("PAUSE");
		exit(-1);

	} else {

		*dim = 0;

		while (fscanf(fp, "%s %d %s\n", temp.seriale, &temp.istante, temp.ip) == 3)
			(*dim)++;

		rewind(fp);

		recordLetti = (Record *) malloc(sizeof(Record) * (*dim));

		for (i = 0; i < *dim; i++) {

			fscanf(fp, "%s %d %s\n", recordLetti[i].seriale, &recordLetti[i].istante, recordLetti[i].ip);

		}

		fclose(fp);
		return recordLetti;

	}
}

//ricevuto in ingresso il nome di un file di testo contenente l’elenco dei clienti, restituisca un array di
//strutture dati di tipo Cliente allocato dinamicamente (della dimensione minima necessaria), contenente
//tutte le informazioni presenti nel file indicato come parametro. Tramite il parametro dim la funzione deve
//restituire la dimensione del vettore.
Cliente * leggiClienti(char* fileName, int *dim)
{
	FILE *fp;
	Cliente *clientiLetti = NULL, temp;
	int i;

	if ( (fp = fopen(fileName, "rt")) == NULL )  {

		perror("Errore apertura file archivio");
		system("PAUSE");
		exit(-1);

	} else {

		*dim = 0;

		while (fscanf(fp, "%s %s %s\n", temp.seriale, temp.nome, temp.cognome) == 3)
			(*dim)++;

		rewind(fp);

		clientiLetti = (Cliente *) malloc(sizeof(Cliente) * (*dim));

		for (i = 0; i < *dim; i++) {

			fscanf(fp, "%s %s %s\n", clientiLetti[i].seriale, clientiLetti[i].nome, clientiLetti[i].cognome);

		}

		fclose(fp);
		return clientiLetti;

	}
}

//riceva in ingresso un vettore di strutture dati di tipo Record e la dimensione di tale vettore, e ordini il
//vettore secondo un ordine lessicografico sul codice seriale. A parità di seriale, le strutture dati devono essere
//ordinate in base all’istante temporale a cui fanno riferimento, in ordine crescente. Si usi a tal scopo un
//algoritmo di ordinamento a scelta tra quelli visti a lezione.
void scambia(Record *a, Record *b)
{
	Record tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Record a[], int iniz, int fine)
{
	Record pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareRecord(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareRecord(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareRecord(a[i], a[iPivot]) != 0)
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
void quickSort(Record a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Record * v, int dim)
{
	quickSort(v, dim);
}


//ES.2

//ricevuta come parametro un vettore di strutture dati di tipo Record ordinato come specificato
//nell’esercizio 1 e la sua dimensione dimR, un vettore di strutture dati di tipo Cliente e la sua dimensione
//dimC, restituisca una lista dei clienti attivi. Un cliente è da considerarsi attivo se ha utilizzato almeno una
//volta il software. In altre parole, sono clienti attivi tutti coloro che possiedono il software (e che quindi
//compaiono nel file “archivio.txt”), e il cui seriale compaia almeno una volta nel file “info.txt”.
boolean isAttivo(Cliente cliente, Record *registrazioni, int dimR)
{
	int i, attivo = 0;

	for (i = 0; i < dimR && !attivo; i++)
		if (strcmp(cliente.seriale, registrazioni[i].seriale) == 0)
			attivo = 1;

	return attivo;
}
list clientiAttivi(Record * r, int dimR, Cliente * C, int dimC)
{
	list listaClienti = emptyList();
	int i;

	for (i = 0; i < dimC; i++) {

		if (!contains(listaClienti, C[i]) && isAttivo(C[i], r, dimR))
			listaClienti = cons(C[i], listaClienti);
		
	}

	return listaClienti;
}

//ricevuta in ingresso una lista di strutture dati di tipo Cliente, stampi a video il contenuto di tale lista.
//La procedura deve essere implementata in maniera ricorsiva.
void stampaListaClienti(list l)
{
	if (!empty(l)) {

		printElement(head(l));
		stampaListaClienti(tail(l));

	}
}


//ES.3

//ricevuta come parametro un vettore di strutture dati di tipo Record ordinato come specificato
//nell’esercizio 1 e la sua dimensione dimR, un vettore di strutture dati di tipo Cliente e la sua dimensione
//dimC, restituisca una lista dei clienti il cui software è stato usato in maniera illecita. Un software è stato
//usato illecitamente se compaiono due registrazioni diverse (due Record diversi) relativi allo stesso seriale,
//ma usati da due indirizzi ip diversi, e in due istanti temporali distanti non più di 5 ore. La lista restituita deve
//essere ordinata in base al solo cognome del cliente, e non dovrà contenere ripetizioni. Ad esempio, usando i
//files forniti nello StartKit, la lista dovrà contenere (in ordine) le strutture dati “abcde98765abcde
//Federico Chesani” e “qwert54321qwert Carlo Giannelli”.
boolean isIllecito(Cliente c, Record *r, int dimR)	//registrazioni ordinate per seriale e per ore
{
	int i = 0, j, illecito = 0, trovato = 0; 

	while (i < dimR && !trovato) { //ciclo finche non arrivo alla fine o trovo l'illecito

		if (strcmp(c.seriale , r[i].seriale) == 0)
			trovato = 1;

		if (trovato) {

			j=i+1;
			while (j < dimR && !illecito && strcmp(r[i].seriale, r[j].seriale) == 0) {

				if (strcmp(r[j].ip, r[i].ip) != 0 &&
						r[j].istante-r[i].istante <= 5) {

						illecito = 1;
						
				}

				i++, j++;
			}

		} else //se non l'ho trovato
			i++;

	}

	return illecito;
}
list illeciti(Record * r, int dimR, Cliente * c, int dimC)
{
	
	list clientiIlleciti = emptyList();
	int i;

	for (i = 0; i < dimC; i++) {

		if (!contains(clientiIlleciti, c[i]) && isIllecito(c[i], r, dimR))
			clientiIlleciti = insord_p(c[i], clientiIlleciti);

	}

	return clientiIlleciti;
}