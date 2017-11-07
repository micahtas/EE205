//	File: appt.cc
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 2/9/14

// Implementation file for Appt and SoM

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "appt.h"
#include "class.h"
using namespace std;

//#define DEBUG


/* Attempt to initialize array? */
Time t1(-1, -1);
DaTime a('z', t1, t1);
Appt b("w", "w", a);
int SOM::realMAX = 0;
Appt SOM::som[MAX]={b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b};

/* Initialization Functions */
Appt::Appt(string location, string individual, DaTime whenwhere)
{
	a_SetLocation(location);
	a_SetIndividual(individual);
	DaTime a(whenwhere);	
}
	
void Appt::a_Clear()
{
	#ifdef DEBUG
	cerr << "\tEnter a_Clear" << endl;
	#endif

	/* Local class object */
	Time t1(-1, -1);
	DaTime a('\0', t1, t1);

	a_SetIndividual('\0');
	a_SetLocation('\0');
	a_SetWhenWhere(a);
	

	#ifdef DEBUG
	cerr << "\tExit a_Clear" << endl;
	#endif
}

void Appt::a_Copy(Appt &dest, Appt &source)
{

	#ifdef DEBUG
	cerr << "\tEnter a_Copy" << endl;
	#endif

	dest.location = source.a_GetLocation();
	dest.individual = source.a_GetIndividual();
	dest.whenwhere = source.a_GetWhenWhere();

	#ifdef DEBUG
	cerr << "\tExit a_Copy" << endl;
	#endif
}

/* Get Functions */
string Appt::a_GetIndividual() const
{

	#ifdef DEBUG
	cerr << "\tExecute a_GetIndividual" << endl;
	#endif
	
	return individual;
}

string Appt::a_GetLocation() const
{
	#ifdef DEBUG
	cerr << "\tExecute a_GetLocation" << endl;
	#endif
	
	return location;
}

DaTime Appt::a_GetWhenWhere() const
{
	#ifdef DEBUG
	cerr << "\tExecute a_GetWhenWhere" << endl;
	#endif

	return whenwhere;
}

/* Set Functions */
void Appt::a_SetIndividual(string a)
{
	#ifdef DEBUG
	cerr << "\tEnter a_SetIndividual" << endl;
	#endif
	
	individual = a;

	#ifdef DEBUG
	cerr << "\tExit a_SetIndividual" << endl;
	#endif
}

void Appt::a_SetLocation(string a){
	
	#ifdef DEBUG
	cerr << "\tExecute a_SetLocation" << endl;
	#endif

	location = a;
}

void Appt::a_SetWhenWhere(DaTime a){
	#ifdef DEBUG
	cerr << "\tExecute a_SetWhenWhere" << endl;
	#endif

	whenwhere = a;
}


/*
 *	Begin SOM Functions
 */

/* Constructor */
SOM::SOM(){
	Time t1(-1, -1);
        DaTime whenwhere('z', t1, t1);
        DaTime a(whenwhere);
        Appt b('\0', '\0', a);
	Appt som[MAX] = b;
}

Appt SOM::s_FindAppt() const
{
        #ifdef DEBUG
        cerr << "\tEnter a_FindAppt" << endl;
        #endif



        for(int i = 0; i < realMAX; i++){
                if(a.a_GetIndividual() == som[i].a_GetIndividual()) &&
                if(dt_Equal(dt1, som[i].datime)){
                        return a;
                }
        }

        #ifdef DEBUG
        cerr << "\tExit a_FindAppt" << endl;
        #endif
}

/* Manipulator Functions */
void SOM::s_MakeAppt(){
	#ifdef DEBUG
	cerr << "\tEnter s_MakeAppt" << endl;
	#endif

	/* Local to store data */
	Day day1 = 'z';
	int hour, minute, hour2, minute2 = 0;
	string p1;
	Time t1(-1, -1);
	Time t2(-1, -1);
	DaTime dt1('w', t2, t2);
	Appt a("w", "w", dt1);

	cout << "\nPlease enter day of your desired appointment: " << endl;
	day1 = getchar();
	while(getchar() != '\n'){}	/* Rids of random excess characters */
	if (s_IsValidDay(day1)){
		dt1.dt_SetDay(day1);
	}
	else { 
		cout << "Invalid day!" << endl;
		a.a_Clear();
		return;
	}

	cout << "Thank you." << endl;
	cout << "Please enter the start time in the following format: " << endl;
	cout << "Ex: 1130am = 11 30. Ex: 225pm = 14 25." << endl;
	cin >> hour >> minute;
	if(hour < 24 && hour >= 0){
		if(minute >= 0 && minute < 60){
			t1.time_SetHour(hour); 
        		t1.time_SetMinute(minute);	
		}
	}
	else {
		cout << "Invalid time!" << endl;
		a.a_Clear();
		return;
	}

	cout << "\nThank you." << endl;
	cout << "Please enter the end time in the following format: " << endl;
	cout << "Ex: 1130am = 11 30. Ex: 225pm = 14 25." << endl;
 	cin >> hour2 >> minute2;

	/* Time validity checks */
	if(hour > hour2){
		cout << "Invalid time!" << endl; 
		a.a_Clear();
		return;
	}
	if(hour2 <= hour && minute2 <= minute){
		cout << "Invalid time!" << endl;
 		a.a_Clear();
		return;
	}
	
	if(hour2 < 24 && hour2 >= 0){
  		if(minute2 >= 0 && minute2 < 60){
			t2.time_SetHour(hour2);
			t2.time_SetMinute(minute2);
		}
	}
	
	else{
		cout << "Invalid time!" << endl;
		a.a_Clear();
		return;
	}
	
	/* Populate datime instance */
	dt1.dt_SetStart(t1);
	dt1.dt_SetEnd(t2);

	/* Prompt for individuals name */
	cout << "\nThank you." << endl;
	cout << "Please enter the name of the individual attending the meeting: " << endl;
	cout << "No spaces please!" << endl; 
	cin >> p1;
	
	/* Set meeting */
	a.a_SetIndividual(p1);
	a.a_SetWhenWhere(dt1);
	a.a_SetLocation(s_RandomLocation());

	cout << "\nThe person you are meeting is deciding upon a location.... " << endl;
	cout << "\nCongratulations " << p1 << ", your meeting is set at " 
	<< a.a_GetLocation() << "." << endl;
	cout << "Your meeting is from " << hour << ":" << minute <<" until " << 
		hour2 << ":" << minute << "." << endl;

	/* Insert Appt into array */
	s_InsertAppt(a);

	#ifdef DEBUG
	cerr << "\tExit s_MakeAppt" << endl;
	#endif
}

void SOM::s_CancelAppt(){

	#ifdef DEBUG
 	cerr << "\tEnter s_CancelakeAppt" << endl;
 	#endif

        /* Local to store data */
        Day day1 = 'z';
        int hour, minute, hour2, minute2 = 0;
        string p1;
        Time t1(-1, -1);
        Time t2(-1, -1);
        DaTime dt1('w', t2, t2);
        Appt a("w", "w", dt1);

        cout << "\nPlease enter day of your desired appointment: " << endl;
        day1 = getchar();
        while(getchar() != '\n'){}      /* Rids of random excess characters */
        if (s_IsValidDay(day1)){
                dt1.dt_SetDay(day1);
        }
        else {
                cout << "Invalid day!" << endl;
                a.a_Clear();
                return;
        }

        cout << "Thank you." << endl;
        cout << "Please enter the start time in the following format: " << endl;
        cout << "Ex: 1130am = 11 30. Ex: 225pm = 14 25." << endl;
        cin >> hour >> minute;
        if(hour < 24 && hour >= 0){
                if(minute >= 0 && minute < 60){
                        t1.time_SetHour(hour);
                        t1.time_SetMinute(minute);
                }
        }
        else {
                cout << "Invalid time!" << endl;
                a.a_Clear();
		return;
	}

        cout << "\nThank you." << endl;
        cout << "Please enter the end time in the following format: " << endl;
        cout << "Ex: 1130am = 11 30. Ex: 225pm = 14 25." << endl;
        cin >> hour2 >> minute2;

        /* Time validity checks */
        if(hour > hour2){
                cout << "Invalid time!" << endl;
                a.a_Clear();
                return;
        }
        if(hour2 <= hour && minute2 <= minute){
                cout << "Invalid time!" << endl;
                a.a_Clear();
                return;
        }

        if(hour2 < 24 && hour2 >= 0){
                if(minute2 >= 0 && minute2 < 60){
                        t2.time_SetHour(hour2);
                        t2.time_SetMinute(minute2);
                }
        }

        else{
                cout << "Invalid time!" << endl;
                a.a_Clear();
                return;
        }

        /* Prompt for individuals name */
        cout << "\nThank you." << endl;
        cout << "Please enter the name of the individual the meeting is for: " << endl;
        cout << "No spaces please!" << endl;
        cin >> p1;

        /* Set meeting */
        a.a_SetIndividual(p1);
        a.a_SetWhenWhere(dt1);
        a.a_SetLocation(s_RandomLocation());

	if(s_FindAppt(a)){
		som[i].location = '\0';
		som[i].individual = '\0';
		som[i].dt_Clear();
	}
		


 	#ifdef DEBUG
  	cerr << "\tExit s_MakeAppt" << endl;
	#endif
}

void SOM::s_ChangeAppt(Appt a){
	#ifdef DEBUG
	cerr << "\tEnter s_ChangeAppt" << endl;
	#endif

        /* Local to store data */
        Day day1 = 'z';
        int hour, minute, hour2, minute2 = 0;
        string p1;
        Time t1(-1, -1);
        Time t2(-1, -1);
        DaTime dt1('w', t2, t2);
        Appt a("w", "w", dt1);

        cout << "\nPlease enter day of your desired appointment: " << endl;
        day1 = getchar();
        while(getchar() != '\n'){}      /* Rids of random excess characters */
        if (s_IsValidDay(day1)){
                dt1.dt_SetDay(day1);
        }
        else {
                cout << "Invalid day!" << endl;
                a.a_Clear();
                return;
        }

        cout << "Thank you." << endl;
        cout << "Please enter the start time in the following format: " << endl;
        cout << "Ex: 1130am = 11 30. Ex: 225pm = 14 25." << endl;
        cin >> hour >> minute;
        if(hour < 24 && hour >= 0){
                if(minute >= 0 && minute < 60){
                        t1.time_SetHour(hour);
                        t1.time_SetMinute(minute);
                }
        }
        else {
                cout << "Invalid time!" << endl;
                a.a_Clear();
		return;
	}

        cout << "\nThank you." << endl;
        cout << "Please enter the end time in the following format: " << endl;
        cout << "Ex: 1130am = 11 30. Ex: 225pm = 14 25." << endl;
        cin >> hour2 >> minute2;

        /* Time validity checks */
        if(hour > hour2){
                cout << "Invalid time!" << endl;
                a.a_Clear();
                return;
        }
        if(hour2 <= hour && minute2 <= minute){
                cout << "Invalid time!" << endl;
                a.a_Clear();
                return;
        }

        if(hour2 < 24 && hour2 >= 0){
                if(minute2 >= 0 && minute2 < 60){
                        t2.time_SetHour(hour2);
                        t2.time_SetMinute(minute2);
                }
        }

        else{
                cout << "Invalid time!" << endl;
                a.a_Clear();
                return;
        }

        /* Prompt for individuals name */
        cout << "\nThank you." << endl;
        cout << "Please enter the name of the individual the meeting is for: " << endl;
        cout << "No spaces please!" << endl;
        cin >> p1;

        /* Set meeting */
        a.a_SetIndividual(p1);
        a.a_SetWhenWhere(dt1);
        a.a_SetLocation(s_RandomLocation());

	/* Traverse array to search for appt */
	if(s_FindAppt(a))
		a_Copy(som[i], a);		
	else{
		cout << "Appt not found!" << endl;
		return;
	}

	#ifdef DEBUG
	cerr << "\tExit s_ChangeAppt" << endl;
	#endif
}

void SOM::s_InsertAppt(Appt a){
	#ifdef DEBUG
	cerr << "\tEnter s_InsertApp" << endl;
	#endif

		som[realMAX + 1] = a;
		realMAX++;

	#ifdef DEBUG
	cerr << "\tExit s_InsertApp" << endl;
	#endif;
}

bool SOM::s_IsValidDay(const char day)
{
	/* checking if day is a valid entry */
	int valid = 0;

	switch(day)
	{
		case 'u':
		case 'm':
		case 't':
		case 'w':
		case 'r':
		case 'f':
		case 's': valid = 1;
			  break;
		default:  valid = 0;
	}
	
	return valid;
}

string SOM::s_RandomLocation()
{
	int i = rand() % 4 + 1;
	switch (i){
		case 1: 
			return "office";
			break;
		case 2:
			return "Starbucks";
			break;
		case 3:
			return "Ala Moana Mall";
			break;
		case 4: 
			return "Kapiolani Park";
			break;
		default: return "office"; 
	}
}

/* SoM member functions */
void SOM::s_DisplayDay() const
{
        #ifdef DEBUG
        cerr << "\tEnter s_DisplayWeek" << endl;
        #endif

	char day = 'z';

	cout << "Please enter day of the week to display: " << endl;
	cin >> z;
	
	for (int i = 0; i < realMAX; i++){
		if(som[i].whenwhere.dt_GetDay() == z){
			cout << "Individual: " << som[i].a_GetIndividual() << endl;
			cout << "Location: " << som[i].a_GetLocation() << endl;
			cout << "From: " << som[i].whenwhere.dt_GetStart()
			<< "to" << som[i].whenwhere.dt_GetEnd() << endl;
		}
	}

        #ifdef DEBUG
        cerr << "\tExit s_DisplayWeek" << endl;
        #endif

}

void SOM::s_DisplayWeek() const
{       
        #ifdef DEBUG
        cerr << "\tEnter s_DisplayDay" << endl;
        #endif

	for (int i = 0; i < realMAX; i++){
               	cout << "Individual: " << som[i].a_GetIndividual() << endl;
                cout << "Location: " << som[i].a_GetLocation() << endl;
                cout << "From: " << som[i].whenwhere.dt_GetStart()
                << "to" << som[i].whenwhere.dt_GetEnd() << endl;
        }

        #ifdef DEBUG
        cerr << "\tExit s_DisplayDay" << endl;
        #endif
}

