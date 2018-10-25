#include "stdio.h" 
#include "constants.h"
#include "calculator.h"

#define INVALID_INPUT "invalid input"

#define EXPECTED_AMMOUNT_OF_EXPRESSION_SYMBOLS 3 // program name, and the certain string
 
#define EXPECTED_AMMOUNT_OF_SHUTDOWN_SYMBOLS 1 // the single sign '0'


  
enum  PARAMETER_STATES  checkParameterAmmount(int cmdParamAmmount){
  
    if(cmdParamAmmount == EXPECTED_AMMOUNT_OF_SHUTDOWN_SYMBOLS){

        return CORRECT; 
    }
    else if(cmdParamAmmount == EXPECTED_AMMOUNT_OF_EXPRESSION_SYMBOLS){

        return CORRECT; 
    } 
    else{

        printf("%s\n", INVALID_INPUT);
        return NOTCORRECT; 
    }

}