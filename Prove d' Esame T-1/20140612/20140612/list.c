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

/* OPERAZIONI NON PRIMITIVE */
list diff(list l1, list l2)
{
	element cur;
	list difference = NULL, temp;

	while(!empty(l1)) {

		cur = l1->value;
		if(!contains(l2, cur)) {

			temp = (list) malloc(sizeof(item));
			temp->value = cur;
			temp->next = difference;
			difference = temp;
		}

		l1 = l1->next;
	}

	return difference;
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
	while (!empty(l)) {
		
		printf("%s", head(l).cliente);
		l = tail(l);
		if (!empty(l)) 
			printf(", ");
	} 

	printf("]\n");
}

list copy(list l)
{
	if (empty(l)) 
		return l;
	else
		return cons(head(l), copy(tail(l)));
}

boolean contains(list l, element e)
{
	boolean found = 0;

	while(!empty(l) && !found)
	{
		found = (compareTrasloco(head(l), e) == 0);
		l = tail(l);
	}

	return found;
}

list deleteL(element el, list l) 
{
	if (empty(l))
		return emptylist();
	else if (compareTrasloco(el, head(l)) == 0) 
		return tail(l);
	else 
		return cons(head(l), deleteL(el, tail(l)));
}

list insord_p(element el, list l) 
{
	list pprec, patt = l, paux;
	int trovato = 0;
	while (patt!=NULL && !trovato) {

		if (compareTrasloco(el, patt->value)<0)
			trovato = 1;
		else {
			pprec = patt;
			patt = patt->next;
		}
	}

	paux = (list) malloc(sizeof(item));
	paux->value = el;
	paux->next = patt;
	if (patt==l)
		return paux;
	else {
		pprec->next = paux;
		return l;
	}
}
