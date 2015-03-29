//Bonacci Francesco 0900050944
#include "element.h"
#include <string.h>

//compareto ordine naturale crescente
int compareTrasloco(Trasloco t1,Trasloco t2)
{
	if (t1.giorno != t2.giorno)
			return (t1.giorno - t2.giorno);
	else {

		if (t1.stima != t2.stima)
			return (t1.stima - t2.stima);
		else
			return strcmp(t1.cliente, t2.cliente);	
	}
}
//
//oolean equals(Fattura f1, Fattura f2)
//{
//	return (compareFattura(f1, f2) == 0) ? TRUE : FALSE;
//}
//
//void scambia(Fattura *a, Fattura *b)
//{
//	Fattura tmp = *a;
//	*a = *b;
//	*b = tmp;
//}