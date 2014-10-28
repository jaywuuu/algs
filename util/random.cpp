/*
* Random number generator and functionality
* using <random>
* 
*/

#include <random>
#include "random.h"

/* simple shuffle using Knuth shuffle */
template < typename ttype >
void shuffle(ttype *arr, uint32 arrSize) {
	uint32 rand = 0;
	std::default_random_engine generator;

	for (uint32 i = 1; i < arrSize; i++) {
		std::uniform_int_distribution<int> distribution(0, i);
		rand = distribution(generator);

		swap(&arr[i], &arr[rand]);
	}
}

/* dummy for linking */
void dummy_random() {
	int arr[] = { 1, 2 };
	shuffle(arr, 2);
}