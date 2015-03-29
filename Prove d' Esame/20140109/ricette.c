//Bonacci Francesco 0900050944 Prova1A

#include "ricette.h"

//ricevuto in ingresso un puntatore ad un file, legga da tale file il nome e la quantità di un ingrediente, e
//restituisca tali valori tramite una struttura dati di tipo Ingrediente. Qualora vi siano problemi nella lettura,
//la funzione deve restituire un ingrediente dal nome “NULL” e quantità pari a zero.
Ingrediente leggiIngrediente(FILE * fp)
{

	Ingrediente ingredienteLetto;

	if (fp == NULL) {

		perror("File non aperto in lettura");
		exit(-1);
	}

	if (fscanf(fp, "%s %d", ingredienteLetto.nomeIngrediente, &ingredienteLetto.quantitaIngrediente) != 2) {

		strcpy(ingredienteLetto.nomeIngrediente, "NULL");
		ingredienteLetto.quantitaIngrediente = 0;

	}

	return ingredienteLetto;

}

//ricevuto in ingresso il nome di un file di testo contenente le ricette, restituisca un array di strutture dati
//di tipo Ricetta allocato dinamicamente (della dimensione minima necessaria), contenente tutte le
//informazioni presenti nel file il cui nome è passato come parametro. Tramite il parametro dim la funzione
//deve restituire la dimensione del vettore. Qualora si verifichino dei problemi nell’apertura o nell’accesso al
//contenuto del file, la funzione deve restituire un puntatore a NULL e restituire il valore zero tramite il
//parametro dim.
Ricetta * leggiRicette(char* fileName, int *dim)
{
	
	FILE *fp;
	Ricetta ricettaTemp, *ricetteLette = NULL;
	Ingrediente ingTemp;
	int i = 0, j = 0, dimArray = 0;
	char ch;

	if ((fp = fopen("ricette.txt", "rt")) == NULL) {

		perror("Errore apertura File ricette.txt");

		*dim = 0;
		return ricetteLette;	//puntatore a NULL

	}

	while (fscanf(fp, "%s", ricettaTemp.nomeRicetta) == 1) {
			
		while ( (ch = fgetc(fp)) != '\n' && 
					strcmp((ingTemp = leggiIngrediente(fp)).nomeIngrediente, "NULL") != 0 );
			
		dimArray++;

	}

	if (dimArray == 0) {

		perror("Errore formattazione File ricette");

		*dim = 0;
		return ricetteLette;

	}

	ricetteLette = (Ricetta *) malloc(sizeof(Ricetta) * dimArray);
	rewind(fp);

	for (i = 0; i < dimArray; i++) {	//adesso ho il vantaggio di conoscere il numero delle ricette

		fscanf(fp, "%s", ricettaTemp.nomeRicetta);

		j = 0;
		while ( (ch = fgetc(fp)) != '\n' && 
					strcmp((ingTemp = leggiIngrediente(fp)).nomeIngrediente, "NULL") != 0 ) {

			ricettaTemp.ingredientiRicetta[j] = ingTemp;
			ricettaTemp.numIngredientiUsati = ++j;
		}

		ricetteLette[i] = ricettaTemp;

	}

	*dim = dimArray;
	return ricetteLette;
}

//ricevuto in ingresso un array di strutture dati di tipo Ricetta e la dimensione dim di tale vettore,
//stampi a video il contenuto di tali strutture dati.
void stampaRicette(Ricetta* leRicette, int dim)
{
	int i, j;
	for (i = 0; i < dim; i++) {

		printf("%s ", leRicette[i].nomeRicetta);

		for (j = 0; j < leRicette[i].numIngredientiUsati; j++) {

			printf("%s %d ", leRicette[i].ingredientiRicetta[j].nomeIngrediente, 
								leRicette[i].ingredientiRicetta[j].quantitaIngrediente);

			if (j == leRicette[i].numIngredientiUsati-1)
				printf("\n");

		}

	}
}

//ricevuto in ingresso il nome di un file contenente la dieta di un cliente, restituisca una lista di strutture
//dati di tipo Ingrediente opportunamente inizializzate con i dati presenti nel file. In caso di errore
//nell’apertura del file, il programma deve terminare.
list leggiDieta(char * fileName)
{
	FILE *fp;
	list listaDieta;
	Ingrediente temp;

	if ((fp = fopen(fileName, "rt")) == NULL ) {

		perror("Errore apertura File diete.txt");
		exit(-3);
	}

	listaDieta = emptyList();

	while ( strcmp((temp = leggiIngrediente(fp)).nomeIngrediente, "NULL") != 0 ) {

		listaDieta = cons(temp, listaDieta);

	}

	return listaDieta;


}

//ricevuta in ingresso una lista di strutture dati di tipo Ingrediente, ne stampi a video il contenuto.
void stampaDieta(list laDieta)
{
	while (!empty(laDieta)) {

		printElement(head(laDieta));

		laDieta = tail(laDieta);

	}
}

//ricevuti in ingresso un vettore di strutture dati di tipo Ricetta e la dimensione di tale vettore, ordini il
//vettore secondo il seguente criterio: in maniera crescente in base al numero di ingredienti presenti in ogni
//ricetta; a parità di ingredienti, in ordine lessicografico in base al nome della ricetta. A tal fine, il candidato
//utilizzi l’algoritmo naïve sort visto a lezione.
void merge(Ricetta v[], int i1, int i2, int fine, Ricetta vout[])
{
	int i=i1, j=i2, k=i1;

	while ( i <= i2-1 && j <= fine ) {
		if (compareRicette(v[i], v[j]) < 0)
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
void mergeSort(Ricetta v[], int first, int last, Ricetta vout[]) 
{
	int mid;
	if ( first < last ) {

		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid+1, last, vout);
		merge(v, first, mid+1, last, vout);

	}
}
void ordina(Ricetta * v, int dim)
{
	Ricetta *temp = (Ricetta *) malloc(sizeof(Ricetta) * dim);
	mergeSort(v, 0, dim - 1, temp);
	free(temp);
}

//ricevuti come parametri un vettore di strutture dati di tipo Ricetta e la sua dimensione dim e una lista
//contenente i vincoli della dieta, restituisca un nuovo vettore di strutture dati di tipo Ricetta e la sua
//dimensione dimR (non necessariamente della dimensione minima), dove siano state inserite tutte le ricette
//compatibili. Una ricetta è compatibile con una dieta se tutti gli ingredienti contenuti nella ricetta o (a) non
//sono soggetti a restrizioni della dieta, o (b) la ricetta prevede per un certo ingrediente una quantità minore o
//uguale al limite imposto dalla dieta.
//A tal scopo si suggerisce di implementare le seguenti funzioni ausiliarie:
//int ingredienteCompatibile(Ingrediente ing, list laDieta);
//che valuta se un certo ingrediente è compatibile con una dieta specificata;
//e la funzione:
//int ricettaCompatibile(Ricetta r, list laDieta);
//che valuta se una ricetta è compatibile con una dieta.
int ricettaCompatibile(Ricetta r, list laDieta)
{
	//per ogni ricetta scorro l' array di ingredienti
	//--> verifico che tutti ingrediente sia comptibile con 
	//laDieta (ingrdienteCompatibile)
	int i;
	for (i = 0; i < r.numIngredientiUsati; i++) {

		if (!ingredienteCompatibile(r.ingredientiRicetta[i], laDieta)) {

			return 0;

		}

	}

	return 1;;
}
int ingredienteCompatibile(Ingrediente ing, list laDieta)
{
	//scorro la lista laDieta --> per ogni ingrediente verifico che
	//o esso non abbia il nome di ing (non compaia) o che la sua quantita
	//sia minore di quella di ing
	int compatibile = 1;
	while (!empty(laDieta)) {

		if (strcmp(head(laDieta).nomeIngrediente, ing.nomeIngrediente) == 0) { //se l'ingrediente compare

			if (ing.quantitaIngrediente > head(laDieta).quantitaIngrediente) { //se la quantita nella ricetta è > della tollerata

				compatibile = 0;

			}

		}

		laDieta = tail(laDieta);

	}

	return compatibile;
}
Ricetta * filtra(Ricetta * leRicette, int dim, list laDieta, int * dimR)
{
	Ricetta *ricetteFiltrate = (Ricetta *) malloc(sizeof(Ricetta) * dim);
	int  i, j = 0;

	for (i = 0; i < dim; i++) {

		if (ricettaCompatibile(leRicette[i], laDieta)) {

			ricetteFiltrate[j++] = leRicette[i];

		}

	}
	
	*dimR = j;
	return ricetteFiltrate;
}
