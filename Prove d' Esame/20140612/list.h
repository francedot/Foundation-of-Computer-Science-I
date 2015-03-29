//Bonacci Francesco 0900050944
#ifndef LIST_H
#define LIST_H

#include "element.h"

typedef struct list_element {

	element value;
	struct list_element *next;

} item;

typedef item *list;
typedef int boolean;

/* PRIMITIVE */
list emptylist(void);
boolean empty(list);
list cons(element, list);
element head(list);
list tail(list);

/* NON PRIMITIVE */
list diff(list l1, list l2);
void showList(list l);
int length(list l);
void freelist(list l);
boolean contains(list l, element e);
list copy(list l);
list deleteL(element el, list l);
list insord_p(element el, list l);

#endif