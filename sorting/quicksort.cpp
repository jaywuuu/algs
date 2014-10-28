/*
* Quick sort algoirthm.
* So elegant, so cool. Wish I came up with this.
* 
*/

#include "quicksort.h"
#include "../util/random.h"

/* Standard 2-partition Quick sort.  
*  Shuffle array, choose pivot, partition, then finish up. 
*/
template < typename ttype >
void quickSort(ttype *arr, int arrSize) {
	uint32 pivot = 0;
	// TODO: implement shuffle and looking for a pivot
	shuffle(arr, arrSize);

	qsort(arr, arrSize, pivot);
}

/* recursive part */
template < typename ttype >
void qsort(ttype *arr, int arrSize, uint32 pivot) {
	if (arrSize <= 1) return;
	uint32 p = quickSortPartition(arr, arrSize, pivot);
	/* sort left of pivot, sort right of pivot */
	qsort(&arr[0], p, 0);
	qsort(&arr[p+1], arrSize - p - 1, 0);
}

/* partition subroutine.  Returns the new pivot position */
template < typename ttype >
uint32 quickSortPartition(ttype *arr, int arrSize, uint32 pivot) {
	uint32 lt = 1;
	uint32 p = pivot;
	
	/* swap pivot with first element */
	if (pivot > 0) {
		swap(&arr[0], &arr[p]);
		p = 0;
	}

	for (int i = 1; i < arrSize; i++) {
		if (arr[i] < arr[p]) {
			swap(&arr[i], &arr[lt]);
			lt++;
		}
	}

	/* at the end swap element left of lt with the pivot */
	swap(&arr[0], &arr[lt - 1]);
	p = lt - 1; // return pivot;

	return p;
}

/* dummy function for linking */
void dummy_quicksort() {
	int arr[] = { 1 };
	quickSort(arr, 1);
	qsort(arr, 1, 0);
	quickSortPartition(arr, 1, 0);
}