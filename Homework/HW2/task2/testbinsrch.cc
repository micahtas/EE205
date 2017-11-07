
/*  File:  testbinsrch.cc
 *  By:    
 *  Date:  
 */

#include <iostream>

#include <cstdlib>

#include <ctime>

#include "sort_container.h"
#include "container.h"
#include "entry.h"
using namespace std;

int BinSearch(SortedContainer &s, Entry key);

int bsrch(SortedContainer &s, int low, int high, Entry key);
void testbinsearch(SortedContainer & s, Entry key);

main()
{
   SortedContainer s;
	
	int randx;
	srand( time(0));
	for(int i=0; i < 5000; i++)
	{
	randx=rand()%(10000+1);
	s.insert(randx);
	//cout<< "i="<<i<<endl;
	}

	// replace me with a randomly generated list of many entrie

	cout << s << endl;


	time_t start;
	time(&start);

	clock_t t = clock();

	// replace me with searches for 100 random keys
	int randy;
	for(int i = 0; i < 20000; i++)
	{
		randy = rand()%(20000+1);
	//	testbinsearch(s, randy);
		s.bsrch(randy);
	}
	
	printf("\nTime taken: % .10fs\n", (float)(clock() - t)/CLOCKS_PER_SEC);
	time_t end;
	time(&end);

	cout << "Time is " << end - start << endl;

}

Position BinSearch(SortedContainer &s, Entry key)
// pre:  the entries are in sorted (ascending) order
// post: returns the index of element matching x, or -1 if not found.
{
	// replace me with an iterative search
	return bsrch(s, 0, s.size()-1, key);
}

int bsrch(SortedContainer &s, int low, int high, Entry key)
{
	if(low > high) return -1;

	int middle = (low + high + 1) / 2;
	
	if(s.get(middle) == key) return middle;
	else if(key < s.get(middle))
		return bsrch(s, low, middle-1, key);
	else return bsrch(s, middle+1, high, key);
}

void testbinsearch(SortedContainer & seq, Entry key)
{
	Position pos = BinSearch(seq, key);
	if(pos >= 0) cout << key << " found at index " << pos << endl;
	else cout << key << " not found" << endl;

}

