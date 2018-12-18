
/*  
 * @brief "Choose Game Mode" Message
 */
 
static char const Choose_Game_Mode[] =  "Choose your game mode.";

/* 
 * @brief "Human vs. Human Game Mode" Message
 */

static char const Human_vs_Human_Mode[] = "(1) Human vs. Human";

/* 
 * @brief "Human vs. Computer (Random) Game Mode" Message
 */

static char const Human_vs_Computer_Random_Mode[] = "(2) Human vs. Computer (Random)";

/* 
 * @brief "Exit Program" Message
 */

static char const EXIT_PROGRAM[] = "(3) Exit Program";

/* 
 * @brief "Exit Program" Message
 */

static char const Invalid_Input[] = "Invalid Input";

/* 
 * @brief "Invalid field selection" Message
 */

static char const Invalid_Field_Selection[] = "Invalid field selection";



/**
 * enum indicating 
 * the state of the application
 * 
*/

enum APPLICATION_STATES {

    RUNNING = 0, 
    GAME_BETWEEN_HUMAN_AND_HUMAN = 1, 
    GAME_BETWEEN_HUMAN_AND_COMPUTER_RANDOM = 2, 
    EXIT = 3, 
    INVALID_INPUT = 42
};


