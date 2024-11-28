# -*- MakeFile -*-

CFLAGS = -Wall -g

main: main.o sarasai.o
	gcc $(CFLAGS) main.o sarasai.o -o main.exe

main.o: main.c mystruct.h
	gcc $(CFLAGS) -c main.c

sarasai.o: sarasai.c mystruct.h
	gcc $(CFLAGS) -c sarasai.c

clean:
	rm -f *.o main