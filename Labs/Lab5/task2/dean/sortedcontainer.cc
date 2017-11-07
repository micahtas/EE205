
/*  File: container.c
 *  Date: 12 Sep 06
 *  Rev:  25 Sep 07
 *
 *  Container class definitions - version 2
 */

#include <stdlib.h>
#include "common.h"
#include "entry.h"
#include "sortedcontainer.h"


void sortedcontainer::insert(Entry x)
{
	c.insert(x);
	for(int i=0; i<c.size();i++)
	{
	    for(int j=i;j>0;j--)
	    {
		if(c.get(j) < c.get(j-1))
		{
		    int temp = c.get(j-1);
		    c.replace(c.get(j),j-1);
		    c.replace(temp,j);
		}
	    }
	}
}

