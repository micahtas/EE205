//
// "queue.h"
//
// Queue class declaration for a queue of times.
//
#include "time.h"

const int MaxQueueSize = 100;

class TimeQueue
{
  public:
    TimeQueue(int initsize = MaxQueueSize);     // Construct empty queue
    TimeQueue(const TimeQueue& other_q);        // Construct from queue
    ~TimeQueue();                               // Destruct queue

    TimeQueue& operator=(const TimeQueue& other_q); // Assign queues

    void Enqueue(const Time& value);        // Add element at end
    Time Dequeue();                         // Delete first element
    bool IsEmpty() const;                   // True if no elements
    int  Length() const;                    // # of elements

  friend ostream& operator<<(ostream& output, const TimeQueue& q);

  

  private:
    Time *elements;                         // Actual queue elements
    int  f, r;                              // Indices to start/finish
    int  elementCount;                      // Number of elements
    int  maxElements;                       // Max number of elements
 
    int  NextIndex(int current);            // Update queue index

    void Init(const TimeQueue& other_q);    // Initialize by copying
    void CleanUp();                         // Deallocate fields
};
