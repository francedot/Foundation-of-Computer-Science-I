//Bonacci Francesco 0900050944 Prova4A

#include "pagamenti.h"

//funzioni esame

//ES.1

//ricevuto come parametro il nome di un file contenente dei pagamenti, legga i dati ivi contenuti e
//restituisca come risultato una lista di strutture dati Pagamento istanziata con i dati letti. In caso di errore
//nell’apertura del file, la funzione deve stampare a video un messaggio di errore, e deve restituire una lista
//vuota. La funzione deve inoltre controllare in fase di lettura la dimensione della causale: capita infatti che nel
//file vengano inserite causali molto più lunghe di quanto previsto per il campo causale. In tal caso, la funzione
//deve leggere soltanto i primi 255 caratteri, e tralasciare i rimanenti. Si noti inoltre che tutte le linee del file
//sono sempre terminate da un carattere speciale ‘\n’, e che l’ultima riga del file è vuota.
list leggiPagamenti(char * nomeFile)
{
	FILE *fp;
	list pagamentiLetti = emptyList();
	Pagamento temp;
	char ch;
	int count;

	if ((fp = fopen(nomeFile, "r")) == NULL) {

		perror("Impossibile aprire file pagamenti");
		return pagamentiLetti;

	}

	while (fscanf(fp, "%d %d %f ", &temp.idCliente, 
				&temp.idPagamento, &temp.importoPagamento) == 3) {
		
		count = 0;
		ch = fgetc(fp);
		while (ch != 10 && ch != EOF && count < 256) {

			temp.causalePagamento[count] = ch;

			ch = fgetc(fp);
			count++;
		}

		temp.causalePagamento[count] = '\0';

		pagamentiLetti = cons(temp, pagamentiLetti);
	}

	return pagamentiLetti;
}

//ricevuto in ingresso due pagamenti p1 e p2, restituisca in uscita un intero. L’intero restituito dovrà
//essere interpretabile come “vero” qualora p1 e p2 siano uguali, o come “falso” altrimenti. Due pagamenti
//p1 e p2 sono uguali se hanno tutti i campi uguali eccetto l’importo (che quindi può essere diverso in p1 e
//p2).
int equals(Pagamento p1, Pagamento p2)
{
	return (strcmp(p1.causalePagamento, p2.causalePagamento) == 0 &&
				p1.idCliente == p2.idCliente && p1.idPagamento == p2.idPagamento);
}


//ES.2

//ricevuta in ingresso una lista di strutture dati di tipo Pagamento, restituisca in uscita una 'nuova' lista di
//strutture dati di tipo Pagamento, da cui siano stati eliminati eventuali pagamenti ripetuti. Due pagamenti
//sono ripetuti se sono uguali, secondo il criterio definito per la funzione equals(…) di cui all’esercizio
//precedente. Si noti che in caso di pagamenti ripetuti solo uno dei pagamenti ripetuti (a scelta del candidato)
//deve essere inserito nella lista restituita come risultato, mentre gli altri pagamenti vanno ignorati.
boolean contains(list l, element e)
{
	boolean found = 0;

	while(!empty(l) && !found)
	{
		found = (equals(head(l), e));
		l = tail(l);
	}

	return found;
}
list cancellaDoppi(list pag)
{
	list pagamentiSingle = emptyList();

	while (!empty(pag)) {

		if (!contains(pagamentiSingle, head(pag)))
			pagamentiSingle = cons(head(pag), pagamentiSingle);

		pag = tail(pag);

	}

	return pagamentiSingle;
}

//ricevuta in ingresso una lista di strutture dati di tipo Pagamento, e un intero rappresentante l’id di un
//cliente, restituisca in uscita un vettore di strutture dati di tipo Pagamento contenente tutti i pagamenti
//effettuati da quel cliente. Tramite il parametro dim passato per riferimento, la funzione deve restituire la
//dimensione del vettore. Tale vettore deve essere allocato dinamicamente (della dimensione strettamente
//necessaria), e inoltre deve essere ordinato in base al valore decrescente dell’importo; per valori di importo
//uguali, si ordini in base all’ordine lessicografico rispetto alla causale del pagamento. Il candidato, per
//effettuare l’ordinamento, usi l’algoritmo MergeSort visto a lezione. Ovviamente si abbia cura di deallocare
//eventuali aree di memoria usate temporaneamente per l’ordinamento.
void merge(Pagamento v[], int i1, int i2, int fine, Pagamento vout[])
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
void mergeSort(Pagamento v[], int first, int last, Pagamento vout[]) 
{
	int mid;
	if ( first < last ) {

		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid+1, last, vout);
		merge(v, first, mid+1, last, vout);

	}
}
Pagamento * elencoPag(list pag, int id_cliente, int * dim)
{
	Pagamento *pagamentiCliente = NULL, *temp = NULL;
	list rif = pag;
	int i = 0;
	
	*dim = 0;

	//scorrimento alla ricerca della dimensione dell' array dinamico
	while (!empty(rif)) {

		if (head(rif).idCliente == id_cliente)
			(*dim)++;

		rif = tail(rif);

	}

	if (*dim == 0)
		return pagamentiCliente;

	pagamentiCliente = (Pagamento *) malloc(sizeof(Pagamento) * (*dim));

	while (!empty(pag)) {

		if (head(pag).idCliente == id_cliente) {

			pagamentiCliente[i++] = head(pag);

		}

		pag = tail(pag);

	}

	//ordinamento mergesort

	temp = (Pagamento *) malloc(sizeof(Pagamento) * (*dim));
	mergeSort(pagamentiCliente, 0, (*dim) - 1, temp);
	free(temp);

	return pagamentiCliente;
}


//ES.3

//riceva in ingresso una lista di strutture dati di tipo Pagamento. La procedura deve stampare a video, per
//ogni cliente, i pagamenti a lui riferibili, correttamente ordinati come specificato nell’esercizio precedente. La
//procedura deve stampare poi anche la somma totale dei pagamenti presenti in pag e riferibili a tale cliente.
void stampaPagamentiESomma(Pagamento *pagamentiCliente, int dimPagamentiCliente)
{
	int i;
	float importoTot = 0.9f;

	printf("Cliente n. %d\n", pagamentiCliente[0].idCliente);

	for (i = 0; i < dimPagamentiCliente; i++) {

		printf("%d %d %.2f %s\n", pagamentiCliente[i].idCliente, pagamentiCliente[i].idPagamento, 
						pagamentiCliente[i].importoPagamento, pagamentiCliente[i].causalePagamento);

		importoTot += pagamentiCliente[i].importoPagamento;
	}

	printf("Importo Totale: %.2f\n\n", importoTot);
}
boolean containsClienti(int *clientiStampati, int dimClientiStampati, int idCliente)
{
	int trovato = 0, i;

	for (i = 0; i < dimClientiStampati; i++) {

		if (clientiStampati[i] == idCliente)
			trovato = 1;

	}

	return trovato;
}
void totali(list pag)
{
	//scorro la lista pagamenti pag --> per ogni pagamento.cliente
	//prendo l'elenco dei pagamenti per quel cliente (elencoPag())
	//-->stampo i pagamenti è la somma degli importi --> verificare che non si ripetino -->
	//

	Pagamento *pagamentiCliente = NULL;
	int *clientiStampati = (int *) malloc(sizeof(int) * length(pag));
	int dimPagamentiCliente, dimClientiStampati = 0;

	while(!empty(pag)) {

		if (!containsClienti(clientiStampati, dimClientiStampati, head(pag).idCliente)) {

			clientiStampati[dimClientiStampati++] = head(pag).idCliente;

			pagamentiCliente = elencoPag(pag, head(pag).idCliente, &dimPagamentiCliente);

			stampaPagamentiESomma(pagamentiCliente, dimPagamentiCliente);
			free(pagamentiCliente);
		}

		pag = tail(pag);

	}

	free(clientiStampati);
}