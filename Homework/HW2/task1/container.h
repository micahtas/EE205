
/*  File: container.h
 *  Date: 12 Sep 06
 *  Rev: 25 Sep 07
 *
 *  Container class declarations and prototypes - version 2
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "common.h"
#include "entry.h"
using namespace std;

const int MAXSIZE  = 5000;

typedef int Position;

class Container {

public:

	// constructors
	Container();

	// accessors
	inline bool isempty() const;
	inline bool isfull() const;
	inline int size() const;
	Entry get(Position p) const;
	Position lsrch(Entry x);

	// mutators
	inline void clear();
		// clear the container to empty
	void traverse(void(*Visit)(Entry));
		// apply Visit to each element in the container
	virtual void insert(Entry x, Position p = -1 );
		// add a new node with data x at position p (-1 is end
		// of container)
	Entry remove(Position p);
		// remove node at position p returning its data
	void replace(Entry x, Position p);
		// replace data at position p with x

	friend ostream & operator << (ostream &s,const Container &a);

protected:
	int count;
	Entry elements[MAXSIZE];

};

#include "container_inl.h"

#endif
