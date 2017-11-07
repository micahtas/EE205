
CC = gcc
CFLAGS = -ansi

datest: test.o datime.o time.o util.o
	$(CC) -o datest test.o datime.o time.o util.o

test.o: datime.h time.h

datime.o: datime.h util.h time.h

time.o: time.h util.h

clean:
	rm -f *.o

real_clean: clean
	rm -f datest

