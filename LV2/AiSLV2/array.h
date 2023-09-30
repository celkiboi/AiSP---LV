#ifndef ARRAY_H
#define ARRAY_H

int* newEmptyArray(size_t numberOfElements);

int* randomArray(size_t numberOfElements, int low, int high);

int* newZeroArray(size_t numberOfElements);

int searchArray(int* arr, size_t numberOfElements, int x);

#endif