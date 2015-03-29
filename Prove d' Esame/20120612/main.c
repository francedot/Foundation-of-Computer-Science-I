//Bonacci Francesco 0900050944 Prova 4A

#include "cliente.h"

int main()
{
	//TEST ES.1

	/*list clientiLetti;

	clientiLetti = leggiClienti("elenco.txt");
	stampaLista(clientiLetti);

	freeList(clientiLetti);*/


	//TEST ES.2

	/*Spesa * speseLette;
	int dimSpeseLette, i;

	speseLette = leggiSpese("33.txt", &dimSpeseLette);

	for (i = 0; i < dimSpeseLette; i++)
		printf("%d %s %c\n", speseLette[i].importo, 
			speseLette[i].descrizione, speseLette[i].detraibilile);

	printf("\n");

	ordina(speseLette, dimSpeseLette);

	for (i = 0; i < dimSpeseLette; i++)
		printf("%d %s %c\n", speseLette[i].importo, 
			speseLette[i].descrizione, speseLette[i].detraibilile);

	free(speseLette);*/


	//TEST ES.3

	/*list clientiLetti, clientiSingle;

	clientiLetti = leggiClienti("elenco.txt");
	clientiSingle = eliminaRipetuti(clientiLetti);
	freeList(clientiLetti);*/

	//PROGRAMMA PRINCIPALE

	list clientiLetti, clientiNonRip, temp;
	Spesa * speseLette;
	int dimSpeseLette, i;

	clientiLetti = leggiClienti("elenco.txt");
	
	clientiNonRip = eliminaRipetuti(clientiLetti);
	freeList(clientiLetti);
	
	temp = clientiNonRip;
	while(!empty(clientiNonRip)) {

		printElement(head(clientiNonRip));
		speseLette = leggiSpese(head(clientiNonRip).nomeFile, &dimSpeseLette);

		ordina(speseLette, dimSpeseLette);

		for (i = 0; i < dimSpeseLette; i++)
			printf("%d %s %c\n", speseLette[i].importo, speseLette[i].descrizione, speseLette[i].detraibilile);

		free(speseLette);

		printf("\n");

		clientiNonRip = tail(clientiNonRip);
	}

	freeList(temp);

	system("pause");
	return 0;
}