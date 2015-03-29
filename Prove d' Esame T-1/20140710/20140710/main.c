//Bonacci Francesco 0900050944
#include "fatture.h"
#include <string.h>

int main()
{
	//Fattura f1, f2, f3, f4;
	//FILE *fp;
	//list fatture;
	//int res, i;
	////float sum;
	//Fattura fatture[4];
	//Fattura *fattureS;

	/*Fattura *fatture;
	int dim, i;*/

	/*if ((fp = fopen("fatture.txt", "rt")) == NULL) {

		perror("Errore");
		exit(-1);
	}

	f1 = leggiUnaFattura(fp);
	f2 = leggiUnaFattura(fp);*/

	//fatture = leggiDaTastiera();

	//salvaFatture("Scrittura.txt", fatture);

	/*fatture = leggiDaFile("Scrittura.txt", &dim);*/

	/*for (i = 0; i < 2; i++) {
		printf("%d\n", fatture[i].identificatore);
		printf("%f\n", fatture[i].importo);
		printf("%s\n", fatture[i].descrizione);
	}*/

	/*fatture[0].identificatore = 2;
	fatture[0].importo = 45.6f;
	strcpy(fatture[0].descrizione, "frances");

	fatture[1].identificatore = 2;
	fatture[1].importo = 45.6f;
	strcpy(fatture[1].descrizione, "frances");

	fatture[2].identificatore = 3;
	fatture[2].importo = 48.9f;
	strcpy(fatture[2].descrizione, "ferances");

	fatture[3].identificatore = 2;
	fatture[3].importo = 12.9f;
	strcpy(fatture[3].descrizione, "enri");*/

	//res = compareFattura(f1, f2);

	//ordina(fatture, 4);

	/*fattureS = ripetuti(fatture, 4, &res);
	for (i = 0; i < 3; i++) {
		printf("%d\n", fattureS[i].identificatore);
		printf("%f\n", fattureS[i].importo);
		printf("%s\n", fattureS[i].descrizione);
	}
		system("pause");
*/

	//sum = totali(fatture, 4, "ran");

	//Il candidato realizzi nella funzione main(…) un programma che chieda all’utente di inserire le fatture e le
	//salvi in un file (nome a scelta del candidato); in seguito, il programma legga le fatture dal file, elimini le
	//eventuali ripetizioni, e calcoli (e stampi a video) la somma degli importi delle fatture relative ad una stringa
	//indicata dall’utente, che deve comparire come sottostringa nel campo descrizione delle fatture.
	//Al termine del programma, il candidato abbia cura di de-allocare tutta la memoria allocata dinamicamente,
	//ivi compresa la memoria allocata per le liste.

	list fattureDaTastiera;
	Fattura *fattureDaTesto, *fattureSingle;
	int dim, newDim;
	float importi;
	char desc[MAX_DESC];

	printf("Prego inserisca le fatture cosi' come indicato (id, importo, descrizione).\n");
	fattureDaTastiera = leggiDaTastiera();
	salvaFatture("lettura.txt", fattureDaTastiera);

	fattureDaTesto = leggiDaFile("lettura.txt", &dim);
	
	fattureSingle = ripetuti(fattureDaTesto, dim, &newDim);

	printf("Prego inserisca una parte della descrizione delle fatture di cui sommare gli importi: ");
	scanf("%s", desc);
	fflush(stdin);

	importi = totali(fattureSingle, newDim, desc);
	printf("L' importo totale delle fatture e': %f\n", importi);

	free(fattureDaTesto), free(fattureSingle);
	freelist(fattureDaTastiera);

	system("pause");

	return 0;
}