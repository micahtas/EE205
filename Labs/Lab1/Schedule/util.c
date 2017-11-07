/* File: util.c */

#include "util.h"

void Error(char *s)
{
	printf(stderr, "Error: %s\n", s);
	exit(1);
}

void Warning(char *s)
{
	printf(stderr, "Warning: %s\n", s);
} 
