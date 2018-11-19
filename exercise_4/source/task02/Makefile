CC = g++
CFLAGS = -w -g
OBJS = makevar.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o makevar  -std=c11 -pedantic

makevar.o: makevar.cpp
	$(CC) $(CFLAGS) -c makevar.cpp

clean:
	rm makevar.o makevar 