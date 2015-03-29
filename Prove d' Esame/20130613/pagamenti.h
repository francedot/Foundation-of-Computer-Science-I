//Bonacci Francesco 0900050944 Prova4A

#ifndef PAGAMENTI_H
#define PAGAMENTI_H

#include "list.h"
//#include "utility.h"

//funzioni esame

//ES.1
list leggiPagamenti(char * nomeFile);
int equals(Pagamento p1, Pagamento p2);

//ES.2
list cancellaDoppi(list pag);
Pagamento * elencoPag(list pag, int id_cliente, int * dim);

//ES.3
void totali(list pag);


#endif