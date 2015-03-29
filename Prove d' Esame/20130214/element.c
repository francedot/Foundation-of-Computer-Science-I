//Bonacci Francesco 0900050944 Prova 3A

#include "element.h"

//gli elementi devono essere ordinati in modo crescente in base all’identificatore del viaggio; in caso
//di stesso identificatore, allora in ordine lessicografico rispetto al tipo di spesa; in caso di spesa uguale, in
//modo crescente in base all’importo.
int compareSpese(Spesa sp1, Spesa sp2)
{
	int result = sp1.idSpesa - sp2.idSpesa;

	if (result == 0) {

		result = strcmp(sp1.tipoSpesa, sp2.tipoSpesa);

		if (result == 0) {

			if ((sp1.importoSpesa - sp2.importoSpesa) == 0.0f)
				return 0;
			else
				return ((sp1.importoSpesa - sp2.importoSpesa) > 0) ? 1 : -1;

		}
	}

	return result;
}

int compare(element el1, element el2)
{
	//Da rimappare

	/*if (t1.giorno != t2.giorno)
			return (t1.giorno - t2.giorno);
	else {

		if (t1.stima != t2.stima)
			return (t1.stima - t2.stima);
		else
			return strcmp(t1.cliente, t2.cliente);	
	}*/

	return 0; //caso specifico
}

boolean isEqual(element el1, element el2)
{
	return (compare(el1, el2) == 0);
}

boolean isLess(element el1, element el2)
{
	return (compare(el1, el2) < 0);
}

//element getElement()
//{
//	element el;
//	scanf("%d", &el.prop);
//	return el; 
//}

//void printElement(element el)
//{
//	printf("%d", el.prop);
//}