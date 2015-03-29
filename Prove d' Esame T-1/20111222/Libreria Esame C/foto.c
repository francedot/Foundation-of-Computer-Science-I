//Bonacci Francesco 0900050944 Prova 1A

#include "foto.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo rappresentante l’archivio, restituisca un array di strutture
//dati di tipo Foto allocato dinamicamente (della dimensione minima necessaria), contenente tutte le
//informazioni presenti nel file il cui nome è passato come parametro. Tramite il parametro dim la funzione
//deve restituire la dimensione del vettore.
Foto * leggiFoto(char* fileName, int *dim)
{
	FILE *fp;
	Foto *fotoLette;
	int i;
	char ch;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file archivio");
		system("pause");
		exit(-1);

	} else {

		fscanf(fp,"%d\n", dim);
		
		fotoLette = (Foto *) malloc(sizeof(Foto) * (*dim));

		for (i = 0; i < *dim; i++) {

			fscanf(fp, "%d %s ", &fotoLette[i].idFoto, fotoLette[i].nomeAutoreFoto);

			fotoLette[i].numTag = 0; // all' inizio no tag
			do { //c' è almeno un tag!

				fscanf(fp, "%d", &fotoLette[i].idTag[(fotoLette[i].numTag)++]);

				ch = fgetc(fp); //legge spazio

			} while (ch != ';');

		}

		fclose(fp);
		return fotoLette;

	}
}

//ricevuto in ingresso il nome di un file di testo contenente l’elenco dei tag, restituisca una lista di
//strutture dati di tipo Tag.
list leggiTag(char* fileName)
{
	FILE *fp;
	list tagLetti = emptyList();
	element temp;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		perror("Errore apertura file keyword");
		system("pause");
		exit(-2);

	} else {

		while (fscanf(fp, "%d %s\n", &temp.idTag, temp.descrizione) == 2)
			tagLetti = cons(temp, tagLetti);

		fclose(fp);
		return tagLetti;

	}
}


//ES.2

//ricevuto un vettore di strutture dati di tipo Foto, e la dimensione di tale vettore, ordini tale vettore
//in ordine lessicografico in base all’autore della foto. In caso di più foto dello stesso autore, devono comparire
//prima le foto con un numero minore di tag.
void scambia(Foto *a, Foto *b)
{
	Foto tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Foto a[], int iniz, int fine)
{
	Foto pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareFoto(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareFoto(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareFoto(a[i], a[iPivot]) != 0)
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
void quickSort(Foto a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Foto * v, int dim)
{
	quickSort(v, dim);
}

//ricevuti in ingresso un vettore di strutture dati di tipo Foto e la dimensione di tale vettore, e una lista di
//strutture dati di tipo Tag, stampi a video l’elenco delle foto, avendo cura di sostituire ai codici numerici
//identificativi delle tag le corrispondenti etichette linguistiche, come specificate tramite il parametro tagList.
//A tal fine, si suggerisce al candidato di realizzare una funzione ausiliaria che, ricevuti in ingresso la lista dei
//tag ed un codice numerico, restituisca la stringa contenente l’etichetta linguistica associata a tale codice.
char * getDescrizioneFromTag(list tagList, int idTag)
{
	char *descrizione = (char *) malloc(sizeof(char) * DIM_DESCR);

	while (!empty(tagList)) {

		if (tagList->value.idTag == idTag)
			strcpy(descrizione, head(tagList).descrizione);

		tagList = tail(tagList);
	}

	return descrizione;
}
void stampa(Foto * v, int dim, list tagList)
{
	char *descrizioneAssociata;
	int i, j;

	for (i = 0; i < dim; i++) {

		printf("%d %s ", v[i].idFoto, v[i].nomeAutoreFoto);

		for (j = 0; j < v[i].numTag; j++) {

			descrizioneAssociata = getDescrizioneFromTag(tagList, v[i].idTag[j]);
			
			printf("%s", descrizioneAssociata);
			free(descrizioneAssociata);

			if (j == v[i].numTag-1)
				printf(";\n");
			else
				printf(" ");

		}
	}
}


//ES.3

//ricevuta come parametro un vettore di strutture dati di tipo Foto e la sua dimensione dimV, restituisca
//un nuovo vettore di strutture dati di tipo Foto e la sua dimensione dimR (non necessariamente della
//dimensione minima), dove siano stati inseriti i dati contenuti nel vettore passato in input, ma con le foto
//ripetute eliminate. Due foto sono ripetute se hanno lo stesso codice identificativo e lo stesso autore. In caso
//di due foto ripetute, nel vettore risultante dovrà essere messa la foto con il numero maggiore di tag.
Foto getMaxTagFoto(Foto *v, int dimV,  Foto foto)
{
	Foto maxTagFoto;
	int i;

	maxTagFoto.numTag = -1;

	for (i = 0; i < dimV; i++) {

		if (v[i].idFoto == foto.idFoto &&
				strcmp(v[i].nomeAutoreFoto, foto.nomeAutoreFoto) == 0 &&
					v[i].numTag > maxTagFoto.numTag) {

			maxTagFoto = v[i];

		}
	}

	return maxTagFoto;
}
boolean containsFoto(Foto *v, int dimV, Foto foto)
{
	int i, trovato = 0;

	for (i = 0; i < dimV; i++) {

		if (v[i].idFoto == foto.idFoto &&
				strcmp(v[i].nomeAutoreFoto, foto.nomeAutoreFoto) == 0)
					trovato = 1;

	}

	return trovato;
}
Foto * duplicati(Foto * v, int dimV, int * dimR)
{
	Foto *fotoSingle = (Foto *) malloc(sizeof(Foto) * dimV);
	Foto fotoMaxTag;
	int i;

	*dimR = 0;

	for (i = 0; i < dimV; i++) {

		fotoMaxTag = getMaxTagFoto(v, dimV, v[i]);

		if (!containsFoto(fotoSingle, dimV, fotoMaxTag))
			fotoSingle[(*dimR)++] = fotoMaxTag;

	}

	return fotoSingle;
}
	//ALGORITMO CASO ID ORDINATI!
	//*dimR = 0;

	//while (i < dimV) {

	//	fotoMaxTag = v[i];
	//	j = i+1;

	//	while ( j < dimV && v[i].idFoto == v[j].idFoto &&
	//				strcmp(v[i].nomeAutoreFoto, v[j].nomeAutoreFoto) == 0 ) {

	//		if (v[j].numTag > fotoMaxTag.numTag)
	//			fotoMaxTag = v[j];

	//		j++;
	//	}
	//	
	//	fotoSingle[(*dimR)++] = fotoMaxTag;
	//	
	//	i = j; //condizione di incremento ciclo esterno
	//}