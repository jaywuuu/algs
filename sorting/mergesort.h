/*
* Merge sort algoirthm.
*
* header file.
*
*/

#ifndef MERGESORT_H
#define MERGESORT_H

#include "../types.h"

uint64 mergeSort(int *arr, int arrSize, bool(*compare)(int, int));
uint64 merge(int *, int, int *, int, int *, int, bool(*compare)(int, int));

#endif