
/*  File: container.h
 *  Date: 12 Sep 06
 *  Rev: 25 Sep 07
 *
 *  Container class declarations and prototypes - version 2
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <stdlib.h>
#include "common.h"
#include "entry.h"

#define MAXSIZE 100

typedef int Position;

class Container {

public:

	// constructors
	Container();

	// accessors
	bool isempty() const;
	bool isfull() const;
	int size() const;
	Entry get(Position p) const;

	// mutators
	void clear();
		// clear the container to empty
	void traverse(void(*Visit)(Entry));
		// apply Visit to each element in the container
	void insert(Entry x, Position p = -1 );
		// add a new node with data x at position p (-1 is end
		// of container)
	Entry remove(Position p);
		// remove node at position p returning its data
	void replace(Entry x, Position p);
		// replace data at position p with x

private:

	int count;
	Entry elements[MAXSIZE];

};

#endif
