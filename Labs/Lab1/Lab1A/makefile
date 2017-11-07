CC = g++
CFLAGS = -ansi

datest: driver.o datime.o time.o common.o
	$(CC) -o datest driver.o datime.o time.o common.o

datest2: driver1.o soc.o datime.o time.o common.o
	$(CC) -o datest2 driver1.o soc.o datime.o time.o common.o

soc.o: soc.h

driver.o: datime.h time.h

driver1.o: datime.h soc.h

datime.o: datime.h common.h time.h

time.o: time.h common.h

clean:
	rm -f *.o

real_clean: clean
	rm -f datest datest2
