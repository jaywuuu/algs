/*
*
* For testing purposes
*
*
*/

#include <iostream>
#include "util/in.h"
#include "sorting/mergesort.h"
#include "sorting/sort.h"

using namespace std;

void testReadIntArray();
void testMerge();

int main() {

	return 0;
}

/* unit testing */
void testReadIntArray() {
	In fileIn("test.txt");
	int intArray[10];

	int intCount = fileIn.readIntArray(intArray, 10);

	cout << "intCount: " << intCount << endl;

	for (int i = 0; i < 10; i++) {
		cout << "line " << i << ": " << intArray[i] << endl;
	}

	fileIn.close();
}

void testMerge() {
	int arrL[] = { 1, 2, 4 };
	int arrR[] = { 3, 5, 6 };
	int arr[6];

	memset(arr, 0, 6 * sizeof(int));

	int invCount = merge(arrL, 3, arrR, 3, arr, 6, SORT_ASCEND);

	cout << "merged array: ";
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	cout << "inversion count: " << invCount << endl;
}
