/*
*
* Functions for reading input.
* header file.
*
*/

#ifndef IN_H
#define IN_H

#include <fstream>

class In {
public:
	char *fileName;
	std::ifstream file;

	In(char *);
	~In();

	void open();
	void open(char *);
	void close();

	int readIntArray(int *, int);

private:
	void cpyFileName(char *);
};

#endif