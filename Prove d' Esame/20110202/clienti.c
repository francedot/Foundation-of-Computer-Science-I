//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "clienti.h"

//funzioni esame

//ES.1

//ricevuto in ingresso il nome di un file di testo contenente l’anagrafe, restituisca un vettore di strutture
//dati di tipo Cliente, allocato dinamicamente, e “riempito” con i dati presenti sul file specificato come
//parametro. A tal fine, nello StartKit sono forniti anche i file “readField.h/readField.c”, con la funzione
//readField(…).Si assuma inoltre, per semplicità, che il file di testo sia sempre “ben formato”, cioè che tutti i
//campi previsti siano sempre presenti.
Cliente * leggiClienti(char* fileName, int * dim)
{
	FILE *fp;
	Cliente *clientiLetti;
	int i;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		printf("Errore apertura file %s.\n", fileName);
		system("pause");
		exit(-1);

	} else {
		
		fscanf(fp, "%d", dim);

		clientiLetti = (Cliente *) malloc(sizeof(Cliente) * (*dim));

		for (i = 0; i < *dim; i++) {

			fscanf(fp, "%d", &clientiLetti[i].idCliente);
			fgetc(fp); //scarto ;
			readField(clientiLetti[i].indirizzoCliente, ';', fp);
			fscanf(fp, "%d", &clientiLetti[i].cap);

		}

		fclose(fp);
		return clientiLetti;
	}
}

//ricevuto in ingresso un vettore di strutture dati di tipo Cliente, stampi a video il contenuto di tale
//array.
void stampaClienti(Cliente * v, int dim)
{
	int i;

	for (i = 0; i < dim; i++) {

		printf("%d;%s;%d\n", v[i].idCliente, v[i].indirizzoCliente, v[i].cap);

	}
}


//ES.2

list leggiPref(char * fileName)
{
	FILE* fp;
	list preferenzeLette = emptyList();
	element temp;

	if ((fp = fopen(fileName, "rt")) == NULL) {

		printf("Errore apertura file %s.\n", fileName);
		system("pause");
		exit(-2);

	} else {

		while (fscanf(fp, "%d %s", &temp.idCliente, temp.keyWord) == 2)
			preferenzeLette = cons(temp, preferenzeLette);

		fclose(fp);
		return preferenzeLette;
	}
}
void stampaPref(list l)
{
	if (l != NULL) {

		printf("%d %s\n", l->value.idCliente, l->value.keyWord);
		stampaPref(tail(l));

	}
}


//ES.3

//valuti se nella lista l è presente una struttura dati di tipo Pref, con cliente uguale a quello specificato da
//id, e keyword pari a quella passata come parametro. Il risultato restituito deve poter essere interpretabile
//come vero/falso secondo la convenzione del linguaggio C. A tal scopo, si realizzi una funzione:
int cerca(list l, int id, char * keyword)
{
	Pref toSearch;
	int trovato = 0;

	toSearch.idCliente = id;
	strcpy(toSearch.keyWord, keyword);

	while (!empty(l)) {

			if (isEqual(head(l), toSearch))
				trovato = 1; 

		l = l->next;

	}

	return trovato;
}

//restituisca un valore interpretabile come “vero” se le due preferenze p1 e p2 sono uguali. Due
//preferenze sono uguali se riguardano lo stesso cliente (stesso id) e la stessa keyword.
int isEqual(Pref p1, Pref p2)
{
	return ( p1.idCliente == p2.idCliente && 
				strcmp(p1.keyWord, p2.keyWord) == 0 );
}