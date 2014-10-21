/*
*
* For testing purposes or executing helper code.
*
*
*/

#include <iostream>
#include <cstring>
#include "In.h"
#include "sort/sort.h"

using namespace std;

int main() {
	In fileIn("E:\\Workplace\\algs\\test.txt");
	int intArray[10];

	int intCount = fileIn.readIntArray(intArray, 10);

	cout << "intCount: " << intCount << endl;

	for (int i = 0; i < 10; i++) {
		cout << "line " << i << ": " << intArray[i] << endl;
	}

	fileIn.close();

	return 0;
}