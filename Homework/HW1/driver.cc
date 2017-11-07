//	File: driver.cc
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 2/9/14


//	Test driver for DaTime data type

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "class.h"
//#include "datime.h"
//#include "time.h"
using namespace std;

void time_Init(Time *t, int hour, int minute);
void time_InitSingle(Time *t, int hrmin);

main()
{
   	Time t1, t2, t3, t4, t5, t6, t7;
   	DaTime a, b, c, d, e, f, g;

	t1.time_Init(11, 30);
	t2.time_Init(12, 20);
	t3.time_InitSingle(300);
	t4.time_InitSingle(415);
	t5.time_InitSingle(1030);
	t6.time_InitSingle(1215);
	t7.time_InitSingle(515);

	dt_Init('m', t1, t2);		/* Implementation of Set functions */
	cout << "Class A: ";
	dt_Display(&a);	
	dt_Copy(&f, &a);		/* Implementation of Copy */
	cout << "Copied class A to class F." << endl;
	cout << "Class F: ";
        dt_Display(&f);
	dt_GetDay(&a);			/* Implementation of GetDay */
	dt_GetStart(&a); 		/* Implementation of GetStart */
	dt_GetEnd(&a);			/* Implementation of GetEnd */
	dt_GetDuration(&a);		/* Implementation of GetDuration */

	dt_Init('t', t3, t4);		/* Implementation of Set functions */
	cout << "Class B :";
	dt_Display(&b);
	if(dt_Equal(&a, &b))		/* Implementation of Equal */
		cout << "Class A and Class B are Equal." << endl;
	if(dt_NotEqual(&a, &b))		/* Implementation of NotEqual */
		cout << "Class A and Class B are NOT Equal." << endl;
	if(dt_LessThan(&a, &b))		/* Implementation of LessThan */
		cout << "Class A is Less Than Class B." << endl;
	if(!dt_LessThan(&a, &b))
		cout << "Class A is NOT Less Than Class B." << endl;
	cout << "Class A: ";
        dt_Display(&a);
	cout << "Class B: ";
        dt_Display(&b);


	dt_Init('m', t5, t1);		/* Implementation of Set functions */
	cout << "Class C: ";
	dt_Display(&c);
	d = dt_Merge(&c, &a);		/* Implementation of Merge functions */
	cout << "Class D: ";
	dt_Display(&d);
	e = dt_Merge(&d, &b);		/* Implementation of Merge functions */
	cout << "Class E: ";
	dt_Display(&e);
	

	dt_Init('m', t5, t6);		/* Implementation of Set functions */
	cout << "Class G: ";
	dt_Display(&g);			/* Showing the 'Set' functions worked */
	
	if(dt_NotEqual(&g, &c))		/* Implementation of NotEqual */
		cout << "Class G and Class C are NOT equal." << endl;
	if(!dt_NotEqual(&g, &c))
		cout << "Class G and Class C are equal." << endl;
	if(dt_GreaterThan(&g, &c))	/* Implementation of GreaterThan*/
		cout << "Class G is Greater Than Class C." << endl;
	if(!dt_GreaterThan(&g, &c))
		cout << "Class G is NOT Greater Than Class C." << endl;
	if(dt_LessThanOrEqual(&g, &b))	/* Implementation of LessThanOrEqual */
		cout << "Class G is Less Than or Equal to Class B." << endl;
	if(!dt_LessThanOrEqual(&g, &b))
                cout << "Class G is NOT Less Than or Equal to Class B." << endl;
	/* Implementation of GreaterThanOrEqual */
	if(dt_GreaterThanOrEqual(&g, &a))
		cout << "Class G is Greater Than or Equal to Class A." << endl;
	if(!dt_GreaterThanOrEqual(&g, &a))
                cout << "Class G is NOT Greater Than or Equal to Class A." << endl;
	if(dt_Overlap(&g, &d))		/* Implementation of Overlap */
		cout << "Class G and Class D overlap!" << endl;
	if(dt_Overlap(&c, &d))		/* Implementation of Overlap */
		cout << "Class C and Class D overlap!" << endl;
	if(dt_NonOverlap(&a, &c))	/* Implementation of NonOverlap */
		cout << "Class A and Class C do NOT overlap!" << endl;
	cout << "Classes A and C: ";
	dt_Difference(&a, &c);          /* Implementation of Difference */
	cout << "Class A: ";
        dt_Display(&a);
	cout << "Class C: ";
        dt_Display(&c);


	/* Manipulation Functions */
	dt_ChangeDay(&a, 's');		/* Implementation of ChangeDay */
	dt_ChangeStart(&a, t3);		/* Implementation of ChangeStart */
	dt_ChangeDuration(&a, 120);     /* Implementation of ChangeDuration */
	cout << "Changed day and times of Class A." << endl;
	cout << "Class A: ";
	dt_Display(&a);			/* Showing Change function */
	


	/* Print contents of class structs to check results */
	cout << "Class B: ";
	dt_Display(&b);
	cout << "Class C: ";
	dt_Display(&c);
	cout << "Class D: ";
	dt_Display(&d);
	cout << "Class E: ";
	dt_Display(&e);
	cout << "Note: Class E should be empty since it fails to merge." << endl;
	cout << "Class F: ";
	dt_Display(&f);		
	cout << "Class G: ";
	dt_Display(&g);
}
