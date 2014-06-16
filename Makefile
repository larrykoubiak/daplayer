CC=gcc
CFLAGS = -c
LIBS = -lgdi32
WINDRES = windres

all: daplayer

daplayer: main.o resource.o
	$(CC) main.o resource.o -o daplayer

main.o: main.c
	$(CC) $(CFLAGS) main.c $(LIBS)

resource.o: resource.rc resource.h
	$(WINDRES) resource.rc resource.o
	
clean:
	rm -f *.o *.exe stdout.txt stderr.txt *~

	
