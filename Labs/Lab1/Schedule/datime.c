/* File: datime.c */

#include <stdio.h>
#include "datime.h"
#include "time.h"
#include "util.h"


/* Initialization functions   */
void dt_Init(DaTime *d, Day day, time start, time end)
{	
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Init\n");
	#endif

	dt_SetDay(d, day);
	dt_SetStart(d, start);
	dt_SetEnd(d, end);

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Init\n");
	#endif
}

void dt_Clear(DaTime *d)
{	
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Clear\n");
	#endif

	dt_SetDay(d, '\0');
	time_Clear(&(d->start));
	time_Clear(&(d->end));

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Clear\n");
	#endif
}

void dt_Copy(DaTime *dest, DaTime *source)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Copy\n");
	#endif

	dt_Init(dest,
		dt_GetDay(source),
		dt_GetStart(source),
		dt_GetEnd(source));

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Copy\n");
	#endif
}


/* Accessor functions  */
Day dt_GetDay(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetDay\n");
	#endif

	return d->day;
}

time dt_GetStart(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetStart\n");
	#endif

	return d->start;
}

time dt_GetEnd(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetEnd\n");
	#endif

	return d->end;
}

int dt_GetDuration(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetDuration\n");
	#endif
}


/* Mutator functions  */
void dt_SetDay(DaTime *d, Day day)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetDay\n");
	#endif

	d->day = day;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetDay\n");
	#endif
}

void dt_SetStart(DaTime *d, time start)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetStart\n");
	#endif

	d->start = start;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetStart\n");
	#endif
}

void dt_SetEnd(DaTime *d, time end)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetEnd\n");
	#endif

	d->end = end;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetEnd\n");
	#endif
}

void dt_SetDuration(DaTime *d, int mins)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetDuration\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetDuration\n");
	#endif
}



/* Display functions  */
void dt_Display(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Display\n");
	#endif

	switch(dt_GetDay(d))
	{
	   case 'm':	printf("Monday ");
			break;
	   case 't':	printf("Tuesday ");
			break;
	   case 'w':	printf("Wednesday ");
			break;
	   case 'r':	printf("Thursday ");
			break;
	   case 'f':	printf("Friday ");
			break;
	   default:	printf("Unknown day ");
	};
	time_Display(&d->start);
	putchar('-');
	time_Display(&d->end);
	putchar('\n');

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Display\n");
	#endif
}


/* Comparison functions  */
Boolean dt_Equal(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Equal\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Equal\n");
	#endif
}

Boolean dt_NotEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_NotEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_NotEqual\n");
	#endif
}

Boolean dt_LessThan(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_LessThan\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_LessThan\n");
	#endif
}

Boolean dt_GreaterThan(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_GreaterThan\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_GreaterThan\n");
	#endif
}

Boolean dt_LessThanOrEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_LessThanOrEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_LessThanOrEqual\n");
	#endif
}

Boolean dt_GreaterThanOrEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_GreaterThanOrEqual\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_GreaterThanOrEqual\n");
	#endif
}

Boolean dt_Overlap(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Overlap\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Overlap\n");
	#endif
}

Boolean dt_NonOverlap(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_NonOverlap\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_NonOverlap\n");
	#endif
}


/* Manipulation functions  */
void dt_ChangeDay(DaTime *d, Day day)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeDay\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeDay\n");
	#endif
}

void dt_ChangeDuration(DaTime *d, int dur)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeDuration\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeDuration\n");
	#endif
}

void dt_ChangeStart(DaTime *d, time newstart)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeStart\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeStart\n");
	#endif
}


DaTime dt_Merge(DaTime *a, DaTime *b)
{  DaTime temp;
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Merge\n");
	#endif

	if(dt_GetDay(a) != dt_GetDay(b))
	{	Warning("Cannot merge across days; result cleared");
		dt_Clear(&temp);
		return temp;
	}

	dt_SetDay(&temp, dt_GetDay(a));
	dt_SetStart(&temp, dt_GetStart(a));
	dt_SetEnd(&temp, dt_GetEnd(b));

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Merge\n");
	#endif

	return temp;
}

int dt_Difference(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Difference\n");
	#endif

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Difference\n");
	#endif
}


