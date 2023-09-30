#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "niz_povrh.h"
#include "lista_povrh.h"

uint64_t rekurzivniPovrh(uint64_t n, uint64_t m)
{
	if (n == m || n == 1 || m == 0) return 1;
	return rekurzivniPovrh(n - 1, m - 1) + rekurzivniPovrh(n - 1, m);
}



int main(void)
{
	uint8_t n, m;
	uint64_t rezultat;
	time_t vrijeme;

	puts("Unesite vrijednost n: ");
	scanf("%hhu", &n);

	m = n / 2;

	vrijeme = clock();
	rezultat = rekurzivniPovrh(n, m);
	vrijeme = clock() - vrijeme;
	printf("Rjesenje rekurzije: %zu\n", rezultat);
	printf("Vrijeme potrebno za rekurzivno rjesavanje problema: %lli\n\n", vrijeme);

	vrijeme = clock();
	rezultat = nizPovrh(n, m);
	vrijeme = clock() - vrijeme;
	printf("Rjesenje stoga izvedenog pomocu niza: %zu\n", rezultat);
	printf("Vrijeme potrebno za rjesavanje problema stoga izvedenog u nizu: %lli\n\n", vrijeme);


	vrijeme = clock();
	rezultat = listaPovrh(n, m);
	vrijeme = clock() - vrijeme;
	printf("Rjesenje stoga izvedenog pomocu povezanog popisa: %zu\n", rezultat);
	printf("Vrijeme potrebno za rjesavanje problema stoga izvedenog u povezanom popisu: %lli\n\n", vrijeme);

	return 0;
}