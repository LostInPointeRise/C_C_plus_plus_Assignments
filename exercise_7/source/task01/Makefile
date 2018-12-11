CC = g++
CFLAGS = -w -g -std=c++11
VERBOSEFLAG = -DVERBOSE
TASK02FLAG = -DTASK02
TASK03FLAG = -DTASK03
OBJSALL = stopwatch.o staticbaseforall.o virtderforall.o virtbaseforall.o purebaseforall.o overheadforall.o
OBJSTASK02 = stopwatch.o staticbasefortask02.o virtderfortask02.o virtbasefortask02.o purebasefortask02.o overheadfortask02.o
OBJSTASK03 = stopwatch.o staticbasefortask02.o virtderfortask02.o virtbasefortask02.o purebasefortask02.o  overheadfortask03.o


all: $(OBJSALL)
	$(CC) $(CFLAGS)   $(OBJSALL) -o allcalls 

task02: $(OBJSTASK02)
	$(CC) $(CFLAGS)   $(OBJSTASK02) -o overhead 

task03: $(OBJSTASK03)
	$(CC) $(CFLAGS)  $(OBJSTASK03) -o casting

overheadfortask03.o: overhead.cpp
	$(CC) $(CFLAGS) $(TASK03FLAG) -c overhead.cpp -o overheadfortask03.o

stopwatch.o: stopwatch.cpp
	$(CC) $(CFLAGS) -c stopwatch.cpp

overheadforall.o: overhead.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c overhead.cpp -o overheadforall.o

purebaseforall.o: purebase.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c purebase.cpp -o purebaseforall.o

virtbaseforall.o: virtbase.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c virtbase.cpp -o virtbaseforall.o

virtderforall.o: virtder.cpp
	$(CC) $(CFLAGS) $(VERBOSEFLAG) -c virtder.cpp -o virtderforall.o

staticbaseforall.o: staticbase.cpp
	$(CC) $(CFLAGS)  $(VERBOSEFLAG) -c staticbase.cpp -o staticbaseforall.o


overheadfortask02.o: overhead.cpp
	$(CC) $(CFLAGS) $(TASK02FLAG) -c overhead.cpp -o overheadfortask02.o

purebasefortask02.o: purebase.cpp
	$(CC) $(CFLAGS) -c purebase.cpp -o purebasefortask02.o

virtbasefortask02.o: virtbase.cpp
	$(CC) $(CFLAGS) -c virtbase.cpp -o virtbasefortask02.o

virtderfortask02.o: virtder.cpp
	$(CC) $(CFLAGS) -c virtder.cpp -o virtderfortask02.o

staticbasefortask02.o: staticbase.cpp
	$(CC) $(CFLAGS)  -c staticbase.cpp -o staticbasefortask02.o

clean:
	rm  *.o overhead casting allcalls