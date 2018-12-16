CC = g++
CFLAGS = -w -g -std=c++11
OBJS = game.o tictactoe.o

   
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tictactoe

tictactoe.o: tictactoe.cpp
	$(CC) $(CFLAGS) -c tictactoe.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) -c game.cpp

clean:
	rm game.o tictactoe.o tictactoe