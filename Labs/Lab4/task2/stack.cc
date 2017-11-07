//
// "stack.cc"
//
// Definitions of stack functions
//
#include "stack.h"


stack::stack()
{
    Container();
}

stack::~stack()
{
}

void stack :: push(const Entry &x)
{
    c.insert(x);
}

Entry stack :: pop(void)
{
    int x = -1, temp;

	x = c.size();
	temp = c.remove(x-1);
	return temp;
}

Entry stack :: top(void)
{
    int x = -1, temp;

	x = c.size();
	temp = c.get(x-1);
	return temp;
}


int stack :: size() const
{
    int temp;
	temp = c.size();
    return temp;
}

bool stack :: isempty() const
{
   int temp;
	temp = c.isempty();
   	return temp;
}

bool stack :: isfull() const
{
   int temp;
	temp = c.isfull();
	return temp;
}

void stack :: clear()
{
    c.clear();
}

stack & stack :: operator=(const stack& s)
{
    c = s.c;
    return *this;
}

bool stack::operator!=(const stack &s)
{
    if(c == s.c)
        return false;
    return true;
}

bool stack::operator==(const stack &s)
{
    if(c == s.c)
        return true;
    return false;
}

ostream & operator << (ostream &s, const stack &a)
{
    cout << "\n";
    for (int i=0; i<a.c.size(); i++)
	cout << i << ": " << a.c.get(i) << endl;
    return s;
}
