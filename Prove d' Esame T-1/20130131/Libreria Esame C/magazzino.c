//Bonacci Francesco 0900050944 Prova 2A

#include "magazzino.h"

//funzioni esame

//ES.1

Farmaco * leggiMagazzino(char* fileName, int *dim)
{
	FILE *fr = NULL;
	Farmaco *farmaciLetti = NULL;
	Farmaco temp;
	int i;

	*dim = 0;

	if ((fr = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file farmaci");
		return farmaciLetti;

	}

	while (fscanf(fr, "%s %s %d %d\n", temp.nome, temp.nomePrincipio, 
					&temp.quantitaPrincipio, &temp.numConfezioni) == 4) {

		(*dim)++;

		if (feof(fr))
			break;

	}

	rewind(fr);
	farmaciLetti = (Farmaco *) malloc(sizeof(Farmaco) * (*dim));

	for (i = 0; i < *dim; i++) {

		fscanf(fr, "%s %s %d %d\n", farmaciLetti[i].nome, farmaciLetti[i].nomePrincipio, 
						&farmaciLetti[i].quantitaPrincipio, &farmaciLetti[i].numConfezioni);

	}

	if (fclose(fr) == EOF)
		perror("Errore chiusura file farmaci");

	return farmaciLetti;
}

void scriviMagazzino(char* fileName, Farmaco * v, int dim)
{
	FILE *fw = NULL;
	int i;

	if ((fw = fopen(fileName, "wt")) == NULL) {
		
		perror("Errore apertura file in scrittura");
		exit(-1);

	}

	for (i = 0; i < dim; i++) {

		fprintf(fw, "%s %s %d %d\n", v[i].nome, v[i].nomePrincipio, 
						v[i].quantitaPrincipio, v[i].numConfezioni);

	}

	if (fclose(fw) == EOF)
		perror("Errore chiusura file in scrittura");
	
	return;
}

void insOrd(Farmaco v[], int pos)
{
	int i = pos-1;
	Farmaco x = v[pos];

	while (i>=0 && compareFarmaco(x, v[i]) < 0) {
		v[i+1]= v[i]; /* crea lo spazio */
		i--;
	}

	v[i+1]=x; /* inserisce l’elemento */
}
void insertSort(Farmaco v[], int n)
{
	int k;
	for (k=1; k<n; k++)
	insOrd(v,k);
}
int ordina(Farmaco * v, int dim)
{
	insertSort(v, dim);
	return 0;
}


//ES.2

list leggiRicetta(char * fileName)
{
	FILE *fr = NULL;
	list prescrizioniLette = emptyList();
	Prescrizione temp;

	if ((fr = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file prescrizioni");
		return prescrizioniLette;

	}
	
	while (fscanf(fr, "%s %d\n", temp.nomeFarmaco, &temp.numConfezioni) == 2) {

		prescrizioniLette = cons(temp, prescrizioniLette);

		if (feof(fr) == EOF)
			break;

	}

	if (fclose(fr) == EOF)
		perror("Errore chiusura file prescrizioni");

	return prescrizioniLette;
}

int disponibile(Farmaco * v, int dim, Prescrizione p)
{
	int i, result = -2;

	for (i = 0; i < dim; i++) {

		if (strcmp(v[i].nome, p.nomeFarmaco) == 0) {

			result = -1;

			if (v[i].numConfezioni >= p.numConfezioni) {

				result = i;

			}
		}
	}

	return result;
}


//ES.3
boolean equivalenti(Farmaco f1, Farmaco f2)
{
	return (strcmp(f1.nomePrincipio, f2.nomePrincipio) == 0 && f1.quantitaPrincipio == f2.quantitaPrincipio);
}

int trovaGenerico(Farmaco * v, int dim, Prescrizione p)
{
	int i, result = -2;
	Farmaco farmacoCercato;

	strcpy(farmacoCercato.nome, p.nomeFarmaco);
	farmacoCercato.numConfezioni = p.numConfezioni;

	for (i = 0; i < dim; i++) {

		if (strcmp(p.nomeFarmaco, v[i].nome) == 0) {

			strcpy(farmacoCercato.nomePrincipio, v[i].nomePrincipio); //nome principio trovato
			farmacoCercato.quantitaPrincipio = v[i].quantitaPrincipio; // quantita trovata

		}
	}

	for (i = 0; i < dim; i++) {

		if (equivalenti(v[i], farmacoCercato)) {

			result = -1;

			if (v[i].numConfezioni >= farmacoCercato.numConfezioni) {

				result = i;
				break; //meglio di cosi non può andare

			}
		}
	}

	return result;
}

int accettabile(Farmaco * v, int dim, list ricetta)
{
	int result = 1;

	while(!empty(ricetta)) {

		if (trovaGenerico(v, dim, head(ricetta)) < 0)
			result = 0;

		ricetta = tail(ricetta);
	}

	return result;
}