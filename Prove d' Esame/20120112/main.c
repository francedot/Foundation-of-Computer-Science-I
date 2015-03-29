//Bonacci Francesco 0900050944 Prova 2A

#include "dist.h"

int main()
{
	//TEST ES.1

	/*Distributore *distributoriLetti;
	int dimDistributoriLetti;

	distributoriLetti = leggiDistributori("distributori.txt", &dimDistributoriLetti);
	stampaDist(distributoriLetti, dimDistributoriLetti);

	free(distributoriLetti);*/

	//TEST ES.2

	//list provinceEstratte;
	//Distributore *distributoriLetti;
	//int dimDistributoriLetti;
	//char pr1[DIM_NOME_PROVINCIA] = "Mo";
	//char pr2[DIM_NOME_PROVINCIA];

	//provinceEstratte = estrai("regioni.txt", "Emilia_Romagna");
	//freeList(provinceEstratte);

	//diminuisci(pr2, pr1);

	//distributoriLetti = leggiDistributori("distributori.txt", &dimDistributoriLetti);
	//ordina(distributoriLetti, dimDistributoriLetti);
	//stampaDist(distributoriLetti, dimDistributoriLetti);
	//free(distributoriLetti);


	//TEST ES.3

	/*list provinceEstratte;
	Distributore *distributoriLetti, *distributoriEconomici;
	int dimDistributoriLetti, dimDistributoriEconomici;

	provinceEstratte = estrai("regioni.txt", "Emilia_Romagna");
	distributoriLetti = leggiDistributori("distributori.txt", &dimDistributoriLetti);

	distributoriEconomici = economico(distributoriLetti, dimDistributoriLetti, provinceEstratte, &dimDistributoriEconomici);
	freeList(provinceEstratte), free(distributoriLetti);

	ordina(distributoriEconomici, dimDistributoriEconomici);
	stampaDist(distributoriEconomici, dimDistributoriEconomici);
	free(distributoriEconomici);*/


	//PROGRAMMA PRINCIPALE

	list provinceEstratte;
	Distributore *distributoriLetti, *distributoriEconomici;
	char nomeRegione[DIM_NOME_REGIONE];
	int dimDistributoriLetti, dimDistributoriEconomici;

	printf("Inserisca il nome di una regione: ");
	scanf("%s", nomeRegione);

	provinceEstratte = estrai("regioni.txt", nomeRegione);
	distributoriLetti = leggiDistributori("distributori.txt", &dimDistributoriLetti);

	distributoriEconomici = economico(distributoriLetti, dimDistributoriLetti, provinceEstratte, &dimDistributoriEconomici);
	freeList(provinceEstratte), free(distributoriLetti);

	if (dimDistributoriEconomici == 0)
		printf("\nNon sono presenti distributori nella sua regione.\n\n");
	else {

		ordina(distributoriEconomici, dimDistributoriEconomici);
		printf("\nDistributori piu' economici in ordine di provincia: \n");
		stampaDist(distributoriEconomici, dimDistributoriEconomici);
		printf("\n");
	}

	free(distributoriEconomici);
	system("pause");
	return 0;
}