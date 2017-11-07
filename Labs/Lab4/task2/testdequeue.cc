/* File: testdequeue.cc
 * Author: Mark Miw
 */


#include "dequeue.h"

main()
{
	int o=20;
	int p=40;
	int q=2;
	dequeue a;
	if(a.isempty())
	cout << "Entering data" << endl;

	a.pushfront(o);
	cout << a;

	if(a.isempty())
	cout << "Error" << endl;
	if(a.isfull())
	cout << "Error" << endl;
   
	a.pushfront(p);
	cout << a;

	cout << "Current stack size: " << a.size() << endl;

	a.pushback(q);
	cout << a;
	cout << "Top: " << a.front() << endl;
	a.popfront();
	cout << a;

	dequeue b;

	if(b==a)
	cout << "same stack" << endl;

	b = a;
	cout << "stack a: " << a << endl;
	cout << "stack b: " << b << endl;
	if(b==a)
	cout << "same stack" << endl;

	b.pushfront(q);
	a.popback();
	cout << "stack a: " << a << endl;
	cout << "stack b: " << b << endl;
	if(b==a)
	cout << "same stack" << endl;

}
