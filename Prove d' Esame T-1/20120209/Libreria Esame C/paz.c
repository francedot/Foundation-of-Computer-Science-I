//Bonacci Francesco 0900050944 Prova 6A

#include "paz.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo rappresentante l’elenco dei pazienti, restituisca una lista
//di strutture dati di tipo Paziente, contenente tutte le informazioni presenti nel file il cui nome è passato
//come parametro. La lista restituita deve essere ordinata in senso lessicografico in base al cognome del
//paziente e, in caso di cognomi identici, in base al nome.
list leggiPazienti(char* fileName)
{
	FILE *fp = NULL;
	list pazientiLetti = emptyList();
	element temp;

	if ((fp = fopen(fileName, "r")) == NULL) {

		perror("Errore apertura file nomi");
		system("PAUSE");
		exit(-1);

	} else {

		while (fscanf(fp, "%s %s %d\n", temp.nomePaziente, temp.cognomePaziente, &temp.idPaziente) == 3) {

			pazientiLetti = insord_p(temp, pazientiLetti); //inserimento ordinato secondo compare

		}

		fclose(fp);
		return pazientiLetti;
	}
	
	
}

//ricevuta in ingresso una lista di strutture dati di tipo Paziente, stampi a video l’elenco dei pazienti con
//tutte le informazioni relative.
void stampaLista(list v)
{
	showList(v);
}

//ES.2

//ricevuto in ingresso il nome di un file contenente gli esami clinici, e un intero passato per riferimento,
//restituisca un vettore allocato dinamicamente (della dimensione minima necessaria) contenente gli esami
//clinici memorizzati nel file indicato come parametro. Tramite l’intero passato per riferimento, la funzione
//deve restituire la dimensione del vettore allocato dinamicamente.
Esame * leggiEsami(char * fileName, int * dim)
{
	FILE *fp = NULL;
	Esame *esamiLetti = NULL, temp;
	int i;

	if ((fp = fopen(fileName, "r")) == NULL) {

		perror("Errore apertura file esami");
		system("pause");
		exit(-2);

	} else {

		*dim = 0;
		while (fscanf(fp, "%d %s %d\n", &temp.idPaziente, temp.nomeEsame, &temp.annoEsame) == 3)
			(*dim)++;

		esamiLetti = (Esame *) malloc(sizeof(Esame) * (*dim));
		rewind(fp);

		for(i = 0; i < *dim; i++)
			fscanf(fp, "%d %s %d\n", &esamiLetti[i].idPaziente,
					esamiLetti[i].nomeEsame, &esamiLetti[i].annoEsame);

		fclose(fp);
		return esamiLetti;

	}
}

//ricevuti un vettore di strutture dati di tipo Esame e la dimensione di tale vettore, ordini tale vettore
//in base al codice identificativo unico del paziente, poi in base al nome dell’esame clinico (in ordine
//lessicografico), ed infine in base all’anno in cui l’esame è stato effettuato (in senso crescente).
void scambia(Esame *a, Esame *b)
{
	Esame tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Esame a[], int iniz, int fine)
{
	Esame pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareEsami(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareEsami(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareEsami(a[i], a[iPivot]) != 0)
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
void quickSort(Esame a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Esame * v, int dim)
{
	quickSort(v, dim);
}


//ES.3

//ricevuti come parametri la lista dei pazienti, e un vettore contenente gli esami e la dimensione di tale
//vettore, stampi a video i dati dei pazienti, il nome dell’esame e il numero di volte che tale esame è stato
//fatto, solo nel caso che il singolo paziente abbia sostenuto almeno 3 volte lo stesso esame. Ad esempio,
//usando come riferimento i file forniti nello StartKit, risulta che il paziente con codice identificativo 46 ha
//sostenuto cinque volte l’esame “ECG_sotto_sforzo”. In maniera simile, il paziente con codice identificativo
//34 l’esame “ECG_sotto_sforzo” tre volte. La funzione deve stampare a video codice identificativo, nome e
//cognome del paziente, assieme al nome dell’esame che è stato ripetuto almeno 3 volte, e al numero
//effettivo di quante volte quell’esame è stato ripetuto.
void ripetuti(list pazienti, Esame * vEsame, int dim)
{	
	list temp;
	Paziente datiPaziente;
	int i = 0, j = 0, numVolteFatto;

	ordina(vEsame, dim); //array ordinato per id e poi per nomeEsame

	while (i < dim) {

		numVolteFatto = 0;
		while ( vEsame[i].idPaziente == vEsame[j].idPaziente && //conto finche l'id && il nome dell'esame non cambiano
					 strcmp(vEsame[i].nomeEsame, vEsame[j].nomeEsame) == 0 ) {

			numVolteFatto++;
			j++;

		}

		if (numVolteFatto >= 3) {

			temp = pazienti;
			while (!empty(temp)) {

				if (head(temp).idPaziente == vEsame[i].idPaziente)
					datiPaziente = head(temp);

				temp = tail(temp);
			}

			printElement(datiPaziente);
			printf("Esame: %s.\tEffettuato: %d volte.\n", vEsame[i].nomeEsame, numVolteFatto);

		}

		i = j; //condizione di incemento
	}
}