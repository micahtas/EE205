#include "sortedcontainer.h"

SortedContainer::SortedContainer()
{
	Container();
}

void SortedContainer::insert(Entry x, Position p)
{

        if(isfull())
        {
                Warning("Container:Container is full; did nothing");
        }
	
	element[count] = x;
	count++;
	sort();	
}

void SortedContainer::sort()
{
	for(int i = 0; i < size(); i++)
	{
		for(int j = i; j > 0; j--)
		{
			if (elements[j] < elements[j-1])
			{
				swap(elemets[j], elemenets[j-1]);
			}
		}
	}
}

void SortedContainer::swap(int &a, int &b)
{
	int = temp;
	temp = a;
	a = b;
	b = temp;
}
