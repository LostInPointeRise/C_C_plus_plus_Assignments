#include "stdio.h"  
#include "calculator.h"
#include "constants.h" 

void solveExpression(char* expression){

    // we declare the final result 
    int result = 42; 


    /**
     * variable and pointer declaration 
    */

    int first_operand = 42;   
    int *ptr_to_first_operand = &first_operand;
 
    char operator = 'o';
    char  *ptr_to_operator = &operator;
 
    int second_operand = 42; 
    int *ptr_to_second_operand = &second_operand;

    // we read the given input and try to recognize the given parameter 

    sscanf(expression, EXPECTEDINPUT ,  ptr_to_first_operand,  ptr_to_operator , ptr_to_second_operand ); 
      

    /**
     * We determine the 
     * demanded operator, 
     * to calculate the correct solution
    */

    if(*ptr_to_operator == '+'){
        
        result = *ptr_to_first_operand + *ptr_to_second_operand; 

        // finally we print the operation to the user 
        printf("%d %c %d = %d \n", *ptr_to_first_operand, *ptr_to_operator, *ptr_to_second_operand, result);
    }
    else if(*ptr_to_operator == '-'){
       
        result = *ptr_to_first_operand - *ptr_to_second_operand;
        // finally we print the operation to the user 
        printf("%d %c %d = %d \n", *ptr_to_first_operand, *ptr_to_operator, *ptr_to_second_operand, result);
    }
    else if(*ptr_to_operator == '*'){
      
        result = (*ptr_to_first_operand) * (*ptr_to_second_operand);
        // finally we print the operation to the user 
        printf("%d %c %d = %d \n", *ptr_to_first_operand, *ptr_to_operator, *ptr_to_second_operand, result);
    }
    else if(*ptr_to_operator == '/'){
       
        if(*ptr_to_second_operand != 0){

             result = *ptr_to_first_operand / *ptr_to_second_operand;
             // finally we print the operation to the user 
             printf("%d %c %d = %d \n", *ptr_to_first_operand, *ptr_to_operator, *ptr_to_second_operand, result);
        }
        else{

            printf("%s\n", INVALID_INPUT );
        }

    }
} 