//Bonacci Francesco 0900050944 Prova 5A

#include "dati.h"
//funzioni esame

//ES.1

//ricevuto come parametro il nome di un file contenente le transazioni, legga i dati ivi contenuti e
//restituisca come risultato una lista di strutture dati Transazione istanziata con i dati letti. In caso di errore
//nell’apertura del file, la funzione deve stampare a video un messaggio di errore, e deve restituire una lista
//vuota. In caso di apertura e lettura dei dati con successo, la funzione deve effettuare comunque un ulteriore
//controllo: il numero di transazioni lette e memorizzate nella lista deve essere pari al numero intero
//specificato nella prima riga. In caso contrario, la funzione deve restituire una lista vuota poiché i dati letti
//non sono affidabili. Si noti che lo StartKit contiene il modulo “read.h/.c” con la funzione readField(…)
//che può essere usata dal candidato qualora necessario/utile.
list leggiT(char * nomeFile)
{
	FILE *fp;
	list transazioniLette = emptyList();
	Transazione temp;
	int numeroTransazioni;

	if ((fp = fopen(nomeFile, "rt")) == NULL) {

		perror("Errore apertura file transazioni");
		return transazioniLette;

	}

	fscanf(fp, "%d\n", &numeroTransazioni);

	while (fscanf(fp, "%d ", &temp.idTransazione) == 1) {

		readField(temp.titoloLibro, JOLLY, fp);
		readField(temp.nomeCognome, JOLLY, fp);
		fscanf(fp, "%c%*c", &temp.stato);

		transazioniLette = cons(temp, transazioniLette);
	}

	if (length(transazioniLette) != numeroTransazioni) {

		freeList(transazioniLette);
		return emptyList();

	}

	return transazioniLette;
}

//ricevuta in ingresso una lista l1 di strutture dati di tipo Transazione , stampi a video il contenuto
//della lista.
void showlist(list l1)
{
	while (!empty(l1)) {

		fprintf(stdout, "%d %s;%s;%c\n", head(l1).idTransazione, 
			head(l1).titoloLibro, head(l1).nomeCognome, head(l1).stato);

		l1 = tail(l1);

	}
}

//ES.2

//ricevuta in ingresso una lista di strutture dati di tipo Transazione, restituisca in uscita una nuova lista
//di strutture dati di tipo Transazione, ordinata in ordine lessicografico in base al titolo del libro acquistato.
//La nuova lista dovrà contenere solo le transazioni relative al cliente specificato tramite il parametro nome.
//Inoltre, tramite il parametro dim passato per riferimento, la funzione dovrà restituire il numero di elementi
//memorizzati nella lista.
list ordina(list t, char * nome, int * dim)
{
	list transazioniOrdinate = emptyList();

	*dim = 0;

	while (!empty(t)) {

		if (! strcmp(head(t).nomeCognome, nome)) {

			transazioniOrdinate = insord_p(head(t), transazioniOrdinate);
			(*dim)++;
		}

		t = tail(t);

	}

	return transazioniOrdinate;
}

//ricevuta in ingresso una lista di strutture dati di tipo Transazione, e il numero di elementi ivi contenuti
//tramite il parametro dim, restituisca un array di interi allocato dinamicamente, che contenga tutti gli id di
//transazione presenti nella lista, ordinato in senso crescente in base all’identificatore. Per ordinare il vettore,
//il candidato deve utilizzare l’algoritmo naiveSort visto a lezione.
void scambia(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int trovaPosMax(int v[], int n)
{
	int i, posMax=0;

	for (i=1; i<n; i++)
		if (v[posMax]<v[i]) 
			posMax=i;

	return posMax;
}
void naiveSort(int v[], int n)
{
	int p;

	while (n>1) {

		p = trovaPosMax(v,n);
		if (p<n-1) 
			scambia(&v[p],&v[n-1]);
		n--;

	}
}
int * elenca(list t, int dim)
{
	int *idTransizioni = (int *) malloc(sizeof(int) * dim);
	int i = 0;

	while (!empty(t)) {

		//idTransizioni++ = provare

		idTransizioni[i++] = t->value.idTransazione;

		t = tail(t);

	}

	//ordinamento naiveSort

	naiveSort(idTransizioni, dim);

	return idTransizioni;
}

//ES.3

//riceva in ingresso una lista di strutture dati di tipo Transazione. La procedura deve stampare a video
//tutti i clienti per i quali esiste il sospetto di una possibile truffa. Un cliente è a sospetto di truffa se esistono a
//suo nome almeno due transazioni la cui spedizione sia in stato “perduto” (‘P’) e almeno una transazione con
//spedizione in stato “rispedito” (‘R’). Inoltre, per ognuno dei clienti a sospetto di truffa, la procedura stampi a
//video anche tutti gli identificatori di transazione, in ordine crescente di id.
//Attenzione: la procedura deve stampare ogni cliente a sospetto di truffa una e una sola volta. Inoltre il
//candidato abbia cura di non generare memory leaking, tramite deallocazione opportuna delle liste e degli
//array di appoggio eventualmente creati.
void stampaIdTruffa(int *idtransazioniTruffa, int dim)
{
	int i;
	printf("ID Transizioni: \n");

	for (i = 0; i < dim; i++) {

		printf("%d\n", idtransazioniTruffa[i]);

	}

	printf("\n");
}
boolean isTruffa(list transizioniPerCliente)
{
	int numPersi = 0, numRispediti = 0;

	while (!empty(transizioniPerCliente)) {

		if (head(transizioniPerCliente).stato == 'P')
			numPersi++;
		else if (head(transizioniPerCliente).stato == 'R')
			numRispediti++;

		transizioniPerCliente = tail(transizioniPerCliente);

	}

	return (numPersi >= 2 && numRispediti >= 1);
}
boolean containsNomi(StringaNomeCognome *nomiTruffatori, int numeroTruffatori,  char* nomeTruffatore)
{
	int i, trovato = 0;

	for (i = 0; i < numeroTruffatori; i++) {

		if (strcmp(nomiTruffatori[i], nomeTruffatore) == 0)
			trovato = 1;

	}

	return trovato;
}
void truffe(list t)
{
	//scorro nelle transazioni t --> sfrutto ordina() per ricevere la lista delle transizioni per
	//il cliente di t --> verifico su questa lista la possibilità di una truffa - isTruffa() -
	//--> si tratta di una truffa se ci sono almeno due trans. con P && almeno una con R --> memorizzo
	//i nomi dei truffatori --> 
	
	list transizioniPerCliente;
	int *idTransazioniTruffa;
	int dimTransizioniPerCliente, numeroTruffatori = 0;
	StringaNomeCognome *nomiTruffatori = (StringaNomeCognome *) malloc(sizeof(StringaNomeCognome) * length(t));

	while (!empty(t)) {

		transizioniPerCliente = ordina(t, head(t).nomeCognome, &dimTransizioniPerCliente);

		if ( isTruffa(transizioniPerCliente) && 
				!containsNomi(nomiTruffatori, numeroTruffatori, head(t).nomeCognome) ) {

			strcpy(nomiTruffatori[numeroTruffatori++], head(t).nomeCognome);

			printf("Truffatore: %s\n", head(t).nomeCognome);

			idTransazioniTruffa = elenca(transizioniPerCliente, dimTransizioniPerCliente); //già in ordine

			stampaIdTruffa(idTransazioniTruffa, dimTransizioniPerCliente);
			free(idTransazioniTruffa);

		}

		freeList(transizioniPerCliente);
		t = tail(t);

	}

	free(nomiTruffatori);
	return;
}