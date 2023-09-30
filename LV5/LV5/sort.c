#include "sort.h"
#include "heap.h"
#include <stdlib.h>

void heap_sort(int* niz, int duljina)
{
	int i;

	napravi_hrpu(niz, duljina);

	for (int i = duljina - 1; i >= 0; i--)
	{
		zamjeni(&niz[0], &niz[i]);
		uhrpi(niz, i, 0);
	}
}

void bubble_sort(int* niz, int duljina)
{
	int i, j;

	for (i = 0; i < duljina; i++)
	{
		for (j = 0; j < duljina - i - 1; j++)
		{
			if (niz[j] > niz[j + 1])
				zamjeni(&niz[j], &niz[j + 1]);
		}
	}
}

int* zauzmi_memoriju(int duljina)
{
	int* niz = (int*)malloc(duljina * sizeof(int));
	if (niz == NULL)
	{
		perror("Error pri zauzimanju memorije");
		exit(-1);
	}

	return niz;
}

void merge(int* niz, int doljnja, int srednja, int gornja)
{
	int i, j, k;
	int duljina_doljnje = srednja - doljnja + 1;
	int duljina_gornje = gornja - srednja;

	int* doljnji_niz = zauzmi_memoriju(duljina_doljnje);
	int* gornji_niz = zauzmi_memoriju(duljina_gornje);

	for (i = 0; i < duljina_doljnje; i++)
		doljnji_niz[i] = niz[doljnja + i];
	for (j = 0; j < duljina_gornje; j++)
		gornji_niz[j] = niz[srednja + 1 + j];

	i = 0; j = 0; k = doljnja;

	while (i < duljina_doljnje && j < duljina_gornje)
	{
		if (doljnji_niz[i] <= gornji_niz[j])
		{
			niz[k] = doljnji_niz[i];
			i++;
		}
		else
		{
			niz[k] = gornji_niz[j];
			j++;
		}
		k++;
	}

	while (i < duljina_doljnje)
	{
		niz[k] = doljnji_niz[i];
		i++;
		k++;
	}

	while (j < duljina_gornje)
	{
		niz[k] = gornji_niz[j];
		j++;
		k++;
	}

	free(doljnji_niz);
	free(gornji_niz);
}

void merge_sort(int* niz, int doljnja, int gornja)
{
	int srednja;
	if (doljnja < gornja)
	{
		srednja = doljnja + (gornja - doljnja) / 2;

		merge_sort(niz, doljnja, srednja);
		merge_sort(niz, srednja + 1, gornja);

		merge(niz, doljnja, srednja, gornja);
	}
}