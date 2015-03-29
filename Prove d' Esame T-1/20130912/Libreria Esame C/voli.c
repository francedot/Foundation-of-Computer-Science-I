//Bonacci Francesco 0900050944 Prova6A

#include "voli.h"


//ES.1

//ricevuta come parametro il nome di un file contenente i voli prenotati tramite il sito web, legga i dati ivi
//contenuti e restituisca come risultato un vettore di strutture dati di tipo Volo, allocato dinamicamente. Non
//è noto a priori quanti voli siano registrati nel file: la funzione quindi tramite il parametro dim passato per
//riferimento deve restituire la dimensione del vettore, ovvero il numero di prenotazioni di voli lette dal file. La
//dimensione del vettore restituito deve essere la minima necessaria per contenere tutti i dati presenti nel file.
//In caso di errore nell’apertura del file, la funzione deve stampare a video un messaggio di errore, e deve
//restituire un puntatore a NULL, e il parametro dim pari a zero (nota: il programma non deve terminare).
Volo * leggiVoli(char * nomeFile, int * dim)
{
	FILE * fp;
	Volo *voliLetti = NULL;
	Volo temp;
	int i;

	*dim = 0;

	if ((fp = fopen(nomeFile, "r")) == NULL) {
	
		perror("Errore apertura file voli");
		return voliLetti;

	}

	while (fscanf(fp, "%s %s %s %d %s", temp.codiceCliente, temp.siglaAereoportoP, 
						temp.siglaAereoportoA, &temp.giornoPartenza, temp.codiceVolo) != EOF) {

		(*dim)++;

	}

	rewind(fp);

	voliLetti = (Volo *) malloc(sizeof(Volo) * (*dim));

	for (i = 0; i < *dim; i++) {

		fscanf(fp, "%s %s %s %d %s", temp.codiceCliente, temp.siglaAereoportoP, 
						temp.siglaAereoportoA, &temp.giornoPartenza, temp.codiceVolo);

		voliLetti[i] = temp;

	}

	return voliLetti;
}

//ricevuta in ingresso un vettore di strutture dati di tipo Volo, e la dimensione dim di tale vettore, stampi
//a video l’elenco delle prenotazioni.
void stampaVoli(Volo * lista, int dim)
{
	int i;
	
	for (i = 0; i < dim; i++) {

		printf("%s %s %s %d %s\n", lista[i].codiceCliente, lista[i].siglaAereoportoP, 
						lista[i].siglaAereoportoA, lista[i].giornoPartenza, lista[i].codiceVolo);

	}
}

//ricevute in ingresso due strutture dati di tipo Volo, restituisca un valore interpretabile come vero se tali
//strutture sono uguali. Due prenotazioni sono da considerarsi uguali se tutti i sotto-campi sono identici.
int equals(Volo v1, Volo v2)
{

	int uguali = strcmp(v1.codiceCliente, v2.codiceCliente);

	if (uguali == 0) {

		uguali = strcmp(v1.codiceVolo, v2.codiceVolo);

		if (uguali == 0) {

			uguali = strcmp(v1.siglaAereoportoP, v2.siglaAereoportoP);

			if (uguali == 0) {

				uguali = strcmp(v1.siglaAereoportoA, v2.siglaAereoportoA);

				if (uguali == 0) {

					uguali = v1.giornoPartenza - v2.giornoPartenza;

				}
			}
		}
	}

	return !uguali;
}


//ES.2

//ricevuto in ingresso un vettore di strutture dati di tipo Volo e la dimensione dimV di tale vettore,
//restituisca un nuovo vettore allocato dinamicamente, e che contenga i soli voli relativi all’aeroporto di
//partenza specificato tramite il parametro partenza. Il vettore restituito come risultato deve essere di
//dimensione minima possibile; la dimensione di tale vettore deve essere restituita tramite il parametro dimR.
//Inoltre il vettore restituito deve essere ordinato secondo il seguente criterio: in ordine crescente in base al
//giorno di partenza, e poi in ordine lessicografico in base al codice del volo. Per ordinare il vettore, il
//candidato deve utilizzare l’algoritmo bubbleSort visto a lezione.
void scambia(Volo *a, Volo *b)
{
	Volo tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubbleSort(Volo v[], int n)
{
	int i, ordinato = 0;

	while (n>1 && !ordinato) {

		ordinato = 1;

		for (i=0; i<n-1; i++)
			if (compare(v[i], v[i+1]) > 0) {

				scambia(&v[i],&v[i+1]);
				ordinato = 0;

			}

		n--;
	}
}
Volo * filtra(Volo * elenco, int dimV, char * partenza, int * dimR)
{
	Volo *volifiltrati = NULL;
	int i, j = 0;

	*dimR = 0; //reinizializzo per sicurezza

	for (i = 0; i < dimV; i++) {

		if ( strcmp(elenco[i].siglaAereoportoP, partenza) == 0 ) {

			(*dimR)++;

		}

	}

	if (*dimR == 0)
		return volifiltrati;

	volifiltrati = (Volo *) malloc(sizeof(Volo) * (*dimR));

	for (i = 0; i < dimV; i++) {

		if ( strcmp(elenco[i].siglaAereoportoP, partenza) == 0 ) {

			volifiltrati[j++] = elenco[i];

		}

	}

	//ordinamento bubbleSort voliFiltrati

	bubbleSort(volifiltrati, *dimR);

	return volifiltrati;
}

//ricevuta in ingresso un vettore di strutture dati di tipo Volo, e il numero di elementi ivi contenuti
//tramite il parametro dim, restituisca una lista di strutture dati di tipo Volo, contenente tutte le
//prenotazioni effettuate dal cliente specificato tramite il parametro cliente. Si faccia attenzione al fatto
//che a causa di un piccolo bug l’applicazione web ogni tanto registra due volte la stessa identica
//prenotazione. La funzione quindi deve evitare di inserire nella lista da restituire gli eventuali duplicati.
boolean contains(list l, element el)
{
	boolean found = 0;

	while(!empty(l) && !found)
	{
		found = (equals(head(l), el));
		l = tail(l);
	}

	return found;
}
list selCliente(Volo * v, int dim, char * cliente)
{
	list voliCliente = emptyList();
	int i;

	//scorro il vettore v --> verifico che la mia lista non
	//contenga già l'elemento del vettore(equals) && che 
	//il codice cliente del vettore v sia uguale a quello
	//cercato

	for (i = 0; i < dim; i++) {

		if (!contains(voliCliente, v[i]) && 
				 (strcmp(v[i].codiceCliente, cliente) == 0) ) {
			voliCliente = cons(v[i], voliCliente);

		}

	}

	return voliCliente;
}


//ES.3

//riceva in ingresso un vettore di strutture dati di tipo Volo e la sua dimensione dim, e un aeroporto di
//partenza di cui si intende fare l’analisi. La procedura deve stampare a video, per ogni cliente che parte da
//quell’aeroporto, tutti i voli prenotati da tale cliente. Il candidato utilizzi le funzioni di cui all’Esercizio 2: in
//particolare deve procedere a determinare tutte le prenotazioni che interessano l’aeroporto specificato nel
//parametro d’ingresso; quindi a partire da tale elenco, per ogni cliente, deve determinare la lista di tutte le
//prenotazioni, e deve stamparle a video. I voli relativi ad un singolo cliente devono essere stampati una e una
//sola volta, onde evitare possibili confusioni.
//Attenzione: il candidato abbia cura di non generare memory leaking, tramite deallocazione opportuna delle
//liste e degli array di appoggio eventualmente creati.
boolean containsArray(String *vettoreStringhe, int dimVettoreStringhe, char *codiceCliente)
{

	int i, trovato = 0;

	for (i = 0; i < dimVettoreStringhe; i++) {

		if (strcmp(vettoreStringhe[i], codiceCliente) == 0) {

			trovato = 1;

		}

	}

	return trovato;

}
void freq(Volo * v, int dim, char * partenza)
{
	//trovare l' array dei voli per l' aereoporto di partenza (filtra) 
	//--> scorrere l' array --> trovare la lista di voli prenotati per
	//quel cliente (selCliente) --> stampare le prenotazioni per quel cliente
	//-->stampare solo una volta per i voli per cliente! (appoggiarsi a struttuura dati
	//che andrà stampata alla fine!)

	Volo *voliPartenza;
	list voliCliente;
	int dimVoliPartenza, i, dimClientiStampati = 0;
	String *clientiStampati;

	voliPartenza = filtra(v, dim, partenza, &dimVoliPartenza);
	clientiStampati = (String *) malloc(sizeof(String) * dimVoliPartenza);

	for (i = 0; i < dimVoliPartenza; i++) {

		if (!containsArray(clientiStampati, dimClientiStampati, voliPartenza[i].codiceCliente)) {

			voliCliente = selCliente(voliPartenza, dimVoliPartenza, voliPartenza[i].codiceCliente);  
			showList(voliCliente);
			freeList(voliCliente);

			strcpy(clientiStampati[dimClientiStampati], voliPartenza[i].codiceCliente);
			dimClientiStampati++;
		}
	}

	free(voliPartenza), free(clientiStampati);
	return;
}