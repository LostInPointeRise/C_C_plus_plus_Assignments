  
 
#ifndef GAME_HPP
#define GAME_HPP
 
/**
 * @brief function that starts the Gaming Application
 * @param (int) number of input variables 
 * @param (char const* []) arguments
*/ 
void doGaming();

/**
 * @brief function that reads the demanded game mode form the use
 * @param int amount of input arguments
 * @param (char const* []) input arguments
 * @return (char*), pointer to the expression to solve
*/
int readFromCommandLine();
 

#endif  // end of class Game
 