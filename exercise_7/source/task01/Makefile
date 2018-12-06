CC = g++
CFLAGS = -w -g -std=c++11
VERBOSEFLAG = -DVERBOSE
OBJS = purebase.o overhead.o

   
all: $(OBJS)
	$(CC) $(CFLAGS) $(VERBOSEFLAG) $(OBJS) -o allcalls 

overhead.o: overhead.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c overhead.cpp

purebase.o: purebase.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c purebase.cpp

clean:
	rm overhead.o purebase.o allcalls