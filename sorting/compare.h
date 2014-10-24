/*
* For comparing between general types.
*
* header file.
*
*/

#ifndef COMPARE_H
#define COMPARE_H

template < typename ttype >
bool isGreater(ttype a, ttype b) {
	return (a > b);
}

template < typename ttype >
bool isLess(ttype a, ttype b) {
	return (a < b);
}

template < typename ttype >
bool isEqual(ttype a, ttype b) {
	return (a == b);
}

#endif