CC = g++
CFLAGS = -w -g -std=c++11
OBJS = secarr.o secarrtest.o

   
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o secarray

secarrtest.o: secarrtest.cpp
	$(CC) $(CFLAGS) -c secarrtest.cpp

secarr.o: secarr.cpp
	$(CC) $(CFLAGS) -c secarr.cpp

clean:
	rm secarrtest.o secarr.o secarray