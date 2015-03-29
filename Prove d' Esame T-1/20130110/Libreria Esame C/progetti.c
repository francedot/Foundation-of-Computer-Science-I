//Bonacci Francesco 0900050944 Prova 1A

#include "progetti.h"

//funzioni esame

//ES.1

Progetto * leggiProgetti(char* fileName, int *dim)
{
	FILE *fr = NULL;
	Progetto *progettiLetti = NULL, temp;
	int i = 0, j;

	*dim = 0;

	if ((fr = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file progetti");
		return progettiLetti;
	}

	if (feof(fr) == EOF)
		return progettiLetti;
	else
		fscanf(fr, "%d\n", dim);

	progettiLetti = (Progetto *) malloc(sizeof(Progetto) * (*dim));

	while (fscanf(fr, "%d %f ", &temp.id, &temp.finanziamentoRichiesto) == 2) {

		if (feof(fr))
			break;
		else { //file non corrotto

			readField(temp.titolo, '\n', fr);
			
			for (j = 0; j < NUM_VOTI; j++)
				temp.voti[j] = -1;

			progettiLetti[i++] = temp;

		}
	}

	if (fclose(fr) == EOF)
		perror("Errore chiusura file progetti");

	return progettiLetti;
}

list leggiValutazioni(char* fileName)
{
	FILE *fr = NULL;
	list valutazioniLette = emptyList();
	Valutazione temp;

	if ((fr = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file valutazioni");
		return valutazioniLette;

	}

	if (feof(fr) == EOF)
		return valutazioniLette;
	
	while (fscanf(fr, "%s %d %d\n", temp.nomeValutatore, &temp.idProgetto, &temp.voto) == 3) {

		valutazioniLette = cons(temp, valutazioniLette);
		
		if (feof(fr)) //N.B feof non legge il carattere! + tipo hasNextToken di Java
			break;

	}

	if (fclose(fr) == EOF)
		perror("Errore chiusura file valutazioni");

	return valutazioniLette;
}


//ES.2

void merge(Progetto * v, int dim, list valutazioni)
{
	list rif;
	int i, indexVoti;

	for (i = 0; i < dim; i++) {

		indexVoti = 0;
		rif = valutazioni;

		while (!empty(rif)) {

			if (head(rif).idProgetto == v[i].id) {

				v[i].voti[indexVoti++] = head(rif).voto;

			}

			rif = tail(rif);
		}

		if (indexVoti < NUM_VOTI)
			for (;indexVoti < NUM_VOTI; indexVoti++)
				v[i].voti[indexVoti] = -1;

	}

	return;
}

void scambia(Progetto *a, Progetto *b)
{
	Progetto tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Progetto a[], int iniz, int fine)
{
	Progetto pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareProgetti(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareProgetti(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareProgetti(a[i], a[iPivot]) != 0)
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
void quickSort(Progetto a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Progetto * v, int dim)
{
	quickSort(v, dim);
}


//ES.3

boolean isValutato(Progetto p)
{
	int valutato = 1, i;

	for (i = 0; i < NUM_VOTI; i++) {

		if (p.voti[i] == -1)
			valutato = 0;

	}

	return valutato;
}
Progetto * finanziati(Progetto * v, int dimV, int * dimR, float soldi)
{
	Progetto *progettiFinanziati = (Progetto *) malloc(sizeof(Progetto) * dimV);
	int i;

	*dimR = 0;
	ordina(v, dimV);

	for (i = 0; i < dimV; i++) {

		if (isValutato(v[i]) && v[i].finanziamentoRichiesto <= soldi) {

			soldi -= v[i].finanziamentoRichiesto;
			progettiFinanziati[(*dimR)++] = v[i];

		}
	}

	return progettiFinanziati;
}