/* File: testqueue.cc
 * Author: Kunliang Xiao
 */


#include "queue.h"

main()
{
	int o=20;
	int p=40;
	int q=2;
	queue a;
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

	cout << "Current queue size: " << a.size() << endl;

	a.push(q);
	cout << a;
	cout << "Front: " << a.front() << endl;
	a.pop();
	cout << a;

	queue b;

	if(b==a)
	cout << "same queue" << endl;

	b = a;
	cout << "queue a: " << a << endl;
	cout << "queue b: " << b << endl;
	if(b==a)
	cout << "same queue" << endl;

	b.push(q);
	a.pop();
	cout << "queue a: " << a << endl;
	cout << "queue b: " << b << endl;
	if(b==a)
	cout << "same queue" << endl;

}
