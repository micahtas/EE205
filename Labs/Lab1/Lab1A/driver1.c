/* File: driver1.c
 * team: Team E
 * login: shultzam
 * 	  maychen
 * 	  micahtas
 * 	  sojacky
 * date: 2/4/2014
 */

/* Driver to implement soc */

#include <stdio.h>
#include <string>
#include "datime.h"
#include "soc.h"

int main()
{
	Course C1, C2, C3, C4, C5, C6, C7;

	// Professors
	string p1 = "T Dobry", p2 = "N Gaarder", p3 = "G Sasaki";
	// Locations
	string r1 = "Kuy 306", r2 = "PSB 101A", r3 = "Holmes 241";
	// Courses
	string c1 = "EE211", c2 = "EE367", c3 = "Sophomore Project";
	// Titles
	string t1 = "Basic Analysis I", t2 = "Data Structures and Algorithms";
	// Credits
	int g1 = 1, g2 = 3, g3 = 4;
	// CRNs
	int CRN1 = 67890, CRN2 = 56658, CRN3 = 67800;
	// Sections
	int s1 = 1, s2 = 2, s3 = 3;
	// Focuses
	string f1 = "NI", f2 = "DP", f3 = "WI";
	
	
	c_Init(&C1, "POST214", "EE205", "Object Oriented Programming", "R Zhang",
		"NI", 3, 86055, 1);
	c_Init(&C2, "POST126", "EE315", "Signal and System Analysis", 
		"A Host-Madsen", "\0", 3, 82686, 1);
	c_Init(&C3, "KUY209", "EE342", "EE Probability & Statistics", "J Yee",
                "\0", 3, 84401, 1);
	c_Init(&C4, "PHYSCI217", "EE323", "Microelctronic Circuits", "W Massagram",
                "DP", 3, 80783, 1);
	c_Init(&C5, "HOLM358", "EE323L", "Microelectronics Circuits Lab", 
		"W Massagram", "DY", 1, 84289, 2);

	printf("Printing course #1.\n");
	c_Display(&C1);	
	printf("Printing course #2.\n");
        c_Display(&C2);
	printf("Printing course #3.\n");
        c_Display(&C3);
	printf("Printing course #4.\n");
        c_Display(&C4);
	printf("Printing course #5.\n");
        c_Display(&C5);

	c_SetLocation(&C5, r3);
	c_SetCourse(&C5, c1);
	c_SetTitle(&C5, t1);
	c_SetProf(&C5, p2);
	c_SetCredit(&C5, g2);
	c_SetCRN(&C5, CRN1);
	c_SetSection(&C5, s1);
	c_SetFocus(&C5, f3);
	printf("Printing NEW course #5.\n");
	c_Display(&C5);

	c_Init(&C6, r3, c2, t2, p3, f1, g3, CRN3, s1);
	printf("Printing course #6.\n");
	c_Display(&C6);

//	c_GetLocation(&C6);
//	c_GetCourse(&C6);
//	c_GetTitle(&C6);
//	c_GetProf(&C6);
	c_GetCredit(&C6);
	c_GetCRN(&C6);
	c_GetSection(&C6);
//	c_GetFocus(&C6);

}
