#include "stdio.h" 
#include "constants.h"
#include "calculator.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define BUFFERSIZE 10

char* readFromCommandLine(){

    /**
     * calloc let  us reserve memory. 
     * 
     * we receive a pointer to some memory 
     * with the size (BUFFERSIZE *  sizeof(char)), 
     * the ammount of memory needed to 
     * store a certain character 
     * 
    */

    char *expression  = calloc(BUFFERSIZE  , sizeof(char));
   
    // buffer that teporatily stores read characters 
    char buffer[BUFFERSIZE]; 

    /**
     * We cannot obtain the end of some 
     * user input , cuase we do not know its fully size ... 
     * 
     * fgets , puts the '\0' at the end of the read string.... 
     * 
     * so if we check for some '\0', at the end of the read buffer, 
     * we can assert the end of the user input 
    */
    while( fgets(buffer, BUFFERSIZE , stdin)[BUFFERSIZE - 1] != '\0') 
    {
        // we resize the length of the final expression, to the 
        // ammount of read characters, so it can fit the command line input 
        expression = realloc( expression, strlen(expression)+strlen(buffer) );
        
        strncat( expression, buffer, BUFFERSIZE);   
        fflush(stdin);
    } 

      printf("expression is %s \n", buffer);
    return expression;
}