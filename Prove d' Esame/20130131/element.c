//Bonacci Francesco 0900050944 Prova 2A

#include "element.h"

int compareFarmaco(Farmaco f1, Farmaco f2)
{
	int result = strcmp(f1.nomePrincipio, f2.nomePrincipio);

	if (result == 0) {

		result = f2.quantitaPrincipio - f1.quantitaPrincipio;

		if (result == 0)
			result = strcmp(f1.nome, f2.nome);

	}

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
//
//boolean isEqual(element el1, element el2)
//{
//	return (compare(el1, el2) == 0);
//}
//
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
	printf("%s %d\n", el.nomeFarmaco, el.numConfezioni);
}