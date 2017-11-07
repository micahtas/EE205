/* File: datime.h */

#ifndef DATIME_H
#define DATIME_H

#include "util.h"
#include "day.h"
#include "time.h"

/*  DaTime data type declaration  */
typedef struct DaTime {
	Day day;
	time start;
	time end;
	int duration; 
} DaTime;

/* Initialization functions   */
void dt_Init(DaTime *d, Day day, time start, time end);
void dt_Clear(DaTime *d);
void dt_Copy(DaTime *dest, DaTime *source);

/* Accessor functions  */
Day dt_GetDay(DaTime *d);
time dt_GetStart(DaTime *d);
time dt_GetEnd(DaTime *d);
int dt_GetDuration(DaTime *d);

/* Mutator functions  */
void dt_SetDay(DaTime *d, Day day);
void dt_SetStart(DaTime *d, time start);
void dt_SetEnd(DaTime *d, time end);
void dt_SetDuration(DaTime *d, int mins);


/* Display functions  */
void dt_Display(DaTime *d);

/* Comparison functions  */
Boolean dt_Equal(DaTime *a, DaTime *b);
Boolean dt_NotEqual(DaTime *a, DaTime *b);
Boolean dt_LessThan(DaTime *a, DaTime *b);
Boolean dt_GreaterThan(DaTime *a, DaTime *b);
Boolean dt_LessThanOrEqual(DaTime *a, DaTime *b);
Boolean dt_GreaterThanOrEqual(DaTime *a, DaTime *b);
Boolean dt_Overlap(DaTime *a, DaTime *b);
Boolean dt_NonOverlap(DaTime *a, DaTime *b);

/* Manipulation functions  */
void dt_ChangeDay(DaTime *da, Day day);
void dt_ChangeDuration(DaTime *d, int dur);
void dt_ChangeStart(DaTime *d, time newstart);

DaTime dt_Merge(DaTime *a, DaTime *b);
int dt_Difference(DaTime *a, DaTime *b);


#endif
