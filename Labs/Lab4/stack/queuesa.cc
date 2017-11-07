//
// "queuesa.cc"
//
// Definitions of Queue constructors, destructors, and assignment operator.
//
#include <memory.h>
#include "queues.h"

void TimeQueue::Init(const TimeQueue& other_q)
{
  elements = new Time [maxElements = other_q.maxElements];
  f = other_q.f;   r = other_q.r;
  elementCount = other_q.elementCount;
  for (int i = 0; i < elementCount; i++)
    elements[i] = other_q.elements[i];
}

inline void TimeQueue::CleanUp() 
  { delete [] elements; }

TimeQueue::TimeQueue(int initsize)          // Initialize queue to specified
{                                           //   number of entries
  elements = new Time[maxElements = initsize];
  f = r = elementCount = 0;
}

TimeQueue::TimeQueue(const TimeQueue &other_q)   // Initialize queue to copy
  { Init(other_q); }                        //   existing queue

TimeQueue::~TimeQueue()                     // Clean up queue before removal
  { CleanUp(); }

TimeQueue& TimeQueue::operator=(const TimeQueue& other_q)
{
  if (this != &other_q)
  {
    CleanUp();
    Init(other_q);
  }
  return *this;
}
