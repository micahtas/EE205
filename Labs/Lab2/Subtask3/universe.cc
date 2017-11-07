

/*  File: universe.cc
 *  Date: 27 Sep 05
 *  Rev:  v1
 *
 *  definition of universe class
 *  a simplest case with updates as a copy of the current universe
 */
/*
#include "universe.h"
#include "entry.h"
#include "container.h"
//#define DEBUGGER 1

// maximum number of generations to process
static const int MAXGEN = 10;

// symbols for cell state
const int DEAD = 0;
const int ALIVE = 1;

// Constructor and Destructors
Universe :: Universe()
{	init_to_empty();	}

Universe :: ~Universe()
{	init_to_empty();	}

// Accessors
void Universe :: display() const
{
	// show header
        printf("             begin: %3d",begin - 2);
        for(int i = begin; i <= end+2; i++) printf("  ");
        printf("%3d end\n", end +2);

	// show universe
	printf("Generation %03d: ", generation);
	printf(". . . 0 0 ");
	for(int i = begin; i <= end; i++)
		printf("%d ", cells.get(i));
	printf("0 0 . . .\n");
}

// Mutators

void Universe :: clear()
{	init_to_empty();	}

void Universe :: populate()
{
	// a simple initial universe for testing
	cells.insert(DEAD);
	cells.insert(ALIVE);
    cells.insert(ALIVE);
	cells.insert(ALIVE);
	cells.insert(DEAD);
    cells.insert(ALIVE);
    cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(ALIVE);
    cells.insert(DEAD);
    cells.insert(ALIVE);
    cells.insert(ALIVE);
	cells.insert(ALIVE);
    cells.insert(DEAD);
	end = 15;
}

int Universe :: update(Universe *other)
{
	// a trivial update operation which copies to the next generation.
	update_from_copy(*other);
	other->generation++;
	return other->generation - MAXGEN;
}

// Private helper functions

void Universe :: init_to_empty()
{	begin = end = generation = 0;
	cells.clear();
}

void Universe :: update_from_copy(Universe &other)
{
    int newBegin = begin;
    int newEnd = end;
    
#ifdef DEBUGGER
    printf("DEBUG: Entering update_from_copy\n");
    printf("Container Size = %i\n",cells.size());
#endif
    
	for(int i = begin; i <= end; i++)
	{
#ifdef DEBUGGER
        printf("Checking cell %i\n", i);
#endif
        if (eval_cell(i)) {
#ifdef DEBUGGER
            printf("Cell is alive\n");
#endif
            other.cells.insert(update_live(i));
        }
        else {
#ifdef DEBUGGER
            printf("Cell is dead\n");
#endif

                other.cells.insert(update_dead(i));

                if (i == begin && update_dead(i) == 0)
                    newBegin++;
                if (i == end && update_dead(i) == 0)
                    newEnd--;
                if (i == begin && update_dead(i) == 1) {
                    //newBegin--;
                    newEnd++;
                    other.cells.insert(DEAD,0);
                    }
                if (i == end && update_dead(i) == 1) {
                    newEnd++;
                    other.cells.insert(DEAD, -1);
                    }
            }
        }

	other.generation = generation;
	other.begin = newBegin;
	other.end = newEnd;
    
#ifdef DEBUGGER
    printf("DEBUG: exiting update_from_copy\n");
#endif
}

Entry Universe::update_live(Coordinate p) const
{
#ifdef DEBUGGER
    printf("DEBUG: Entering update_live\n");
#endif
    int count = 0;
    int j;
    int k;
    int status;
    
    if (p == begin) {
        j = begin;
        k = p + 2;
    }
    else if (p == begin+1) {
        j = begin;
        k = p + 2;
    }
    else if (p == end) {
        j = p - 2;
        k = end;
    }
    else if (p == end-1) {
        j = p -2;
        k = end;
    }
    else {
        j = p - 2;
        k = p + 2;
    }
    if (j < begin) {
        j = begin;
    }
    if (k > end) {
        k = end;
    }
#ifdef DEBUGGER
    printf("Begin = %i \tEnd = %i\n", begin, end);
    printf("J = %i \tK = %i\n", j, k);
#endif
    for ( ; j <= k; j++) {
        if (eval_cell(j) && j != p) {
            count++;
        }
    }
    if (count == 0 || count == 1 || count == 3) {   // cell dies
        status = 0;
    }
    else    // cell lives
        status = 1;
#ifdef DEBUGGER
    printf("DEBUG: Exiting update_live\n");
#endif
    return status;
}

Entry Universe::update_dead(Coordinate p) const
{
#ifdef DEBUGGER
    printf("DEBUG: Entering update_dead\n");
#endif
    int count = 0;
    int j;
    int k;
    int status;
    
    if (p == begin) {
        j = begin;
        k = p + 2;
    }
    else if (p == begin+1) {
        j = begin;
        k = p + 2;
    }
    else if (p == end) {
        j = p - 2;
        k = end;
    }
    else if (p == end-1) {
        j = p -2;
        k = end;
    }
    else {
        j = p - 2;
        k = p + 2;
    }
    if (j < begin) {
        j = begin;
    }
    if (k > end) {
        k = end;
    }
#ifdef DEBUGGER
    printf("Begin = %i \tEnd = %i\n", begin, end);
    printf("J = %i \tK = %i\n", j, k);
#endif
    for ( ; j <= k; j++) {
        if (eval_cell(j)) {
            count++;
        }
    }
    if (count == 2 || count == 3) { // cell lives
        printf("Dead cell now lives\n");
        status = 1;
    }
    else {                          // cell dies
        status = 0;
    }
#ifdef DEBUGGER
    printf("DEBUG: Exiting update_dead\n");
#endif
    return status;
}

int Universe::count_cells(Coordinate start, Coordinate stop) const
{
    int count = 0;
    for (int i = start; i <= stop; i++) {
        if (cells.get(i) == 1) {
            count++;
        }
    }
    return count;
}

int Universe::eval_cell(Coordinate p) const
{
        return cells.get(p);
}
*/
