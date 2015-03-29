//Bonacci Francesco 0900050944

#include "beni.h"
#include "utility.h"
#include <string.h>

//ricevuto in ingresso il nome di un file contenente i beni disponibili, legga tali informazioni e restituisca
//l’elenco dei beni tramite una lista di strutture dati di tipo Bene. In caso di errore nell’apertura del file la
//funzione deve stampare un messaggio di errore, e poi deve chiedere esplicitamente all’utente se si vuole
//riprovare ad aprire il file: l’utente deve specificare una risposta tramite un solo carattere (‘s’ o ‘n’, seguito da
//invio), in base al quale il programma deve riprovare ad aprire il file oppure terminare immediatamente. Il
//programma deve continuare a provare ad aprire il file fino a che non ha successo e fino a che l’utente
//continua a specificare la risposta ‘s’.
list leggiBeni(char* fileName)
{
	FILE *fp;
	list beniLetti;
	Bene temp;
	char risposta;

	//apertura
	do {

		fp = fopen(fileName, "rt");

		if (fp == NULL) {

			perror("Errore apertura file");
			do {

				printf("Riprovare? (s/n): ");
				scanf("%c%*c", &risposta);

			} while (risposta != 's' && risposta != 'n');
		}


	} while (fp == NULL && risposta == 's');

	beniLetti = emptyList();
	//lettura

	while (fscanf(fp, "%s %f %d ", 
				temp.id, &temp.prezzo, 
					&temp.numMinimo) == 3) {

		readField(temp.descrizione, '\n', fp);

		beniLetti = cons(temp, beniLetti);
	}

	return beniLetti;

}

//ricevuto in ingresso una lista di strutture dati di tipo Bene, restituisca una nuova lista contenente le
//stesse strutture dati fornite in ingresso, ma ordinate in base alla descrizione del bene (ordine lessicografico),
//e a parità di descrizione in base al prezzo per unità, in senso crescente. Per generare la nuova lista, si utilizzi
//una delle funzioni di inserimento ordinato per le liste viste a lezione, e non si usino gli algoritmi di
//ordinamento per array.
list ordinaBeni(list elenco)
{
	return sortList(elenco);
}

//ricevuta in ingresso una lista di strutture dati di tipo Bene, stampi a video tale elenco.
void stampaBeni(list elenco)
{
	showList(elenco);
}

//ricevuto in ingresso una lista di strutture dati di tipo Bene e una stringa rappresentante la parola chiave,
//restituisca un array di strutture dati di tipo Bene, allocato dinamicamente e della dimensione minima
//necessaria, contenente tutti i beni nella cui descrizione è presente la parola chiave specificata. Tramite il
//parametro dim passato per riferimento la funzione deve restituire la dimensione del vettore risultato.
//Qualora non vi siano beni la cui descrizione contiene la parola-chiave cercata, la funzione deve restituire un
//puntatore a NULL e dimensione pari a zero.
Bene * estrai(list elenco, char * keyword, int * dim)
{
	list temp = elenco;	//puntatore di supporto per primo scorrimento
	Bene *arrayBeni;
	int i = 0;
	*dim = 0;

	//ricavare dimensione array dinamico 
	while (!empty(temp)) {

		if (strstr(head(temp).descrizione, keyword) != NULL) {

			(*dim)++;
		}

		temp = tail(temp);

	}

	if (*dim != 0) {
	
		arrayBeni = (Bene *) malloc(sizeof(Bene) * (*dim));

		while (!empty(elenco)) {

			if (strstr(head(elenco).descrizione, keyword) != NULL) {

				arrayBeni[i] = head(elenco);
				i++;
			}

			elenco = tail(elenco);

		}

		return arrayBeni;

	} else {

		return NULL;
	}

	
}

//ricevuti in ingresso un vettore di strutture dati di tipo Bene e la dimensione di tale vettore, ordini il
//vettore secondo il seguente criterio: in ordine lessicografico in base alla descrizione del bene, e a parità di
//descrizione in base all’importo in senso crescente. A tal fine, il candidato utilizzi l’algoritmo “Merge Sort”
//visto a lezione.
void merge(Bene v[], int i1, int i2, int fine, Bene vout[])
{
	int i=i1, j=i2, k=i1;

	while ( i <= i2-1 && j <= fine ) {
		if (isLess(v[i], v[j]))
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}

	while (i<=i2-1) { 
		vout[k] = v[i++]; 
		k++;
	}

	while (j<=fine) { 
		vout[k] = v[j++]; 
		k++; 
	}

	for (i=i1; i<=fine; i++) 
		v[i] = vout[i];
}
void mergeSort(Bene v[], int first, int last, Bene vout[]) 
{
	int mid;
	if ( first < last ) {

		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid+1, last, vout);
		merge(v, first, mid+1, last, vout);

	}
}
void ordina(Bene * v, int dim)
{
	Bene *temp = (Bene *) malloc(sizeof(Bene) * dim);
	mergeSort(v, 0, dim - 1, temp);
	free(temp);
}

//ricevuta in ingresso un array di strutture dati di tipo Bene, e la sua dimensione dim, stampi a video il
//contenuto dell’array.
void stampaVettBeni(Bene * iBeni, int dim)
{
	int i;
	for (i = 0; i < dim; i++) {
		
		printf("%s %f %d %s\n", iBeni[i].id, 
				iBeni[i].prezzo, iBeni[i].numMinimo, iBeni[i].descrizione);

	}
}

//ricevuti come parametri una lista di strutture dati di tipo Bene, una parola-chiave da cercare, il numero
//di pezzi da acquistare e il budget disponibile, restituisca l’offerta più vantaggiosa per il bene da acquistare. A
//tal scopo il candidato utilizzi la funzione di cui al punto precedente per trovare i beni la cui descrizione
//contiene la parola-chiave specificata. Il candidato poi abbia cura di verificare nella funzione che il numero di
//pezzi da acquistare sia maggiore o uguale al numero minimo specificato nella struttura dati di tipo Bene, e
//che il costo totale sia inferiore o uguale al budget specificato. Infine il candidato si assicuri che la struttura
//dati restituita sia effettivamente la più economica possibile.
//Qualora non vi sia alcun bene acquistabile secondo i criteri specificati, la funzione restituisca una struttura
//dati il cui identificatore unico sia “NULL”.
boolean isValid(Bene bene, int num, float budget)
{

	//isValid -->true se:
	//num >= numMinimo del bene &&
	//num*prezzoBene <= budget

	return ( num >= bene.numMinimo && (num*(bene.prezzo) <= budget) );

}
Bene effettivo(list elenco, char * keyword, int num, float budget)
{
	Bene *estratti, estrattiValidi;
	int dimEstratti, i;
	Bene beneCorrente;
	float totaleCorrente = 1000, totaleEstratto;

	strcpy(beneCorrente.id, "NULL");

	estratti = estrai(elenco, keyword, &dimEstratti); //da deallocare

	for (i = 0; i < dimEstratti; i++) {

		if (isValid(estratti[i], num, budget)) {

			totaleEstratto = estratti[i].prezzo * num;

			if (totaleEstratto < totaleCorrente) {

				totaleCorrente = totaleEstratto;
				beneCorrente = estratti[i];

			}
		}
	}

	free(estratti);
	return beneCorrente;

}
