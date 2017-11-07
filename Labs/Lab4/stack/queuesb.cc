//
// "queuesb.cc"
//
// Definitions of other Queue operations.
//
#include <memory.h>
#include "queues.h"

inline int TimeQueue::NextIndex(int i)
  { return (i + 1 < MaxQueueSize) ? i + 1 : 0; }

void TimeQueue::Enqueue(const Time& value)
{
  elements[r] = value;
  elementCount++;
  r = NextIndex(r);
}

Time TimeQueue::Dequeue(void)
{
  Time &value = elements[f];

  f = NextIndex(f);
  elementCount--;

  return value;
}

int TimeQueue::Length() const
  { return elementCount; }

bool TimeQueue::IsEmpty() const
  { return Length() == 0; }

ostream& operator<<(ostream& output, const TimeQueue& q)
{
  if (q.f < q.r)
  {
    for (int i = q.f; i < q.r; i++)
      cout << q.elements[i] << endl;
  }
  else
  {
    for (int i = q.f; i < q.maxElements; i++)
      cout << q.elements[i] << endl;
    for (int j = 0; j < q.r; j++)
      cout << q.elements[j] << endl;
  }
  return output;
}
