//Bonacci Francesco 0900050944 Prova 2A

#include "magazzino.h"

int main()
{
	//TEST ES.1

	//Farmaco *farmaciLetti;
	//int dimFarmaciLetti, i;

	//farmaciLetti = leggiMagazzino("magazzino.txt", &dimFarmaciLetti);
	//scriviMagazzino("magazzinoW.txt", farmaciLetti, dimFarmaciLetti);
	//ordina(farmaciLetti, dimFarmaciLetti);

	//for (i = 0; i < dimFarmaciLetti; i++) {

	//	printf("%s %s %d %d\n", farmaciLetti[i].nome, farmaciLetti[i].nomePrincipio, 
	//					farmaciLetti[i].quantitaPrincipio, farmaciLetti[i].numConfezioni);

	//}
	//free(farmaciLetti);

	//TEST ES.2

	//list prescrizioniLette;
	//Farmaco *farmaciLetti;
	//Prescrizione p;
	//int dimFarmaciLetti, disponibilità;

	//prescrizioniLette = leggiRicetta("ricetta1.txt");

	//strcpy(p.nomeFarmaco, "Enapren");
	//p.numConfezioni = 2;

	//farmaciLetti = leggiMagazzino("magazzino.txt", &dimFarmaciLetti);
	//disponibilità = disponibile(farmaciLetti, dimFarmaciLetti, p);

	//free(farmaciLetti);


	//TEST ES.3

	//list ricetta1, ricetta2;
	//Farmaco *farmaciLetti;
	//Prescrizione p;
	//int dimFarmaciLetti, result, accettabilità;

	//strcpy(p.nomeFarmaco, "Aspriinetta");
	//p.numConfezioni = 12;

	//farmaciLetti = leggiMagazzino("magazzino.txt", &dimFarmaciLetti);

	//result = trovaGenerico(farmaciLetti, dimFarmaciLetti, p);

	//ricetta1 = leggiRicetta("ricetta1.txt");
	//ricetta2 = leggiRicetta("ricetta2.txt");

	//accettabilità = accettabile(farmaciLetti, dimFarmaciLetti, ricetta1);
	//accettabilità = accettabile(farmaciLetti, dimFarmaciLetti, ricetta2);

	//free(farmaciLetti);
	//freeList(ricetta1), freeList(ricetta2);


	//PROGRAMMA PRINCIPALE

	list ricetta1, ricetta2;
	Farmaco *farmaciLetti;
	int dimFarmaciLetti, soddisfacibileTrue, soddisfacibileFalse;

	farmaciLetti = leggiMagazzino("magazzino.txt", &dimFarmaciLetti);

	ricetta1 = leggiRicetta("ricetta1.txt");
	ricetta2 = leggiRicetta("ricetta2.txt");

	soddisfacibileTrue = accettabile(farmaciLetti, dimFarmaciLetti, ricetta1);
	soddisfacibileFalse = accettabile(farmaciLetti, dimFarmaciLetti, ricetta2);

	printf("Ricette non soddisfacibili dalla farmacia: \n");
	showList(ricetta2);

	printf("\n");

	printf("Ricette soddisfacibili dalla farmacia: \n");
	showList(ricetta1);

	free(farmaciLetti);
	freeList(ricetta1), freeList(ricetta2);

	printf("\n");

	system("pause");
	return 0;
}