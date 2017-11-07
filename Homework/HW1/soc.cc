/*      file: soc.cc
 *      team: Team E
 *   	logins: shultzam
 *       	maychen
 *    		micahtas
 *      	sojacky
 * 	date: 2/4/2014
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "class.h"
//#include "soc.h"
using namespace std;

//#define DEBUG

/* Initialization functions   */
void Course::c_Init(Course *d, string location, string course, string title, 
	string prof, string focus, int credit, int CRN, int section)
{
        #ifdef DEBUG
        cerr << "\tEnter c_Init" << endl;
        #endif

	c_SetLocation(d, location);

	c_SetCourse(d, course);

	c_SetTitle(d, title);

	c_SetProf(d, prof);

	c_SetFocus(d, focus);

	c_SetCredit(d, credit);

	c_SetCRN(d, CRN);

	c_SetSection(d, section);

	#ifdef DEBUG 
        cerr << "\tExit c_Init" << endl;
        #endif
}

void Course::c_Clear(Course *d)
{
        #ifdef DEBUG
        cerr << "\tEnter c_Clear" << endl;
        #endif

        c_SetLocation(d, '\0');

        c_SetCourse(d, '\0');

        c_SetTitle(d, '\0');

        c_SetProf(d, '\0');

        c_SetCredit(d, -1);

        c_SetCRN(d, -1);

        c_SetSection(d, -1);

        c_SetFocus(d, '\0');

        #ifdef DEBUG
        cerr << "\tExit c_Clear" << endl;
        #endif
}


void Course::c_Copy(Course *dest, Course *source)
{
        #ifdef DEBUG
        cerr << "\tEnter c_Copy" << endl;
        #endif

	c_Init(dest,
		c_GetLocation(source),
		c_GetCourse(source),
		c_GetTitle(source),
		c_GetProf(source),
		c_GetCredit(source),
		c_GetCRN(source),
		c_GetSection(source),
		c_GetFocus(source));

        #ifdef DEBUG
        cerr << "\tExit c_Copy" << endl;
        #endif
}

/* Get Functions */
string Course::c_GetLocation(Course *d) const 
{

	#ifdef DEBUG
        cerr << "\tEnter c_GetLocation" << endl;
	#endif

	string location = "nowhere";
	location.assign(d->location);

	return d->location;

	#ifdef DEBUG
        cerr << "\tExit c_GetLocation" << endl;
	cout << location << endl;
        #endif
}

string Course::c_GetCourse(Course *d) const {
	
	#ifdef DEBUG
        cerr << "\tEnter c_GetCourse" << endl;
        #endif

	string course = "no course";
        course.assign(d->course);

        return d->course;

	#ifdef DEBUG
	cerr << "\tExit c_GetCourse" << endl;
	#endif
}

string Course::c_GetTitle(Course *d) const 
{

	#ifdef DEBUG
        cerr << "\tEnter c_GetTitle" << endl;
        #endif
	
        string title = "no title";
        title.assign(d->title);

        return d->title;

        #ifdef DEBUG
        cerr << "\tExit c_GetTitle" << endl;
        #endif
}

string Course::c_GetProf(Course *d) const {

	#ifdef DEBUG
        cerr << "\tEnter c_GetProf" << endl;
        #endif

        string prof = "no prof";
        prof.assign(d->prof);

        return d->prof;

        #ifdef DEBUG
        cerr << "\tExit c_GetProf" << endl;
        #endif

}

int Course::c_GetCredit(Course *d) const 
{
	
	#ifdef DEBUG
        cerr << "\tEnter c_GetCredit" << endl;
        #endif

        int credit = 0;
        credit.assign(d->credit);

        return d->credit;

        #ifdef DEBUG
        cerr << "\tExit c_GetCredit" << endl;
        #endif

}

int Course::c_GetCRN(Course *d) const {

	#ifdef DEBUG
        cerr << "\tEnter c_GetCRN" << endl;
        #endif

	int CRN = 12348;
        CRN.assign(d->CRN);

        return d->CRN;

        #ifdef DEBUG
        cerr << "\tExit c_GetCRN" << endl;
        #endif

}

int Course::c_GetSection(Course *d) const 
{
	
	#ifdef DEBUG
        cerr << "\tEnter c_GetSection" << endl;
        #endif
	
	int section = 0;
        section = d->section;

        return d->section;

        #ifdef DEBUG
        cerr << "\tExit c_GetSection" << endl;
        #endif

}

string Course::c_GetFocus(Course *d) const {

	#ifdef DEBUG
        cerr << "\tEnter c_GetFocus" << endl;
        #endif	
	
	string focus = "none";
        focus.assign(d->focus);

        return d->focus;
	
        #ifdef DEBUG
        cerr << "\tExit c_GetFocus" << endl;
        #endif

}

/* Set Functions */
void Course::c_SetLocation(Course *d, string location){

	#ifdef DEBUG
        cerr << "\tEnter c_SetLocation" << endl;
        #endif

	d->location = location;

        #ifdef DEBUG
        cerr << "\tExit c_SetLocation" << endl;
        #endif

}

void Course::c_SetCourse(Course *d, string course){

	#ifdef DEBUG
        cerr << "\tEnter c_SetCourse" << endl;
        #endif

	d->course = course;

        #ifdef DEBUG
        cerr << "\tExit c_SetCourse" << endl;
        #endif
}

void Course::c_SetTitle(Course *d, string title){

	#ifdef DEBUG
        cerr << "\tEnter c_SetTitle" << endl;
        #endif

	d->title = title;

        #ifdef DEBUG
        cerr << "\tExit c_SetTitle" << endl;
        #endif

}

void Course::c_SetProf(Course *d, string prof){

	#ifdef DEBUG
        cerr << "\tEnter c_SetProf" << endl;
        #endif

	d->prof = prof;

        #ifdef DEBUG
        cerr << "\tExit c_SetProf" << endl;
        #endif

}

void Course::c_SetCredit(Course *d, int credit){

	#ifdef DEBUG
        cerr << "\tEnter c_SetCredit" << endl;
        #endif

	d->credit = credit;

        #ifdef DEBUG
        cerr << "\tExit c_SetCredit" << endl;
        #endif

}

void Course::c_SetCRN(Course *d, int CRN){

	#ifdef DEBUG
        cerr << "\tEnter c_SetCRN" << endl;
        #endif

	d->CRN = CRN;

        #ifdef DEBUG
        cerr << "\tExit c_SetCRN" << endl;
        #endif
	
}

void Course::c_SetSection(Course *d, int section){

	#ifdef DEBUG
        cerr << "\tEnter c_SetSection" << endl;
        #endif

	d->section = section;

        #ifdef DEBUG
        cerr << "\tExit c_SetSection" << endl;
        #endif
}

void Course::c_SetFocus(Course *d, string focus){

	#ifdef DEBUG
        cerr << "\tEnter c_SetFocus" << endl;
        #endif

        d->focus = focus;

        #ifdef DEBUG
        cerr << "\tExit c_SetFocus" << endl;
        #endif

}

// Display Function
void Course::c_Display(Course *d) const {
	
	#ifdef DEBUG
        cerr << "\tEnter c_Display" << endl;
        #endif

	cout << "Location: " << c_GetLocation(d) << "\t";
	cout << "Course: " << c_GetCourse(d) << "\t";
	cout << "Course Title: " << c_GetTitle(d) << endl;
	cout << "Professor: " << c_GetProf(d) << "\t";
	cout << "Credits: " << c_GetCredit(d) << "\t";
	cout << "CRN: " << c_GetCRN(d) << "\t";
	cout << "Focus: " << c_GetFocus(d) << endl;

        #ifdef DEBUG
        cerr < "\tExit c_Display" << endl;
        #endif

}
