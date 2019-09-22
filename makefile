CC = cc
CFLAGS = -std=c++17 -pedantic -Wall
OBJECTS = filename.o

all: appname

filename.o: filename.c
    $(CC)   $(CFLAGS)   -c  filename.c

appname: $(OBJECTS)
    $(CC)   $(OBJECTS)    -o appname

clean:
    rm -f *.o appname