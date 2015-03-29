//Bonacci Francesco 0900050944
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* OPERAZIONI PRIMITIVE */
list emptylist(void) /* costruttore lista vuota */
{
	return NULL;
}

boolean empty(list l) /* verifica se lista vuota */
{
	return (l==NULL);
}

list cons(element e, list l)
{
	list t; /* costruttore che aggiunge in testa alla lista */
	t=(list)malloc(sizeof(item));
	t->value=e;
	t->next=l;
	return(t);
}

element head(list l) /* selettore testa lista */
{
	if (empty(l)) 
		exit(-2);
	else 
		return (l->value);
}

list tail(list l) /* selettore coda lista */
{
	if (empty(l)) 
		exit(-1);
	else 
		return (l->next);
}
void freelist(list l) 
{
	if (empty(l))
		return;
	else 
	{
		freelist(tail(l));
		free(l);
	}
	return;
}

int length(list l) 
{
	int n = 0;

	while (!empty(l)) {
		n++; 
		l = tail(l); 
	}

	return n;
}

void showList(list l) 
{ 
	printf("[");
	while (!empty(l)) {
		
		printf("%d", head(l));
		l = tail(l);
		if (!empty(l)) 
			printf(", ");
	} 

	printf("]\n");
}

// NON PRIMITIVE
//list insord_p(element el, list l) 
//{
//	list pprec, patt = l, paux;
//	int trovato = 0;
//	while (patt!=NULL && !trovato) {
//
//		if (compareTrasloco(el, patt->value)<0)
//			trovato = 1;
//		else {
//			pprec = patt;
//			patt = patt->next;
//		}
//	}
//
//	paux = (list) malloc(sizeof(item));
//	paux->value = el;
//	paux->next = patt;
//	if (patt==l)
//		return paux;
//	else {
//		pprec->next = paux;
//		return l;
//	}
//}
