//	file: soc.h
//	team: Team E
//	logins:	shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 1/28/2014
	


//	Defines the "Course" class and the "SoC" class. The "Course" 
//	class will contain "DaTime" and "SoC" will contain the "Course" class.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "datime.h"
#include "day.h"
#include "time.h"
using namespace std;

/* Defining default max size for array */
const int MAX = 10;

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
};

class SoC{
	public:
	Course schedule[MAX];
	int realMAX;
	
/*
	void printCourseList(Course d[MAX]);
	void addCourse(schedule d[MAX]);
	void removeCourse(schedule d[MAX]);
	void arrangeByCourse(schedule d[MAX]);
	void arrangeByDay(schedule d[MAX]);
	void arrangeByTime(schedule d[MAX]);

	If we implement these functions, the Course schedule[MAX]
	and int realMAX will become private. IF.
 */	
};

/* Intialization functions */
/*
void c_Init(Course *d, string location, string course, string title, 
	string prof, string focus, int credit, int CRN, int section);
void c_Clear(Course *d);
void c_Copy(string *dest, string *source);
*/

/* Display Function */
//void c_Display(Course *d) const;

/* Get Functions */
/*
string c_GetLocation(Course *d) const;
string c_GetCourse(Course *d) const;
string c_GetTitle(Course *d) const;
string c_GetProf(Course *d) const;
int c_GetCredit(Course *d) const;
int c_GetCRN(Course *d) const;
int c_GetSection(Course *d) const;
string c_GetFocus(Course *d) const;
*/

/* Set Functions */
/*
void c_SetLocation(Course *d, string location);
void c_SetCourse(Course *d, string course);
void c_SetTitle(Course *d, string title);
void c_SetProf(Course *d, string prof);
void c_SetCredit(Course *d, int credit);
void c_SetCRN(Course *d, int CRN);
void c_SetSection(Course *d, int section);
void c_SetFocus(Course *d, string focus);
*/

/*
void printCourseList(Course d[MAX]);
void addCourse(schedule d[MAX]);
void removeCourse(schedule d[MAX]);
void arrangeByCourse(schedule d[MAX]);
void arrangeByDay(schedule d[MAX]);
void arrangeByTime(schedule d[MAX]);
*/
