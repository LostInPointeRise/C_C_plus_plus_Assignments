 

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
 * @param: (int), argc describes the number of command line arguments 
 * @param: (char const *argv[]), the expression that forms a calculation request 
 * @return: (int), flag that indicates if the calculation, shallbe continued
 * 
*/

 
int doCalculation(int argc, char const *argv[]);


/**
 * Function taht checks, 
 * if the given operator, does match one of 
 * the expected ones ( + , / , - , *)
 * 
 * @param (char),  operator to check 
 * 
 * @return (PARAMETER_STATES) , flag indicating if the certain operands are integers
*/

enum  PARAMETER_STATES  checkIfOperatorMatchTheExpectedOnes(char Operator);



/**
 * Function that checks 
 * if the ammount of given parameters, 
 * match the expected one
 * 
 * @param int cmdParamAmmount, ammount of read parameters
 * @return (PARAMETER_STATES), flag indicating if a certain expression seems to be correctly formed
*/

enum  PARAMETER_STATES checkParameterAmmount(int cmdParamAmmount);



/**
 * 
 * Function that finally solve 
 * the demanded expression 
 *  
 *  @param (int) firstOperand
 *  @param (char) Operator 
 *  @param (int) secondOperand
 * 
*/

void solveExpression(int firstOperand,  char Operator , int secondOperand);


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
 