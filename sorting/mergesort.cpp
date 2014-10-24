/* 
* Merge sort algoirthm.
*
*/

#include <cstring>
#include "mergesort.h"

/* returns the number of inversions 
* sorts according to the function pointer passed in.  
* Use SORT_ASCENDING or SORT_DESCENDING defined in sort.h
*/
uint64 mergeSort(int *arr, int arrSize, bool(*compare)(int, int)) {
	uint64 invCount = 0;
	int *aux = new int[arrSize];
	int mid = arrSize / 2;
	int sizeL = mid;
	int sizeR = arrSize - mid;

	// base case: 1 item in array.
	if (arrSize <= 1) return 0;

	// copy whole contents over into auxillary array.
	memcpy(aux, arr, arrSize*sizeof(int));

	// left side.
	invCount += mergeSort(aux, mid, compare);
	// Right side.
	invCount += mergeSort(&aux[mid], sizeR, compare);
	// merge together.
	invCount += merge(aux, sizeL, &aux[mid], sizeR, arr, arrSize, compare);

	delete[] aux; // clean up
	return invCount;
}

/* merges two arrays into one 
* Uses a function pointer to determine how to compare the items for ascending
* or descending order.  Returns the number of inversions. */
uint64 merge(
	int *arrL, int sizeL,
	int *arrR, int sizeR,
	int *arrOut, int sizeOut,
	bool (*compare)(int, int)) {
	uint64 invCount = 0;	// keep track of number of inversions.
	int i = 0, j = 0;

	for (int k = 0; k < sizeOut; k++) {
		if (compare(arrL[i], arrR[j]) && j < sizeR || i >= sizeL) {
			// take from arrR and count the inversions.
			arrOut[k] = arrR[j];
			j++;

			// increase inversion count to total number of elements left in arrL.
			invCount += sizeL - i;
		}
		else {
			arrOut[k] = arrL[i];
			i++;
		}
	}

	return invCount;
}

