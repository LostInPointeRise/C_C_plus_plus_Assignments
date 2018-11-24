CC = g++
CFLAGS = -w -g -std=c++11
OBJS = stack.o stacksimpletest.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o stack 

stacksimpletest.o: stacksimpletest.cpp
	$(CC) $(CFLAGS) -c stacksimpletest.cpp

stack.o: stack.cpp
	$(CC) $(CFLAGS) -c stack.cpp

clean:
	rm stacksimpletest.o stack.o stack