//	File: time.h
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 2/9/14


//	Defines the "Time" data time and the functions that manipulate it 
//	A "Time" object records the hours and minutes of a time of day

#include <iostream>
#include <cstdio>
#include <cstdlib>

#ifndef TIME_H
#define TIME_H

#include "common.h"

using namespace std;


/*  Time data type declaration  */
class Time {
	
	public:
	/* Accessor Functions */
	int time_GetHour(Time *t) const;
	int time_GetMinute(Time *t) const;
	/* Comparison Functions */
	Boolean time_Equal(Time *a, Time *b) const;
	Boolean time_NotEqual(Time *a, Time *b) const;
	Boolean time_LessThan(Time *a, Time *b) const;
	Boolean time_GreaterThan(Time *a, Time *b) const;
	Boolean time_LessThanOrEqual(Time *a, Time *b) const;
	Boolean time_GreaterThanOrEqual(Time *a, Time *b) const;
	int time_Difference(Time *a, Time *b) const;
	/* Inititialization Functions */
	void time_Init(Time *t, int hour, int minute);
	void time_InitSingle(Time *t, int hrmin);
	void time_Clear(Time *t);
	void time_Copy(Time *dest, Time *source);	
	/* Mutator Functions */
	void time_SetHour(Time *t, int hour);
	void time_SetMinute(Time *t, int min);
	/* Display Function */
	void time_Display(Time *d) const;
	/* Manipulation Functions */
	Time time_Add(Time *a, int minutes);		

	private:
	int hour;
        int minute;
};

/* Initialization functions   */
/*
void time_Init(Time *t, int hour, int minute);
void time_InitSingle(Time *t, int hrmin);
void time_Clear(Time *t);
void time_Copy(Time *dest, Time *source);
*/

/* Accessor functions  */
/*
int time_GetHour(Time *t) const;
int time_GetMinute(Time *t) const;
*/

/* Mutator functions  */
/*
void time_SetHour(Time *t, int hour);
void time_SetMinute(Time *t, int min);
*/

/* Display functions  */
//void time_Display(Time *d) const;

/* Comparison functions  */
/*
Boolean time_Equal(Time *a, Time *b) const;
Boolean time_NotEqual(Time *a, Time *b) const;
Boolean time_LessThan(Time *a, Time *b) const;
Boolean time_GreaterThan(Time *a, Time *b) const;
Boolean time_LessThanOrEqual(Time *a, Time *b) const;
Boolean time_GreaterThanOrEqual(Time *a, Time *b) const;
int time_Difference(Time *a, Time *b) const;
*/

/* Manipulation functions  */
//Time time_Add(Time *a, int minutes);


#endif
