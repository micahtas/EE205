

/*
 * 	File:  driver.c
 *	Name: Allen Shultz
 * 	login: shultzam
 * 	Date:  25 Aug 07
 *	Mod: 1/24/14
 */

/*  Test driver for DaTime data type
 */   


#include <stdio.h>
#include "datime.h"
#include "time.h"

main()
{
   	Time t1, t2, t3, t4, t5, t6, t7;
   	DaTime a, b, c, d, e, f, g;

	time_Init(&t1, 11, 30);
	time_Init(&t2, 12, 20);
	time_InitSingle(&t3, 300);
	time_InitSingle(&t4, 415);
	time_InitSingle(&t5, 1030);
	time_InitSingle(&t6, 1215);
	time_InitSingle(&t7, 515);

	dt_Init(&a, 'm', t1, t2);	/* Implementation of Set functions */
	printf("Class A: ");
	dt_Display(&a);	
	dt_Copy(&f, &a);		/* Implementation of Copy */
	printf("Copied class A to class F.\n");
	printf("Class F: ");
        dt_Display(&f);
	dt_GetDay(&a);			/* Implementation of GetDay */
	dt_GetStart(&a); 		/* Implementation of GetStart */
	dt_GetEnd(&a);			/* Implementation of GetEnd */
	dt_GetDuration(&a);		/* Implementation of GetDuration */

	dt_Init(&b, 't', t3, t4);	/* Implementation of Set functions */
	printf("Class B :");
	dt_Display(&b);
	if(dt_Equal(&a, &b))		/* Implementation of Equal */
		printf("Class A and Class B are Equal.\n");
	if(dt_NotEqual(&a, &b))		/* Implementation of NotEqual */
		printf("Class A and Class B are NOT Equal.\n");
	if(dt_LessThan(&a, &b))		/* Implementation of LessThan */
		printf("Class A is Less Than Class B.\n");
	if(!dt_LessThan(&a, &b))
		printf("Class A is NOT Less Than Class B.\n");
	printf("Class A: ");
        dt_Display(&a);
	printf("Class B: ");
        dt_Display(&b);


	dt_Init(&c, 'm', t5, t1);	/* Implementation of Set functions */
	printf("Class C: ");
	dt_Display(&c);
	d = dt_Merge(&c, &a);		/* Implementation of Merge functions */
	printf("Class D: ");
	dt_Display(&d);
	e = dt_Merge(&d, &b);		/* Implementation of Merge functions */
	printf("Class E: ");
	dt_Display(&e);
	

	dt_Init(&g, 'm', t5, t6);	/* Implementation of Set functions */
	printf("Class G: ");
	dt_Display(&g);			/* Showing the 'Set' functions worked */
	
	if(dt_NotEqual(&g, &c))		/* Implementation of NotEqual */
		printf("Class G and Class C are NOT equal.\n");
	if(!dt_NotEqual(&g, &c))
		printf("Class G and Class C are equal.\n");
	if(dt_GreaterThan(&g, &c))	/* Implementation of GreaterThan*/
		printf("Class G is Greater Than Class C.\n");
	if(!dt_GreaterThan(&g, &c))
		printf("Class G is NOT Greater Than Class C.\n");
	if(dt_LessThanOrEqual(&g, &b))	/* Implementation of LessThanOrEqual */
		printf("Class G is Less Than or Equal to Class B.\n");
	if(!dt_LessThanOrEqual(&g, &b))
                printf("Class G is NOT Less Than or Equal to Class B.\n");
	/* Implementation of GreaterThanOrEqual */
	if(dt_GreaterThanOrEqual(&g, &a))
		printf("Class G is Greater Than or Equal to Class A.\n");
	if(!dt_GreaterThanOrEqual(&g, &a))
                printf("Class G is NOT Greater Than or Equal to Class A.\n");
	if(dt_Overlap(&g, &d))		/* Implementation of Overlap */
		printf("Class G and Class D overlap!\n");
	if(dt_Overlap(&c, &d))		/* Implementation of Overlap */
		printf("Class C and Class D overlap!\n");
	if(dt_NonOverlap(&a, &c))	/* Implementation of NonOverlap */
		printf("Class A and Class C do NOT overlap!\n");
	printf("Classes A and C: ");
	dt_Difference(&a, &c);          /* Implementation of Difference */
	printf("Class A: ");
        dt_Display(&a);
	printf("Class C: ");
        dt_Display(&c);


	/* Manipulation Functions */
	dt_ChangeDay(&a, 's');		/* Implementation of ChangeDay */
	dt_ChangeStart(&a, t3);		/* Implementation of ChangeStart */
	dt_ChangeDuration(&a, 120);     /* Implementation of ChangeDuration */
	printf("Changed day and times of Class A.\n");
	printf("Class A: ");
	dt_Display(&a);			/* Showing Change function */
	


	/* Print contents of class structs to check results */
	printf("Class B: ");
	dt_Display(&b);
	printf("Class C: ");
	dt_Display(&c);
	printf("Class D: ");
	dt_Display(&d);
	printf("Class E: ");
	dt_Display(&e);
	printf("Note: Class E should be empty since it fails to merge.\n");
	printf("Class F: ");
	dt_Display(&f);		
	printf("Class G: ");
	dt_Display(&g);
}
