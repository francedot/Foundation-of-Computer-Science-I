//Bonacci Francesco 0900050944 Prova 5A

#include "dati.h"

int main()
{
	//TEST ES.1

	/*list transazioniLette;

	transazioniLette = leggiT("transazioni.txt");

	showlist(transazioniLette);*/


	//TEST ES.2

	/*list transazioniLette, transazioniOrdinate;
	int dimTransazioniOrdinate;
	int *idTransizioni, i;
	transazioniLette = leggiT("transazioni.txt");

	transazioniOrdinate = ordina(transazioniLette, "Federico Chesani", &dimTransazioniOrdinate);
	freeList(transazioniLette);

	showlist(transazioniOrdinate);

	idTransizioni = elenca(transazioniOrdinate, dimTransazioniOrdinate);
	freeList(transazioniOrdinate);

	for (i = 0; i < dimTransazioniOrdinate; i++) {

		printf("%d\n", idTransizioni[i]);

	}*/

	//free(idTransazioni);


	//TEST ES.3

	/*list transazioniLette;

	transazioniLette = leggiT("transazioni.txt");

	truffe(transazioniLette);
	freeList(transazioniLette)*/

	//PROGRAMMA PRINCIPALE

	list transazioniLette;

	transazioniLette = leggiT("transazioni2.txt");

	printf("Transazioni Registrate: \n");
	showlist(transazioniLette);

	printf("\nProbabili Truffatori e relative Transazioni: \n");
	truffe(transazioniLette);
	freeList(transazioniLette);

	system("pause");
	return 0;
}