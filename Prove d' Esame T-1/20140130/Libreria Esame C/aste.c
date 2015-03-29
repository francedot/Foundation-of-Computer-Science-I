//Bonacci Francesco 0900050944

#include "aste.h"
#include "utility.h"
#include <string.h>

//ricevuto in ingresso il nome di un file contenente gli oggetti in vendita, legga tale elenco di oggetti e
//restituisca le informazioni tramite una lista di strutture dati di tipo Oggetto. In caso di errore nell’apertura
//del file la funzione deve stampare un messaggio di errore a video e poi far terminare immediatamente il
//programma.
Data leggiData(FILE *fp)
{
	Data data;

	fscanf(fp, "%d %d %d ", &data.anno, &data.mese, &data.giorno);

	return data;

}
list leggiOggetti(char* fileName)
{
	FILE *fp;
	Oggetto temp;
	Data data;
	list oggettiLetti = emptyList();

	if ( (fp = fopen(fileName, "r")) == NULL ) {

		perror("Errore apertura File oggetti");
		exit(-1);
	} else {

		while (fscanf(fp, "%d ", &temp.idOggetto) == 1) {

			data = leggiData(fp);
			temp.dataChiusura = data;
			readField(temp.descrizioneOggetto, '\n', fp);

			oggettiLetti = cons(temp, oggettiLetti);

		}

		return oggettiLetti;

	}


}

//ricevuto in ingresso una lista di strutture dati di tipo Oggetto, restituisca una nuova lista contenente le
//stesse strutture dati fornite in ingresso, ma ordinate in base alla data di scadenza, in senso crescente. Cioè in
//cima alla lista si dovranno trovare gli oggetti la cui asta scade prima in senso temporale.
list ordinaOggetti(list elenco)
{
	return sortList(elenco);
}

//ricevuta in ingresso una lista di strutture dati di tipo Oggetto, stampi a video tale elenco.
void stampaOggetti(list elenco)
{
	showList(elenco);
}

//ricevuto in ingresso il nome di un file contenente le offerte effettuate e una struttura dati di tipo
//Oggetto, restituisca un vettore di strutture dati di tipo Offerta (vettore allocato dinamicamente e della
//dimensione minima necessaria), contenente tutte le offerte relative all’oggetto specificato. La funzione deve
//restituire la dimensione del vettore risultato tramite il parametro dim passato per riferimento. In caso di
//errore nell’apertura del file, il programma deve terminare. Si presti attenzione al fatto che per un dato
//oggetto potrebbero non esserci offerte. In tal caso la funzione deve restituire un puntatore a NULL, e dim
//pari a zero.
Offerta * leggiOfferte(char * fileName, Oggetto target, int * dim)
{

	//trovare dimensione array ossia quanti id di oggetti matchano e poi fare rewind testina con scanf
	//oppure creare due array dinamici --> (caso 1)

	FILE * fp;
	Offerta *offerteLette;
	Offerta temp;
	int dimLogica = 0, i = 0;

	if ( (fp = fopen(fileName, "rt")) == NULL ) {

		perror("Errore apertura File offerte");
		exit(-2);
	} else {

		while (fscanf(fp, "%d %d %d %d %d %f\n", 
					&temp.idCliente, &temp.idOggetto, 
						&temp.dataEffettuata.anno, &temp.dataEffettuata.mese,
							&temp.dataEffettuata.giorno , &temp.importo) != EOF) {

			if (temp.idOggetto == target.idOggetto) {

				dimLogica++;

			}

		}

		if (dimLogica == 0) {

			*dim = dimLogica;
			return NULL;

		} else {

			offerteLette = (Offerta *) malloc(sizeof(Offerta) * dimLogica);
			rewind(fp);

			while (fscanf(fp, "%d %d %d %d %d %f\n", 
					&temp.idCliente, &temp.idOggetto, 
						&temp.dataEffettuata.anno, &temp.dataEffettuata.mese,
							&temp.dataEffettuata.giorno , &temp.importo) != EOF) {

				if (temp.idOggetto == target.idOggetto) {

					offerteLette[i] = temp;
					i++;

				}

			}

			*dim = dimLogica;
			return offerteLette;

		}

	}

}

//ricevuta in ingresso un array di strutture dati di tipo Offertta, e la sua dimensione dim, stampi a
//video il contenuto dell’array.
void stampaOfferte(Offerta * leOfferte, int dim)
{
	int i;
	for (i = 0; i < dim; i++) {

		printOfferta(leOfferte[i]);

	}

	return;
}

//ricevuti in ingresso un vettore di strutture dati di tipo Offerta e la dimensione di tale vettore, ordini il
//vettore secondo il seguente criterio: in maniera crescente in base alla data in cui è stata effettuata l’offerta;
//a parità di data, in base all’importo dell’offerta (in senso crescente); a parità di importo, in base
//all’identificatore del cliente (ancora in senso crescente). A tal fine, il candidato utilizzi l’algoritmo “quick sort”
//visto a lezione.
void scambia(Offerta *a, Offerta *b)
{
	Offerta tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSortR(Offerta a[], int iniz, int fine)
{
	Offerta pivot;
	int i, j, iPivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && compareOfferte(a[i], pivot) <= 0) 
				i++;
			while (j > i && compareOfferte(a[j], pivot) >= 0) 
				j--;
			if (i < j) scambia(&a[i], &a[j]);
		}
		while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compareOfferte(a[i], a[iPivot]) != 0)
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
void quickSort(Offerta a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}
void ordina(Offerta * v, int dim)
{
	quickSort(v, dim);
}

//ricevuti come parametri un vettore di strutture dati di tipo Offerta e la sua dimensione dim, e
//l’oggetto target a cui si riferiscono le offerte, restituisca un 'nuovo' vettore di strutture dati di tipo Offerta
//e la sua dimensione dimV (non necessariamente della dimensione minima), dove siano state inserite tutte le
//offerte corrette. Una offerta è corretta se la data dell’offerta precede o è pari alla data di chiusura dell’asta
//per l’oggetto e se l’importo è sempre maggiore stretto dell’importo della precedente offerta. Si presti
//attenzione al fatto che per un dato oggetto potrebbero non esserci offerte (cioè dim pari a zero). In tal caso
//la funzione si deve limitare a restituire un puntatore a NULL e parametro dimV pari a zero.
boolean isValid(Offerta of, Oggetto og, float importoPrecedente)
{
	return ( (compareDate(of.dataEffettuata, og.dataChiusura) <= 0) && (of.importo > importoPrecedente) );
}
Offerta * filtra(Offerta * leOfferte, int dim, Oggetto target, int * dimV) //leOfferte sono già relative a target
{
	Offerta *offerteFiltrate;
	float importoPrecedente;
	int i, dimLogica = 0;;
	//scorrere leOfferte e se l' offerta è valida la prendo e metto in un altro array dinamico
	
	if (dim == 0) {	//controllo caso no offerte per oggetto

		*dimV = 0;
		return NULL;
	}

	offerteFiltrate = (Offerta *) malloc(sizeof(Offerta) * dim); //dimensione al più uguale a dim
	ordina(leOfferte, dim); //offerte da ordinare secondo data effettuata

	importoPrecedente = 0.0f;

	for (i = 0; i < dim; i++) {

		if (i > 0)
			importoPrecedente = leOfferte[i-1].importo;

		if (isValid(leOfferte[i], target, importoPrecedente)) {

			offerteFiltrate[dimLogica] = leOfferte[i];
			dimLogica++;
		
		}

	}

	if (dimLogica == 0) { //nessuna offerta valida

		*dimV = dimLogica;
		return NULL;

	} else {

		*dimV = dimLogica;
		return offerteFiltrate;

	}

}