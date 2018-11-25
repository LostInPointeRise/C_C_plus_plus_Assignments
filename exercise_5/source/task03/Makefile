CC = g++
CFLAGS = -w -g -std=c++11
OBJS = stopwatch.o stack.o timetest.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o timetest

timetest.o: timetest.cpp
	$(CC) $(CFLAGS) -c timetest.cpp

stopwatch.o: stopwatch.cpp
	$(CC) $(CFLAGS) -c stopwatch.cpp

stack.o: stack.cpp
	$(CC) $(CFLAGS) -c stack.cpp

clean:
	rm stopwatch.o stopwatch stack.o stack timetest.o timetest