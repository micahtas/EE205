//

#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "container.h"
#include "queue.h"
#include "stack.h"

class dequeue {

public:
	//Constructor
	dequeue();

	//Destructor
	~dequeue();

	//Operator Overload
	dequeue& operator=(const dequeue &d);
	bool operator==(const dequeue &d);
	bool operator!=(const dequeue &d);

	//accessors
	bool isempty() const;
	bool isfull() const;
	int size() const;

	//mutators
	void clear();

	friend ostream& operator<<(ostream&s, const dequeue &d);
	void push_back(const Entry &x);
	void push_front(const Entry &x);
	Entry pop_front(void);
	Entry pop_back(void);
	Entry front(void);
	Entry back(void);

private:
	Container c;
	friend class queue;
	friend class stack;
};

#endif
