//Bonacci Francesco 0900050944 Prova6A

#include "voli.h"

int main()
{
	//TEST ES.1

	/*Volo *voliLetti;
	int dimVoliLetti, uguali;
	Volo v1, v2, v3;*/

	/*voliLetti = leggiVoli("voli.txt", &dimVoliLetti);

	stampaVoli(voliLetti, dimVoliLetti);*/

	//free(voliLetti);

	/*strcpy(v1.codiceCliente, "ITE456");
	strcpy(v1.siglaAereoportoP, "BLQ");
	strcpy(v1.siglaAereoportoA, "JFK");
	v1.giornoPartenza = 289;
	strcpy(v1.codiceVolo, "AZ348");

	strcpy(v2.codiceCliente, "ITE456");
	strcpy(v2.siglaAereoportoP, "BLQ");
	strcpy(v2.siglaAereoportoA, "JFK");
	v2.giornoPartenza = 289;
	strcpy(v2.codiceVolo, "AZ348");

	strcpy(v3.codiceCliente, "ITE456");
	strcpy(v3.siglaAereoportoP, "BLQ");
	strcpy(v3.siglaAereoportoA, "CIA");
	v3.giornoPartenza = 289;
	strcpy(v3.codiceVolo, "AZ348");

	uguali = equals(v1, v2);
	uguali = equals(v1, v3);*/


	//TEST ES.2

	//Volo *voliLetti, *voliFiltrati;
	//list voliCliente;
	//int dimVoliLetti, dimVoliFiltrati;

	//voliLetti = leggiVoli("voli.txt", &dimVoliLetti);

	//voliFiltrati = filtra(voliLetti, dimVoliLetti, "JFK", &dimVoliFiltrati);
	//free(voliLetti);

	//stampaVoli(voliFiltrati, dimVoliFiltrati);
	//free(voliFiltrati);

	//voliCliente = selCliente(voliLetti, dimVoliLetti, "ITE456");
	//freeList(voliCliente);


	//TEST ES.3

	/*Volo *voliLetti;
	int dimVoliLetti;
	voliLetti = leggiVoli("voli.txt", &dimVoliLetti);

	freq(voliLetti, dimVoliLetti, "BLQ");
	free(voliLetti);*/


	//PROGRAMMA PRINCIPALE

	Volo *voliLetti;
	int dimVoliLetti;
	char aereoportoPartenza[DIM_SIGLA_AEREOPORTO];

	printf("Prego specifichi un aereoporto di partenza: ");
	scanf("%s", aereoportoPartenza);

	voliLetti = leggiVoli("voli.txt", &dimVoliLetti);

	freq(voliLetti, dimVoliLetti, aereoportoPartenza);
	
	free(voliLetti);
	system("pause");

	return 0;
}