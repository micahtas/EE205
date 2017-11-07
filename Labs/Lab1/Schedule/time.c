/* File: time.c */

#include <stdio.h>
#include "time.h"
#include "util.h"

#define DEBUG

/* Initialization functions   */
void time_Init(time *t, int hour, int minute)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Init\n");
	#endif

	time_SetHour(t, hour);
	time_SetMinute(t, minute);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Init\n");
	#endif
}

void time_InitSingle(time *t, int hrmin)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_InitSingle\n");
	#endif

	time_SetHour(t, hrmin/100);
	time_SetMinute(t, hrmin%100);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_InitSingle\n");
	#endif
}

void time_Clear(time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Clear\n");
	#endif

	time_SetHour(t, 0);
	time_SetMinute(t, 0);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Clear\n");
	#endif
}

void time_Copy(time *dest, time *source)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Copy\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Copy\n");
	#endif
}

/* Accessor functions  */
int time_GetHour(time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetHour\n");
	#endif

	return t->hour;
}

int time_GetMinute(time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetMinute\n");
	#endif

	return t->minute;
}

/* Mutator functions */ 
void time_SetHour(time *t, int hour)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_SetHour\n");
	#endif

	t->hour = hour;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_SetHour\n");
	#endif
}

void time_SetMinute(time *t, int min)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_SetMinute\n");
	#endif

	t->minute = min;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_SetMinute\n");
	#endif
}

/* Display functions  */
void time_Display(time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Display\n");
	#endif

	printf("%02d:%02d", time_GetHour(t),time_GetMinute(t));

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Display\n");
	#endif
}

/* Comparison functions  */
Boolean time_Equal(time *a, time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Equal\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Equal\n");
	#endif
}

Boolean time_NotEqual(time *a, time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_NotEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_NotEqual\n");
	#endif
}

Boolean time_LessThan(time *a, time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThan\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThan\n");
	#endif
}

Boolean time_GreaterThan(time *a,time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThan\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThan\n");
	#endif
}

Boolean time_LessThanOrEqual(time *a, time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThanOrEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThanOrEqual\n");
	#endif
}

Boolean time_GreaterThanOrEqual(time *a, time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThanOrEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThanOrEqual\n");
	#endif
}

/* Manipulation functions  */
time time_Add(time *a, int minutes)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Add\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Add\n");
	#endif
}

int time_Difference(time *a, time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Difference\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Difference\n");
	#endif
}

