#include "heap.h"

void zamjeni(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void uhrpi(int* niz, int duljina, int index)
{
	int najveci = index;
	int lijevi = index * 2 + 1;
	int desni = index * 2 + 2;

	if (lijevi < duljina && niz[lijevi] > niz[najveci])
		najveci = lijevi;

	if (desni < duljina && niz[desni] > niz[najveci])
		najveci = desni;

	if (najveci != index)
	{
		zamjeni(&niz[index], &niz[najveci]);
		uhrpi(niz, duljina, najveci);
	}
}

void napravi_hrpu(int* niz, int duljina)
{
	int i;

	for (i = duljina / 2 - 1; i >= 0; i--)
	{
		uhrpi(niz, duljina, i);
	}
}