#include "traslochi.h"
#include "list.h"

//ricevuto in ingresso il nome di un file contenente i traslochi previsti,
//legga tali informazioni e restituisca l’elenco dei traslochi tramite
//una lista di strutture dati di tipo Trasloco. In caso di errore nell’apertura del
//file la funzione deve stampare un messaggio di errore, e poi deve restituire una lista vuota.
list leggiTraslochi(char* fileName)
{
	FILE *fp;
	Trasloco trasloco;
	list traslochi = emptylist();

	if ( (fp = fopen(fileName, "rt")) == NULL ) {

		printf("Errore apertura file \"%s\"\n", fileName);
		return traslochi;

	} else {

		while ( fscanf(fp, "%s %d %d\n", 
			 trasloco.cliente, &trasloco.giorno, &trasloco.stima) != EOF ) {

				 traslochi = cons(trasloco, traslochi);

		}

		return traslochi;

	}

}

//ricevuta in ingresso una lista di strutture dati di tipo Trasloco, 
//stampi a video tale elenco.
void stampaTraslochi(list elenco)
{
	while (!empty(elenco)) {
		
		printf("%s ", head(elenco).cliente);
		printf("%d ", head(elenco).giorno);
		printf("%d\n", head(elenco).stima);
		elenco = tail(elenco);
	} 
}

//ricevuta in ingresso una lista di strutture dati di tipo Trasloco, restituisca una nuova lista contenente
//le stesse strutture dati fornite in ingresso, ma ordinate in base al giorno di trasloco, in ordine crescente. A
//parità di giorno, le strutture devono essere ordinate in ordine crescente secondo la durata del trasloco, e in
//caso di parità ulteriore, in ordine lessicografico in base al nome del cliente.
list ordina(list elenco)
{
	list ordinata=emptylist();
	while(!empty(elenco)){
		ordinata=insord_p(head(elenco), ordinata); //la funzione insord_p usa come funzione comparativa compareTrasloco
		elenco=tail(elenco);
	}
	return ordinata;
}

//ricevuta in ingresso una lista di strutture dati di tipo Trasloco e un giorno specifico, restituisca una
//nuova lista contenente le stesse strutture dati relative ai traslochi che saranno effettuati nel giorno
//specificato come parametro.
list filtra(list elenco, int giorno)
{
	list traslochiPerGiorno = emptylist();

	while (elenco != NULL) {

		if (head(elenco).giorno == giorno) {

			traslochiPerGiorno = cons(head(elenco), traslochiPerGiorno);
		}

		//incremento
		elenco = tail(elenco);
	}

	return traslochiPerGiorno;
}

//ricevuta in ingresso una lista di strutture dati di tipo Trasloco, restituisca un vettore di interi allocato
//dinamicamente (eventualmente non della minima dimensione possibile), contenente i giorni in cui sono
//previsti dei traslochi, senza ripetizioni. Tramite il parametro dim passato per riferimento, la funzione deve
//restituire la dimensione (logica) del vettore. Il vettore restituito deve essere ordinato in senso crescente (si
//usi un algoritmo di ordinamento a scelta tra quelli visti a lezione).
void scambia(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubbleSort(int v[], int n)
{
	int i, ordinato = 0;

	while (n>1 && !ordinato) {

		ordinato = 1;

		for (i=0; i<n-1; i++)
			if (v[i]>v[i+1]) {

				scambia(&v[i],&v[i+1]);
				ordinato = 0;

			}
		n--;
	}
}
int * giorni(list elenco, int * dim)
{
	//creazione vett dinamico
	int dimFisica = sizeof(int) * length(elenco), i, trovato, dimLogica = 0;
	int *giorniTrasloco = (int *) malloc(dimFisica); //dim non minima

	while (elenco != NULL) {

		trovato = 0;
		//verificare se già presente nel vettore
		for (i = 0; i < dimFisica; i++) {
			if (giorniTrasloco[i] == head(elenco).giorno) {

				trovato = 1;
			}
		}
		if (!trovato) {
			giorniTrasloco[dimLogica++] = head(elenco).giorno;
		}
		//incremento
		elenco = tail(elenco);
	}

	bubbleSort(giorniTrasloco, dimLogica);

	*dim = dimLogica;
	return giorniTrasloco;
}

//ricevuta in ingresso una lista di strutture dati di tipo Trasloco, restituisca una 'nuova' lista contenente
//le stesse strutture dati fornite in ingresso, dalla quale siano stati rimossi tutti quei traslochi che, sommata la
//loro durata, eccederebbero il limite giornaliero. In particolare, se per un giorno si prevede di eccedere il
//limite, si devono eliminare tutti i traslochi previsti per quel giorno.

list elimina(list elenco)
{
	list traslochiMaxOre = emptylist(); //nuova lista
	list codaElenco, temp, temp1, temp2; // struttura riferimento di appoggio per lo scorrimento
	int orePerGiorno, step_two = 0; //ore totali in un giorno

	temp2 = elenco;

	while (!empty(temp2)) {

		codaElenco = tail(temp2);
		orePerGiorno = head(temp2).stima;

		//verifica superamento ore
		while (!empty(codaElenco) && orePerGiorno <= 8) {

			if (head(temp2).giorno == head(codaElenco).giorno) {

				orePerGiorno += head(codaElenco).stima;
			}

			codaElenco = tail(codaElenco);

		}

		if (orePerGiorno <= 8) {

			traslochiMaxOre = cons(head(temp2), traslochiMaxOre); //aggiungo a nuova lista
			temp2 = tail(temp2); //passo a verificare la successiva

		} else { //elimino tutti gli elementi con stesso giorno sfruttando filtra e differ
			
			temp = filtra(temp2, head(temp2).giorno);

			temp1 = temp2;

			temp2 = diff(temp2, temp);

			freelist(temp); //libero temp
			if (step_two)	//distrugge temp1 se passato almeno un ciclo
				freelist(temp1);
			
			step_two = 1;

		}
		
	}

	return traslochiMaxOre;

}
