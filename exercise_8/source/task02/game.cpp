#include <iostream>
#include <stdlib.h> 
#include "mode.hpp"
#include "game.hpp"
#include "humanplayer.hpp"
#include "computerplayer.hpp"
#include "gamemaster.hpp" 
#include "stdio.h"
 
#define BUFFERSIZE 2

using namespace std;

void doGaming(){
  
    // print the "Choose Game Mode" Message
    cout << Choose_Game_Mode << endl;

    // print the "Human vs. Human Game Mode" Message
    cout << Human_vs_Human_Mode << endl;

    // print the "Human vs. Computer (Random) Game Mode" Message
    cout << Human_vs_Computer_Minimax_Mode << endl; 

    // print the "Human vs. Computer (Minimax) Game Mode" Message
    cout << Human_vs_Computer_Random_Mode << endl; 

    // print the "Computer (Minimax) vs. Computer (Minimax)  Game Mode" Message
    cout << Computer_Minimax_Mode_vs_Computer_Minimax_Mode << endl; 

    // print the "Exit Program" Message
    cout << EXIT_PROGRAM << endl; 

    // after the user has put something... 

    // we read the parameter from the console
    APPLICATION_STATES choosen_State =  static_cast<APPLICATION_STATES>(readFromCommandLine());
    
    switch(choosen_State) {
 
        case GAME_BETWEEN_HUMAN_AND_HUMAN : startGameBetweenHumanAndHuman();
             break; 
    
        case GAME_BETWEEN_HUMAN_AND_COMPUTER_RANDOM : startGameBetweenHumanAndComputerRandom();
             break;

        case GAME_BETWEEN_HUMAN_AND_COMPUTER_MINIMAX : startGameBetweenHumanAndComputerMinimax();
             break;

        case GAME_BETWEEN_COMPUTER_MINIMAX_AND_BETWEEN_COMPUTER_MINIMAX : startGameBetweenComputerAndComputerMinimax();
               break;
        case EXIT :  exit(0);
             break;
             
        default:
                // acessed if a user did an invalid input
                cout << Invalid_Input << endl; 
                break;
    }     
}

int readFromCommandLine(){

     int ARGUMENT_ENCODED = INVALID_INPUT;

     string input;
     getline(cin, input); 

     /**
      * variable and pointer declaration 
     */

     int test = 42; 
     int *ptr_to_first_operand = &test;

     char test2 = 'o';
     char *ptr_to_second_operand = &test2;;

     /**
      * we use sscanf , cause it tries to match a given
      * pattern and return the number of arguments , that was matched 
      * 
      * If there is more or less than  "one single" integer, than the input is invalid.
      * 
      * We need to put a second operand , to give sscanf a possibility to 
      * track another argument.
     */
 

     if(1 == sscanf(input.c_str(), "%d %c" ,  ptr_to_first_operand, ptr_to_second_operand)){
           
          ARGUMENT_ENCODED =  *ptr_to_first_operand;
     }
     else{
          // if the user entered a character 
          ARGUMENT_ENCODED = 42; 
     }
   
     return ARGUMENT_ENCODED;
}
 
  
void startGameBetweenHumanAndHuman(){
 
     HumanPlayer player1(1); 
     HumanPlayer *ptr_to_player1 = &player1;

     HumanPlayer player2(2);
     HumanPlayer *ptr_to_player2 = &player2;

     GameBoard gameBoard(3); 

     GameMaster gameMaster; 

     gameMaster.setplayer1(ptr_to_player1);
     gameMaster.setplayer2(ptr_to_player2);
     gameMaster.setgameboard(gameBoard);

     gameMaster.start();
}

  
void startGameBetweenHumanAndComputerRandom(){

     HumanPlayer player1(1); 
     HumanPlayer *ptr_to_player1 = &player1;

     ComputerPlayer player2(2, Mode::RANDOM);
     ComputerPlayer *ptr_to_player2 = &player2;

     GameBoard gameBoard(3); 

     GameMaster gameMaster;

     gameMaster.setplayer1(ptr_to_player1);
     gameMaster.setplayer2(ptr_to_player2);
  
    
     gameMaster.setgameboard(gameBoard);

     gameMaster.start();
}

void startGameBetweenHumanAndComputerMinimax(){

     HumanPlayer player1(1); 
     HumanPlayer *ptr_to_player1 = &player1;

     ComputerPlayer player2(2, Mode::MINIMAX);
     ComputerPlayer *ptr_to_player2 = &player2;

     GameBoard gameBoard(3); 

     GameMaster gameMaster;

     gameMaster.setplayer1(ptr_to_player1);
     gameMaster.setplayer2(ptr_to_player2);
  
    
     gameMaster.setgameboard(gameBoard);

     gameMaster.start();
}

void startGameBetweenComputerAndComputerMinimax(){

     ComputerPlayer player1(2, Mode::MINIMAX);
     ComputerPlayer *ptr_to_player1 = &player1;

     ComputerPlayer player2(2, Mode::MINIMAX);
     ComputerPlayer *ptr_to_player2 = &player2;

     GameBoard gameBoard(3); 

     GameMaster gameMaster;

     gameMaster.setplayer1(ptr_to_player1);
     gameMaster.setplayer2(ptr_to_player2);
  
    
     gameMaster.setgameboard(gameBoard);

     gameMaster.start();
}