#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked.h"
#include "array.h"

void Exercise1()
{
	int* V = NULL;
	OE* headNode = NULL;
	size_t N;
	time_t time;

	printf("How many elements do you want in array V?:");
	scanf("%zu", &N);

	time = clock();
	V = randomArray(N, 0, 10);
	time = clock() - time;
	printf("Time taken to allocate and initialize an array with a length of %zu: %li ms\n", N, time);

	time = clock();
	searchArray(V, N, 20);
	time = clock() - time;
	printf("Time taken to fully search the array of %zu elements: %li ms\n", N, time);


	time = clock();
	headNode = createSLLfromArray(V, N);
	time = clock() - time;
	printf("Time taken to allocate and intitialize %zu nodes of SLL: %li ms\n", N, time);

	time = clock();
	searchSLL(headNode, -1);
	time = clock() - time;
	printf("Time taken to fully search the SLL of %zu nodes: %li ms\n", N, time);

	headNode = freeSLL(headNode);
	free(V);
}

void Exercise2()
{
	int* arr = NULL;
	register OE* headNode = NULL;
	size_t maxSize = 1;

	while (1)
	{
		arr = (int*)malloc(maxSize);
		if (arr == NULL)
		{
			maxSize /= 10;
			break;
		}
		printf("%zu\n", maxSize);
		maxSize*=10;
		free(arr);
	}
	printf("Biggest malloc size: %zu", maxSize);

	maxSize = 0;
	while (1)
	{
		headNode = newHeadNode(headNode, maxSize);
		if (headNode == NULL)
		{
			maxSize--;
			printf("Jebemti");
			break;
		}
		maxSize++;
		if (maxSize % 10000 == 0)
			printf("%i %x\n", maxSize, headNode);
	}
	printf("Biggest SLL size: %zu", maxSize);
}

int main(void)
{
	//Exercise1();
	Exercise2();

	return 0;
}
