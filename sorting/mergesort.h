/*
* Merge sort algoirthm.
*
* header file.
*
*/

#ifndef MERGESORT_H
#define MERGESORT_H

unsigned long int mergeSort(int *arr, int arrSize, bool(*compare)(int, int));
unsigned long int merge(int *, int, int *, int, int *, int, bool (*compare)(int, int));

#endif