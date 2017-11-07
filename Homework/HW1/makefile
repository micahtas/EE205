CC = g++
CFLAGS = -ansi

appt: driver2.o appt.o datime.o time.o common.o
	$(CC) -o appt appt.o driver2.o datime.o time.o common.o

appt.o: appt.h class.h

driver2.o: appt.h class.h

datime.o: common.h class.h

time.o: common.h class.h

clean:
	rm -f *.o

real_clean: clean
	rm -f datest datest2 appt
