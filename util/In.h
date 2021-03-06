/*
*
* Functions for reading input.
* header file.
*
*/

#ifndef IN_H
#define IN_H

#include <fstream>
#include "../types.h"

enum IN_ERR_CODE {
	IN_FILE_NOT_OPEN = -1
};

class In {
public:
	char *fileName;
	std::ifstream file;

	In(char *);
	~In();

	void open();
	void open(char *);
	void close();

	uint32 readIntArray(int *, int);

private:
	void cpyFileName(char *);
};

#endif