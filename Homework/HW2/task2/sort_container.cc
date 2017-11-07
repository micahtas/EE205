#include "sort_container.h"

SortedContainer::SortedContainer()
{
	Container();
}

SortedContainer::SortedContainer(Entry array[], const int &n)
{
	Container();
	int p = n-1;
	for(p;p>0;p--)
	{
		insert(array[p]);
	}
}

SortedContainer::SortedContainer(Entry a[], int size)
{
	for(int i = 0; i < size(); i++)
		sel_sort(a[i]);
}

void SortedContainer::insert(const Entry &x)
{
	if(isfull())
	{
		Warning("Container is full");
	}
	elements[count] = x;
	count++;
	sort();
}

Position SortedContainer::bsrch(const Entry &x)
{
	Position low = 0;
	Position high = size();
	Position middle;
	while(low < high)
	{
		middle = (low+high + 1)/2;
		if(get(middle) == x) return middle;
		else if(x < get(middle))
		{
			high = middle-1;
		}else{
			low = middle+1;
		}
	}
	return -1;
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

void SortedContainer::sel_sort(Entry x[])
{
	int temp;
	
	for(int i = 0; i < size(); i++)
	{
		for(int j = i+1; j < i; j++)
		{
			if(x[i] > x[j])
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
}
