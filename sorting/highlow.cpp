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
	bool state = true;
	
	// Use alternating states to determine how to compare.
	// We alternative between comparing less than or greater than
	// when determining when to swap.  Each time we reverse the 
	// state.  Just by changing the initial state, bool state,
	// into either true or false (bool state = true | false),
	// you can change the order from either high-low-high-low to 
	// low-high-low-high.
	for (uint16 i = 0; i < arraySize-1; i++) {
		if (state) {
			if (arr[i + 1] > arr[i]) swap(&arr[i + 1], &arr[i]);
		}
		else {
			if (arr[i + 1] < arr[i]) swap(&arr[i + 1], &arr[i]);
		}
		state = !state; // reverse state.
	}
}