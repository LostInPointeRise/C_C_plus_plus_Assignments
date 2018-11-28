CC = g++
CFLAGS = -w -g -std=c++11
OBJS = mytime.o mytimetest.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o mytime 

mytimetest.o: mytimetest.cpp
	$(CC) $(CFLAGS) -c mytimetest.cpp

mytime.o: mytime.cpp
	$(CC) $(CFLAGS) -c mytime.cpp

clean:
	rm mytimetest.o mytime.o mytime