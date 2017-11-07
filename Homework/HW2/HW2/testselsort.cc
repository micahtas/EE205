
/*  File:  testselsort.cc
 *  By:   
 *  Date: 
 */

#include <iostream>
using namespace std;
#include "sort_container.h"
#include "entry.h"


main()
{
   Entry a[10] = {34,56,4,10,77,51,93,30,5,52};
   SortedContainer s(a,10);

	cout << s << endl;

	Entry x = 51;
	cout << "Entry " << x << " at position " << s.bsrch(x) << endl;

	x = 27;
	cout << "Entry " << x << " at position " << s.bsrch(x) << endl;

}

