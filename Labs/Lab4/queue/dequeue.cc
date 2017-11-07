/* File: dequeue.cc
 * Author: Kunliang Xiao
 */


#include "dequeue.h"

dequeue::dequeue()
{
	Container();
}

dequeue::~dequeue()
{
	//No memory need to be released
	//destructor from container are called in sublevel
}

bool dequeue::isempty() const
{
	return c.isempty();
}

bool dequeue::isfull() const
{
	return c.isfull();
}

int dequeue::size() const
{
	return c.size();
}

void dequeue::clear()
{
	c.clear();
}

ostream & operator << (ostream &s,const dequeue &a)
{
	cout << "\n";
	for (int i=0; i<a.c.size() ; i++)
	cout << i << ": " << a.c.get(i) << endl;
	return s;
}

dequeue& dequeue::operator=(const dequeue& d)
{	
	c = d.c;
	return *this;
}

bool dequeue::operator==(const dequeue& d)
{
	if(c==d.c)
	return true;
	return false;
}

bool dequeue::operator!=(const dequeue& d)
{
	if(c==d.c)
	return false;
	return true;
}

void dequeue::push_back(const Entry &x)
{
	queue a;
	c = a.c;
	a.push(x);	
}

void dequeue::push_front(const Entry &x)
{
	stack.push(x);
}

Entry dequeue::pop_front(void)
{
	Entry x = queue.pop();
	return x;
}

Entry dequeue::pop_back(void)
{
	Entry x = stack.pop();
	return x;
}

Entry dequeue::front(void)
{
	Entry x = queue.front();
	return x;
}

Entry dequeue::back(void)
{
	Entry x = stack.top();
	return stack.top();
}
