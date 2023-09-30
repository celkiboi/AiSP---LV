#include <stdlib.h>
#include <time.h>
#include "array.h"

int* newEmptyArray(size_t numberOfElements)
{
	int* arr = (int*)malloc(numberOfElements * sizeof(int));
	if (arr == NULL)
	{
		exit(-3);
		perror("Error allocating memory for an int array\nAttempted array size: %i");
	}

	return arr;
}

int* randomArray(size_t numberOfElements, int low, int high)
{
	int i;
	int* arr = newEmptyArray(numberOfElements);

	for (i = 0; i < numberOfElements; i++)
	{
		arr[i] = low + rand() % (high - low + 1);
	}

	return arr;
}

int* newZeroArray(size_t numberOfElements)
{
	int* arr = (int*)calloc(numberOfElements, sizeof(int));
	if (arr == NULL)
	{
		exit(-3);
		perror("Error allocating memory for an int array");
	}

	return arr;
}

int searchArray(int* arr, size_t numberOfElements, int x)
{
	int i;

	for (i = 0; i < numberOfElements; i++)
	{
		if (arr[i] == x) return i;
	}

	return -1;
}