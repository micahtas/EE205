//      File: class.h
//      team: Team E
//      login: shultzam
//              maychen
//              micahtas
//              sojacky
//      date: 2/9/14

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "day.h"
#include "common.h"
using namespace std;

#ifndef CLASS_H
#define CLASS_H

class Time {

        public:
        /* Accessor Functions */
        int time_GetHour() const;
        int time_GetMinute() const;
        /* Comparison Functions */
        bool time_Equal(const Time &other) const;
        bool time_NotEqual(const Time &other) const;
        bool time_LessThan(const Time &other) const;
        bool time_GreaterThan(const Time &other) const;
        bool time_LessThanOrEqual(const Time &other) const;
        bool time_GreaterThanOrEqual(const Time &other) const;
        /* Inititialization Functions */
	Time();
	Time(int hour, int minute);
        /*void time_InitSingle(int hrmin); */
        void time_Clear();
        void time_Copy(Time &dest, Time &source);
        /* Display Function */
        void time_Display() const;
        /* Manipulation Functions */
	int time_Difference(Time &a, Time &b) const;
	/* Mutator Functions */
        void time_SetHour(int hr);
        void time_SetMinute(int min);

        private:
        int hour;
        int minute;

};

/*  DaTime data type declaration  */
class DaTime {

        public:
       
        /* Accessor functions  */
        Day dt_GetDay() const;
        Time dt_GetStart() const;
        Time dt_GetEnd() const;
        int dt_GetDuration() const;
        /* Display functions  */
        void dt_Display() const;
        /* Comparison functions  */
        bool dt_Equal(DaTime &a, DaTime &b) const;
        bool dt_NotEqual(DaTime &a, DaTime &b) const;
        bool dt_LessThan(DaTime &a, DaTime &b) const;
        bool dt_GreaterThan(DaTime &a, DaTime &b) const;
        bool dt_LessThanOrEqual(DaTime &a, DaTime &b) const;
        bool dt_GreaterThanOrEqual(DaTime &a, DaTime &b) const;
        bool dt_Overlap(DaTime &a, DaTime &b) const;
        bool dt_NonOverlap(DaTime &a, DaTime &b) const;
        int dt_Difference(DaTime &a, DaTime &b) const;
        /* Initialization functions   */
	DaTime(Day day, Time start, Time end);
	/* Replaced by Contructor */
        void dt_Clear();
        void dt_Copy(DaTime &dest, DaTime &source);
        /* Manipulation Functions */
        void dt_ChangeDay(DaTime &d, Day day);
        void dt_ChangeDuration(DaTime &d, int dur);
        void dt_ChangeStart(DaTime &d, Time newstart);
/*	DaTime dt_Merge(DaTime &a, DaTime &b);
*/
	/* Mutator Functions */
        void dt_SetDay(Day day);
        void dt_SetStart(Time start);
        void dt_SetEnd(Time end);
        void dt_SetDuration(int mins);

	private:
        int duration;
	Day day = 'm';   
        Time start = {9, 30};
        Time end = {9, 30};  

};

#endif /* CLASS_H */
