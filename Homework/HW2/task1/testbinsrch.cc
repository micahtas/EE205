
/*  File:  testbinsrch.cc
 *  By:    
 *  Date:  
 */

#include <iostream>
using namespace std;

#include <cstdlib>
using std::rand;

#include <ctime>
using std:: time;

#include "sort_container.h"
#include "entry.h"

int BinSearch(SortedContainer &s, Entry key);

int bsrch(SortedContainer &s, int low, int high, Entry x);
void testbinsearch(SortedContainer & s, Entry key);

main()
{
   SortedContainer s;
/*
	// replace me with a randomly generated list of many entries
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
*/
	int xRan;
	srand(time(0));
	for(int i = 0; i < MAXSIZE; i++);
	{
	xRan = rand()%MAXSIZE;
	s.insert(xRan);
	}
	
	cout << s << endl;


	time_t start;
	time(&start);

	// replace me with searches for 100 random keys
	testbinsearch(s, 51);
	testbinsearch(s, 27);
	testbinsearch(s, 56);
	testbinsearch(s, 4);
	testbinsearch(s, 93);

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

