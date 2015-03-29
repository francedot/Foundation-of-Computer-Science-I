//Bonacci Francesco 0900050944 Prova4A

#include "pagamenti.h"

int main()
{
	//TEST ES.1

	/*list pagamentiLetti;
	Pagamento p1, p2, p3;
	int res;

	pagamentiLetti = leggiPagamenti("20130613.txt");
	freeList(pagamentiLetti);

	p1.idCliente = 12;
	p1.idPagamento = 34;
	p1.importoPagamento = 45.4f;
	strcpy(p1.causalePagamento, "Causale");

	p2.idCliente = 12;
	p2.idPagamento = 34;
	p2.importoPagamento = 41.4f;
	strcpy(p2.causalePagamento, "Causale");

	p3.idCliente = 19;
	p3.idPagamento = 30;
	p3.importoPagamento = 45.4f;
	strcpy(p3.causalePagamento, "Causale");

	res = equals(p1, p2);
	res = equals(p1, p3);
	res = equals(p3, p2);*/


	//TEST ES.2

	/*list pagamentiLetti, pagamentiSingle;
	Pagamento *pagamentiCliente;
	int dimPagamentiCliente, i;

	pagamentiLetti = leggiPagamenti("20130613.txt");

	pagamentiSingle = cancellaDoppi(pagamentiLetti);
	freeList(pagamentiSingle);

	pagamentiCliente = elencoPag(pagamentiLetti, 23, &dimPagamentiCliente);
	freeList(pagamentiLetti);

	for (i = 0; i < dimPagamentiCliente; i++) {

		printf("%d %d %f %s\n", pagamentiCliente[i].idCliente, pagamentiCliente[i].idPagamento, 
						pagamentiCliente[i].importoPagamento, pagamentiCliente[i].causalePagamento);

	}

	free(pagamentiCliente);*/


	//TEST ES.3

	/*list pagamentiLetti = NULL;

	pagamentiLetti = leggiPagamenti("20130613.txt");

	totali(pagamentiLetti);
	freeList(pagamentiLetti);*/


	//PROGRAMMA PRINCIPALE

	list pagamentiLetti = NULL, pagamentiSingle = NULL;

	pagamentiLetti = leggiPagamenti("20130613.txt");

	pagamentiSingle = cancellaDoppi(pagamentiLetti);
	freeList(pagamentiLetti);

	totali(pagamentiSingle);
	freeList(pagamentiSingle);

	system("pause");
	return 0;
}