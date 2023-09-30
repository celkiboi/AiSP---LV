#ifndef LISTA_POVRH_H
#define LISTA_POVRH_H

#include <stdint.h>

struct uint8_struct
{
	uint8_t x;
	struct uint8_struct *next;
};

typedef struct uint8_struct UINT8_S;

uint64_t listaPovrh(uint8_t n, uint8_t m);

#endif