CC = g++
CFLAGS = -w -g -std=c++11
OBJS = collectiontest.o
  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o collection  


collectiontest.o: collectiontest.cpp node.hpp node.tpp list.hpp list.tpp
	$(CC) $(CFLAGS) -c collectiontest.cpp


clean:
	rm *.o collection