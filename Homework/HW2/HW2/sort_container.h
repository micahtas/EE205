#include "container.h"

class SortedContainer : public Container
{
public:
	SortedContainer();
	SortedContainer(Entry array[],const int &n);

	//motators
	void insert(const Entry &x);

	//accessors
	Position bsrch(const Entry &x);

private:
	void sort();
	int min(const int &a, const int &b);
	void sel_sort();
	void swap(int &a, int &b);
};
