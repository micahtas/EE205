
/* File: commmon.c
 * Date: 5 Sep 05
 * Rev:  
 *
 *  contains common utility functions
 */

#include "common.h"
#define DEBUGGER 1

void Error(const string s)
/* Reports program error
   Pre:  s pionts to message to be printed
   Post: message printed and program terminated.
*/
{
	fprintf(stderr, "Error: %s\n", s.c_str());
	exit(1);
}

void Warning(string s)
/* Reports unusual program condition
   Pre:  s pionts to message to be printed
   Post: message printed and program resumed.
*/
{
	fprintf(stderr, "Warning: %s\n", s.c_str());
}

void printString(string s)
{
    printf("%s\n", s.c_str());
}

void debug(string s)
{
#ifdef DEBUGGER
    printf("DEBUG: %s\n", s.c_str());
#endif
}
