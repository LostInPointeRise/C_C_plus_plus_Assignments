#include "stdio.h"
#include "calculator.h"
#include "constants.h"

/**
 *  <int> <op> <int>” with +-
 *  
 *  as <op> and executes this calculation
 * 
 *  with only integer types (division will round au-tomatically).
 * 
 *  The program should run in a loop that is exited with a single ‘0’ in theinputline above.
 */


int main(int argc, char const *argv[])
{ 

    // we declare some kind of current application state 
    enum APPLICATION_STATES CURRENT_STATE;

    // we start the application at this point 
    CURRENT_STATE = RUNNING; 

    // main loop, execution is running till the user aborts the execution 

    do{

        CURRENT_STATE  = doCalculation(argc, argv);
    }
    while(CURRENT_STATE);
    
    return 0;
}

