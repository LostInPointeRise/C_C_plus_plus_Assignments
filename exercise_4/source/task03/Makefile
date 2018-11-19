CC = g++
CFLAGS = -w -g
OBJS = overflow.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o overflow  -std=c11 -pedantic

overflow.o: overflow.cpp
	$(CC) $(CFLAGS) -c overflow.cpp

clean:
	rm overflow.o overflow 