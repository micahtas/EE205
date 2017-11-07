//	File: appt.h
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 2/9/14

// Header file for appt

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "class.h"
using namespace std;

/* Defining default max size for array */
const int MAX = 20;

inline char getCommand();
// Header file includes the commands for making, deleting, canceling, changing 
// and displaying appointments.

inline char getCommand()
{
        char command;
        int valid;

        do
        {
                cout << "Enter command (M)ake an appointment" << endl
                        << "(F)ind an appointment"
                << endl << "(C)ancel an appointment previously found" << endl
                << "C(H)ange an appointment previously found" << endl
                        << "(D)isplay appointments"
                << endl << "Enter (q)uit por favor" << endl;

                command = getchar();

                while (getchar() != '\n') {}    // Gets rid of random characters
                switch(command){
                        case 'm':
                        case 'f':
                        case 'c':
                        case 'h':
                        case 'q':
                        case 'd': valid = 1;
                                  break;
                        default:  valid = 0;
                                  cout << "Your entry " << command << " is invalid!" <<  endl;
                }

        } while(valid == 0);

        return command;
}

class Appt{

	public:
	/* Initialization Functions */
	Appt() {}
	Appt(string location, string individual, DaTime whenwhere);
	void a_Clear();
	void a_Copy(Appt &dest, Appt &source);

	/* Get Functions */
	string a_GetIndividual() const;
	string a_GetLocation() const;
	DaTime a_GetWhenWhere() const;

	/* Set Functions */
	void a_SetIndividual(string a);	
	void a_SetLocation(string a);
	void a_SetWhenWhere(DaTime a);
	
	private:
	string individual = "z";
	string location = "z";
	Time t1 = {-1, -1};
	DaTime whenwhere = {'w', t1, t1};
	DaTime a = {whenwhere};
};

class SOM{
        public:
	// Display Functions
        void s_DisplayWeek() const;
        void s_DisplayDay() const;
	
	/* Accessor Functions */
	Appt s_FindAppt() const;

	/* Manipulator Functions */
        static void s_MakeAppt();
        void s_CancelAppt();
        void s_ChangeAppt(Appt a);
	static void s_InsertAppt(Appt a);

	/* Constructor */	
	SOM();

        private:
	/* Checking functions */
	static bool s_IsValidDay(const char day);
	static string s_RandomLocation();

	Time t1 = {-1, -1};
        DaTime whenwhere = {'z', t1, t1};
        DaTime a = {whenwhere};
	Appt b = {'\0', '\0', a};
	static Appt som[MAX];//={b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b};
	static int realMAX;// = 0;
};
