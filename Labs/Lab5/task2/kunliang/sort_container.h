#include "container.h"

class SortedContainer : public Container
{
public:
	SortedContainer();

	//motators
	void insert(Entry x);

private:
	void sort();
	void swap(int &a, int &b);
};
