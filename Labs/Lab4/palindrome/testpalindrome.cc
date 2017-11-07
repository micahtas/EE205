#include "stack.h"
#include "testpalindrome.h"
#include <iostream>

//#define DEBUG

using std::cout;
using std::cin;
using namespace std;

main()
{
    stack a, b, c;
    char x;
	
	while(x = cin.get())
	{
	    if( whitep(x) )
	    {}
	    else if( x == '\r' || x == '\n')
	    {
		break;
	    }
	    else
	    {
	    x = to_upper(x);

#ifdef DEBUG
cout << "\n" << "x is: " << x << endl;
#endif


#ifdef DEBUG
cout << "\ninsert here" << endl;
#endif

	    	c.push(x);
	    }

	}
	    a = c;	

	    Entry temp;

	    while( a.size() > b.size() )
	    {
		if( a.size() == b.size() + 1)
		{
		    a.pop();
		}
		else
		{
		temp = a.pop();
		b.push(temp);
		}
	    }

	    if( a == b )
	    {
		cout << "This is a palindrome" << endl;
	    }
	    else
	    {
		cout << "This is not a palindrome" << endl;
	    }
#ifdef DEBUG
cout << a << endl;
cout << b << endl;
#endif
}

char to_upper(char c)
{
    if( IS_LOWER(c) )
	return c - 'a' + 'A';
    return c;
}

int whitep(char c)
{
    if( c == '\t' || c == ' ' )
	return true;
    return false;
}
