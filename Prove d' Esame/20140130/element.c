//Bonacci Francesco 0900050944

#include "element.h"
#include <string.h>



int compareDate(Data d1, Data d2)
{

	if (d1.anno == d2.anno) {

		if (d1.mese == d2.mese) {

			return (d1.giorno - d2.giorno);

		} else {

			return (d1.mese - d2.mese);

		}

	} else {

		return (d1.anno - d2.anno);

	}

}

int compareOfferte(Offerta of1, Offerta of2)
{
	int res = compareDate(of1.dataEffettuata, of2.dataEffettuata);

	if (res == 0) {

		if (of1.importo == of2.importo) {

			return (of1.idCliente - of2.idCliente);

		} else {

			return ( (of1.importo < of2.importo) ? -1 : 1 );

		}

	} else {

		return res;

	}

}

int compareOggetti(Oggetto og1, Oggetto og2)
{

	return ( compareDate(og1.dataChiusura, og2.dataChiusura) );

}

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
//
void printOggetto(Oggetto og)
{
	printf("%d %d %d %d %s\n", og.idOggetto, og.dataChiusura.anno,
		og.dataChiusura.mese, og.dataChiusura.giorno, og.descrizioneOggetto);
}

void printOfferta(Offerta of)
{
	printf( "%d %d %d %d %d %f\n", of.idCliente, 
			of.idOggetto, of.dataEffettuata.anno,
				of.dataEffettuata.mese, of.dataEffettuata.giorno,
					of.importo );
}