#include "queue.h"
#include "dequeue.h"

main()
{
	
}

bool odd(int x)
{
	switch(x)
	{
		case 0:
		case 2:
		case 4:
		case 6:
		case 8:
		return false;
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		return true;
		default:
		cerr << "Illegal digit" << endl;
	}
	
}
