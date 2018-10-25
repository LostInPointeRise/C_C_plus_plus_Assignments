#include "stdio.h" 
#include "constants.h"
#include "calculator.h"

enum  PARAMETER_STATES  checkIfOperatorMatchTheExpectedOnes(char Operator){

    if((Operator == '/') || (Operator == '*') || (Operator == '-') || (Operator == '+') ){

        return CORRECT; 
    }
    else {

        return NOTCORRECT;
    }
}