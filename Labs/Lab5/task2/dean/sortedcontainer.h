
/*  File: sortedcontainer.h
 *  Date: 12 Sep 06
 *  Rev: 25 Sep 07
 *
 *  sortedcontainer class declarations and prototypes - version 2
 */

#ifndef SORTEDCONTAINER_H
#define SORTEDCONTAINER_H
#endif

#include <stdlib.h>
#include "common.h"
#include "entry.h"
#include <iostream>
using namespace std;
#include "container.h"

#define MAXSIZE 100

typedef int Position;

class sortedcontainer {

public:

	// constructors
	//sortedcontainer();

	void insert(Entry x);
		// add a new node with data x at position p (-1 is end
		// of container)

	Container c;
private:

	int count;
	Entry elements[MAXSIZE];

};

