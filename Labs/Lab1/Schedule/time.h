/* File: time.h */

#ifndef TIME_H
#define TIME_H

#include "util.h"

typedef struct time{
int hour;
int minute;
} time;

void time_Init(time *t, int hour, int minute);

int time_gethour(time *t);
int time_getminute(time *t);

void time_sethour(time *t, int hour);
void time_setminute(time *t, int minute);

void time_display(time *d);

Boolean time_equal(time *a, time *b);
Boolean time_notequal(time *a, time *b);
Boolean time_lessthan(time *a, time *b);
Boolean time_greaterthan(time *a, time *b);
Boolean time_lessthanorequalto(time *a, time *b);
Boolean time_greaterthanorequalto(time *a, time *b);

#endif
