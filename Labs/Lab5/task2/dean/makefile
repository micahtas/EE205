
CCC = g++
CCFLAGS = -ansi

testsearch: testsearch.o container.o common.o sortedcontainer.o
	$(CCC) -o testsearch testsearch.o container.o common.o sortedcontainer.o

testbinsrch: testbinsrch.o sort_container.o container.o common.o
	$(CCC) -o testbinsrch testbinsrch.o sort_container.o container.o common.o

testselsort: testtestselsort.o sort_container.o container.o common.o
	$(CCC) -o testselsort testselsort.o sort_container.o container.o common.o

testsearch.o: container.h entry.h common.h sortedcontainer.h

testbinsrch.o: sort_container.h entry.h

testselsort.o: sort_container.h entry.h

container.o: container.h container_inl.h common.h

clean:
	rm -f *.o

real_clean: clean
	rm -f testsearch testbinsrch testselsort
