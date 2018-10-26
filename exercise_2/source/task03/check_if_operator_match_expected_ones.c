#include "stdio.h" 
#include "constants.h"
#include "calculator.h"

enum  PARAMETER_STATES  checkIfOperatorMatchTheExpectedOnes(char* expression){

    int first_operand = 42;   
    int *ptr_to_first_operand = &first_operand;
 
    char operator = 'o';
    char  *ptr_to_operator = &operator;

    int second_operand = 42; 
    int *ptr_to_second_operand = &second_operand;

    // we read the expression and check, if we can put it in the needed format <int> <op> <int>

    sscanf(expression, EXPECTEDINPUT ,  ptr_to_first_operand,  ptr_to_operator, ptr_to_second_operand ); 
      
    // here we do validate the operator symbol 

    if((*ptr_to_operator == '/') || (*ptr_to_operator == '*') || (*ptr_to_operator == '-') || (*ptr_to_operator == '+') ){

        return CORRECT; 
    }
    else {
 
        printf("%s\n", INVALID_INPUT);
        return NOTCORRECT;
    }
}