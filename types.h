/*
* Defines commonly used types.
*
*/

#ifndef TYPES_H
#define TYPES_H

typedef unsigned int				uint16;
typedef unsigned long int			uint32;
typedef unsigned long long int		uint64;

template < typename ttype >
void swap(ttype *a, ttype *b) {
	ttype swap = *a;
	*a = *b;
	*b = swap;
}

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