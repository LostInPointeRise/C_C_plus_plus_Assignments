#include "gamemaster.hpp" 

#include <stdio.h> 

#define USAGE_PLAYER_1 "Player 1: X"
#define USAGE_PLAYER_2 "Player 2: O"

#define PLAYER_1_TURN_MESSAGE "Player 1's turn"
#define PLAYER_2_TURN_MESSAGE "Player 2's turn"

#define PLAYER_1_COMMAND "Player 1: "
#define PLAYER_2_COMMAND "Player 2: "

using namespace std; 

void GameMaster::start(void){

    // print GameBoard
    round = 1; 

    do{
        cout<< gameBoard <<endl; 
        
        if(round == 1){
            printf("%s \n", USAGE_PLAYER_1);
            printf("%s \n", USAGE_PLAYER_2);
        }

        // read the actions of the current user
        readUserActions();
    }
    while(1);
    //while(!checkIfGameHasFinished());
}
/*
bool GameMaster::checkIfGameHasFinished(void){

    return ((gameBoard.getWinner() == NOT_FINISHED) || (!gameBoard.hasAvailableMoves())? false : true; 
}
*/

void GameMaster::readUserActions(void){

    // determine the player of the current turn
    determinecurrentPlayer();
    cout << "vor " << round << endl;
    round += 1;
    cout << "nach " << round << endl;
    currentPlayer->play(gameBoard);
 
}
 
void GameMaster::determinecurrentPlayer(void){
    // determine the player of the current turn  
    if(round % 2 != 0) { 
        printf("%s\n", PLAYER_1_TURN_MESSAGE);
        currentPlayer = player1;
    }
    else{ 
        printf("%s\n", PLAYER_2_TURN_MESSAGE);
        currentPlayer = player2;
    }
  
}


void GameMaster::setplayer1(Player* _player1){

    player1 = _player1;
}

void GameMaster::setplayer2(Player* _player2){

    player2 = _player2;
}

void GameMaster::setgameboard(GameBoard _gameBoard){

    gameBoard = _gameBoard;
}