#include <stdlib.h>
#include "lista_povrh.h"

UINT8_S* glavni_cvorN = NULL;
UINT8_S* glavni_cvorM = NULL;

void clearN()
{
	UINT8_S* pomocni_cvor = NULL;

	while (glavni_cvorN != NULL)
	{
		pomocni_cvor = glavni_cvorN;
		free(glavni_cvorN);
		glavni_cvorN =  pomocni_cvor->next;
	}
	
	glavni_cvorN = NULL;
}

void clearM()
{
	UINT8_S* pomocni_cvor = NULL;

	while (glavni_cvorM != NULL)
	{
		pomocni_cvor = glavni_cvorM;
		free(glavni_cvorM);
		glavni_cvorM = pomocni_cvor->next;
	}

	glavni_cvorM = NULL;
}

void listaPush(uint8_t n, uint8_t m)
{
	UINT8_S* noviCvor = NULL;

	noviCvor = (UINT8_S*)calloc(1, sizeof(UINT8_S));
	if (noviCvor == NULL)
	{
		perror("Greska pri dodavanju novog cvora...");
		exit(-3);
	}

	noviCvor->x = n;
	noviCvor->next = glavni_cvorN;
	glavni_cvorN = noviCvor;

	noviCvor = (UINT8_S*)calloc(1, sizeof(UINT8_S));
	if (noviCvor == NULL)
	{
		perror("Greska pri dodavanju novog cvora...");
		exit(-3);
	}

	noviCvor->x = m;
	noviCvor->next = glavni_cvorM;
	glavni_cvorM = noviCvor;
}

uint8_t listaPopN()
{
	uint8_t n = glavni_cvorN->x;
	UINT8_S* privremeni = glavni_cvorN;

	glavni_cvorN = glavni_cvorN->next;
	free(privremeni);

	return n;
}

uint8_t listaPopM()
{
	uint8_t m = glavni_cvorM->x;
	UINT8_S* privremeni = glavni_cvorM;

	glavni_cvorM = glavni_cvorM->next;
	free(privremeni);

	return m;
}


uint64_t listaPovrh(uint8_t n, uint8_t m)
{
	uint64_t povrh = 0;
	uint8_t x, y;

	clearM(); clearN();
	listaPush(n, m);

	do
	{
		x = listaPopN();
		y = listaPopM();

		if (x == y || y == 0) povrh += 1;
		else
		{
			listaPush(x-1, y-1);
			listaPush(x-1, y);
		}

	} while (!(glavni_cvorM == NULL || glavni_cvorN == NULL));

	clearN();clearM();

	return povrh;
}