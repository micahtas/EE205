/* File: time.c
 *  login: 
 *   *  Date:  25 Aug 07
 *    *  Mod:
 *     */
/*  Implementation of Time data type operations
 *   */
#include <stdio.h>
#include "time.h"
#include "common.h"
/*
 * #define DEBUG
 * */
/* Initialization functions   */
void time_Init(Time *t, int hour, int minute)
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
void time_InitSingle(Time *t, int hrmin)
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
void time_Clear(Time *t)
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
void time_Copy(Time *dest, Time *source)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Copy\n");
	#endif
/* Copy hour from source to destination */
	dest->hour = source->hour;
/* Copy minutes from source to destination */
	dest->minute = source->minute;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Copy\n");
	#endif
}
/* Accessor functions  */
int time_GetHour(Time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetHour\n");
	#endif
	return t->hour;
}
int time_GetMinute(Time *t)
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetMinute\n");
	#endif
	return t->minute;
}
/* Mutator functions  */
void time_SetHour(Time *t, int hour)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_SetHour\n");
	#endif
	t->hour = hour;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_SetHour\n");
	#endif
}
void time_SetMinute(Time *t, int min)
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
void time_Display(Time *t)
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
Boolean time_Equal(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Equal\n");
	#endif
/* If hour of Time "a" equals hour of Time "b" */
	if(a->hour == b->hour)
	{
	/* If minutes of Time "a" is equal to minutes of Time "b" */
		if(a->minute == b->minute)
		/* Return true */
			return TRUE;
	/* If minutes of Time "a" is not equal to minutes of Time "b" */
		else
		/* Return false */
			return FALSE;
	}
/* If hour of Time "a" is not equal to hour of Time "b" */
	else
/* Return false */
	return FALSE;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Equal\n");
	#endif
}
Boolean time_NotEqual(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_NotEqual\n");
	#endif
/* If hour of Time "a" does not equal to hour of Time "b" */
	if(a->hour != b->hour)
/* Return true */
	return TRUE;
/* If hour of Time "a" equals hour of Time "b" */
	else
/* Return false */
	return FALSE;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_NotEqual\n");
	#endif
}
Boolean time_LessThan(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThan\n");
	#endif
/* If hour of Time "a" is less than hour of Time "b" */
	if(a->hour < b->hour)
/* Return true */
	return TRUE;
/* If hour of Time "a" equals hour of Time "b" */
	else if(a->hour == b->hour)
	{
	/* If minutes of Time "a" is less than minutes of Time "b" */
		if(a->minute < b->minute)
	/* Return true */
		return TRUE;
	/* Return false */
		else
		return FALSE;
	}	
/* If hour of Time "a" is greater than hour of Time "b", return false */
	else
	return FALSE;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThan\n");
	#endif
}
Boolean time_GreaterThan(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThan\n");
	#endif
/* If hour of Time "a" is greater than hour of Time "b" */
	if(a->hour > b->hour)
/* Return true */
	return TRUE;
/* If hour of Time "a" equals hour of Time "b" */
	else if(a->hour == b->hour)
	{
	/* If minutes of Time "a" is greater than minutes of Time "b" */
		if(a->minute > b->minute)
	/* Return true */
		return TRUE;
	/* Return false */
		else
		return FALSE;
	}
/* If hour of Time "a" is less than hour of Time "b", return false */
	else
	return FALSE;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThan\n");
	#endif
}
Boolean time_LessThanOrEqual(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThanOrEqual\n");
	#endif
/* If hour of Time "a" is less than or equal to hour of Time "b" */
	if(a->hour <= b->hour)
	{
	/* If minutes of Time "a" is less than or equal to minutes of Time "b"
 * */
		if(a->minute <= b->minute)
	/* Return true */
		return TRUE;
	/* Return false */
		else
		return FALSE;
	}
/* If hour of Time "a" is greater than hour of Time "b", return false */
	else
	return FALSE;	
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThanOrEqual\n");
	#endif
}
Boolean time_GreaterThanOrEqual(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThanOrEqual\n");
	#endif
/* If hour of Time "a" is greater than or equal to hour of Time "b" */
	if(a->hour >= b->hour)
	{
	/* If minute of Time A is greater than or equal to minute of Time "b"
 * */
		if(a->minute >= b->minute)
	/* Return true */
		return TRUE;
	/* Return false */
		else
		return FALSE;
	}
/* If hour of Time "a" is less than hour of Time "b", return false */
	else
	return FALSE;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThanOrEqual\n");
	#endif
}
/* Manipulation functions  */
Time time_Add(Time *a, int minutes)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Add\n");
	#endif
/* Declare variable */
	int minute;
	int hour;
	Time t;
/* Convert Time "a" into minutes */
	minute = a->hour * 60 + a->minute;
/* Add minutes to current time */
	minute = minute + minutes;
/* Convert back to hour and minutes */
	hour = minute/60;
	minute = minute%60;
/* Put data within structure Time t */
	t.hour = hour;
	t.minute = minute;
/* Return structure Time t */
	return t;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Add\n");
	#endif
}
int time_Difference(Time *a, Time *b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Difference\n");
	#endif
/* Declare variable */
	int minA;
	int minB;
	int diff;
/* Convert to minutes */
	minA = a->hour * 60 + a->minute;
	minB = b->hour * 60 + b->minute;
/* If Time "a" is greater than or equal to Time "b" */
	if(minA >= minB)
	/* Calculate difference */
		diff = minA - minB;
/* If Time "b" is greater than Time "a" */
	else if(minA < minB)
	/* Calculate difference */
		diff = minB - minA;
/* Return difference */
	return diff;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Difference\n");
	#endif
}

