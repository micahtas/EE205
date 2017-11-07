/* File: dequeue.h
 * Author: Mark Miw
 */

#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "container.h"

class dequeue {

public:
	//Constructor
	dequeue();

	//Destructor
	~dequeue();

	//Operator Overload
	dequeue& operator=(const dequeue& x);
	bool operator==(const dequeue& x);
	bool operator!=(const dequeue& x);

	//accessors
	bool isempty() const;
	bool isfull() const;
	int size() const;
	
	// mutators
	void clear();

	friend ostream & operator<<(ostream &s,const dequeue &a);

	void pushback(const Entry& x);
	void pushfront(const Entry &x);
	Entry popfront(void) ;
	Entry popback(void); 
	Entry front(void) const;
	Entry back(void) const;

private:
	Container c;
};

#endif 
