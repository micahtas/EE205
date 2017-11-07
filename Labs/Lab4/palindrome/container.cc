
/*  File: container.cc
 *  Date: 26 Sep 05
 *  Mod:  25 Sep 07
 *  Rev:  v1
 *
 *  Container class definitions as a linked list
 *
 *  Author: Kunliang Xiao
 */

#include "common.h"
#include "entry.h"
#include "container.h"
#include "listnode.h"
#include <iostream>
#include <new>
using namespace std;

/*******************************************************************/
/*                                                                 */
/*  Constructors and Destructors                                   */
/*                                                                 */
/*******************************************************************/

Container :: Container()
/*  initialize a Container object
    pre:  none
    post: container has been created and initialized to empty
 */
{	init_to_empty();	}

Container :: ~Container()
{	destroy_elements();	}

/*******************************************************************/
/*                                                                 */
/*  Accessors                                                      */
/*                                                                 */
/*******************************************************************/

bool Container :: isempty() const
/*  tests if a container is empty
    pre:  container has been created
    post: returns true if container is empty; false otherwise
 */
{	return ( count == 0);	}

bool Container :: isfull() const
/*  tests if a container is full
    pre:  container has been created
    post: returns true if container is full; false otherwise
 */
{	return false;	}

int Container :: size() const
/*  determines the size of a container
    pre:  container has been created
    post: returns the number of entries in the container
 */
{	return count;	}

Entry Container :: get(Position p) const
/*  return entry at position p
    pre:  container has been created, and 0 <= p < n, where n is number
	of container entries
    post: entry at position p has been returned as x, container unchanged
    error: if container is shorter than p, nothing done an waring produced.
 */
{
	if( !valid_position(p,count-1) || isempty())
	{	Warning("Container: Get to illegal position; return ERROR");
		return ERROR;
	}

	ListNode *current = findpos(p);
	return current->getdata();
}


/*******************************************************************/
/*                                                                 */
/*  Mutators                                                       */
/*                                                                 */
/*******************************************************************/

void Container :: clear()
/*  clear a Container object
    pre:  container has been created
    post: all entries have been removed; container is empty
 */
{	destroy_elements();
	init_to_empty();
}


void Container :: traverse(void(*Visit)(Entry))
/*  applies the operation Visit to each element of the container
    pre: container has been created; Visit is a function that processes
	elements of type Entry. Visit does not modify the container.
    post: the action Visit has been applied to each element in the container
	begining at the first
 */
{
	ListNode *current = head;
	while(current!=NULL)
	{	(*Visit)(current->getdata());
		current = current->getnext();
	}
}


void Container :: insert(Entry x, Position p)
/*  insert entry x into container at position p
    pre:  container has been created, x is a valid entry, and 0 <= p <= n,
	where n is number of container entries
    post: x is inserted in the container at position p,
	 all entries at p and after have increased in position by 1.
    error: if container is full, nothing done and waring produced.
 */
{
	// if adding to the end of the container
	if( p == END ) p = count;

	if( !valid_position(p,count) || isfull())
	{	Warning("Container: Insert to illegal position; nothing done");
		return;
	}

	// create new node
	ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
	newnode->setdata(x);

	// if inserting at the begining of the container
	if(p == 0)
	{	newnode->setnext(head);
		head = newnode;
	}
	else  // othewise find position and insert
	{
		ListNode *prev = findpos(p-1);
		newnode->setnext(prev->getnext());
		prev->setnext(newnode);
	}

	// update count;
	count++;

}

Entry Container :: remove(Position p)
/*  delete and return entry at position p
    pre:  container has been created, and 0 <= p < n, where n is number
	of container entries
    post: entry at position p has been deleted and returned as x, all entries
	after p have decreased in position by 1
    error: if container is shorter than p, nothing done an waring produced.
 */
{
	ListNode *prev = (ListNode *)malloc(sizeof(ListNode));
	ListNode *current = (ListNode *)malloc(sizeof(ListNode));
	ListNode *nex = (ListNode *)malloc(sizeof(ListNode));

	if(count <= p)
	{
		Warning("Container: remove illegal position; nothing done");
		return ERROR;
	}

	current = findpos(p);
	nex = findpos(p+1);
	
	if(p == 0)
	{
		head = nex;
	} else
	{
		prev = findpos(p-1);
		prev->setnext(nex);
	}
	count--;
	Entry x = current->getdata();
	free(current);
	return x;
	
}

void Container :: replace(Entry x, Position p)
/*  replace entry at position p with x
    pre:  container has been created, and 0 <= p < n, where n is number
	of container entries
    post: entry at position p has been replaced with x, other entries unchanged
    error: if container is shorter than p, nothing done an waring produced.
 */
{
	if( !valid_position(p,count-1) || isempty())
	{	Warning("Container: Retrieve to illegal position; nothing done");
		return;
	}

	ListNode *current = findpos(p);
	current->setdata(x);

}


/*******************************************************************/
/*                                                                 */
/*  Container private helper functions                                  */
/*                                                                 */
/*******************************************************************/

void Container :: init_to_empty()
{	head = NULL;
	count = 0;
}

void Container :: destroy_elements()
{
	ListNode *current = head;
	ListNode *prev = NULL;
	while(current)
	{	prev = current;
		current = prev->getnext();
		free(prev);
	}
}

ListNode * Container :: findpos(Position pos) const
/*  find the node at position pos
    pre: container has been created; pos is in bounds
    post: returns pointer to the node at pos
 */
{
	if(pos > count)
	{	Warning("Container: Position out of range");
		return NULL;
	}

	ListNode *current = head;
	for(int i = 0; i < pos; i++)
		current = current->getnext();

	return current;
}

bool Container :: valid_position(Position p, int size) const
{	return ((p >= 0) && (p <= size));	}


ostream &operator<<(ostream &s, const Container &a)
{
	for(int i=0; i<a.size() ; i++)
	cout << i << ": " << a.get(i) << endl;
	return s;
}

Container& Container::operator=(const Container &a)
{
	clear();
	init_to_other(a);
	return *this;
}

bool Container::operator==(const Container &a)
{
	if(count != a.count)
	return false;
	int i=0;

	for(ContainerIterator it(a.Start()); it != a.End(); it++)
	{
	if((*it)!=a.get(i))
	return false;
	i++;
	}
	return true;
}

bool Container::operator!=(const Container &a)
{
	if(*this==a)
	return false;
	else
	return true;
}

void Container::init_to_other(const Container &a)
{
	for(ContainerIterator it(a.Start()); it != a.End(); it++)
	{
		
		insert(*it);
	}
}

ContainerIterator::ContainerIterator():current(NULL) {}

ContainerIterator Container::Start() const
{
	ContainerIterator it;
	it.current = head;
	return it;
}

ContainerIterator Container::End() const
{
	ContainerIterator it;
	it.current = NULL;
	return it;
}

bool ContainerIterator::operator==(const ContainerIterator& it) const
{
	if((*this).current == it.current)
	return true;
	return false;
}

bool ContainerIterator::operator!=(const ContainerIterator& it) const
{
	if((*this).current == it.current)
	return false;
	return true;
}

ContainerIterator ContainerIterator::operator++()
{
	if(current != NULL) current = current->getnext();
	return *this;
}

ContainerIterator ContainerIterator::operator++(int)
{
	ContainerIterator it(*this);
	if(current != NULL) current = current->getnext();
	return it;
}

Entry ContainerIterator::operator*() const
{
	if(current == NULL)
	{
		cerr << "Illegal" <<endl;
		abort();
	}
	return (*current).getdata();
} 
