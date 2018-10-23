
#ifndef _strlength_h
#define _strlength_h 

/** 
 * 
 * Function that shall calculate
 * the length of the certain user input 
 * by an integer index 
 * 
 * 
 * @param (int) cmdParamAmmount, ammout of command line parameters
 * @return (bool) flag indicating, if input is invalid 
 * 
*/



int checkParameterAmmount(int cmdParamAmmount);


/**
 * 
 * Function that shall calculate 
 * the length of the certain user input 
 * by an integer index 
 * 
 * 
 * @param (const char *) userInput
 * @return (int) length of user input
 * 
*/

int checkEndOfUserInputByIntegerIndex(const char *argv);


/**
 * 
 * Function that shall calculate
 * the length of the certain user input 
 * by pointer arithmetic 
 * 
 * 
 * @param (const char *) userInput
 * @return (int) length of user input
 * 
 */

int  checkEndOfUserInputByPointerArithmetic(const char *userInput);

#endif