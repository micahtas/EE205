CC = g++
CFLAGS = -ansi

datest: driver.o datime.o time.o common.o soc.o
	$(CC) -o datest driver.o datime.o time.o common.o soc.o

driver.o: datime.h time.h

datime.o: datime.h common.h time.h

time.o: time.h common.h

soc.c: soc.h

clean:
	rm -f *.o

real_clean: clean
	rm -f datest
