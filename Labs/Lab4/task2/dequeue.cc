/* File: dequeue.cc
 * Author: 
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

void dequeue::pushback(const Entry& x)
{
	c.insert(x);
}
void dequeue :: pushfront(const Entry &x)
{
    c.insert(x,0);
}

Entry dequeue::popfront(void) 
{
	Entry x;
	x = c.remove(0);
	return x;
}
Entry dequeue :: popback(void)
{
    int x = -1, temp;

	x = c.size();
	temp = c.remove(x-1);
	return temp;
}

Entry dequeue :: back(void) const
{
    int x = -1, temp;

	x = c.size();
	temp = c.get(x-1);
	return temp;
}

Entry dequeue::front(void) const
{
	Entry x;
	x = c.get(0);
	return x;
}

ostream & operator << (ostream &s,const dequeue &a)
{
	cout << "\n";
	for (int i=0; i<a.c.size() ; i++)
	cout << i << ": " << a.c.get(i) << endl;
	return s;
}

dequeue& dequeue::operator=(const dequeue& x)
{	
	c = x.c;
	return *this;
}

bool dequeue::operator==(const dequeue& x)
{
	if(c==x.c)
	return true;
	return false;
}

bool dequeue::operator!=(const dequeue& x)
{
	if(c==x.c)
	return false;
	return true;
}
