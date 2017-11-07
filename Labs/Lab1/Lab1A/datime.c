/*
 * 	File:  datime.c
 * 	Name:
 *  	login: 
 *  	Date:  25 Aug 07
 * 	Mod:
 */

/*  Implementation of DaTime data type operations
 *   
 */


#include <stdio.h>
#include "datime.h"
#include "time.h"
#include "common.h"

/*
 * #define DEBUG
 */

/* Initialization functions   */
void dt_Init(DaTime *d, Day day, Time start, Time end)
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

	char day = 'z';		/* local variable to store day */

	day = d->day;
}

Time dt_GetStart(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetStart\n");
	#endif

	/* local variable to store start */
	int starthr = 0;
	int startmin = 0;	

	starthr =  time_GetHour(&(d->start));
	startmin = time_GetMinute(&(d->start));
	printf("Start time of class: %d:%d.\n", starthr, startmin);
	
	return d->start;
}

Time dt_GetEnd(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetEnd\n");
	#endif

	/* local variable to store store end */
	int endhr = 0;
	int endmin = 0;

	endhr = time_GetHour(&(d->end));
	endmin = time_GetMinute(&(d->end));
	
	printf("End time of class: %d:%d.\n", endhr, endmin);
	
	return d->end;
}

int dt_GetDuration(DaTime *d)
{
	#ifdef DEBUG
	fprintf(stderr,"\tExecute dt_GetDuration\n");
	#endif

	int hours = 0;  	/* local variable to denote difference in time */
        int mins = 0;       	/* local variable to denote difference in time */
	int duration = 0;	/* local variable to store duration */        

	hours = time_GetHour(&(d->end)) - time_GetHour(&(d->start));
        mins = time_GetMinute(&(d->end)) - time_GetMinute(&(d->start));

	duration = (hours * 60) + mins;
	if(duration < 60)
		printf("Duration of class: %d minutes.\n", duration);
	else if(duration > 60)
		printf("Duration of class: %d:%d.\n", hours, mins);
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

void dt_SetStart(DaTime *d, Time start)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_SetStart\n");
	#endif

	d->start = start;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_SetStart\n");
	#endif
}

void dt_SetEnd(DaTime *d, Time end)
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

	d->duration = mins;

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
	   case 'u':	printf("Sunday ");
			break;
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
	   case 's':	printf("Saturday ");
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
	
	/*if((a->start.hour == b->start.hour) && (a->end.hour == b->end.hour)){
		if((a->start.minute == b->start.minute) && 
		(a->end.minute == b->end.minute))	
			return TRUE;
	}*/

	if(time_Equal(&(a->start), (&(b->start)))){
		if(time_Equal(&(b->end), (&(a->end))))
			return TRUE;
	}
	else
		return FALSE; 


	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Equal\n");
	#endif
}

Boolean dt_NotEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_NotEqual\n");
	#endif

	/* Comparing Hours and minutes of both events */
	if(time_NotEqual(&(a->start), (&(b->start)))){
                if(time_NotEqual(&(b->end), (&(a->end))))
                        return TRUE;
	}

	/*if((a->start.hour != b->start.hour) && (a->end.hour != b->end.hour)){
		if((a->start.minute != b->start.minute) && 
		(a->end.minute != b->end.minute)){
			return TRUE;
		}
	}*/

        else
                return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_NotEqual\n");
	#endif
}

Boolean dt_LessThan(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_LessThan\n");
	#endif

	if(a->day == b->day){
		if(time_LessThan(&(a->start), (&(b->start)))){
                	if(time_LessThan(&(a->start), (&(b->start))))
                        	return TRUE;
        	}
	}
	else	return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_LessThan\n");
	#endif
}

Boolean dt_GreaterThan(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_GreaterThan\n");
	#endif

        if(a->day == b->day){
                if(time_GreaterThan(&(a->start), (&(b->start)))){
                        if(time_GreaterThan(&(a->start), (&(b->start))))
                                return TRUE;
                }
        }
	else	return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_GreaterThan\n");
	#endif
}

Boolean dt_LessThanOrEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_LessThanOrEqual\n");
	#endif

	if(a->day == b->day){
                if(time_LessThanOrEqual(&(a->start), (&(b->start)))){
                        if(time_LessThanOrEqual(&(a->start), (&(b->start))))
                                return TRUE;
                }
        }
        else    return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_LessThanOrEqual\n");
	#endif
}

Boolean dt_GreaterThanOrEqual(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_GreaterThanOrEqual\n");
	#endif

	if(a->day == b->day){
                if(time_GreaterThanOrEqual(&(a->start), (&(b->start)))){
                        if(time_GreaterThanOrEqual(&(a->start), (&(b->start))))
                                return TRUE;
                }
        }
        else    return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_GreaterThanOrEqual\n");
	#endif
}

Boolean dt_Overlap(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Overlap\n");
	#endif

	if(a->day == b->day){
		if(a->start.hour == b->start.hour){
			if(a->end.hour == b->end.hour){
				if(a->start.minute == b->start.minute){
					if(a->end.minute == b->end.minute)
						return TRUE;
				}
			}
		}
	}
	
	else	
		return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Overlap\n");
	#endif
}

Boolean dt_NonOverlap(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_NonOverlap\n");
	#endif

	if(a->day == b->day){
                if(a->start.hour == b->start.hour){
                        if(a->end.hour == b->end.hour){
                                if(a->start.minute == b->start.minute){
                                        if(a->end.minute == b->end.minute)
                                                return FALSE;
                                }
                        }
                }
        }

	else
		return TRUE;

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

		d->day = day;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeDay\n");
	#endif
}

void dt_ChangeDuration(DaTime *d, int dur)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeDuration\n");
	#endif

		d->duration = dur;
		d->end.hour = d->start.hour + dur/60;
		d->end.minute = d->start.minute + dur % 60;

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeDuration\n");
	#endif
}

void dt_ChangeStart(DaTime *d, Time newstart)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_ChangeStart\n");
	#endif
	
	dt_SetStart(d, newstart);

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_ChangeStart\n");
	#endif
}


DaTime dt_Merge(DaTime *a, DaTime *b)
{  	DaTime temp;
	
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Merge\n");
	#endif

	if(dt_GetDay(a) != dt_GetDay(b))
	{	printf("Cannot merge across days; result cleared.\n");
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

/*
 * Gets duration in between classes
 */
int dt_Difference(DaTime *a, DaTime *b)
{
	#ifdef DEBUG
	fprintf(stderr,"\tEnter dt_Difference\n");
	#endif

	int hours = 0;	/* local variable to denote difference in time */
	int mins = 0;	/* loval variable to denote difference in time */
	if(a->day != b->day)
		printf("Not on same day; difference is greater than 12 hours!\n");
        
	else if(a->day == b->day){
		if ((a->start.hour <= b->start.hour) && 
		(a->start.minute < b->start.minute)) {
			hours = b->start.hour - a->end.hour;
			mins = b->start.minute - a->end.minute;
			printf("Difference between classes = %dhr,%dmin.\n",
			hours, mins);
                }
		else if ((b->start.hour <= a->start.hour) && 
		(a->start.minute <= b->start.minute)) {
                	hours = a->start.hour - b->end.hour;
                	mins = a->start.minute - b->end.minute;
         	       	printf("Difference between classes = %dhr,%dmin.\n",
			hours, mins);
		}
		else if ((a->start.hour == b->start.hour)&& 
		(a->start.minute == b->start.minute)) {
			printf("Classes are the same time! No Gap!\n");
		}
		else if ((a->start.hour == b->end.hour)&&
		(a->start.minute == b->end.minute)) {
                        printf("No gap between classes!\n");
                }
		
		else if((a->end.hour == b->start.hour) && 
		(a->end.minute == b->start.minute)) {
			printf("No gap between classes!\n");
		}

	#ifdef DEBUG
	fprintf(stderr, "\tExit dt_Difference\n");
	#endif
	
	}
}



