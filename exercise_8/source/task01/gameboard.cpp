#include "gameboard.hpp"
#include "constants.hpp"
#include <iostream>
#include <iomanip>
#include <string>
 
#define PLAYER_1  1
#define PLAYER_2  2

#define PLAYER_1_MARK  'X'
#define PLAYER_2_MARK 'O'
 
#define FIELD_NOT_SET ' '

using namespace std; 

GameBoard::GameBoard(int _size){
    size = _size; 

    initializeMatrix(_size);
}

GameBoard::~GameBoard(){
    
}

void GameBoard::initializeMatrix(int _size){

    // initialize matrix

    // initialize a pointer to a char array
    matrix  = new char*[size];

    for(int ctr = 0; ctr < _size ; ctr += 1){
        
        // assign every char pointer, another char array
        matrix[ctr] = new char[ctr];

        for(int itr = 0; itr < _size; itr +=1){

            // add nonprintable character to the matrix
            matrix[ctr][itr] = FIELD_NOT_SET;
        }
    }
}
 
bool GameBoard::hasAvailableMoves(){

    return choosenFields < (size * size);
}


int GameBoard::getSize(){

    return size; 
}

int GameBoard::getWinner(){

    const int winningFactor = (size * (size + 1)) / 2; 

    const int Player_1_WinningSum = winningFactor * static_cast<int>(PLAYER_1_MARK);

    const int Player_2_WinningSum = winningFactor * static_cast<int>(PLAYER_2_MARK);

    for(int row = 0; row < size; row +=1){

        int row_CurrentSum = 0;
        int column_CurrentSum = 0;
        int diagonal_CurrentSum = 0;
        int mirrored_diagonal_CurrentSum = 0;

        for(int column = 0; column < size; column +=1){

                row_CurrentSum += static_cast<int>(matrix[row][column]) * (column + 1);
                cout << row_CurrentSum<< " " << Player_1_WinningSum << " " << Player_2_WinningSum << endl; 
                column_CurrentSum += static_cast<int>(matrix[column][row]) * (row + 1);
                cout << column_CurrentSum << " " << Player_1_WinningSum << " " << Player_2_WinningSum << endl; 
                diagonal_CurrentSum += static_cast<int>(matrix[column][column]) * (column + 1);
                cout << diagonal_CurrentSum << " " << Player_1_WinningSum << " " << Player_2_WinningSum << endl;
                mirrored_diagonal_CurrentSum += static_cast<int>(matrix[column][(size - 1) - column]) * (column + 1);             
                cout << mirrored_diagonal_CurrentSum  << " " << Player_1_WinningSum << " " << Player_2_WinningSum << endl;
        }

        if(!(((row_CurrentSum != Player_1_WinningSum) && (column_CurrentSum != Player_1_WinningSum)
                && (diagonal_CurrentSum != Player_1_WinningSum) && (mirrored_diagonal_CurrentSum  != Player_1_WinningSum)) 
                    &&
            ((row_CurrentSum != Player_2_WinningSum) &&  (column_CurrentSum != Player_2_WinningSum)
                && (diagonal_CurrentSum != Player_2_WinningSum) && (mirrored_diagonal_CurrentSum  != Player_2_WinningSum)) ))
        {
         
            return lastPlayerId;
        }
        else{

            return DRAW_CODE;
        }
    }
}

void GameBoard::insert(int playerId, int x_coordinate, int y_coordinate){

    matrix[x_coordinate][y_coordinate] = ( (playerId == PLAYER_1 ) ? PLAYER_1_MARK : PLAYER_2_MARK);

    // we incrment the number of fields that were choosen
    choosenFields += 1; 

    // we need to set the id of the player , who did the current move
    lastPlayerId = playerId;
}
 
bool GameBoard::isFree(int x_coordinate, int y_coordinate){

     // check if move is invalid

    if(x_coordinate >= size || y_coordinate >= size 
                || x_coordinate < 0 || y_coordinate < 0){

           return false; 
    }
    else{

        if(((matrix[x_coordinate][y_coordinate]) != FIELD_NOT_SET)){

            return false;
        }
        else{

            return true; 
        }
    }
}

std::ostream& operator<<(std::ostream& os, const GameBoard& gameboard){
 
      os << R"(      1   2   3
    -------------
  1 | )" << gameboard.matrix[0][0]<< R"( | )" << gameboard.matrix[0][1] << R"( | )" << gameboard.matrix[0][2] << R"( | )" << '\n';


    os << R"(    -------------
  2 | )" << gameboard.matrix[1][0]<< R"( | )" << gameboard.matrix[1][1] << R"( | )" << gameboard.matrix[1][2] << R"( | )" << '\n';


    os << R"(    -------------
  3 | )" << gameboard.matrix[2][0]<< R"( | )" << gameboard.matrix[2][1] << R"( | )" << gameboard.matrix[2][2] << R"( | )" << '\n';


    os << R"(    -------------)" << '\n';

    return os;
}


 

