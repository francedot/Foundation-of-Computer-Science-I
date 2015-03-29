//Bonacci Francesco 0900050944 Prova 1A

#include "foto.h"

int main()
{
	//TEST ES.1
	
	/*list tagLetti;
	Foto *fotoLette;
	int dimFotoLette;

	fotoLette = leggiFoto("archivio.txt", &dimFotoLette);
	free(fotoLette);

	tagLetti = leggiTag("keyword.txt");
	freeList(tagLetti);*/


	//TEST ES.2

	/*list tagLetti;
	Foto *fotoLette;
	int dimFotoLette;

	fotoLette = leggiFoto("archivio.txt", &dimFotoLette);
	ordina(fotoLette, dimFotoLette);

	tagLetti = leggiTag("keyword.txt");

	stampa(fotoLette, dimFotoLette, tagLetti);

	freeList(tagLetti);
	free(fotoLette);*/


	//TEST ES.3

	/*Foto *fotoLette, *fotoSingle;
	int dimFotoLette, dimFotoSingle;

	fotoLette = leggiFoto("archivio.txt", &dimFotoLette);
	fotoSingle = duplicati(fotoLette, dimFotoLette, &dimFotoSingle);
	
	free(fotoLette), free(fotoSingle);*/


	//PROGRAMMA PRINCIPALE

	list tagLetti;
	Foto *fotoLette, *fotoSingle;
	int dimFotoLette, dimFotoSingle;

	fotoLette = leggiFoto("archivio1.txt", &dimFotoLette);
	
	fotoSingle = duplicati(fotoLette, dimFotoLette, &dimFotoSingle);
	free(fotoLette);

	tagLetti = leggiTag("keyword.txt");

	stampa(fotoSingle, dimFotoSingle, tagLetti);
	freeList(tagLetti), free(fotoSingle);

	system("pause");
	return 0;
}