#include "stdio.h"
#include "constants.h"
#include "calculator.h" 
 
void doCalculation( char const *argv[]){

    
    // at first print the usage 
    printf("%s ", USAGE);

    // after the user has put something... 

    // we read the parameter from the console
    char* expressionToSolve = readFromCommandLine();
   
    // and verify , if the number of parameter match the expected one
    if( checkParameterAmmount(expressionToSolve) == CORRECT){
   
        // now we try to verify, if the operator is truly an operator 
        if(checkIfOperatorMatchTheExpectedOnes(expressionToSolve) == CORRECT){
 
            // after the data is verified , we will start to solve the given expression
            solveExpression(expressionToSolve);
        }
        else{
            // if the operator symbol is wrong 
            // we will ask again for input   
        } 
    }
    else{
            // if the ammount of parameter is wrong, 
            // we will ask again for input
    }
     
}