//	File: datime.h
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	Date: 2/9/14

//	Defines the "DaTime" data time and the functions that manipulate it 
//	A "DaTime" object records the day of the week and time span for
//	a scheduled event.

#ifndef DATIME_H
#define DATIME_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "common.h"
#include "day.h"
#include "time.h"
using namespace std;


/*  DaTime data type declaration  */
class DaTime {	
	public:
	Day day;	/**/
	Time start;	/**/
	Time end;	/**/
	
	/* Accessor functions  */
	Day dt_GetDay(DaTime *d) const;
	Time dt_GetStart(DaTime *d) const;
	Time dt_GetEnd(DaTime *d) const;
	int dt_GetDuration(DaTime *d) const;	
	/* Display functions  */
	void dt_Display(DaTime *d) const;	
	/* Comparison functions  */
 	Boolean dt_Equal(DaTime *a, DaTime *b) const;
 	Boolean dt_NotEqual(DaTime *a, DaTime *b) const;
 	Boolean dt_LessThan(DaTime *a, DaTime *b) const;
 	Boolean dt_GreaterThan(DaTime *a, DaTime *b) const;
 	Boolean dt_LessThanOrEqual(DaTime *a, DaTime *b) const;
 	Boolean dt_GreaterThanOrEqual(DaTime *a, DaTime *b) const;
 	Boolean dt_Overlap(DaTime *a, DaTime *b) const;
	Boolean dt_NonOverlap(DaTime *a, DaTime *b) const;
 	int dt_Difference(DaTime *a, DaTime *b) const;
	/* Initialization functions   */
	void dt_Init(DaTime *d, Day day, Time start, Time end);
	void dt_Clear(DaTime *d);
	void dt_Copy(DaTime *dest, DaTime *source);	
	/* Mutator functions  */
	void dt_SetDay(DaTime *d, Day day);
	void dt_SetStart(DaTime *d, Time start);
	void dt_SetEnd(DaTime *d, Time end);
	void dt_SetDuration(DaTime *d, int mins);
	/* Manipulation Functions */
	void dt_ChangeDay(DaTime *da, Day day);
	void dt_ChangeDuration(DaTime *d, int dur);
	void dt_ChangeStart(DaTime *d, Time newstart);
	DaTime dt_Merge(DaTime *a, DaTime *b);	
	
	private:
	int duration; 
};

/* Initialization functions   */
/*
void dt_Init(DaTime *d, Day day, Time start, Time end);
void dt_Clear(DaTime *d);
void dt_Copy(DaTime *dest, DaTime *source);
*/

/* Accessor functions  */
/*
Day dt_GetDay(DaTime *d) const;
Time dt_GetStart(DaTime *d) const;
Time dt_GetEnd(DaTime *d) const;
int dt_GetDuration(DaTime *d) const;
*/

/* Mutator functions  */
/*
void dt_SetDay(DaTime *d, Day day);
void dt_SetStart(DaTime *d, Time start);
void dt_SetEnd(DaTime *d, Time end);
void dt_SetDuration(DaTime *d, int mins);
*/

/* Display functions  */
//void dt_Display(DaTime *d) const;

/* Comparison functions  */
/*
Boolean dt_Equal(DaTime *a, DaTime *b) const;
Boolean dt_NotEqual(DaTime *a, DaTime *b) const;
Boolean dt_LessThan(DaTime *a, DaTime *b) const;
Boolean dt_GreaterThan(DaTime *a, DaTime *b) const;
Boolean dt_LessThanOrEqual(DaTime *a, DaTime *b) const;
Boolean dt_GreaterThanOrEqual(DaTime *a, DaTime *b) const;
Boolean dt_Overlap(DaTime *a, DaTime *b) const;
Boolean dt_NonOverlap(DaTime *a, DaTime *b) const;
int dt_Difference(DaTime *a, DaTime *b) const;
*/

/* Manipulation functions  */
/*
void dt_ChangeDay(DaTime *da, Day day);
void dt_ChangeDuration(DaTime *d, int dur);
void dt_ChangeStart(DaTime *d, Time newstart);
DaTime dt_Merge(DaTime *a, DaTime *b);
*/

#endif
