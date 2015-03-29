//Bonacci Francesco 0900050944 Prova 1A

#include "element.h"

int compareProgetti(Progetto p1, Progetto p2)
{
	int votoTot1 = 0, votoTot2 = 0, i;

	for (i = 0; i < NUM_VOTI; i++) {

		votoTot1 += p1.voti[i];
		votoTot2 += p2.voti[i];
	}

	return votoTot2 - votoTot1;
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
	printf("%s %d %d\n", el.nomeValutatore, el.idProgetto, el.voto);
}