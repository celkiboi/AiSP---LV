#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sekv_pret(float V[], int n, float x);

void sort(float V[],int low, int high);

int bin_pret(float V[], int n, float x);

void gen_arr(float V[], int n, float dg, float gg);

/*
void print_arr(float V[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%.2f ", V[i]);
	}
}
*/

int main(void)
{
	float* V = NULL, dg, gg;
	int n, rezultat;
	clock_t t;
	double vrijeme;

	srand((unsigned)time(NULL));

	printf("Unesite duljinu polja V: ");
	scanf("%d", &n); 

	V = (float*)malloc(n * sizeof(float));
	if (V == NULL)
	{
		perror("Greska pri zauzimanju memorije za polje realnih brojeva V!");
		exit(-1);
	}

	printf("Odaberite donju granicu, potom gornju: ");
	scanf("%f %f", &dg, &gg);

	gen_arr(V, n, dg, gg);
	

	//print_arr(V, n);
	t = clock();
	rezultat = sekv_pret(V, n, gg+1);
	t = clock() - t;
	vrijeme = ((double)t) / CLOCKS_PER_SEC;
	printf("Sekvencijalno pretrazivanje: %d\n", rezultat);
	printf("Vrijeme potrebno za sekvencijalno pretrazivanje: %.8f\n", vrijeme);


	t = clock();
	sort(V,0, n-1);
	t = clock() - t;
	vrijeme = ((double)t) / CLOCKS_PER_SEC;
	printf("Vrijeme potrebno za sortiranje: %.8f\n", vrijeme);

	//print_arr(V, n);
	t = clock();
	rezultat = bin_pret(V, n, gg+1);
	t = clock() - t;
	vrijeme = ((double)t) / CLOCKS_PER_SEC;
	printf("Binarno pretrazivanje: %d\n", rezultat);
	printf("Vrijeme potrebno za binarno pretrazivanje: %.8f\n", vrijeme);


	free(V);
	return 0;
}

int sekv_pret(float V[], int n, float x)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (V[i] == x) return i; 
	}

	return -1;
}

int bin_pret(float V[], int n, float x)
{
	int gornjaGranica = n-1, donjaGranica = 0, sredina;

	while (gornjaGranica > donjaGranica)
	{
		sredina = (donjaGranica + gornjaGranica) / 2;

		if (V[sredina] == x)  return sredina;

		if (V[sredina] > x) gornjaGranica = sredina-1;

		if (V[sredina] < x) donjaGranica = sredina+1;
	}

	return -1;
}

void swap(float* a, float* b)
{
	float c;

	c = *a;
	*a = *b;
	*b = c;
}

void sort(float V[], int low, int high)
{
	int i = low, j = high;

	float s = V[(low + high) / 2];
	while (i <= j)
	{
		while (V[i] < s) i++;
		while (V[j] > s) j--;

		if (i <= j)
		{
			swap(&V[i], &V[j]);
			i++;
			j--;
		}
	}
	if (low < j) sort(V, low, j);
	if (i < high) sort(V, i, high);

}

void gen_arr(float V[], int n, float dg, float gg)
{
	int i;

	for (i = 0; i < n; i++)
	{
		V[i] = dg + (float)rand() / RAND_MAX * (gg - dg);
	}
}