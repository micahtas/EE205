
/*  File: testcontainer.c
 *  Date: 6 Sep 05
 *  Rev: 25 Sep 07
 *
 *  simple tests for container data type
 */

#include "container.h"
#include "entry.h"

void printcontainer(Entry);

int main()
{
   Container l;
   Entry a;
   int x;
    
    debug("Should be empty");
    
	if(l.isempty()) printf("Container is empty\n");
	else printf("Container not empty\n");

	l.insert(3);
	l.insert(6);
	l.insert(9);

    debug("Should be not empty");
	if(l.isempty()) printf("Container is empty\n");
	else printf("Container not empty\n");

    debug("Should be size 3");
	x = l.size();
	printf("size of Container is %d\n", x);

    debug("Should be: 3, 6, 9");
	l.traverse(printcontainer);

	l.insert(5, 1);
    debug("Should be: 3, 5, 6, 9");
	l.traverse(printcontainer);

    debug("Should be: 6");
	a = l.remove(2);
	printf("deleted entry %d\n", a);
    
    debug("Should be: 3, 5, 9");
	l.traverse(printcontainer);

    debug("Should be: 0");
	a = l.get(3);
	printf("retrieved entry %d\n", a);
    
    debug("Should be: 9");
	a = l.get(2);
	printf("retrieved entry %d\n", a);

	l.replace(6, 1);

    debug("Should be: 3, 6, 9");
	l.traverse(printcontainer);

	l.clear();

	x = l.size();
    debug("Should be: 0");
	printf("size of container is %d\n", x);

    debug("Should be empty");
	if(l.isempty()) printf("Container is empty\n");
	else printf("Container not empty\n");

	l.insert(20);
	l.insert(30);
    debug("Should be: 20, 30");
	l.traverse(printcontainer);

    debug("Should be: 20, 25, 30");
	l.insert(25, 1);
	l.traverse(printcontainer);

    debug("Should be: 15, 20, 25, 30");
	l.insert(15, 0);
	l.traverse(printcontainer);

    debug("Should be: 20");
	a = l.remove(1);
	printf("deleted entry %d\n", a);
    
    debug("Should be: 15, 25, 30");
	l.traverse(printcontainer);

    debug("Should be: 15");
	a = l.remove(0);
	printf("deleted entry %d\n", a);
    
    debug("Should be: 25, 30");
	l.traverse(printcontainer);

    debug("Should be: 30");
	a = l.remove(1);
	printf("deleted entry %d\n", a);
    
    debug("Should be: 25");
	l.traverse(printcontainer);

}

void printcontainer(Entry x)
{   printf("%d\n", x);   }

