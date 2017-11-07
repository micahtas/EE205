
/*  File: container.c
 *  Date: 12 Sep 06
 *  Rev:  25 Sep 07
 *
 *  Container class definitions - version 2
 */

#include <stdlib.h>
#include "common.h"
#include "entry.h"
#include "container.h"

/*******************************************************************/
/*                                                                 */
/*  Simple Container Operations                                    */
/*                                                                 */
/*******************************************************************/

Container::Container()
/*  initialize a Container object
    pre:  none
    post: Container has been created and initialized to empty
 */
{
	for(Entry i=0;i<MAXSIZE;i++)
	{
		elements[i]=0;
	}
		count=0;
}

void Container::traverse(void(*Visit)(Entry))
/*  applies the operation Visit to each element of the Container
    pre: Container has been created; Visit is a function that processes
	elements of type Entry. Visit does not modify the Container.
    post: the action Visit has been applied to each element in the Container
	begining at the first
 */
{
	for(int i = 0; i < count; i++)
	{
		printf("elements[%d]: ", i);
		Visit(elements[i]);
	}
}


/*******************************************************************/
/*                                                                 */
/*  More Complex Container Operations                                   */
/*                                                                 */
/*******************************************************************/

void Container::insert(Entry x, Position p)
/*  insert entry x into Container at position p (-1 is end of container)
    pre:  Container has been created, x is a valid entry, and 0 <= p <= n,
	where n is number of Container entries
    post: x is inserted in the Container at position p, all entries at p and after
	have increased in position by 1.
    error: if Container is full, nothing done and waring produced.
 */
{
	if(isfull())
	{
		Warning("Container is full");
		return;
	}
	else if(p == -1)
	{
		elements[count] = x;
	} else {
		for(int i = count; i>p; i--)
		{
			elements[i]=elements[i-1];
		}
		elements[p]=x;
	}
	count++;
}

Entry Container::remove(Position p)
/*  delete and return entry at position p
    pre:  Container has been created, and 0 <= p < n, where n is number
	of Container entries
    post: entry at position p has been deleted and returned as x, all entries
	after p have decreased in position by 1
    error: if Container is shorter than p, nothing done an waring produced.
*/
{
	Entry x = get(p);
	for(int i=p; i<count ; i++)
	{
		elements[i] = elements[i+1];
	}
	count--;
	return x;
}

Entry Container::get(Position p) const
/*  return entry at position p
    pre:  Container has been created, and 0 <= p < n, where n is number
	of Container entries
    post: entry at position p has been returned as x, Container unchanged
    error: if Container is shorter than p, nothing done an waring produced.
*/
{
	if(count < p)
	{
		Warning("Container is shorter than p");
	} else {
		Entry x = elements[p];
		return x;
	}
}

void Container::replace(Entry x, Position p)
/*  replace entry at position p with x
    pre:  Container has been created, and 0 <= p < n, where n is number
	of Container entries
    post: entry at position p has been replaced with x, other entries unchanged
    error: if Container is shorter than p, nothing done an waring produced.
*/
{
	if(count < p)
	{
		Warning("Container is shorter than p");
	} else {
		elements[p] = x;
	}	
}

ostream &operator<<(ostream &s, const Container &a)
{
	for(int i=0;i<a.size(); i++)
	cout << i << ": " << a.get(i) << endl;
	return s;
}

Position Container::lsrch(Entry x)
{
	Position p=0;
	for(p;p<size();p++)
	{
		if(get(p) == x)
		return p;
	}
	return -1;
}

