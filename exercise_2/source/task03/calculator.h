 

#ifndef _calculator_h
#define _calculator_h

/**
 * 
 * Function that does the demanded calculation.
 * 
 * It shall except a single line input in form “<int> <op> <int>” with +- * /
 *  
 * as <op> and executes this calculation 
 * 
 * with only integer types (division will round au-tomatically).
 *  
 * @param: (char const *argv[]), the expression that forms a calculation request  
 * 
*/

 
void  doCalculation(  char const *argv[]);


/**
 * Function that checks, 
 * if the given operator, does match one of 
 * the expected ones ( + , / , - , *)
 * 
 * @param (char*), expression to check for the used operator 
 * @return (PARAMETER_STATES) , flag indicating if the certain operands are integers
*/

enum  PARAMETER_STATES  checkIfOperatorMatchTheExpectedOnes(char* expression);



/**
 * Function that checks 
 * if the ammount of given parameters, 
 * match the expected one
 * 
 * @param (char*), expression to check for its parameter ammount 
 * @return (PARAMETER_STATES), flag indicating if a certain expression seems to be correctly formed
*/

enum  PARAMETER_STATES checkParameterAmmount(char* expression);



/**
 * 
 * Function that finally solve 
 * the demanded expression 
 *  
 * @param (char*), expression to check for its parameter ammount 
 * 
*/

void solveExpression(char* expression);


/**
 * 
 * Function that reads from the command
 * line , and shall build the expression 
 * to solve 
 *  
 * @return (char*), pointer to the expression to solve
 * 
*/


char* readFromCommandLine(void);
 

#endif 
 