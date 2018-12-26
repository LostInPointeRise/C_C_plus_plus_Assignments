CC = g++
CFLAGS = -w -g -std=c++11
OBJSALL = rbtest.o


all: $(OBJSALL)
	$(CC) $(CFLAGS)   $(OBJSALL) -o ringbuffer

rbtest.o: rbtest.cpp
	$(CC) $(CFLAGS) -c rbtest.cpp

clean:
	rm  *.o ringbuffer