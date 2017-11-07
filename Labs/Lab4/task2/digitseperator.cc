#include "queue.h"
#include "dequeue.h"

bool odd(int x);

main()
{
	char c;
	Entry i;
	dequeue oddset;
	dequeue evenset;
	cout << "\n\nInput your integer, or any character to end adding digits" << endl;
	while(cin >> c)
	{
		if (c > '9' || c < '0') break;
		i = (Entry)c - '0';
		cout << i << endl;
		if(odd(i))
		oddset.pushback(i);
		else
		evenset.pushback(i);
	}
	
	cout << "Odd digits: " << endl;
	cout << oddset << endl;
	cout << "Even digits: " << endl;
	cout << evenset << endl;

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
