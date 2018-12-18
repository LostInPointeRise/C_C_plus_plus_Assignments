CC = g++
CFLAGS = -w -g -std=c++11
OBJS = player.o humanplayer.o gameboard.o gamemaster.o game.o tictactoe.o

   
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tictactoe

tictactoe.o: tictactoe.cpp
	$(CC) $(CFLAGS) -c tictactoe.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) -c game.cpp

gamemaster.o: gamemaster.cpp
	$(CC) $(CFLAGS) -c gamemaster.cpp

gameboard.o: gameboard.cpp
	$(CC) $(CFLAGS) -c gameboard.cpp

humanplayer.o: humanplayer.cpp
	$(CC) $(CFLAGS) -c humanplayer.cpp

player.o: player.cpp
	$(CC) $(CFLAGS) -c player.cpp

clean:
	rm player.o humanplayer.o gameboard.o gamemaster.o game.o tictactoe.o tictactoe