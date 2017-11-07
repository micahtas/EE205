//	File: time.cc
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 2/9/14

//	Implementation of Time data type operations

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "class.h"
//#include "time.h"
#include "common.h"
using namespace std;

/*
#define DEBUG
*/

/* Initialization functions   */
Time::Time(int hour, int minute){
	#ifdef DEBUG
	cerr << "\tExecuted Contructor" << endl;
	#endif

	time_SetHour(hour);
	time_SetMinute(minute);
}

/*
void Time::time_Init(int hour, int minute)
{
	#ifdef DEBUG
	cerr << "\tEnter time_Init" << endl;
	#endif

	t.hour = time_SetHour(t, hour);
	t.minute = time_SetMinute(t, minute);

	#ifdef DEBUG
	cerr << "\tExit time_Init" << endl;
	#endif
}
*/
/*
void Time::time_InitSingle(int hrmin)
{
	#ifdef DEBUG
	cerr << "\tEnter time_InitSingle" << endl;
	#endif

	hour = time_SetHour(hrmin/100);
	minute = time_SetMinute(hrmin%100);

	#ifdef DEBUG
	cerr << "\tExit time_InitSingle" << endl;
	#endif
}
*/
void Time::time_Clear()
{
	#ifdef DEBUG
	cerr << "\tEnter time_Clear" << endl;
	#endif

	time_SetHour(0);
	time_SetMinute(0);

	#ifdef DEBUG
	cerr << "\tExit time_Clear" << endl;
	#endif
}

void Time::time_Copy(Time &dest, Time &source)
{
	#ifdef DEBUG
	cerr << "\tEnter time_Copy" << endl;
	#endif

	/* Copy hour from source to destination */
	dest.hour = source.hour;
	/* Copy minutes from source to destination */
	dest.minute = source.minute;

	#ifdef DEBUG
	cerr << "\tExit time_Copy" << endl;
	#endif
}

/* Accessor functions  */
int Time::time_GetHour() const
{
	#ifdef DEBUG
	cerr << "\tExecute time_GetHour" << endl;
	#endif

	return hour;
}

int Time::time_GetMinute() const
{
	#ifdef DEBUG
	cerr << "\tExecute time_GetMinute" << endl;
	#endif

	return minute;
}

/* Mutator functions  */
void Time::time_SetHour(int hr)
{
	#ifdef DEBUG
	cerr << "\tEnter time_SetHour" << endl;
	#endif

	hour = hr;

	#ifdef DEBUG
	cerr << "\tExit time_SetHour" << endl;
	#endif
}

void Time::time_SetMinute(int min)
{
	#ifdef DEBUG
	cerr << "\tEnter time_SetMinute" << endl;
	#endif

	minute = min;

	#ifdef DEBUG
	cerr << "\tExit time_SetMinute" << endl;
	#endif
}

/* Display functions  */
void Time::time_Display() const
{
	#ifdef DEBUG
	cerr << "\tEnter time_Display" << endl;
	#endif

	cout << " " << time_GetHour() << ":" << time_GetMinute();

	#ifdef DEBUG
	cerr << "\tExit time_Display" << endl;
	#endif
}

/* Comparison functions  */
bool Time::time_Equal(const Time &other) const
{
	#ifdef DEBUG
	cerr << "\tEnter time_Equal" << endl;
	#endif

	/* If hour of Time "a" equals hour of Time "b" */
	if(this->hour == other.hour){
		if(this->hour == other.minute)
			return true;
	}
	
	else
		return false;

	#ifdef DEBUG
	cerr << "\tExit time_Equal" << endl;
	#endif
}

bool Time::time_NotEqual(const Time &other) const
{
	#ifdef DEBUG
	cerr << "\tEnter time_NotEqual" << endl;
	#endif

	if(!time_Equal(other))
		return true;
	else return false;

	#ifdef DEBUG
	cerr << "\tExit time_NotEqual" << endl;
	#endif
}

bool Time::time_LessThan(const Time &other) const
{
	#ifdef DEBUG
	cerr << "\tEnter time_LessThan" << endl;
	#endif

	if(this->hour < other.hour)
		return true;

      	else if(this->hour == other.hour){
          	if(this->minute < other.minute)
                  	return true;
                }
        else    return false;

	#ifdef DEBUG
	cerr << "\tExit time_LessThan" << endl;
	#endif
}

bool Time::time_GreaterThan(const Time &other) const
{
	#ifdef DEBUG
	cerr << "\tEnter time_GreaterThan" << endl;
	#endif

	if(this->hour > other.hour)
		return true;

	else if(this->hour == other.hour){
		if(this->minute > other.minute)
			return true;
	}

	else
		return false;

	#ifdef DEBUG
	cerr << "\tExit time_GreaterThan" << endl;
	#endif
}

bool Time::time_LessThanOrEqual(const Time &other) const
{
	#ifdef DEBUG
	cerr << "\tEnter time_LessThanOrEqual" << endl;
	#endif

        if(this->hour <= other.hour){
                if(this->minute <= other.minute)
                        return true;
                }
        else    return false;

	#ifdef DEBUG
	cerr << "\tExit time_LessThanOrEqual" << endl;
	#endif
}

bool Time::time_GreaterThanOrEqual(const Time &other) const
{
	#ifdef DEBUG
	cerr << "\tEnter time_GreaterThanOrEqual" << endl;
	#endif

	if(this->hour >= other.hour){
                if(this->minute >= other.minute)
                        return true;
                }
        else    return false;

	#ifdef DEBUG
	cerr << "\tExit time_GreaterThanOrEqual" << endl;
	#endif
}

/* Manipulation functions  */
int Time::time_Difference(Time &a, Time &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter time_Difference" << endl;
	#endif

	/* Declare variable */
	int minA;
	int minB;
	int diff;

	/* Convert to minutes */
	minA = a.hour * 60 + a.minute;
	minB = b.hour * 60 + b.minute;

	/* If Time "a" is greater than or equal to Time "b" */
	if(minA >= minB)
		diff = minA - minB;

	/* If Time "b" is greater than Time "a" */
	else if(minA < minB)
		diff = minB - minA;

	return diff;

	#ifdef DEBUG
	cerr << "\tExit time_Difference" << endl;
	#endif
}
