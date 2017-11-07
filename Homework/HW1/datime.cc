//	File: datime.cc
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 2/9/14

// Implementation of DaTime data type operations

#include <iostream>
#include <cstdio>
#include <cstdlib>
/* #include "datime.h" */
#include "class.h"
#include "common.h"
using namespace std;


//#define DEBUG

/* Initialization functions   */
DaTime::DaTime(Day day, Time start, Time end)
{
	#ifdef DEBUG
	cerr << "\tEnter construct" << endl;
	#endif

	dt_SetDay(day);
	dt_SetStart(start);
	dt_SetEnd(end);

	#ifdef DEBUG
	cerr << "\tExit construct" << endl;
	#endif
}

void DaTime::dt_Clear()
{	
	#ifdef DEBUG
	cerr << "\tEnter dt_Clear" << endl;
	#endif

	dt_SetDay('\0');
	start.time_Clear();
	end.time_Clear();

	#ifdef DEBUG
	cerr << "\tExit dt_Clear" << endl;
	#endif
}

void DaTime::dt_Copy(DaTime &dest, DaTime &source)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_Copy" << endl;
	#endif

	dest.day = source.dt_GetDay();
	dest.start = source.dt_GetStart();
	dest.end = source.dt_GetEnd();

	#ifdef DEBUG
	cerr << "\tExit dt_Copy" << endl;
	#endif
}


/* Accessor functions  */
Day DaTime::dt_GetDay() const
{
	#ifdef DEBUG
	cerr << "\tExecute dt_GetDay" << endl;
	#endif

	return day;
}

Time DaTime::dt_GetStart() const
{
	#ifdef DEBUG
	cerr << "\tExecute dt_GetStart" << endl;
	#endif
	
	//cout << "Start time of class: " << endhr << ":" << endmin << endl;
	return start;

}

Time DaTime::dt_GetEnd() const
{
	#ifdef DEBUG
	cerr << "\tExecute dt_GetEnd" << endl;
	#endif

	//cout << "End time of class: " << endhr << ":" << endmin << endl;	
	return end;
}

int DaTime::dt_GetDuration() const
{
	#ifdef DEBUG
	cerr << "\tExecute dt_GetDuration" << endl;
	#endif
	
	return duration;
}

/* Mutator functions  */
void DaTime::dt_SetDay(Day a)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_SetDay" << endl;
	#endif

	day = a;

	#ifdef DEBUG
	cerr << "\tExit dt_SetDay" << endl;
	#endif
}

void DaTime::dt_SetStart(Time a)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_SetStart" << endl;
	#endif

	start = a;

	#ifdef DEBUG
	cerr << "\tExit dt_SetStart" << endl;
	#endif
}

void DaTime::dt_SetEnd(Time a)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_SetEnd" << endl;
	#endif

	end = a;

	#ifdef DEBUG
	cerr << "\tExit dt_SetEnd" << endl;
	#endif
}

void DaTime::dt_SetDuration(int a)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_SetDuration" << endl;
	#endif

	duration = a;

	#ifdef DEBUG
	cerr << "\tExit dt_SetDuration" << endl;
	#endif
}



/* Display functions  */
void DaTime::dt_Display() const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_Display" << endl;
	#endif

	switch(dt_GetDay())
	{
	   case 'u':	cout << "Sunday ";
			break;
	   case 'm':	cout << "Monday ";
			break;
	   case 't':	cout << "Tuesday ";
			break;
	   case 'w':	cout << "Wednesday ";
			break;
	   case 'r':	cout << "Thursday ";
			break;
	   case 'f':	cout << "Friday ";
			break;
	   case 's':	cout << "Saturday ";
			break;
	   default:	cout << "Unknown day ";
	};

	start.time_Display();
	putchar('-');
	end.time_Display();
	putchar('\n');

	#ifdef DEBUG
	cerr << "\tExit dt_Display" << endl;
	#endif
}


/* Comparison functions  */
bool DaTime::dt_Equal(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_Equal" << endl;
	#endif

	if(a.dt_GetDay() == b.dt_GetDay()){	
		if(a.start.time_Equal(b.start)){
			if(a.end.time_Equal(b.end))
				return true;
		}
	}

	else
		return false; 


	#ifdef DEBUG
	cerr << "\tExit dt_Equal" << endl;
	#endif
}

bool DaTime::dt_NotEqual(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_NotEqual" << endl;
	#endif

	if(!dt_Equal(a,b))
		return true;

	else return false;

	#ifdef DEBUG
	cerr << "\tExit dt_NotEqual" << endl;
	#endif
}

bool DaTime::dt_LessThan(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_LessThan" << endl;
	#endif

	if(a.dt_GetDay() == b.dt_GetDay()){
		if(a.start.time_LessThan(b.start))
            		return true;
	}

	else	return false;

	#ifdef DEBUG
	cerr << "\tExit dt_LessThan" << endl;
	#endif
}

bool DaTime::dt_GreaterThan(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_GreaterThan" << endl;
	#endif

	if(!dt_LessThan(a, b))
		return true;

	else	return false;

	#ifdef DEBUG
	cerr << "\tExit dt_GreaterThan" << endl;
	#endif
}

bool DaTime::dt_LessThanOrEqual(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_LessThanOrEqual" << endl;
	#endif

	if(a.dt_GetDay() == b.dt_GetDay()){
                if(a.start.time_LessThanOrEqual(b.start)){
                        if(a.end.time_LessThanOrEqual(b.end))
                                return true;
                }
        }

        else    return false;

	#ifdef DEBUG
	cerr << "\tExit dt_LessThanOrEqual" << endl;
	#endif
}

bool DaTime::dt_GreaterThanOrEqual(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_GreaterThanOrEqual" << endl;
	#endif

	if(!dt_LessThanOrEqual(a, b))         
 		return true;
        
        else    return false;

	#ifdef DEBUG
	cerr << "\tExit dt_GreaterThanOrEqual" << endl;
	#endif
}

bool DaTime::dt_Overlap(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_Overlap" << endl;
	#endif
	
	if(a.dt_GetDay() == b.dt_GetDay()){
                if(a.start.time_LessThanOrEqual(b.start) && 
                a.end.time_GreaterThanOrEqual(b.start) ||
                a.start.time_GreaterThanOrEqual(b.start) &&
                a.start.time_LessThanOrEqual(b.end))
                        return true;
        }

        else
                return false;


	#ifdef DEBUG
	cerr << "\tExit dt_Overlap" << endl;
	#endif
}

bool DaTime::dt_NonOverlap(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_NonOverlap" << endl;
	#endif

	if (!dt_Overlap(a,b))
		return true;

	else return false;

	#ifdef DEBUG
	cerr << "\tExit dt_NonOverlap" << endl;
	#endif
}


/* Manipulation functions  */
void DaTime::dt_ChangeDay(DaTime &d, Day day)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_ChangeDay" << endl;
	#endif

	d.dt_SetDay(day);

	#ifdef DEBUG
	cerr << "\tExit dt_ChangeDay" << endl;
	#endif
}

void DaTime::dt_ChangeDuration(DaTime &d, int dur)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_ChangeDuration" << endl;
	#endif

	d.dt_SetDuration(dur);

	#ifdef DEBUG
	cerr << "\tExit dt_ChangeDuration" << endl;
	#endif
}

void DaTime::dt_ChangeStart(DaTime &d, Time newstart)
{
	#ifdef DEBUG
	cerr << "\tEnter dt_ChangeStart" << endl;
	#endif
	
	d.dt_SetStart(newstart);

	#ifdef DEBUG
	cerr << "\tExit dt_ChangeStart" << endl;
	#endif
}

/*
DaTime DaTime::dt_Merge(DaTime &a, DaTime &b)
{  	
	DaTime tempo;
	
	#ifdef DEBUG
	cerr << "\tEnter dt_Merge" << endl;
	#endif

	if(a.dt_GetDay() != b.dt_GetDay())
	{	cout << "Cannot merge across days; result cleared." << endl;
		dt_Clear();
		return temp;
	}

	tempo.dt_SetDay(a.dt_GetDay());
	tempo.dt_SetStart(b.dt_GetStart());
	tempo.dt_SetEnd(b.dt_GetEnd());

	#ifdef DEBUG
	cerr << "\tExit dt_Merge" << endl;
	#endif

	return tempo;
}
*/

/*
 * Gets duration in between classes
 */
int DaTime::dt_Difference(DaTime &a, DaTime &b) const
{
	#ifdef DEBUG
	cerr << "\tEnter dt_Difference" << endl;
	#endif

	int diff_hour = 0;	/* local variable to denote difference in time */
	int diff_min = 0;	/* loval variable to denote difference in time */
	int diff = 0;

	if(a.dt_GetDay() == b.dt_GetDay())
        {
                if(dt_Overlap(a,b) == 0)
                {
                        if(dt_LessThanOrEqual(a, b))
                        {
                                diff_hour = (b.start.time_GetHour() - a.end.time_GetHour())*60;
                                diff_min = abs(b.start.time_GetHour() - a.end.time_GetHour());
                                diff = diff_hour + diff_min;
                                return diff;
                        }
                        else if(dt_GreaterThanOrEqual(a, b))
                        {
                                diff_hour = (a.end.time_GetHour() - b.end.time_GetHour())*60;
                                diff_min = abs(a.end.time_GetHour() - b.end.time_GetHour());
                                diff = diff_hour + diff_min;
                                return diff;

                        }
                }
        }
        else	return 0;

	#ifdef DEBUG
	cerr << "\tExit dt_Difference" << endl;
	#endif
	
}
