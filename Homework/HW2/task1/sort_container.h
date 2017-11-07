#include "container.h"

class SortedContainer : public Container
{
public:
	SortedContainer();
	SortedContainer(Entry array[], const int &n);

	//motators
	void insert(Entry x);
	
	//accessors
	Position bsrch(const Entry &x);

private:
	void sort();
	void swap(int &a, int &b);
};
