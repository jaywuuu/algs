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
	}
}