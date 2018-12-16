#include "game.hpp"
#include "constants.hpp"

/** 
 * @brief main loop 
 * @inDetail  The program should run in a loop 
 *        that is exited with a single ‘5’ in the inputline
 */
 
 
int main()
{ 
    do{
        // main loop, execution is running till the user aborts the execution 
        doGaming();
    }
    while(!RUNNING);
    
    return 0;
}
