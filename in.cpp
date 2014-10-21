/*
*
* Functions for reading input.
*
*/

#include <fstream>
#include <cstring>
#include "In.h"

/* Constructor.
* Initialize fileName string and copy contents over.
* Open a file stream.
*/
In::In(char *fileName) {
	cpyFileName(fileName);
	file.open(fileName, std::ifstream::in);
}

/* Destructor.
* Free up memory and close file stream if open.
*/
In::~In() {
	if (file.is_open()) {
		delete[] this->fileName;
		file.close();
	}
}

/* opens file */
void In::open() {
	if (fileName) file.open(fileName, std::ifstream::in);
}

/* opens file from string */
void In::open(char *fileName) {
	/* deletes old fileName string and recopies it over. */
	if (fileName) delete [] this->fileName;
	cpyFileName(fileName);

	/* close old stream if open */
	if (file.is_open()) file.close();
	file.open(fileName, std::ifstream::in);
}

/* close file */
void In::close() {
	file.close();
	delete [] this->fileName;
}

/* Read in integers from file as an array line by line. */
int In::readIntArray(int *arrOut, int size) {
	int intCount = 0;
	char line[100]; // temporary for now until I figure out how to correctly 
					// dynamically allocate memory or something.

	/* if stream is open */
	if (file.is_open()) {
		while (file.good()) {
			file.getline(line, 100);
			arrOut[intCount] = atoi(line);
			intCount++;
		}
	}

	return intCount;
}

void In::cpyFileName(char *fileName) {
	int length = strlen(fileName) + 1;	// Add plus 1 for null terminating char
	this->fileName = new char[length];
	strcpy_s(this->fileName, length, fileName);
}
