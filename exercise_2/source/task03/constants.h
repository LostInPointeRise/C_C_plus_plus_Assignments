
// invalid input message
static char const INVALID_INPUT[] =  "invalid input";

// usage message  
static char const USAGE[] = "Enter <int> <op> <int>, single '0' to exit:";

// format string , is used to correctly read inputs for the console 
static char const EXPECTEDINPUT[] = "%d %c %d"; 

 
/**
 * enum indicating 
 * the state of the application 
 * 
*/

enum APPLICATION_STATES {

    RUNNING = 1 
};

/**
 * enums that shall 
 * help to identify , if 
 * the given parameters
 * is correctly formed 
*/

enum PARAMETER_STATES {

    CORRECT = 1,
    NOTCORRECT = 0
};