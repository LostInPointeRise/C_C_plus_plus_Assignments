#include "stdio.h"
#include "strlength.h" 
#define WRONG_INPUT "wrong input"

#define EXPECTED_AMMOUNT 2 // program name, and the certain string
 

int checkParameterAmmount(int cmdParamAmmount){

    if(cmdParamAmmount == EXPECTED_AMMOUNT){

        return 1;
    }
    else{

        printf("%s \n", WRONG_INPUT);
        return 0;
    }

}