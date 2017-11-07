#include "sort_container.h"

SortedContainer::SortedContainer()
{
	Container();
}

void SortedContainer::insert(Entry x)
{
	if(isfull())
	{
		Warning("Container is full");
	}
	elements[count] = x;
	count++;
	sort();
}

void SortedContainer::sort()
{
	for(int i = 0; i<size();i++)
	{
		for(int j = i; j>0;j--)
		{
			if(elements[j] < elements[j-1])
			{
				swap(elements[j],elements[j-1]);
			}
		}	
	}
}

void SortedContainer::swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
