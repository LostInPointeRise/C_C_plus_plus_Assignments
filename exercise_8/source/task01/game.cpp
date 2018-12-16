#include <iostream>
#include "game.hpp"
#include "constants.hpp"  
#include "stdlib.h" 
#include "stdio.h"

#define BUFFERSIZE 2

using namespace std;

void doGaming(){
 
    // print the "Choose Game Mode" Message
    cout << Choose_Game_Mode << endl;

    // print the "Human vs. Human Game Mode" Message
    cout << Human_vs_Human_Mode << endl;

    // print the "Human vs. Computer (Random) Game Mode" Message
    cout << Human_vs_Computer_Random_Mode << endl; 

    // print the "Exit Program" Message
    cout << EXIT_PROGRAM << endl; 

    // after the user has put something... 

    // we read the parameter from the console
    APPLICATION_STATES choosen_State =  static_cast<APPLICATION_STATES>(readFromCommandLine());
    
    switch(choosen_State) {

        case GAME_BETWEEN_HUMAN_AND_HUMAN : cout << "Not implemented yet" << endl;
             break; 
    
        case GAME_BETWEEN_HUMAN_AND_COMPUTER_RANDOM : cout << "Not implemented yet" << endl;
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

 