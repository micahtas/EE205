/* File: teststack.cc
 * Author: Dead Kurozumi
 */


#include "stack.h"

main()
{
	int o=20;
	int p=40;
	int q=2;
	stack a;
	if(a.isempty())
	cout << "Entering data" << endl;

	a.push(o);
	cout << a;

	if(a.isempty())
	cout << "Error" << endl;
	if(a.isfull())
	cout << "Error" << endl;

	a.push(p);
	cout << a;

	cout << "Current stack size: " << a.size() << endl;

	a.push(q);
	cout << a;
	cout << "Top: " << a.top() << endl;
	a.pop();
	cout << a;

	stack b;

	if(b==a)
	cout << "same stack" << endl;

	b = a;
	cout << "stack a: " << a << endl;
	cout << "stack b: " << b << endl;
	if(b==a)
	cout << "same stack" << endl;

	b.push(q);
	a.pop();
	cout << "stack a: " << a << endl;
	cout << "stack b: " << b << endl;
	if(b==a)
	cout << "same stack" << endl;

}
