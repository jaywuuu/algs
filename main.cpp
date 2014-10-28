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
#include "types.h"
#include "sorting/highlow.h"

using namespace std;

typedef enum {
	OK = 0,
	FAIL
} STATUS;

void runUnitTests();
int testReadIntArray();
int testMerge();
int testMergeSort();
int testReadIntArrayMergeSort();
int testHighLow();

int main() {
	runUnitTests();
	return 0;
}

/* unit testing */
void runUnitTests() {
	cout << "Running unit tests..." << endl;
	
	cout << "testReadIntArray():          ";
	if (testReadIntArray()) cout << "FAIL" << endl;
	else cout << "OK" << endl;

	cout << "testMerge():                 ";
	if (testMerge()) cout << "FAIL" << endl;
	else cout << "OK" << endl;

	cout << "testMergeSort():             ";
	if (testMergeSort()) cout << "FAIL" << endl;
	else cout << "OK" << endl;

	cout << "testReadIntArrayMergeSort(): ";
	if (testReadIntArrayMergeSort()) cout << "FAIL" << endl;
	else cout << "OK" << endl;

	cout << "testHighLow():               ";
	if (testHighLow()) cout << "FAIL" << endl;
	else cout << "OK" << endl;
	
}

int testReadIntArray() {
	In fileIn("../tests/testReadIntArray.txt");
	int intArray[10];
	int retval = OK;

	int intCount = fileIn.readIntArray(intArray, 10);


	for (int i = 0; i < 10; i++) {
		if (intArray[i] != i + 1) retval = FAIL;
	}

	if (intCount != 10) retval = FAIL;

	fileIn.close();

	return retval;
}

int testMerge() {
	int arrL[] = { 1, 2, 4 };
	int arrR[] = { 3, 5, 6 };
	int arr[6];
	int sizeL = sizeof(arrL) / sizeof(int);
	int sizeR = sizeof(arrR) / sizeof(int);
	int size = sizeL + sizeR;
	int retval = OK;

	memset(arr, 0, size * sizeof(int));

	uint64 invCount = merge(arrL, sizeL, arrR, sizeR, arr, size, SORT_ASCEND);

	for (int i = 0; i < size; i++) {
		if (arr[i] != i + 1) retval = FAIL;
	}

	if (invCount != 1) retval = FAIL;

	return retval;
}

int testMergeSort() {
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(arr)/sizeof(int);
	uint64 invCount = mergeSort(arr, size, SORT_ASCEND);

	for (int i = 0; i < size; i++) {
		if (arr[i] != i + 1) return FAIL;
	}

	if (invCount != 45) return FAIL;

	return OK;
}

int testReadIntArrayMergeSort() {
	In fileIn("../tests/IntegerArray.txt");
	int arr[100000];

	memset(arr, 0, 100000 * sizeof(int));

	uint32 intCount = fileIn.readIntArray(arr, 100000);
	fileIn.close();

	uint64 invCount = mergeSort(arr, 100000, SORT_ASCEND);

	if (intCount != 100000) return FAIL;
	if (invCount != 2407905288) return FAIL;

	return OK;
}

int testHighLow() {
	uint16 arr[] = { 10, 4, 2, 7, 5, 6, 1, 3, 8, 9 };
	uint16 size = sizeof(arr) / sizeof(uint16);
	bool state = true;

	highlow(arr, size);

	for (int i = 0; i < size-1; i++) {
		if (state) {
			if (arr[i] < arr[i + 1]) return FAIL;
		}
		else {
			if (arr[i] > arr[i + 1]) return FAIL;
		}
		state = !state;
	}

	return OK;
}