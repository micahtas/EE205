CCC = g++
CCFLAGS = -ansi

all: testqueue testdequeue teststack

testqueue: queue.o container.o common.o testqueue.o
	$(CCC) -o testqueue container.o common.o queue.o testqueue.o
teststack: stack.o container.o common.o teststack.o
	$(CCC) -o teststack container.o common.o stack.o teststack.o
testcontainer: container.o common.o testcontainer.o
	$(CCC) -o testcontainer container.o common.o testcontainer.o

testdequeue: dequeue.o container.o common.o testdequeue.o
	$(CCC) -o testdequeue container.o common.o testdequeue.o dequeue.o

queue.o: queue.h container.h

testqueue.o: queue.h

stack.o: stack.h container.h

teststack.o: stack.h

common.o: common.h

container.o: container.h entry.h common.h listnode.h listnode_inl.h

testcontainer.o: container.h entry.h

testdequeue.o: dequeue.h

clean:
	rm -f *.o

real_clean: clean
	rm -f testcontainer testqueue teststack testdequeue
