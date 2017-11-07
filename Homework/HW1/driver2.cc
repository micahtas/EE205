/* 	File: driver2.cc
 * 	team: Team E
 * 	login: shultzam
 * 	  	maychen
 * 	  	micahtas
 * 	  	sojacky
 * 	date: 2/9/2014
 */

/* Driver to implement appt */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "appt.h"
#include "common.h"
#include "class.h"
using namespace std;

int main()
{
//	int SOM::realMAX = 0;

	/* Creating random variables for use in our classes */
	string loc1 = "Office", loc2 = "Starbucks", loc3 = "Ala Moana Mall",
		loc4 = "Kapiolani Park";

	string p1 = "N D Tyson", p2 = "R Dawkins", p3 = "C Sagan";

	/* Creating instances of our classes */
	Time t1(8, 5), t2(8, 30), t3(8, 55), t4(9, 20), t5(9, 50), t6(10, 15),
		t7(10, 25), t8(10, 45), t9(11, 10);

	DaTime dt1('m', t1, t2), dt2('m', t3, t4), dt3('m', t6, t9); 
	
	Appt a1(loc1, p1, dt1), a2(loc1, p2, dt2), a3(loc3, p3, dt3); 

	static Appt som[MAX]={a1,a1,a1,a1,a1,a1,a1,a1,a1,
		a1,a1,a1,a1,a1,a1,a1,a1,a1,a1,a1};

 	char command;		// Command to transverse the menus	
	int display, day;

	do{
		command = getCommand();
		switch(command)
		{
			case 'm': 
				SOM::s_MakeAppt();
				break;
			case 'f':
				SOM::s_FindAppt();
				break;
			case 'c': 
				SOM::s_CancelAppt();
				break;
			case 'h': 
				SOM::s_ChangeAppt();
				break;
			case 'd': 
				cout << "Enter w to display the entire week."<<endl;
				cout << "Enter d to display a day." << endl;
				cin >> display;
				if(display == 'w') s_DisplayWeek();
				if(display == 'd'){
					cout<<"Enter day wanted, m for monday"<<endl;
					cin >> day;
					s_DisplayDay(day);
				}
				break;
			case 'q': cout << "Exiting Program" << endl;
				  exit;
		}
	} while(command != 'q');

}

