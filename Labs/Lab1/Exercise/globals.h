
/*	File: globals.h
 *	 */

#ifndef GLOBALS_H
#define GLOBALS_H

#ifdef MAIN

int global_a;
static int global_b;

#else

extern int global_a;

#endif

#endif

