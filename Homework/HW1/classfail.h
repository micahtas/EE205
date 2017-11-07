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
#include "day.h"
#include "common.h"
using namespace std;

/* Defining default max size for array */
const int MAX = 10;


class Time {

        public:
        // Accessor Functions
        int time_GetHour(Time *t) const;
        int time_GetMinute(Time *t) const;
        // Comparison Functions
        Boolean time_Equal(Time *a, Time *b) const;
        Boolean time_NotEqual(Time *a, Time *b) const;
        Boolean time_LessThan(Time *a, Time *b) const;
        Boolean time_GreaterThan(Time *a, Time *b) const;
        Boolean time_LessThanOrEqual(Time *a, Time *b) const;
        Boolean time_GreaterThanOrEqual(Time *a, Time *b) const;
        int time_Difference(Time *a, Time *b) const;
        // Inititialization Functions
        void time_Init(Time *t, int hour, int minute);
        void time_InitSingle(Time *t, int hrmin);
        void time_Clear(Time *t);
        void time_Copy(Time *dest, Time *source);
        // Mutator Functions
        void time_SetHour(Time *t, int hour);
        void time_SetMinute(Time *t, int min);
        // Display Function
        void time_Display(Time *d) const;
        // Manipulation Functions
        Time time_Add(Time *a, int minutes);

        private:
        int hour;
        int minute;

	public:	
	class DaTime {
	        public:
	        Day day;        // ?
	        Time start;     // ?
	        Time end;       // ?

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

		public:
		class Course{
		        public:
		        /* Display Function */
		       	void c_Display(Course *d) const;
	        	/* Get Functions */
		        string c_GetLocation(Course *d) const;
		        string c_GetCourse(Course *d) const;
		        string c_GetTitle(Course *d) const;
		        string c_GetProf(Course *d) const;
		        int c_GetCredit(Course *d) const;
		        int c_GetCRN(Course *d) const;
		        int c_GetSection(Course *d) const;
		        string c_GetFocus(Course *d) const;
		        /* Initialization Functions */
		        void c_Init(Course *d, string location, string course, string title,
		        string prof, string focus, int credit, int CRN, int section);
	        	void c_Clear(Course *d);
		        void c_Copy(string *dest, string *source);
		        /* Set Functions */
		        void c_SetLocation(Course *d, string location);
		        void c_SetCourse(Course *d, string course);
		        void c_SetTitle(Course *d, string title);
		        void c_SetProf(Course *d, string prof);
		        void c_SetCredit(Course *d, int credit);
		        void c_SetCRN(Course *d, int CRN);
		        void c_SetSection(Course *d, int section);
		        void c_SetFocus(Course *d, string focus);

		        private:
		        string location;
		        string course;
		        string title;
		        string prof;
		        string focus;
		        int credit;
		        int CRN;
		        int section;

//			public:
//			class SoC{
//			        public:
//			        Course schedule[MAX];
//		
//				private:
//				int realMAX;           
//			};
		};


	};
};


