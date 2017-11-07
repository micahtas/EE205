/* File: hmain.cc */

#include <iostream>
#include "hanoi.h"

// Test driver for Towers of Hanoi
// 	DO NOT TRY 64 DISKS!!!

main()
{   int num;

	cout << "Enter number of disk(CRTL+D to exit): " << flush;
	
	while(cin >> num)
	{
		hanoi(num,1,3,2);
		cout << "Enter number of disks(CRTL+D to exit): " << flush;
	}
}

