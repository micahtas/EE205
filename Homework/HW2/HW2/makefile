
CCC = g++
CCFLAGS = -ansi

all: testsearch testbinsrch testselsort

testsearch: testsearch.o sort_container.o container.o common.o
	$(CCC) -o testsearch sort_container.o testsearch.o container.o common.o

testbinsrch: testbinsrch.o sort_container.o container.o common.o
	$(CCC) -o testbinsrch testbinsrch.o sort_container.o container.o common.o

testselsort: testselsort.o sort_container.o container.o common.o
	$(CCC) -o testselsort testselsort.o sort_container.o container.o common.o

testsearch.o: sort_container.h container.h entry.h common.h

testbinsrch.o: sort_container.h entry.h

testselsort.o: sort_container.h entry.h

container.o: container.h common.h

clean:
	rm -f *.o

real_clean: clean
	rm -f testsearch testbinsrch testselsort
