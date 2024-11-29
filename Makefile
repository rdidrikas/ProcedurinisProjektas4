# -*- MakeFile -*-

CFLAGS = -Wall -g

main: main.o sarasai.o
	gcc $(CFLAGS) main.o sarasai.o -o main.exe

tests: tests.o sarasai.o
	gcc $(CFLAGS) tests.o sarasai.o -o tests.exe

tests.o: tests.c mystruct.h
	gcc $(CFLAGS) -c tests.c

main.o: main.c mystruct.h
	gcc $(CFLAGS) -c main.c

sarasai.o: sarasai.c mystruct.h
	gcc $(CFLAGS) -c sarasai.c

clean:
	rm -f *.o main.exe tests.exe