#include "container.h"

class SortedContainer : public Container
{
public:
	SortedContainer();
	SortedContainer(Entry array[],const int &n);
	SortedContainer(Entry a[], int size);

	//motators
	void insert(const Entry &x);

	//accessors
	Position bsrch(const Entry &x);

private:
	void sort();
	void swap(int &a, int &b);
	void sel_sort();
};
