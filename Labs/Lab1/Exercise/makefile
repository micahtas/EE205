CC = gcc
CFLAGS = -ansi

review: review.o review_func.o
	$(CC) -o review review.o review_func.o

review.o: review_func.h globals.h

review_func.o: review_func.h globals.h

clean:
	rm -f *.o

real_clean: clean
	rm -f review
