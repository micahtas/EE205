/*      file: soc.c
 *      team: Team E
 *   	logins: shultzam
 *       	maychen
 *    		micahtas
 *      	sojacky
 * 	date: 2/4/2014
 */

#include <stdio.h>
#include <string>
#include "soc.h"

//#define DEBUG

/* Initialization functions   */
void c_Init(Course *d, string location, string course, string title, 
	string prof, string focus, int credit, int CRN, int section)
{
        #ifdef DEBUG
        fprintf(stderr,"\tEnter c_Init\n");
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
        fprintf(stderr, "\tExit c_Init\n");
        #endif
}

void c_Clear(Course *d)
{
        #ifdef DEBUG
        fprintf(stderr,"\tEnter c_Clear\n");
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
        fprintf(stderr, "\tExit c_Clear\n");
        #endif
}

/*
void c_Copy(Course *dest, Course *source)
{
        #ifdef DEBUG
        fprintf(stderr,"\tEnter c_Copy\n");
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
        fprintf(stderr, "\tExit c_Copy\n");
        #endif
}
*/

/* Get Functions */
string c_GetLocation(Course *d){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetLocation\n");
        #endif

	string location = "nowhere";
	location = d->location;

	//printf("Location: %s.\n", d->location);

	#ifdef DEBUG
        fprintf(stderr,"\tExit c_GetLocation\n");
        #endif
}

string c_GetCourse(Course *d){
	
	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetCourse\n");
        #endif

	string course = "no course";
	course = d->course;

	//return d->course;

	#ifdef DEBUG
	fprintf(stderr,"\tExit c_GetCourse\n");
	#endif
}

string c_GetTitle(Course *d){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetTitle\n");
        #endif
	
	string title = "no title";
	title = d->title;

	//return d->title;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_GetTitle\n");
        #endif
}

string c_GetProf(Course *d){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetProf\n");
        #endif

	string prof = "no prof";
	prof = d->prof;

	//return d->prof;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_GetProf\n");
        #endif

}

int c_GetCredit(Course *d){
	
	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetCredit\n");
        #endif

	int credit = 0;
	credit = d->credit;

	//return d->credit;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_GetCredit\n");
        #endif

}

int c_GetCRN(Course *d){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetCRN\n");
        #endif

	int CRN = 12348;
	CRN = d->CRN;

	//return d->CRN;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_GetCRN\n");
        #endif

}

int c_GetSection(Course *d){
	
	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetSection\n");
        #endif
	
	int section = 0;
	section = d->section;

	//return d->section;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_GetSection\n");
        #endif

}

string c_GetFocus(Course *d){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_GetFocus\n");
        #endif

	string focus = "none";
	focus = d->focus;

	//return d->focus;
	
        #ifdef DEBUG
        fprintf(stderr,"\tExit c_GetFocus\n");
        #endif

}

/* Set Functions */
void c_SetLocation(Course *d, string location){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetLocation\n");
        #endif

	d->location = location;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetLocation\n");
        #endif

}

void c_SetCourse(Course *d, string course){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetCourse\n");
        #endif

	d->course = course;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetCourse\n");
        #endif
}

void c_SetTitle(Course *d, string title){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetTitle\n");
        #endif

	d->title = title;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetTitle\n");
        #endif

}

void c_SetProf(Course *d, string prof){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetProf\n");
        #endif

	d->prof = prof;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetProf\n");
        #endif

}

void c_SetCredit(Course *d, int credit){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetCredit\n");
        #endif

	d->credit = credit;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetCredit\n");
        #endif

}

void c_SetCRN(Course *d, int CRN){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetCRN\n");
        #endif

	d->CRN = CRN;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetCRN\n");
        #endif
	
}

void c_SetSection(Course *d, int section){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetSection\n");
        #endif

	d->section = section;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetSection\n");
        #endif
}

void c_SetFocus(Course *d, string focus){

	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_SetFocus\n");
        #endif

        d->focus = focus;

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_SetFocus\n");
        #endif

}

// Display Function
void c_Display(Course *d){
	
	#ifdef DEBUG
        fprintf(stderr,"\tEnter c_Display\n");
        #endif

//	printf("Location: %s.\t", c_GetLocation(d));
//	printf("Course name: %s.\t", c_GetCourse(d));
//	printf("Course title: %s.\n", c_GetTitle(d));
//	printf("Professor: %s.\t", c_GetProf(d));
	printf("Credits: %d.\t", c_GetCredit(d));
	printf("CRN: %d.\t", c_GetCRN(d));
	printf("Section: %d.\n", c_GetSection(d));
//	printf("Focus:%s.\n", c_GetFocus(d));

        #ifdef DEBUG
        fprintf(stderr,"\tExit c_Display\n");
        #endif

}
