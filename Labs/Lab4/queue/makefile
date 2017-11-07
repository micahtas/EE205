
CCC = g++
CCFLAGS = -ansi

testdequeue: dequeue.o container.o common.o stack.o queue.o testdequeue.o
	$(CCC) -o testdequeue container.o common.o stack.o queue.o dequeue.o testdequeue.o
testqueue: queue.o container.o common.o testqueue.o
	$(CCC) -o testqueue container.o common.o queue.o testqueue.o
teststack: stack.o container.o common.o teststack.o
	$(CCC) -o teststack container.o common.o stack.o teststack.o
testcontainer: container.o common.o testcontainer.o
	$(CCC) -o testcontainer container.o common.o testcontainer.o

dequeue.o: stack.h queue.h dequeue.h container.h

stack.o: stack.h container.h

queue.o: queue.h container.h

testdequeue.o: dequeue.h

testqueue.o: queue.h

teststack.o: stack.h

common.o: common.h

container.o: container.h entry.h common.h listnode.h listnode_inl.h

testcontainer.o: container.h entry.h

clean:
	rm -f *.o

real_clean: clean
	rm -f testcontainer testqueue teststack
