/* File: hanoi.cc */

#include <iostream>
#include "hanoi.h"
using namespace std;

void hanoi(int num, int from, int to, int temp)
{
	if(num > 0)
	{
		hanoi((num-1), from, temp, to);
		cout << "Move " << from << flush << " disk " << num << flush 
		<< " to tower " << to << endl;
		hanoi((num-1), temp, to, from);
	}
}
