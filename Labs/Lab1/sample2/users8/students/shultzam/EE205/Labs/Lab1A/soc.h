/*
 * 	file: soc.h
 *	team: Team E
 *	logins:	shultzam
 *		maychen
 *		micahtas
 *		sojacky
 *	date: 1/28/2014
 */		

/*
 *	Defines the "Course" struct and the "SoC" struct. The "Course" struct will contain "DaTime"
 *	and "SoC" will contain the "Course" struct.
 */

#include <stdio.h>
#define MAX = 10;

typedef struct Course{
	DaTime datime;
	char location;
        char course;
        char title;
        char prof;
	char focus[3];
	int credit;
        int CRN;
        int section;
}

typedef struct SoC{
	Course schedule[MAX];
	int realMAX;
}SoC;

/* Get Functions */
Course c_GetLocation(Course *d);

Course c_GetCourse(Course *d);

Course c_GetTitle(Course *d);

Course c_GetProf(Course *d);

Course c_GetCredit(Course *d);

Course c_GetCRN(Course *d);

Course c_GetSection(Course *d);

Course c_GetFocus(Course *d);

/* Set Functions */
void c_SetLocation(Course *d);

void c_SetCourse(Course *d);

void c_SetTitle(Course *d);

void c_SetProf(Course *d);

void c_SetCredit(Course *d);

void c_SetCRN(Course *d);

void c_SetSection(Course *d);

void c_SetFocus(Course *d);

/* Array Functions 
void printCourseList(Course d[MAX]);

void addCourse(schedule d[MAX]);

void removeCourse(schedule d[MAX]);

void arrangeByCourse(schedule d[MAX]);

void arrangeByDay(schedule d[MAX]);

void arrangeByTime(schedule d[MAX]); */
