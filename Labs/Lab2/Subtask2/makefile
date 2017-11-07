CC = g++
CCFLAGS = -ansi

testcontainer: container.o common.o listnode.o testcontainer.o
	$(CC) -o testcontainer container.o common.o listnode.o testcontainer.o

common.o: common.h

container.o: container.h entry.h common.h

listnode.o: listnode.h

testcontainer.o: container.h entry.h

clean:
	rm -f *.o

real_clean: clean
	rm -f testcontainer

