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

    do{

        // main loop, execution is running till the user aborts the execution 
        doCalculation(argv);
    }
    while(RUNNING);
    
    return 0;
}

