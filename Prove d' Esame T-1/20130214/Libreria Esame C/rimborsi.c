//Bonacci Francesco 0900050944 Prova 3A

#include "rimborsi.h"

//funzioni esame

//ES.1

//legga da standard input le spese sostenute da un lavoratore e le scriva su un file di testo. In particolare,
//la procedura deve innanzitutto chiedere che venga specificata la matricola del lavoratore, e poi deve aprire
//in scrittura un file col nome opportuno, come specificato in precedenza (matricola più “.txt”). Quindi la
//procedura deve chiedere all’utente di inserire i dati relativi ad ogni spesa, e salvarli sul file di testo, ogni
//Spesa su una singola riga, i vari campi separati da uno spazio. Non è noto a priori quante spese saranno
//introdotte. L’utente segnala l’intenzione di terminare la fase di inserimento specificando come identificatore
//unico del viaggio il valore “-1”. Tramite il parametro nomeFile, la procedura deve salvare/restituire al
//chiamante il nome del file su cui sono state salvate le informazioni.
void scriviSpese(char * nomeFile)	//dimmatricola + 4
{
	FILE *fw = NULL;
	Spesa temp;
	char matricola[DIM_MATRICOLA];

	printf("Specificare la matricola: ");
	scanf("%s", matricola);

	nomeFile = strcpy(nomeFile, matricola);
	strcat(nomeFile, ".txt");

	if ((fw = fopen(nomeFile, "wt")) == NULL) {	//verificare

		perror("Impossibile aprire file in scrittura");
		exit(-1);

	}

	do {

		printf("\nNuova Spesa:\nId Spesa: ");
		scanf("%d", &temp.idSpesa);

		printf("Tipo Spesa: ");
		scanf("%s", temp.tipoSpesa);

		printf("Importo Spesa: ");
		scanf("%f", &temp.importoSpesa);

		if (temp.idSpesa != -1) {

			fprintf(fw, "%d %s %f\n", temp.idSpesa, 
					temp.tipoSpesa, temp.importoSpesa);

		}

	} while (temp.idSpesa != -1);

	printf("\n");

	fclose(fw);	//N.B CHIUSURA FILE!
	return;
}

//ricevuto in ingresso il nome di un file di testo contenente le spese di un dipendente, e un intero dim
//passato per riferimento, allochi dinamicamente memoria a sufficienza (la minima necessaria) per contenere
//le strutture dati di tipo Spesa registrate nel file. La funzione deve restituire la dimensione di tale vettore
//tramite il parametro dim. La funzione dovrà leggere il contenuto del file e copiare i dati dentro l’apposito
//vettore allocato: dovrà infine restituire un puntatore all’area di memoria allocata.
Spesa * leggiSpese(char * nomeFile, int * dim)
{
	FILE *fr = NULL;
	Spesa *speseLette = NULL, temp;
	int i = 0;

	*dim = 0;

	if ((fr = fopen(nomeFile, "rt")) == NULL) {

		perror("Impossibile aprire file in lettura");
		return speseLette;

	}

	while (fscanf(fr, "%d %s %f%\n", &temp.idSpesa, 
			temp.tipoSpesa, &temp.importoSpesa) != EOF) {

		(*dim)++;

	}

	rewind(fr);
	speseLette = (Spesa *) malloc(sizeof(Spesa) * (*dim));

	while (fscanf(fr, "%d %s %f%\n", &temp.idSpesa, 
			temp.tipoSpesa, &temp.importoSpesa) != EOF) {

				speseLette[i++] = temp;

	}

	fclose(fr);
	return speseLette;
}


//ES.2

//ricevuto in ingresso un vettore v di strutture dati di tipo Spesa rappresentante le spese effettuate da
//un impiegato in un viaggio di lavoro, e la dimensione dim di tale vettore, ordini il vettore secondo il seguente
//criterio: gli elementi devono essere ordinati in modo crescente in base all’identificatore del viaggio; in caso
//di stesso identificatore, allora in ordine lessicografico rispetto al tipo di spesa; in caso di spesa uguale, in
//modo crescente in base all’importo. Il candidato, per effettuare l’ordinamento, usi l’algoritmo MergeSort
//visto a lezione. Ovviamente si abbia cura di de-allocare eventuali aree di memoria usate
//temporaneamente per l’ordinamento.
void merge(Spesa v[], int i1, int i2, int fine, Spesa vout[])
{
	int i=i1, j=i2, k=i1;

	while ( i <= i2-1 && j <= fine ) {
		if (compareSpese(v[i], v[j]) < 0)
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
void mergeSort(Spesa v[], int first, int last, Spesa vout[]) 
{
	int mid;
	if ( first < last ) {

		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid+1, last, vout);
		merge(v, first, mid+1, last, vout);

	}
}
void ordina(Spesa * v, int dim)
{
	Spesa *temp = (Spesa *) malloc(sizeof(Spesa) * dim);
	mergeSort(v, 0, dim - 1, temp);
	free(temp);
}

//ricevuti in ingresso un vettore di strutture dati di tipo Spesa e la dimensione dim di tale vettore,
//restituisca un nuovo vettore allocato dinamicamente (non necessariamente della dimensione minima
//possibile), da cui siano stati eliminati eventuali spese duplicate. Una spesa è un duplicato di un’altra se tutti i
//campi sono identici. Tramite il parametro dimNew la funzione deve restituire la dimensione logica del nuovo
//vettore restituito come risultato.
boolean containsSpese(Spesa *spese, int dimSpese, Spesa spesa)
{
	int i, trovato = 0;

	for (i = 0; i < dimSpese; i++) {

		if (compareSpese(spese[i], spesa) == 0) {

			trovato = 1;

		}

	}

	return trovato;
}
Spesa * eliminaDuplicati(Spesa * v, int dim, int * dimNew)
{
	Spesa *speseSingle = (Spesa *) malloc(sizeof(Spesa) * dim);
	int i;

	*dimNew = 0;

	for (i = 0; i < dim; i++) {
		
		if (!containsSpese(speseSingle, *dimNew, v[i])) {

			speseSingle[(*dimNew)] = v[i];
			(*dimNew)++;

		}
	}

	return speseSingle;
}


//ES.3

//ricevuti in ingresso un vettore di strutture dati di tipo Spesa e la dimensione dim di tale vettore,
//restituisca una lista di strutture dati di tipo Rimborso. In particolare ogni Rimborso dovrà contenere tutte
//le spese relative ad uno stesso viaggio. A tal scopo si consiglia di ordinare il vettore, raggruppando così
//consecutivamente tutte le spese relative ad uno stesso viaggio.
list creaRimborsi(Spesa * v, int dim)
{
	list rimborsi = emptyList();
	int i, j, index_speseRimb, numeroSpese = 0, currentId = -1;
	Rimborso temp;
	Spesa *speseViaggio;

	ordina(v, dim);

	for (i = 0; i < dim; i++) {

		if (currentId != v[i].idSpesa) {

			if (length(rimborsi) != 0) //distruggo se ho aggiunto almeno un rimborso
				free(speseViaggio);	
			
			currentId = v[i].idSpesa;
			j = i; //indice per conoscere numSpese
			numeroSpese = 0;

			while (currentId == v[j++].idSpesa)
				numeroSpese++;

			speseViaggio = (Spesa *)malloc(sizeof(Spesa) * numeroSpese);

			index_speseRimb = 0; //indice speseViaggio in rimborso
			j = i;

			while (currentId == v[j].idSpesa)
				speseViaggio[index_speseRimb++] = v[j++];

			temp.idRimborso = currentId;
			temp.numSpeseViaggio = numeroSpese;
			temp.speseViaggio = speseViaggio;

			rimborsi = cons(temp, rimborsi);

		}
	}

	return rimborsi;
}