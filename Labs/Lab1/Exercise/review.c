
/*	File: review.c
 *	 */

#include <stdio.h>
#include "review_func.h"

#define MAIN
#include "globals.h"

#define FIXIT


main()
{  int	local_c,
	local_d;

	global_a = 1;
	global_b = 2;

	local_c = 3;
	local_d = 4;

	printf("main says:\n");
	printf("\t global_a = %d\n",global_a);
	printf("\t global_b = %d\n",global_b);
	printf("\t local_c = %d\n",local_c);
	printf("\t local_d = %d\n",local_d);

	review_func(local_c, &local_d);

	printf("main says:\n");
	printf("\t global_a = %d\n",global_a);
	printf("\t global_b = %d\n",global_b);
	printf("\t local_c = %d\n",local_c);
	printf("\t local_d = %d\n",local_d);

	review_func(local_d, &local_c);
	#ifndef FIXIT
	helper_func();
	#endif

	printf("main says:\n");
	printf("\t global_a = %d\n",global_a);
	printf("\t global_b = %d\n",global_b);
	printf("\t local_c = %d\n",local_c);
	printf("\t local_d = %d\n",local_d);
}

