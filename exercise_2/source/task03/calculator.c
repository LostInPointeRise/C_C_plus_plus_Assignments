#include "stdio.h"
#include "constants.h"
#include "calculator.h" 

const char USAGE[] = "Enter <int> <op> <int>, single '0' to exit:";

const char EXPECTEDINPUT[] = "%d %c %d"; 
 
int doCalculation(int argc, char const *argv[]){

    int first_operand = 42;   
    int *ptr_to_first_operand = &first_operand;
 
    char operator = 'o';
    char  *ptr_to_operator = &operator;

    int second_operand = 42; 
    int *ptr_to_second_operand = &second_operand;

    // at first print tbe usage 
    printf("%s ", USAGE);

    // after the user has put something... 

    // we read the parameter from the console
    char* expressionToSolve = readFromCommandLine();

 
   /*   int ammount_of_expression_parameters = sscanf("%d %c %d" , expressionToSolve, ptr_to_first_operand,  ptr_to_operator , ptr_to_second_operand ); 
    
    // and verify , if the number of parameter match the expected one
    if( checkParameterAmmount(ammount_of_expression_parameters) == CORRECT){
 
        // now we try to verify, if the operator is truly an operator 
        if(checkIfOperatorMatchTheExpectedOnes(*ptr_to_operator)){
 
            solveExpression(*ptr_to_first_operand,  *ptr_to_operator , *ptr_to_second_operand);
        }
        else{
                // if not return false   
                return 0; 
        } 
    }
    else{
            // if not return false   
           return 0; 
    }
    */

    return 0;
}