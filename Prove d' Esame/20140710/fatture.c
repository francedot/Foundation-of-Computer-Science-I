//Bonacci Francesco 0900050944
#include "fatture.h"
#include <string.h>
//Ricevuto in ingresso un puntatore a FILE (uno stream già aperto), legga i dati relativi ad una sola fattura
//e li restituisca in una apposita struttura dati. Si assuma che l’utente inserisca i dati in ordine, e termini ognistr
//singolo campo con un carattere invio (quindi per una fattura l’utente inserirà tre volte il carattere invio: uno
//‘\n’ dopo l’id, uno ‘\n’ dopo l’importo, e uno ‘\n’ dopo la descrizione).
Fattura leggiUnaFattura(FILE * fp)
{
	Fattura fattura;
	int fine = 0;

	while( (!fine) && (fscanf(fp, "%d\n%f\n%s%*c", &fattura.identificatore, //niente fine riga dopo stringa --> già considerato separatore
				&fattura.importo, fattura.descrizione) != EOF) ) {

		fine = 1;
		
	}

	//fflush(fp);

	return fattura;
}

//legga un insieme di fatture dal terminale, e restituisca tali informazioni in una lista di strutture dati di
//tipo Fattura. In particolare, la funzione deve come prima cosa chiedere all’utente se vuole inserire una
//fattura. Se la risposta è positiva, allora si deve leggere una fattura usando obbligatoriamente la funzione
//precedente (si passi come parametro fp la costante predefinita “stdin”, che indica appunto un file collegato
//direttamente alla tastiera dell’utente). La fattura letta dovrà essere memorizzata in una lista. Effettuata la
//lettura, la funzione dovrà ripetere il tutto richiedendo all’utente se vuole inserire una fattura, etc. . Quando
//l’utente segnalerà l’intenzione di non inserire altre fatture, la funzione dovrà terminare e restituire la lista
//con i dati letti.
list leggiDaTastiera()
{
	char risposta;
	list fatture = emptylist(); //inizializzo una lista vuota

	do {

		printf("Vuole inserire una fattura? 'S', 'N': ");
		scanf("%c%*c", &risposta);

		while (risposta != 'S' && risposta != 'N') {
			printf("Ritenta 'S', 'N': ");
			scanf("%c%*c", &risposta);
		}

		if (risposta == 'S')
			fatture = cons(leggiUnaFattura(stdin), fatture);

	} while (risposta == 'S');

	return fatture;
}

//ricevuta in ingresso il nome di un file, e una lista di strutture dati di tipo Fattura, scriva tale elenco sul
//file col nome specificato in ingresso. In particolare sulla prima riga del file si scriva il numero di fatture che
//verranno salvate (in pratica la lunghezza della lista), e a seguire tutte le fatture memorizzate nella lista,
//avendo cura di salvare ogni campo di una singola fattura su una riga a sé stante. Quindi ogni fattura
//occuperà tre righe.
void salvaFatture(char * fileName, list elenco)
{
	FILE *fp;
	int listLength;

	listLength = length(elenco);

	if ( (fp = fopen(fileName, "wt")) == NULL) {

		perror("Errore");
		exit(-2);
	}

	//STAMPA FATTURE
	fprintf(fp, "%d\n", listLength);

	while (!empty(elenco)) {
		
		fprintf(fp, "%d\n", head(elenco).identificatore);
		fprintf(fp, "%f\n", head(elenco).importo);
		fprintf(fp, "%s\n", head(elenco).descrizione);
		elenco = tail(elenco);
	} 

	fclose(fp); //BUONA PRASSI ED OBBLIGO IN C
	return;
}

//ricevuta in ingresso il nome di un file contenente le fatture salvate tramite le funzioni di cui all’Esercizio
//1, restituisca un vettore allocato dinamicamente, della dimensione minima necessaria, contenente le fatture
//salvate nel file indicato. A tal scopo, il candidato usi obbligatoriamente la funzione leggiUnaFattura(…)
//definita in precedenza. Tramite il parametro dim inoltre la funzione restituisca la dimensione del vettore
//allocato dinamicamente
Fattura* leggiDaFile(char * fileName, int * dim)
{
	FILE* fp;
	int dimVettore, i;
	Fattura *vettoreDin;

	if ( (fp = fopen(fileName, "rt")) == NULL ) {

		perror("Errore");
		exit(-3);
	}

	fscanf(fp, "%d%*c", &dimVettore);
	vettoreDin = (Fattura*) malloc(sizeof(Fattura) * dimVettore);

	for (i = 0; i < dimVettore; i++) {

		vettoreDin[i] = leggiUnaFattura(fp);
	}

	*dim = dimVettore;
	fclose(fp);
	return vettoreDin;

}

//ricevuta in ingresso un vettore di strutture dati di tipo Fattura, e la dimensione di tale vettore, lo
//ordini in base al seguente criterio: in ordine lessicografico in base alla descrizione della fattura, e a seguire in
//ordine crescente in base all’id della fattura, e poi in base all’importo. Per effettuare l’ordinamento, si usi
//l’algoritmo quick sort visto a lezione.
void ordina(Fattura * elenco, int dim)
{
	quickSortR(elenco, 0, dim - 1);
}
void quickSortR(Fattura *a, int iniz, int fine)
{
	int i, j, iPivot;
	Fattura	pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareFattura(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareFattura(a[i], pivot) >= 0) 
				j--;
			if (i < j) 
				scambia(&a[i], &a[j]);
		}
		while (i < j);

		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareFattura(a[i], a[iPivot]) != 0)
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

//restituisca un nuovo vettore di strutture dati di tipo Fattura, di dimensione eventualmente non
//minima, da cui siano state eliminate eventuali fatture ripetute presenti nel vettore di fatture fornito in
//ingresso. Può capitare infatti che un impiegato in fase di inserimento inserisca più volte la stessa fattura: due
//fatture sono da considerarsi uguali se hanno tutti e tre i campi uguali. In caso di fatture ripetute, il vettore
//restituito come risultato dovrà contenerne solo una. Tramite il parametro newDim la funzione deve restituire
//la dimensione logica del vettore restituito come risultato.
Fattura * ripetuti(Fattura * elenco, int dim, int *newDim)
{
	Fattura *single = (Fattura*) malloc(sizeof(Fattura) * dim);
	int size_s = 0;
	int i, j, trovato;

	for (i=0; i < dim; i++) {

		trovato = 0;

		for (j=0; j<size_s && !trovato; j++) {
			if (equals(elenco[i], single[j]) == TRUE)
				trovato = 1;
		}

		if (!trovato) {
			single[size_s] = elenco[i];
			size_s++;
		}
	}

	*newDim = size_s;

	return single;
}

//ricevuti in ingresso un vettore di strutture dati di tipo Fattura e la sua dimensione, e una stringa ben
//formata sub, calcoli la somma di tutti gli importi delle fatture che contengono nella loro descrizione la
//stringa sub.
float totali(Fattura * elenco, int dim, char * sub)
{
	int i;
	float sum = 0.0f;
	for (i = 0; i < dim; i++)
		if (strstr(elenco[i].descrizione, sub) != NULL)
			sum += elenco[i].importo;

	return sum;
}