CC = g++
CFLAGS = -w -g -std=c++11
VERBOSEFLAG = -DVERBOSE
OBJS = staticbase.o virtbase.o virtder.o purebase.o overhead.o
   
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o allcalls 

overhead.o: overhead.cpp
	$(CC) $(CFLAGS) -c overhead.cpp

purebase.o: purebase.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c purebase.cpp

virtbase.o: virtbase.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c virtbase.cpp

virtder.o: virtder.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c virtder.cpp

staticbase.o: staticbase.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c staticbase.cpp

clean:
	rm staticbase.o  overhead.o virtder.o virtbase.o purebase.o allcalls