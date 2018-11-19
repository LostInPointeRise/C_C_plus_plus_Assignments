CC = g++
CFLAGS = -w -g
OBJS = ex04task04.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o stopwatch  -std=c11 -pedantic

ex04task04.o: ex04task04.cpp
	$(CC) $(CFLAGS) -c ex04task04.cpp

clean:
	rm ex04task04.o stopwatch 