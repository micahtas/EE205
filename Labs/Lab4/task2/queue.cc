/* File: queue.cc
 * Author: Micah Tashima, Kunliang Xiao
 */


#include "queue.h"

queue::queue()
{
	Container();
}

queue::~queue()
{
	//No memory need to be released
	//destructor from container are called in sublevel
}

bool queue::isempty() const
{
	return c.isempty();
}

bool queue::isfull() const
{
	return c.isfull();
}

int queue::size() const
{
	return c.size();
}

void queue::clear()
{
	c.clear();
}

void queue::push(const Entry& x)
{
	c.insert(x,0);
}

Entry queue::pop(void) 
{
	Entry x;
	x = c.remove(0);
	return x;
}

Entry queue::front(void) const
{
	Entry x;
	x = c.get(0);
	return x;
}

ostream & operator << (ostream &s,const queue &a)
{
	cout << "\n";
	for (int i=0; i<a.c.size() ; i++)
	cout << i << ": " << a.c.get(i) << endl;
	return s;
}

queue& queue::operator=(const queue& x)
{	
	c = x.c;
	return *this;
}

bool queue::operator==(const queue& x)
{
	if(c==x.c)
	return true;
	return false;
}

bool queue::operator!=(const queue& x)
{
	if(c==x.c)
	return false;
	return true;
}
