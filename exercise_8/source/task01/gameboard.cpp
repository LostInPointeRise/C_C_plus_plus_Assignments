#include "gameboard.hpp"
#include <iostream>
#include <iomanip>

#include <string>

#define PLAYER_1  1
#define PLAYER_2  2

#define PLAYER_1_MARK  'X'
#define PLAYER_2_MARK 'O'
 
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
            matrix[ctr][itr] = ' ';
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

    return lastPlayerId;
}

void GameBoard::insert(int playerId, int x_coordinate, int y_coordinate){

    cout << "player was  " << playerId <<endl; 
    matrix[x_coordinate][y_coordinate] = ( (playerId == PLAYER_1 ) ? PLAYER_1_MARK : PLAYER_2_MARK);

    cout << matrix[x_coordinate][y_coordinate] << endl; 
    cout << "at " << x_coordinate << y_coordinate <<endl; 
    // we incrment the number of fields that were choosen
    choosenFields += 1; 

    // we need to set the id of the player , who did the current move
    lastPlayerId = playerId;
}
 
bool GameBoard::isFree(int x_coordinate, int y_coordinate){

     // check if move is invalid
     cout<< "size is " << size << endl;
    if(x_coordinate > size || y_coordinate > size 
                || x_coordinate == 0 || y_coordinate == 0){
            
           return false; 
    }
    else{

        return ((matrix[x_coordinate][y_coordinate]) != ' ') ? false : true;  
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


 

