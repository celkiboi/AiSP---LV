#include "niz_povrh.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t stackN[STACK_LENGHT];
uint8_t stackM[STACK_LENGHT];

int32_t stackPointerN = -1;
int32_t stackPointerM = -1;


uint8_t popN()
{
	uint8_t n;

	if (stackPointerN == -1)
	{
		perror("Stack underflow...");
		exit(-2);
	}

	n = stackN[stackPointerN];
	stackPointerN--;

	return n;
}

uint8_t popM()
{
	uint8_t m;

	if (stackPointerM == -1)
	{
		perror("Stack underflow...");
		exit(-2);
	}

	m = stackM[stackPointerM];
	stackPointerM--;

	return m;

}

void push(uint8_t n, uint8_t m)
{
	if (stackPointerN == STACK_LENGHT - 1 || stackPointerM == STACK_LENGHT - 1)
	{
		perror("Stack overflow...");
		exit(-1);
	}

	stackPointerN++;
	stackPointerM++;
	stackN[stackPointerN] = n;
	stackM[stackPointerM] = m;
}

void clear()
{
	stackPointerM = -1;
	stackPointerN = -1;
}

uint64_t nizPovrh(uint8_t n, uint8_t m)
{
	uint64_t povrh = 0;
	uint8_t x, y;

	clear();
	push(n, m);

	do
	{
		x = popN();
		y = popM();

		if (x == y || y == 0) povrh += 1;
		else
		{
			push(x - 1, y - 1);
			push(x - 1, y);
		}
	} while (stackPointerN > -1);

	return povrh;
}