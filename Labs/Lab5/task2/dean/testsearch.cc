
/*  File:  testsearch.cc
 *  By:   
 *  Date: 
 */

#include <iostream>
using namespace std;
#include "entry.h"
#include "sortedcontainer.h"


main()
{
   sortedcontainer s;

	s.insert( 34);
	s.insert( 56);
	s.insert( 4);
	s.insert( 10);
	s.insert( 77);
	s.insert( 51);
	s.insert( 93);
	s.insert( 30);
	s.insert( 5);
	s.insert( 52);

	cout << s.c << endl;
	Entry x = 52;
	cout << "Entry " << x << " at position " << s.c.lsrch(x) << endl;

	x = 27;
	cout << "Entry " << x << " at position " << s.c.lsrch(x) <<endl;

}

