CC = g++
CFLAGS = -w -g -std=c++11
OBJSALL = chattest.o


all: $(OBJSALL)
	$(CC) $(CFLAGS)   $(OBJSALL) -o chat

chattest.o: chattest.cpp
	$(CC) $(CFLAGS) -c chattest.cpp

clean:
	rm  *.o chat