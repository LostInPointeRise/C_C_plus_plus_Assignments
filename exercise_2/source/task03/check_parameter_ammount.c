#include "stdio.h" 
#include "stdlib.h"
#include "constants.h"
#include "calculator.h"

#define EXPECTED_AMMOUNT_OF_EXPRESSION_SYMBOLS 3 // program name, and the certain string
 
#define EXPECTED_AMMOUNT_OF_SHUTDOWN_SYMBOLS 1 // the ammout of corrreclty read parameter

#define EXPECTED_SHUTDOWN_SYMBOL '0' // the single sign '0'

#define SHUTDOWN_MESSAGE  "Goodbye"

enum  PARAMETER_STATES  checkParameterAmmount(char* expression){
  
    /**
     * variable and pointer declaration 
    */

    int first_operand = 42;   
    int *ptr_to_first_operand = &first_operand;
 
    char operator = 'o';
    char  *ptr_to_operator = &operator;

    char shutdown_symbol = 'x';
    char *ptr_to_shutdown_symbol = &shutdown_symbol;

    int second_operand = 42; 
    int *ptr_to_second_operand = &second_operand;

    int third_operand = 42; 
    int *ptr_to_third_operand = &third_operand;


    // becuase sscanf does not verify, if it could read more paams than expected, 
    // we have to ensure some way to detect, more parameters..

    // with the the third operand we can read a fourth parameter, and found a possibility 
    // to check if a user put more params than expected 
    int ammount_of_expression_parameters = sscanf(expression, "%d %c %d %s" ,  ptr_to_first_operand,  ptr_to_operator , ptr_to_second_operand, ptr_to_third_operand ); 
     
    // if the user just put 1 symbol...
     
    if(ammount_of_expression_parameters == EXPECTED_AMMOUNT_OF_SHUTDOWN_SYMBOLS){
    
        // we try to read  the input ...
        sscanf(expression, "%c" ,  ptr_to_shutdown_symbol ); 
     
        // and validate its current state 
        if(*ptr_to_shutdown_symbol == EXPECTED_SHUTDOWN_SYMBOL){

            printf("%s\n" , SHUTDOWN_MESSAGE);
            exit(0);
        }
 
        printf("%s\n", INVALID_INPUT);
        return NOTCORRECT; 
    }
    else if(ammount_of_expression_parameters == EXPECTED_AMMOUNT_OF_EXPRESSION_SYMBOLS){
    
        return CORRECT; 
    } 
    else{

        printf("%s\n", INVALID_INPUT );
        return NOTCORRECT; 
    }

}