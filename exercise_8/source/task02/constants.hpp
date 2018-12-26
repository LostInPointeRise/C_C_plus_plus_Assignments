
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

static char const Human_vs_Computer_Random_Mode[] = "(3) Human vs. Computer (Random)";

/* 
 * @brief "Human vs. Computer (Minimax) Game Mode" Message
 */

static char const Human_vs_Computer_Minimax_Mode[] = "(2) Human vs. Computer (Minimax)";


/* 
 * @brief "Human vs. Computer (Minimax) Game Mode" Message
 */

static char const Computer_Minimax_Mode_vs_Computer_Minimax_Mode[] = "(4) Computer (Minimax) vs. Computer (Minimax)";


/* 
 * @brief "Exit Program" Message
 */

static char const EXIT_PROGRAM[] = "(5) Exit Program";

/* 
 * @brief "Exit Program" Message
 */

static char const Invalid_Input[] = "Invalid Input";

/* 
 * @brief "Invalid field selection" Message
 */

static char const Invalid_Field_Selection[] = "Invalid field selection";


/* 
 * @brief "Draw Code", integer needed to indicate, that no player won the matchj
 */

static int const DRAW_CODE = 0;

/**
 * enum indicating 
 * the state of the application
 * 
*/

enum APPLICATION_STATES {

    RUNNING = 0, 
    GAME_BETWEEN_HUMAN_AND_HUMAN = 1, 
    GAME_BETWEEN_HUMAN_AND_COMPUTER_MINIMAX = 2,
    GAME_BETWEEN_HUMAN_AND_COMPUTER_RANDOM = 3, 
    GAME_BETWEEN_COMPUTER_MINIMAX_AND_BETWEEN_COMPUTER_MINIMAX = 4,
    EXIT = 5, 
    INVALID_INPUT = 42
};


/**
 * enum indicating 
 * the kind of computer player
*/

enum PLAYER {

    MAX = 0, 
    MIN = 1
};


