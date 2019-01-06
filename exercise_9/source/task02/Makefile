CC = g++
CFLAGS = -w -g -std=c++11
OBJSALL = botcommand.o messagecontainer.o chatapplication.o chattest.o


all: $(OBJSALL)
	$(CC) $(CFLAGS)   $(OBJSALL) -o chat

botcommand.o: botcommand.cpp
	$(CC) $(CFLAGS) -c botcommand.cpp

chattest.o: chattest.cpp
	$(CC) $(CFLAGS) -c chattest.cpp

chatapplication.o: chatapplication.cpp
	$(CC) $(CFLAGS) -c chatapplication.cpp

messagecontainer.o: messagecontainer.cpp
	$(CC) $(CFLAGS) -c messagecontainer.cpp

clean:
	rm  *.o chat