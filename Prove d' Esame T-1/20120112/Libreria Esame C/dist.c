//Bonacci Francesco 0900050944 Prova 2A

#include "dist.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo rappresentante l’elenco dei distributori, restituisca un
//array di strutture dati di tipo Distributore allocato dinamicamente (della dimensione minima necessaria),
//contenente tutte le informazioni presenti nel file il cui nome è passato come parametro. Tramite il
//parametro dim la funzione deve restituire la dimensione del vettore allocato. La funzione abbia cura di
//gestire anche il caso in cui il file risulti essere eventualmente vuoto (restituisca cioè zero come dimensione
//del vettore: in tal caso non dovrà essere stata allocata dinamicamente alcuna memoria, ovviamente, e il
//puntatore restituito come risultato avrà valore NULL).
Distributore * leggiDistributori(char* fileName, int *dim)
{
	FILE *fp = NULL;
	Distributore *distributoriLetti = NULL, temp;
	int i;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file distributori");
		system("pause");
		exit(-1);

	}

	*dim = 0;

	if (feof(fp)) {  //file vuoto
		
		fclose(fp);
		return distributoriLetti;
		
	}
	else {

		while (fscanf(fp, "%s %s %d %d\n", temp.provincia, temp.nome, &temp.prezzoBenzina, &temp.prezzoGasolio) == 4)
			(*dim)++;

		rewind(fp);
		distributoriLetti = (Distributore *) malloc(sizeof(Distributore) * (*dim));

		for (i = 0; i < *dim; i++)
			fscanf(fp, "%s %s %d %d\n", distributoriLetti[i].provincia, 
				distributoriLetti[i].nome, &distributoriLetti[i].prezzoBenzina, 
					&distributoriLetti[i].prezzoGasolio);

		fclose(fp);
		return distributoriLetti;

	}
}

//ricevuto in ingresso un array di strutture dati di tipo Distributore e la dimensione di tale array, stampi a
//video l’elenco dei distributori con tutte le informazioni relative. In particolare, poichè i prezzi sono
//memorizzati in centesimi di euro tramite un intero, si abbia cura di stampare i prezzi nella notazione in euro.
//Ad esempio, se la benzina costa 180 centesimi di euro, a video si stampi il prezzo “1.80”.
void stampaDist(Distributore * v, int dim)
{
	float prezzoEurBenzina, prezzoEurGasolio;
	int i;

	for (i = 0; i < dim; i++) {

		prezzoEurBenzina = v[i].prezzoBenzina / 100.0f;
		prezzoEurGasolio = v[i].prezzoGasolio / 100.0f;

		printf("%s %s %.2f %.2f\n", v[i].provincia,
			v[i].nome, prezzoEurBenzina, prezzoEurGasolio);

	}
}


//ES.2

//ricevuti come parametri il nome di un file contenente le coppie regione-provincia, e una stringa
//contenente il nome di una regione, restituisca una lista contenente come elementi le sigle delle province
//relative alla regione specificata come parametro. Tali informazioni sono disponibili nel file indicato come
//parametro. Al fine di riutilizzare agilmente le librerie sulle liste viste a lezione, si suggerisce di definire un
//nuovo tipo Provincia per rappresentare la sigla della provincia.
list estrai(char * fileName, char * regione)
{
	FILE *fp = NULL;
	list provinceEstratte = emptyList();
	element temp;
	char regioneLetta[DIM_NOME_REGIONE];

	if ((fp = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file regioni");
		system("pause");
		exit(-2);

	} else {

		while (fscanf(fp, "%s %s\n", regioneLetta, temp.nome) == 2) {

			if (!strcmp(regioneLetta, regione))
				provinceEstratte = cons(temp, provinceEstratte);

		}

		fclose(fp);
		return provinceEstratte;
	}
	
}

//ricevuti un vettore di strutture dati di tipo Distributore e la dimensione di tale vettore, ordini
//tale vettore in ordine lessicografico in base alla sigla della provincia. Si noti che purtroppo il file con l’elenco
//dei distributori non usa una notazione sempre coerente: infatti alcune volte le sigle delle province sono tutte
//con caratteri maiuscoli, mentre altre volte alcuni caratteri sono maiuscoli e altri minuscoli. La funzione di
//confronto tra le stringhe contenenti le province dovrà quindi tenere conto opportunamente di tale
//differenza: si vuole ottenere cioè un confronto “case insensitive”. A tal scopo, il candidato realizzi una
//funzione di appoggio:
int compareDistributori(Distributore d1, Distributore d2)
{
	char prov1[DIM_NOME_PROVINCIA], prov2[DIM_NOME_PROVINCIA]; 
	diminuisci(prov1, d1.provincia), diminuisci(prov2, d2.provincia);

	return strcmp(prov1, prov2);
}
void scambia(Distributore *a, Distributore *b)
{
	Distributore tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Distributore a[], int iniz, int fine)
{
	Distributore pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareDistributori(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareDistributori(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareDistributori(a[i], a[iPivot]) != 0)
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
void quickSort(Distributore a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Distributore * v, int dim)
{
	quickSort(v, dim);
}

//ricevuto in ingresso una stringa ben formata source, copi in dest tutti i caratteri di source avendo
//cura di trasformare eventuali caratteri maiuscoli in minuscoli. Confrontando le stringhe ottenute non ci sarà
//più il problema delle maiuscole/minuscole.
void diminuisci(char * dest, char * source)
{
	int i = 0;
	while (source[i] != '\0') {
		if (source[i] >= 65 && source[i] <= 90) {
			dest[i] = source[i] + 32;
		} else
			dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
}


//ES.3

//ricevuta come parametro un vettore di strutture dati di tipo Distributore e la sua dimensione dimV,
//e una lista di province passate tramite il parametro elenco, restituisca un nuovo vettore di strutture dati di
//tipo Distributore e la sua dimensione dimR (non necessariamente della dimensione minima). Nel vettore
//restituito come risultato dovranno essere inseriti, per ogni provincia specificata nella lista elenco, il
//distributore sito in tale provincia con il prezzo minore per la benzina. Qualora non esista un distributore per
//la provincia specificata, nel vettore restituito come risultato non dovrà essere inserita alcuna informazione
//relativamente a tale provincia. Il candidato rammenti anche il problema della notazione differente con
//maiuscole/minuscole nella specifica della sigla delle province.
Distributore * economico(Distributore * v, int dimV, list elenco, int * dimR)
{
	Distributore *distributoriEconomici = (Distributore *) malloc(sizeof(Distributore) * dimV);
	Distributore piuEconomico;
	int i;
	char prov1[DIM_NOME_PROVINCIA], prov2[DIM_NOME_PROVINCIA];

	ordina(v, dimV); //vettore ordinato per provincia
	*dimR = 0; //dimensione logica distEconomic

	while (!empty(elenco)) {

		diminuisci(prov1, head(elenco).nome); //nome della provincia in elenco tolowercase

		piuEconomico.prezzoBenzina = INT_MAX;
		for (i = 0; i < dimV; i++) {

			diminuisci(prov2, v[i].provincia);

			if (strcmp(prov1, prov2) == 0 && v[i].prezzoBenzina < piuEconomico.prezzoBenzina) {

				piuEconomico = v[i];

			}

		}
		
		if (piuEconomico.prezzoBenzina != INT_MAX)
			distributoriEconomici[(*dimR)++] = piuEconomico;

		elenco = tail(elenco);
	}

	return distributoriEconomici;
}