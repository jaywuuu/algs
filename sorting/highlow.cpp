/*
* Arrange an array into high - low high - low order.
* 
*/

#include <cstring>
#include "highlow.h"

/* Takes in an array of positive integers and returns
* the array back in order of high - low - high - low.
* e.g. { 1, 2, 3, 4 } into { 4, 2, 3, 1 }.
*/
void highlow(uint16 *arr, uint16 arraySize) {
	if (arraySize == 0) return;
	uint16 *aux = new uint16[arraySize];
	bool state = true;
	int end = 0;
	// use auxillary array to hold a copy of the original,
	// then use the original as the list we will append to.
	memcpy(aux, arr, arraySize*sizeof(uint16));

	// Use alternating states to determine how to compare.
	// We alternative between comparing less than or greater than
	// when determining either to append at the end of the list,
	// or at the second last position.  Each time we reverse the 
	// state.  Just by changing the initial state, bool state,
	// into either true or false (bool state = true | false),
	// you can change the order from either high-low-high-low to 
	// low-high-low-high.
	for (uint16 i = 1; i < arraySize; i++) {
		if (state) {
			if (aux[i] > arr[end]) {
				swap(&arr[end], &arr[end + 1]);
				arr[end] = aux[i];
				end++;
			}
			else {
				end++;
				arr[end] = aux[i];
			}
		}
		else {
			if (aux[i] < arr[end]) {
				swap(&arr[end], &arr[end + 1]);
				arr[end] = aux[i];
				end++;
			}
			else {
				end++;
				arr[end] = aux[i];
			}
		}
		state = !state; // reverse state.
	}
	
	// note: this implementation below doesn't seem to work.
	/*bool state = (arr[0] > arr[1]);

	if (!state) swap(&arr[0], &arr[1]);

	for (uint16 i = 2; i < arraySize-1; i++) {
		if (state) { // falling state
			if (arr[i] < arr[i - 1]) {
				swap(&arr[i], &arr[i - 1]);
			}
			state = false;
		}
		else { // rising state
			if (arr[i] > arr[i - 1]) {
				swap(&arr[i], &arr[i - 1]);
			}
			state = true;
		}
	}*/
}