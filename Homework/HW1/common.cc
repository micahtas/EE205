
//	File: common.cc
//	team: Team E
//	login: shultzam
//		maychen
//		micahtas
//		sojacky
//	date: 2/9/14

//	Contains common utility functions

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "common.h"
using namespace std;


void Error(char *s)
/* Reports program error
 *    Pre:  s points to message to be printed
 *       Post: message printed and program terminated.
 *       */
{
	cerr << "Error: " << s << endl;
	exit(1);
}

void Warning(char *s)
/* Reports unusual program condition
 *    Pre:  s pionts to message to be printed
 *       Post: message printed and program resumed.
 *       */
{
	cerr << "Warning: " << s << endl;
}
