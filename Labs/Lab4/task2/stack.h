//
// "stack.h"
//
// Stack class declaration.
//

#ifndef STACK_H
#define STACK_H
#include "container.h"

class stack
{
  public:
	
	// constructor
	stack();

	// destructor
	~stack();


	// common operations
	stack &operator=(const stack & s);
	bool operator!=(const stack &s);
	bool operator==(const stack &s);
	int size() const;
	bool isempty() const;
	bool isfull() const;
	
	// mutators
	void clear();
		// clears the list
	
	//display
	void display();
	
 	//additional functions
	void push(const Entry &x);
		// Insert x at the top of the stack
	
	Entry pop(void);
		// remove and return the top of the stack
	Entry top(void);
		// return the top of the stack
		
	friend ostream & operator<<(ostream &s, const stack &a);
	
 

  private:
	Container c;
};
#endif
