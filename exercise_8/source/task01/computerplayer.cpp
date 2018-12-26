#include <stdlib.h>  
#include "computerplayer.hpp"
 
void ComputerPlayer::play(GameBoard& gameBoard){
 
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