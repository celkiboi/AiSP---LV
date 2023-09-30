#include "linked.h"
#include "stdlib.h"

OE* createSLL(int x)
{
	OE* newHeadNode = (OE*)calloc(1, sizeof(OE));
	if (newHeadNode == NULL)
	{
		exit(-1);
		perror("cannot allocate memory for a SLL");
	}

	newHeadNode->x = x;

	return newHeadNode;
}

OE* newHeadNode(OE* headNode, int x)
{
	OE* newHeadNode = (OE*)calloc(1, sizeof(OE));
	if (newHeadNode == NULL)
	{
		exit(-2);
		perror("cannot allocate memory for a new head node");
	}

	newHeadNode->next = headNode;
	newHeadNode->x = x;

	return newHeadNode;
}

OE* freeSLL(OE* headNode)
{
	OE* temp = NULL;

	while (headNode != NULL)
	{
		temp = headNode;
		headNode = headNode->next;

		free(temp);
	}

	return NULL;
}

OE* searchSLL(OE* headNode, int x)
{
	OE* foundElement = NULL;

	for (headNode; headNode != NULL; headNode = headNode->next)
	{
		if (headNode->x == x) foundElement = headNode;
	}

	return foundElement;
}

OE* unsafeNewHeadNode(OE* headNode, int x)
{
	OE* newHeadNode = (OE*)malloc(1, sizeof(OE));
	if (newHeadNode == NULL)
	{
		return NULL;
	}
	newHeadNode->next = headNode;
	newHeadNode->x = x;

	return newHeadNode;
}

OE* createSLLfromArray(int* arr, size_t arrLenght)
{
	int i;
	OE* headNode = createSLL(arr[0]);

	for (i = 1; i < arrLenght; i++)
	{
		headNode = newHeadNode(headNode, arr[i]);
	}

	return headNode;
}