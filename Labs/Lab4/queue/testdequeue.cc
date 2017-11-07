/* File: testdequeue.cc
 * Author: Kunliang Xiao
 */


#include "dequeue.h"

main()
{
	int o=20;
	int p=40;
	int q=1;
	int r=2;
	int s=3;
	int t=4;
	dequeue a;

	if(a.isempty())
	cout << "Entering data" << endl;

	a.push_front(q);
	a.push_front(r);
	cout << a;

	a.push_front(s);
	cout << a;

	a.push_back(s);
	cout << a;

	if(a.isempty())
	cout << "Error" << endl;
	if(a.isfull())
	cout << "Error" << endl;

	cout << "Current dequeue size: " << a.size() << endl;

	a.push_back(q);
	cout << a;
	cout << "Front: " << a.front() << endl;
	cout << "Back: " << a.back() << endl;
	a.pop_back();
	cout << a;
	a.pop_front();
	cout << a;

	dequeue b;

	if(b==a)
	cout << "same dequeue" << endl;

	b = a;
	cout << "queue a: " << a << endl;
	cout << "queue b: " << b << endl;
	if(b==a)
	cout << "same dequeue" << endl;

	b.push_front(q);
	a.pop_back();
	cout << "queue a: " << a << endl;
	cout << "queue b: " << b << endl;
	if(b==a)
	cout << "same dequeue" << endl;

}
