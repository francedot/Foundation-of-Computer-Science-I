//Bonacci Francesco 0900050944

#include "list.h"


/* PRIMITIVE */
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

list emptyList(void) /* costruttore lista vuota */
{
	return NULL;
}

boolean empty(list l) /* verifica se lista vuota */
{
	return (l==NULL);
}


/* NON PRIMITIVE */
boolean contains(list l, element e)
{
	boolean found = 0;

	while(!empty(l) && !found)
	{
		found = (compare(head(l), e) == 0);
		l = tail(l);
	}

	return found;
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

list append(list l1, list l2) 
{
	if (empty(l1)) 
		return l2;
	else 
		return cons(head(l1), append(tail(l1),l2));
}

list reverse(list l) 
{
	if (empty(l)) 
		return emptyList();
	else 
		return append(reverse(tail(l)), cons(head(l), emptyList()));
}

list copy(list l)
{
	if (empty(l)) 
		return l;
	else
		return cons(head(l), copy(tail(l)));
}

list deleteEl(element el, list l) 
{
	if (empty(l))
		return emptyList();
	else if (compare(el, head(l)) == 0) 
		return tail(l);
	else 
		return cons(head(l), deleteEl(el, tail(l)));
}

list insord_p(element el, list l)
{
	list pprec, patt = l, paux;
	int trovato = 0;
	while (patt!=NULL && !trovato) {

		if (compare(el, patt->value) < 0)
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

list sortList(list l)
{
	list ord = emptyList();
	while(!empty(l)) {

		ord = insord_p(head(l), ord); //la funzione insord_p usa come funzione comparativa compare
		l = tail(l);
	}
	return ord;
}

//list mergeList(list l1, list l2) 
//{
//	if (empty(l1)) 
//		return l2;
//	else if (empty(l2)) 
//		return l1;
//	else { 
//
//		if (isLess(head(l1), head(l2)))
//			return cons(head(l1), mergeList(tail(l1), l2));
//
//		else if (isEqual(head(l1), head(l2)))
//			return cons(head(l1), mergeList(tail(l1), tail(l2)));
//
//		else 
//			return cons(head(l2), mergeList(l1,tail(l2)));
//	}
//
//} 

list subList(int n, list l) 
{
	int i = 1;
	while ((l!=NULL) && (i<n)) {
		l = l->next;
		i++; 
	}

	return l; 
}

void showList(list l) 
{ 
	while (!empty(l)) {
		
		printf("%s %f %d %s\n", head(l).id, 
				head(l).prezzo, head(l).numMinimo, head(l).descrizione);

		l = tail(l);

	} 
}

void freeList(list l) 
{
	if (empty(l))
		return;
	else 
	{
		freeList(tail(l));
		free(l);
	}
	return;
}

list diff(list l1, list l2)
{
	element cur;
	list difference = NULL, temp;

	while(!empty(l1)) {

		cur = l1->value;
		if(!contains(l2, cur) && !contains(difference, cur)) { //per evitare elementi ripetuti nel risultato

			temp = (list) malloc(sizeof(item));
			temp->value = cur;
			temp->next = difference;
			difference = temp;
		}

		l1 = l1->next;
	}

	return difference;	
}

list intersect(list l1, list l2)
{
	element cur;
	list intersection = emptyList();
	while(!empty(l1))
	{
		cur = head(l1);
		if(contains(l2, cur) && !contains(intersection, cur)) //per evitare elementi ripetuti nel risultato
			intersection = cons(cur, intersection);

		l1 = tail(l1);
	}
	return intersection;
}