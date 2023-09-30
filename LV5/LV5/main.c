#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"
#include "sort.h"

void ispisi_niz(int* niz, int duljina)
{
	int i;

	for (i = 0; i < duljina; i++)
	{
		printf("%d ", niz[i]);
	}
}

void napravi_nizove(int** heap_niz, int** merge_niz, int** bubble_niz, int duljina)
{
	int i, vrijednost;

	*heap_niz = zauzmi_memoriju(duljina);
	*merge_niz = zauzmi_memoriju(duljina);
	*bubble_niz = zauzmi_memoriju(duljina);


	for (i = 0; i < duljina; i++)
	{
		vrijednost = rand() % 10;
		
		(*heap_niz)[i] = vrijednost;
		(*bubble_niz)[i] = vrijednost;
		(*merge_niz)[i] = vrijednost;
	}
}

int main(void)
{
	int* bubble_niz, * merge_niz, * heap_niz;
	int duljina;
	time_t vrijeme;
	srand((unsigned)time(NULL));

	printf("Unesite duljinu niza: ");
	scanf("%d", &duljina);
	napravi_nizove(&bubble_niz, &heap_niz, &merge_niz, duljina);

	vrijeme = clock();
	bubble_sort(bubble_niz, duljina);
	vrijeme = clock() - vrijeme;
	//ispisi_niz(bubble_niz, duljina);
	printf("\nVrijeme potrebno za bubble sort: %llu ms\n", vrijeme);

	vrijeme = clock();
	heap_sort(heap_niz, duljina);
	vrijeme = clock() - vrijeme;
	//ispisi_niz(heap_niz, duljina);
	printf("\nVrijeme potrebno za heap sort: %llu ms\n", vrijeme);

	vrijeme = clock();
	merge_sort(merge_niz, 0, duljina-1);
	vrijeme = clock() - vrijeme;
	//ispisi_niz(merge_niz, duljina);
	printf("\nVrijeme potrebno za merge sort: %llu ms\n", vrijeme);


	free(bubble_niz);
	free(heap_niz);
	free(merge_niz);

	return 0;
}