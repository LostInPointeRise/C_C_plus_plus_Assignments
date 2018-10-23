#include "strlength.h"
#include "stdio.h"


int checkEndOfUserInputByIntegerIndex(const char *userInput)
{
    // length counter
    int ctr = -1;

    do{
   
        ctr +=1;
    } 
    // loop will count every sign till the end, 
    // is reached
    while(!(userInput[ctr] == '\0'));
  
    return ctr;
} 


int checkEndOfUserInputByPointerArithmetic(const char *userInput)
{
    // init ptr to user input
    // printf("%s n", userInput);
    char* ptr = &((char*) userInput) [0]; 
    do{
   
        ptr++;
        
    } 
    // loop will count every sign till the end, 
    // is reached
    while(!( *ptr == '\0'));
 
    // we dtermine the length of the input with ponter arithmetic
    // we substract the init adress, from the adress of the "input-end".. 

    // the char pointer is 1 Byte long, so we do not need, to multiply to the difference
    int differenceInBytes = ( ((ptr)) - ((userInput))) * sizeof(char);

    return differenceInBytes;
}