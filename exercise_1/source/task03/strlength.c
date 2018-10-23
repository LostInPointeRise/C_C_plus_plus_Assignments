#include "stdio.h"
#include "strlength.h"

 
int main(int argc, char const *argv[])
{ 

    if(checkParameterAmmount(argc)){

        printf("%d \n", checkEndOfUserInputByIntegerIndex(argv[1]));
        printf("%d \n", checkEndOfUserInputByPointerArithmetic(argv[1]));
    }
    return 0;
}
  