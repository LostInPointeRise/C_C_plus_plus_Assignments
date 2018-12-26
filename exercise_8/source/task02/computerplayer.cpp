#include <stdlib.h>  
#include <limits>
#include<iterator> 
#include "computerplayer.hpp"

void ComputerPlayer::play(GameBoard& gameBoard){
 
    if(mode == Mode::RANDOM){

        int const min = 0; 

        int const max = gameBoard.getSize() - 1;

        int row_index = 42; 

        int column_index = 42; 

        do{
    
            row_index = min + (rand() % static_cast<int>(max - min + 1)); 
        
            column_index =  min + (rand() % static_cast<int>(max - min + 1)); 
        }
        while(!gameBoard.isFree(row_index, column_index));

        gameBoard.insert(turn, row_index, column_index);
    }
    else if(mode == Mode::MINIMAX){

        // at first we create a copy of the current game situation
        GameBoard boardCopy(gameBoard);

        // next step , we need to get a list of all free fields 

        // we will do a move on any , of the free fields
        // we will copy 
 
        Score score = minimax(boardCopy, 3, MAX);


        gameBoard.insert(turn, score .x_coordinate, score.y_coordinate);
    }
    
}
 
 
Score ComputerPlayer::minimax(GameBoard gameBoard , int depth, PLAYER player){

    Score best; 
 
    if( player == MAX) {
      
         best = Score(-1, -1, -100000);
    
    } else if( player == MIN) {
      
         best = Score(-1, -1, 100000);
 
    }

    
    if (depth == 0 || !gameBoard.hasAvailableMoves()){

        if(DRAW_CODE != gameBoard.getWinner()){

            return Score(-1, -1, ( (player == PLAYER::MAX) ? 1 : -1));
        }
        else{

            return Score(-1, -1, 0);
        }
     }
  

    std::list<Field>::iterator it;
 
    std::list<Field> freefieldList = gameBoard.getListOfFreeFields();

    Score score(0,0,0);
    for (it = freefieldList.begin(); it != freefieldList.end(); ++it){
       
        gameBoard.insert( player, it->x_coordinate, it->y_coordinate);

        score =  minimax(GameBoard(gameBoard),  depth - 1, ((player == MAX) ? PLAYER::MIN : PLAYER::MAX));
 
        score.x_coordinate = it->x_coordinate; 

        score.y_coordinate = it->y_coordinate; 
 
    }
  
    if(player == MAX ){
 

        if(score.value > best.value){

            best = score;  
        }
    }
    else{
  
        
         if(score.value < best.value){

            best = score;  
        }
    }
 
  return best; 
}

