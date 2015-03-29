//Bonacci Francesco 0900050944 Prova 5A

#include "misure.h"

//funzioni esame

//ES.1

//ricevuto in ingresso un puntatore a struttura dati FILE (rappresentante un file già aperto in lettura),
//provveda a leggere da tale file le misurazioni relative ad un solo giorno (cioè i dati presenti in una sola riga).
//La funzione deve restituire una struttura dati di tipo Giornaliero, dove devono essere memorizzati i dati
//letti.
Giornaliero leggiSingoloGiorno(FILE* fp)
{
	Giornaliero giornalieroLetto;
	char ch;
	float rilevamento;

	giornalieroLetto.rilevazioni = emptyList(); //altrimenti crashano tutte le operazioni su lista! la coda deve valere NULL (0)

	if (fscanf(fp, "%d", &giornalieroLetto.giorno) != 1) {

		perror("File giornaliero corrotto");
		system("pause");
		exit(-1);

	} else {

		ch = fgetc(fp);	//ch deve consumare sempre lo spazio bianco!!
		while (ch != 10 && ch != EOF && ch != ';' && fscanf(fp, "%f", &rilevamento) == 1) {

			giornalieroLetto.rilevazioni = cons(rilevamento, giornalieroLetto.rilevazioni);
			ch = fgetc(fp);

		}
	}

	/*if (fclose(fp) == EOF) 
		perror("Errore chiusura file giornaliero");*/

	fscanf(fp,"%*c", &ch);

	return giornalieroLetto;
}

//ricevuta in ingresso una struttura dati di tipo Giornaliero, stampi a video il giorno a cui si riferisce, e
//l’elenco delle misurazioni relative al tal giorno. Si abbia cura che i valori vengano stampati nello stesso
//ordine con cui erano memorizzati nel file di origine.
void stampaSingoloGiorno(Giornaliero m)
{
	list rilevazioniReverted = reverse(m.rilevazioni);
	list rif = rilevazioniReverted;

	printf("%d ", m.giorno);

	while (!empty(rif)) {

		printf("%.1f", head(rif));

		if (!empty(tail(rif)))
			printf(" ");
		else
			printf(";");

		rif = tail(rif);
	}

	printf("\n");

	freeList(rilevazioniReverted);
	return;
}


//ES.2

//ricevuto in ingresso il nome di un file contenente tutte le misurazioni relative ad una singola stazione di
//rilevamento, ed un intero passato per riferimento, restituisca un vettore allocato dinamicamente (della
//dimensione minima necessaria) contenente tutte le rilevazioni memorizzate nel file indicato come
//parametro. Tali informazioni devono essere restituite tramite un array di strutture dati di tipo
//Giornaliero; la dimensione dell’array deve essere restituita tramite l’intero passato per riferimento. Al
//fine di semplificare la lettura il candidato utilizzi la funzione di cui al punto precedente.
//Il candidato inoltre abbia cura che l’array sia ordinato secondo il seguente criterio: all’inizio dell’array vanno
//messe le strutture dati di tipo Giornaliero con più valori rilevati (cioè i giorni in cui sono state effettuate
//più rilevazioni di temperatura), e poi a seguire in ordine decrescente le strutture dati con meno valori
//rilevati. A tal scopo, si suggerisce di implementare una apposita funzione che effettui l’ordinamento
//richiesto.
int compareGiornalieri(Giornaliero g1, Giornaliero g2)
{
	return length(g2.rilevazioni) - length(g1.rilevazioni);
}
void scambia(Giornaliero *a, Giornaliero *b)
{
	Giornaliero tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Giornaliero a[], int iniz, int fine)
{
	Giornaliero pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareGiornalieri(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareGiornalieri(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareGiornalieri(a[i], a[iPivot]) != 0)
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
void quickSort(Giornaliero a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
Giornaliero * leggiTuttiGiorni(char * fileName, int * dim)
{
	FILE *fp = NULL;
	Giornaliero *giornalieriLetti;
	int i;

	*dim = 0;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file stazioni\n");
		system("pause");
		exit(-3);

	}

	while (!feof(fp)) {

		leggiSingoloGiorno(fp);

		(*dim)++;

	}

	rewind(fp);
	giornalieriLetti = (Giornaliero *) malloc(sizeof(Giornaliero) * (*dim));

	for (i = 0; i < *dim; i++)
		giornalieriLetti[i] = leggiSingoloGiorno(fp);

	//ordinamento
	quickSort(giornalieriLetti, *dim);

	return giornalieriLetti;
}

//ES.3

//provveda a determinare, per ogni giorno dell’anno, quante centraline hanno fornito dati per quel giorno.
//La funzione deve restituire un array di interi allocato dinamicamente, di dimensione pari a 365, che tiene
//traccia, per ogni giorno dell’anno, di quante centraline hanno registrato temperature in quel giorno (all’inizio
//dell’esecuzione tale array sarà tutto inizializzato a zero). La funzione deve chiedere all’utente di specificare il
//nome di un file contente le rilevazioni, e per ogni giorno in cui è stata memorizzata almeno una temperatura,
//deve incrementare il valore nella cella corrispondente dell’array risultato. Eseguito l’aggiornamento, la
//funzione deve chiedere all’utente di inserire un nuovo nome di file (ogni nome di file al massimo occupa 23
//caratteri). L’utente può segnalare l’intenzione di fermarsi inserendo la parola “fine”. In tal caso, la funzione
//deve stampare a video, per ogni giorno dell’anno, quante centraline hanno fornito dati, cosi ché si possano
//scegliere i giorni con più dati possibili.
int * frequenze()
{
	Giornaliero* giorniLetti;
	char nomeFile[DIM_NOME_FILE];
	int *dati = (int *) malloc(sizeof(int) * 365), dimGiorniLetti, i, day;

	//inizializzazione array a 0
	for (i = 0; i < 365; i++)
		dati[i] = 0;

	do {

		printf("Specificare il nome del file: ");
		scanf("%s", nomeFile);

		if (strcmp(nomeFile, "fine") == 0)
			break;
		
		giorniLetti = leggiTuttiGiorni(nomeFile, &dimGiorniLetti);

		for (day = 1; day <= 365; day++) {

			for (i = 0; i < dimGiorniLetti; i++) {

				if ( day == giorniLetti[i].giorno && 
						length(giorniLetti[i].rilevazioni) > 0 ) {

				dati[day-1]++;

				}
			}

		}

	} while (strcmp(nomeFile, "fine") != 0);

	//deallocazione lista dentro struttura!
	for (i = 0; i < dimGiorniLetti; i++) {
		
		freeList(giorniLetti[i].rilevazioni);

	}

	//stampa dati
	for (i = 0; i < 365; i++) {

		printf("Giorno %d. Rilevazioni effettuate: %d\n", i+1, dati[i]);

	}

	return dati;
}