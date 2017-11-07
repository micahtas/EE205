
/*	File: review_func.c
 *	 */


#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "review_func.h"

#define FIXIT


void review_func(int param_e, int *param_f)
{  int local_c;
   static int local_h = 5;
   int *dynamic_i;

	local_c = param_e;
	param_e = 6;
	*param_f = local_h;
	global_a = 8;

	dynamic_i = malloc(sizeof(int));
	*dynamic_i = 9;
	
        printf("\treview_func says:\n");
        printf("\t\t global_a = %d\n",global_a);
        printf("\t\t param_e = %d\n",param_e);
        printf("\t\t *param_f = %d\n",*param_f);
        printf("\t\t local_c = %d\n",local_c);
        printf("\t\t local_h = %d\n",local_h);
        printf("\t\t *dynamic_i = %d\n",*dynamic_i);

	#ifndef FIXIT
	global_b = 10;
        printf("\t\t global_b = %d\n",global_b);
	#endif

	helper_func();

	local_h++;

	free(dynamic_i);
	
}

static void helper_func(void)
{
	printf("\t\t\tHelper function\n");
}


