

/*  File: universe.cc
 *  Date: 27 Sep 05
 *  Rev:  v1
 *
 *  definition of universe class
 *  a simplest case with updates as a copy of the current universe
 */

#include "universe.h"
#include "entry.h"
#include "container.h"

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
	for(int i = 0; i <= end-begin; i++)
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
    cells.insert(DEAD);
	cells.insert(ALIVE);
	cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(DEAD);
    cells.insert(ALIVE);
    cells.insert(DEAD);
    cells.insert(ALIVE);
    cells.insert(ALIVE);
	end = 13;
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
    if (eval_cell(0)) {
        cout << "Inserting beginning" << endl;
        begin--;
        cells.insert(DEAD,0);
    }
    if (eval_cell(end-begin)) {
        cout << "Inserting ending" << endl;
        end++;
        cells.insert(DEAD, -1);
    }
    
    int newBegin = begin;
    int newEnd = end;
    
    debug("DEBUG: Entering update_from_copy\n");
    
	for(int i = 0; i <= end-begin; i++)
	{
        if (eval_cell(i)) {
            
debug("Cell is alive\n");
            
            other.cells.insert(update_live(i));
        }
        else {

debug("Cell is dead\n");

                other.cells.insert(update_dead(i));
            
                if (i == 0 && update_dead(i) == 1) {
                    newBegin--;
                    other.cells.insert(DEAD,0);
                    }
                if (i == end-begin && update_dead(i) == 1) {
                    newEnd++;
                    other.cells.insert(DEAD, -1);
                    }
            }
        }
    
    int beginFlag = 0;
    int beginFlagFlag = 0;
    int endFlag = 0;
    int otherEnd = newEnd;
    int otherBegin = newBegin;
    
    for (int i = 0; i <= otherEnd-otherBegin; i++) {
        if (beginFlagFlag == 0 && other.eval_cell(i)) {
            cout << "found one " << i << endl;
            cout << "begin is " << begin << endl;
            beginFlag = i - 1;
            beginFlagFlag = 1;
        }
        if (i<otherEnd-otherBegin) {
            endFlag++;
        }
        if (other.eval_cell(i)) {
            endFlag = 0;
        }
    }
    for (int i = 0; i <= beginFlag; i++) {
        other.cells.remove(0);
    }
    cout << "endflag = " << endFlag << endl;
    newBegin += beginFlag;
    newEnd -= endFlag;
    

	other.generation = generation;
	other.begin = newBegin;
	other.end = newEnd;
    
debug("DEBUG: exiting update_from_copy\n");
}

Entry Universe::update_live(Coordinate p) const
{

debug("DEBUG: Entering update_live\n");

    int count = 0;
    int j;
    int k;
    int status;
    
    if (p == 0) {
        j = 0;
        k = p + 2;
    }
    else if (p == 1) {
        j = 0;
        k = p + 2;
    }
    else if (p == end-begin) {
        j = p - 2;
        k = end-begin;
    }
    else if (p == end-begin-1) {
        j = p -2;
        k = end-begin;
    }
    else {
        j = p - 2;
        k = p + 2;
    }
    if (j < 0) {
        j = 0;
    }
    if (k > end-begin) {
        k = end-begin;
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

debug("DEBUG: Exiting update_live\n");

    return status;
}

Entry Universe::update_dead(Coordinate p) const
{

debug("DEBUG: Entering update_dead\n");

    int count = 0;
    int j;
    int k;
    int status;
    
    if (p == 0) {
        j = 0;
        k = p + 2;
    }
    else if (p == 1) {
        j = 0;
        k = p + 2;
    }
    else if (p == end-begin) {
        j = p - 2;
        k = end-begin;
    }
    else if (p == end-begin-1) {
        j = p -2;
        k = end-begin;
    }
    else {
        j = p - 2;
        k = p + 2;
    }
    if (j < 0) {
        j = 0;
    }
    if (k > end-begin) {
        k = end-begin;
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

debug("Dead cell now lives\n");

        status = 1;
    }
    else {                          // cell dies
        status = 0;
    }

debug("DEBUG: Exiting update_dead\n");

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
