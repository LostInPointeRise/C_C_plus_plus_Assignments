CC = g++
CFLAGS = -w -g
OBJS = macromax.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o macromax  -std=c11 -pedantic

macromax.o: macromax.cpp
	$(CC) $(CFLAGS) -c macromax.cpp

clean:
	rm macromax.o macromax 