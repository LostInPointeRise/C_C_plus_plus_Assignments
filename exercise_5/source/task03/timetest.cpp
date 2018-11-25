#include <stdio.h>
#include <iostream>
#include "stopwatch.hpp"
#include "stack.hpp"
 
using namespace std;
  
StopWatch stopwatch;  

#define MOVE_ASSIGNMENT_TEST "Move assignment test";


#define COPY_ASSIGNMENT_TEST  \
    Stack stack(100000);  \
    stack.load();   \
    Stack stackCopiedByAssignmentOperator; \
    stackCopiedByAssignmentOperator = stack; \
 

#define MOVE_ASSIGNMENT_TEST  \
    Stack stack(100000);  \
    stack.load();   \
    Stack stackMovedByAssignmentOperator; \
    stackMovedByAssignmentOperator = static_cast<Stack&&>(stack); \

#define MEASURETIME(description, repetitions, instructions2test) \
        stopwatch.start();  \
        for(int ctr = 0; ctr < 10000; ctr += 1){ \
            instructions2test\
        }\
        printf("My computer requires %f seconds to execute %s %d times \n",  stopwatch.stop(), description, repetitions); \
 

int main(){
 
    MEASURETIME("Copy assignment test", 10000, COPY_ASSIGNMENT_TEST);
    MEASURETIME("Move assignment test", 10000, MOVE_ASSIGNMENT_TEST);
    return 0;  
}