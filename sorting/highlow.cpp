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
	bool state = (arr[0] > arr[1]);

	for (uint16 i = 0; i < arraySize-1; i++) {
		if (state) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
			}
			state = false;
		}
		else { // state < 0
			if (arr[i] < arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
			}
			state = true;
		}
	}
}