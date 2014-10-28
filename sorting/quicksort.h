/*
* Quick sort algoirthm.
*
* header file.
*
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../types.h"

template < typename ttype >
void quickSort(ttype *arr, int arrSize);

template < typename ttype >
void qsort(ttype *arr, int arrSize, uint32 pivot);

template < typename ttype >
uint32 quickSortPartition(ttype *arr, int arrSize, uint32 pivot);

#endif