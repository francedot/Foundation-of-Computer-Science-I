//Bonacci Francesco 0900050944 Prova 6A 11/09/2014

#include "scommesse.h"

int main()
{
	//TEST ES.1

	/*Scommessa *scommesseLette;
	int dimScommesseLette;

	scommesseLette = leggiScommesse("registro.txt", &dimScommesseLette);

	stampaScommesse(scommesseLette, dimScommesseLette);
	free(scommesseLette);*/


	//TEST ES.2

	/*list clientiLetti;
	Scommessa *scommesseLette, *scommesseSelezionate;
	int dimScommesseLette, dimScommesseSelezionate;

	scommesseLette = leggiScommesse("registro.txt", &dimScommesseLette);

	scommesseSelezionate = seleziona(scommesseLette, dimScommesseLette, 12, &dimScommesseSelezionate);
	stampaScommesse(scommesseSelezionate, dimScommesseSelezionate);
	free(scommesseSelezionate);

	clientiLetti = leggiClienti("anagrafe.txt", scommesseLette, dimScommesseLette);

	freeList(clientiLetti);
	free(scommesseLette);*/


	//TEST ES.3

	/*list clientiLetti;
	Scommessa *scommesseLette;
	int dimScommesseLette;

	scommesseLette = leggiScommesse("registro.txt", &dimScommesseLette);
	clientiLetti = leggiClienti("anagrafe.txt", scommesseLette, dimScommesseLette);
	free(scommesseLette);

	stampaAssidui(clientiLetti);
	freeList(clientiLetti);*/	 //freeList modificata per deallocare anche le scommesse dei clienti
	

	//PROGRAMMA PRINCIPALE

	list clientiLetti;
	Scommessa *scommesseLette;
	int dimScommesseLette;

	scommesseLette = leggiScommesse("registro.txt", &dimScommesseLette);
	clientiLetti = leggiClienti("anagrafe.txt", scommesseLette, dimScommesseLette);
	free(scommesseLette);

	printf("Clienti Assidui: \n");
	stampaAssidui(clientiLetti);
	freeList(clientiLetti);		//freeList modificata per deallocare anche le scommesse dei clienti

	system("pause");
	return 0;
}