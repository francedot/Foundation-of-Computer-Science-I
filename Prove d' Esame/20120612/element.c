//Bonacci Francesco 0900050944 Prova 4A

#include "element.h"

int compareSpese(Spesa sp1, Spesa sp2)
{
	int result = sp1.detraibilile - sp2.detraibilile; //D - N < 0 --> prima D

	if (result == 0)
		result = sp2.importo - sp1.importo; //ordine decrescente importo

	return result;
}

//int compare(element el1, element el2)
//{
//	//Da rimappare
//
//	/*if (t1.giorno != t2.giorno)
//			return (t1.giorno - t2.giorno);
//	else {
//
//		if (t1.stima != t2.stima)
//			return (t1.stima - t2.stima);
//		else
//			return strcmp(t1.cliente, t2.cliente);	
//	}*/
//
//	return 0; //caso specifico
//}

//boolean isEqual(element el1, element el2)
//{
//	return (compare(el1, el2) == 0);
//}

//boolean isLess(element el1, element el2)
//{
//	return (compare(el1, el2) < 0);
//}

//element getElement()
//{
//	element el;
//	scanf("%d", &el.prop);
//	return el; 
//}

void printElement(element el)
{
	printf("%s;%s;%s %d\n", el.cognome, el.nome, el.nomeFile, el.redditoAnnuale);
}