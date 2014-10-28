/*
* Merge sort algoirthm.
*
* header file.
*
*/

#ifndef MERGESORT_H
#define MERGESORT_H

#include "../types.h"

template < typename ttype >
uint64 mergeSort(ttype *arr, int arrSize, bool(*compare)(ttype, ttype));

template < typename ttype >
uint64 merge(ttype *, int, ttype *, int, ttype *, int, bool(*compare)(ttype, ttype));

#endif