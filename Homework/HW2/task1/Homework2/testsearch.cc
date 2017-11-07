
/*  File:  testsearch.cc
 *  By:   
 *  Date: 
 */

#include <iostream>
using namespace std;
#include "container.h"
#include "entry.h"
#include "sort_container.h"

main()
{
   SortedContainer s;

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

	cout << s << endl;

	Entry x = 51;
	cout << "Entry " << x << " at position " << s.lsrch(x) << endl;

	x = 27;
	cout << "Entry " << x << " at position " << s.lsrch(x) << endl;

}

