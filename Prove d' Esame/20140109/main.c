//Bonacci Francesco 0900050944 Prova1A

#include "ricette.h"

int main()
{
	//TEST ES.1
	/*Ingrediente ingredienteLetto;
	FILE *fp;
	Ricetta *ricetteLette;
	int dimRicetteLette;*/

	/*if ((fp = fopen("dieta.txt", "rt")) == NULL) {

		perror("Errore");
		exit(-1);
	}

	ingredienteLetto = leggiIngrediente(fp);
	ingredienteLetto = leggiIngrediente(fp);
	ingredienteLetto = leggiIngrediente(fp);
	ingredienteLetto = leggiIngrediente(fp);
	ingredienteLetto = leggiIngrediente(fp);
	ingredienteLetto = leggiIngrediente(fp);*/

	/*ricetteLette = leggiRicette("ricette.txt", &dimRicetteLette);

	stampaRicette(ricetteLette, dimRicetteLette);*/

	//TEST ES.2

	/*list listaDieta;
	Ricetta *ricetteLette;
	int dimRicetteLette;

	listaDieta = leggiDieta("dieta.txt");

	stampaDieta(listaDieta);

	ricetteLette = leggiRicette("ricette.txt", &dimRicetteLette);
	stampaRicette(ricetteLette, dimRicetteLette);

	ordina(ricetteLette, dimRicetteLette);
	stampaRicette(ricetteLette, dimRicetteLette);*/

	//TEST ES.3

	/*list listaDieta;
	Ricetta *ricetteLette, *ricetteFiltrate;
	int dimRicetteLette, dimRicetteFiltrate;

	listaDieta = leggiDieta("dieta.txt");
	ricetteLette = leggiRicette("ricette.txt", &dimRicetteLette);

	ricetteFiltrate = filtra(ricetteLette, dimRicetteLette, listaDieta, &dimRicetteFiltrate);

	stampaRicette(ricetteFiltrate, dimRicetteFiltrate);*/

	
	//PROGRAMMA PRINCIPALE

	list listaDieta;
	Ricetta *ricetteLette, *ricetteFiltrate;
	int dimRicetteLette, dimRicetteFiltrate;

	listaDieta = leggiDieta("dieta.txt");
	ricetteLette = leggiRicette("ricette.txt", &dimRicetteLette);

	ricetteFiltrate = filtra(ricetteLette, dimRicetteLette, listaDieta, &dimRicetteFiltrate);
	
	freeList(listaDieta), free(ricetteLette);

	ordina(ricetteFiltrate, dimRicetteFiltrate);
	printf("Ecco le ricette compatibili con la sua dieta.\n");
	stampaRicette(ricetteFiltrate, dimRicetteFiltrate);

	free(ricetteFiltrate);

	system("pause");
	return 0;
}