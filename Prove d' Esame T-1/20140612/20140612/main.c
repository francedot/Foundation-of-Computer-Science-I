#include "traslochi.h"

int main()
{

	////TEST ES.1
	list traslochiLetti, traslochiOrd, traslochiPerGiorno, traslochiEliminati;
	element el1, el2;

	//int res;
	/*int *vettGiorni;
	int dim, i;*/

	traslochiLetti = leggiTraslochi("lavori.txt");
	//stampaTraslochi(traslochiLetti);

	//res = compareTrasloco(traslochiLetti->value, traslochiLetti->next->value);

	//traslochiOrd = ordina(traslochiLetti);
	//stampaTraslochi(traslochiOrd);

	////TEST ES.2

	/*traslochiPerGiorno = filtra(traslochiLetti, 5);
	stampaTraslochi(traslochiPerGiorno);*/

	/*vettGiorni = giorni(traslochiLetti, &dim);

	for (i = 0; i < dim; i++)
		printf("%d\n", vettGiorni[i]);*/


	////TEST ES. 3

	//traslochiEliminati = elimina(traslochiLetti);

	/*list traslochi1, traslochi2, traslochi3;

	traslochi1 = leggiTraslochi("traslochi1.txt");
	traslochi2 = leggiTraslochi("traslochi2.txt");

	traslochi3 = diff(traslochi2, traslochi1);*/

	//PROGRAMMA PRINCIPALE

	/*list traslochiLetti, traslochiEliminati, traslochiGiorno;
	int giorno;
	
	printf("Specificare un giorno dall' inizio dell' anno: ");
	scanf("%d%*c", &giorno);

	traslochiLetti = leggiTraslochi("lavori.txt");
	traslochiEliminati = elimina(traslochiLetti);
	freelist(traslochiLetti);

	traslochiGiorno = filtra(traslochiEliminati, giorno);
	freelist(traslochiEliminati);

	stampaTraslochi(traslochiGiorno);
	freelist(traslochiGiorno);*/

	system("pause");
	return 0;
}