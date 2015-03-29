//Bonacci Francesco 0900050944 Prova 3A

#ifndef LIST_H
#define LIST_H

#include "element.h"

typedef struct list_element {

	element value;
	struct list_element *next;

} item;

typedef item *list;

/* PRIMITIVE */
list cons(element, list);
element head(list);
list tail(list);
list emptyList(void);
boolean empty(list);

/* NON PRIMITIVE */
boolean contains(list l, element e);
int length(list l);
list append(list l1, list l2);
list reverse(list l);
list copy(list l);
list deleteEl(element el, list l);
list insord_p(element el, list l);
list sortList(list l);
//list mergeList(list l1, list l2);
list subList(int n, list l);
//void showList(list l); //da rimappare
void freeList(list l);
list diff(list l1, list l2);
list intersect(list l1, list l2);


#endif