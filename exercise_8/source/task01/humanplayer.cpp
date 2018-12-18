#include "humanplayer.hpp" 
#include <iostream>  
#include "constants.hpp"
#include "stdlib.h" 

#define COLUMN_SELECTION "Select a column:"
#define ROW_SELECTION "Select a row:"

using namespace std;


void HumanPlayer::play(GameBoard& gameBoard){

    int row_index = 42; 

    int column_index = 42; 

    bool run = true; 

    while(run){

        row_index = read_index(ROW_SELECTION); 

        column_index = read_index(COLUMN_SELECTION); 
 
        run = !gameBoard.isFree(row_index, column_index);
    }
    gameBoard.insert(turn, row_index - 1, column_index - 1);
}

 
int HumanPlayer::read_index(string questionedIndex){
  
    do{

        cout << questionedIndex << endl; 

    string input;
    getline(cin, input); 

    /**
      * variable and pointer declaration 
     */

     int test = 42; 
     int *ptr_to_first_operator = &test;

     char test1 = 'o';
     char *ptr_to_second_operator = &test1;

    
    /**
      * we use sscanf , cause it tries to match a given
      * pattern and return the number of arguments , that was matched 
      * 
      * If there is more or less than  "one single" integer, than the input is invalid.
      * 
      * We need to put a second operand , to give sscanf a possibility to 
      * track another argument.
     */

      
    if(sscanf(input.c_str(), "%d %c" ,  ptr_to_first_operator , ptr_to_second_operator) == 1){
           
          return *ptr_to_first_operator;
    }
    else{

        cout << Invalid_Input << endl; 
    }
    }
    while(1);
}