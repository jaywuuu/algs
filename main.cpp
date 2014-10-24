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

using namespace std;

void testReadIntArray();
void testMerge();
void testMergeSort();
void testReadIntArrayMergeSort();

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
	int sizeL = sizeof(arrL) / sizeof(int);
	int sizeR = sizeof(arrR) / sizeof(int);
	int size = sizeL + sizeR;

	memset(arr, 0, size * sizeof(int));

	int invCount = merge(arrL, sizeL, arrR, sizeR, arr, size, SORT_ASCEND);

	cout << "merged array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	cout << "inversion count: " << invCount << endl;
}

void testMergeSort() {
	int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(arr)/sizeof(int);
	int invCount = mergeSort(arr, size, SORT_ASCEND);

	cout << "sorted array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	cout << "inversion count: " << invCount << endl;
}

void testReadIntArrayMergeSort() {
	In fileIn("IntegerArray.txt");
	int arr[100000];

	memset(arr, 0, 100000 * sizeof(int));

	uint32 intCount = fileIn.readIntArray(arr, 100000);
	fileIn.close();

	uint64 invCount = mergeSort(arr, 100000, SORT_ASCEND);

	cout << "total integers read: " << intCount << endl;
	cout << "inversion count: " << invCount << endl;
}
