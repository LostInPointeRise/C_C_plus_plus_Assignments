CC = g++
CFLAGS = -w -g -std=c++11
OBJS = player.o field.o score.o  computerplayer.o humanplayer.o gameboard.o gamemaster.o game.o tictactoe.o

   
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tictactoe

tictactoe.o: tictactoe.cpp
	$(CC) $(CFLAGS) -c tictactoe.cpp

computerplayer.o: computerplayer.cpp
	$(CC) $(CFLAGS) -c computerplayer.cpp

field.o: field.cpp
	$(CC) $(CFLAGS) -c field.cpp

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

score.o: score.cpp
	$(CC) $(CFLAGS) -c score.cpp

clean:
	rm field.o score.o player.o computerplayer.o humanplayer.o gameboard.o gamemaster.o game.o tictactoe.o tictactoe