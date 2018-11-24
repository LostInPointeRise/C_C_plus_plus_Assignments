CC = g++
CFLAGS = -w -g -std=c++11
OBJS = helloworldchanger.o helloext.o

  
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o helloext

helloext.o: helloext.cpp
	$(CC) $(CFLAGS) -c helloext.cpp

helloworldchanger.o: helloworldchanger.cpp
	$(CC) $(CFLAGS) -c helloworldchanger.cpp

clean:
	rm helloworldchanger.o helloext.o helloext