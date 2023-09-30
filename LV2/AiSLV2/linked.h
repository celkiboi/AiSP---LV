#ifndef LINKED_H
#define LINKED_H

struct OE_
{
	int x;
	struct OE_* next;
};

typedef struct OE_ OE;

OE* createSLL(int x);

OE* newHeadNode(OE* headNode, int x);

OE* freeSLL(OE* headNode);

OE* searchSLL(OE* headNode, int x);

OE* unsafeNewHeadNode(OE* headNode, int x);

OE* createSLLfromArray(int* arr, size_t arrLenght);

#endif
