/* File: queue.h
 * Author: Micah Tashima, Kunliang Xiao
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "container.h"

class queue {

public:
	//Constructor
	queue();

	//Destructor
	~queue();

	//Operator Overload
	queue& operator=(const queue& x);
	bool operator==(const queue& x);
	bool operator!=(const queue& x);

	//accessors
	bool isempty() const;
	bool isfull() const;
	int size() const;
	
	// mutators
	void clear();

	friend ostream & operator<<(ostream &s,const queue &a);

	void push(const Entry& x);
	Entry pop(void) ; 
	Entry front(void) const;

private:
	Container c;
};

#endif 
