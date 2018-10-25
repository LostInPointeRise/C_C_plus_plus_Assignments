#include "stdio.h" 
#include "constants.h"
#include "calculator.h"
 
void solveExpression(int firstOperand,  char Operator , int secondOperand){

    // we declare the final result 
    int result = 42; 

    /**
     * We determine the 
     * demanded operator, 
     * to calculate the correct solution
    */

    if(Operator == '+'){
        
        result = firstOperand + secondOperand; 
    }
    else if(Operator == '-'){
       
        result = firstOperand - secondOperand;
    }
    else if(Operator == '*'){
      
        result = firstOperand * secondOperand;
    }
    else if(Operator == '/'){
       
        result = firstOperand / secondOperand;
    }

    // finall we print the operation to the user 
    printf("%d %c %d = %d \n", firstOperand, Operator , secondOperand, result);
} 