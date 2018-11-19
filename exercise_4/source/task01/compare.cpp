#include <stdio.h>
#include <cstdlib>
#include "compare.hpp"

using namespace std;

int maxf(int a, int b){

    printf("In maxf(int)\n");
    return ((a)>(b)?(a):(b));
};



double maxf(double a, double b){

    printf("In maxf(double)\n");
    /* its difficult to determine the correct size of two doubles
     * couse of the decimal, representaion. 
     * 
     * Instead of a simple comparison, we will substract 
     * the arguments with each other. 
     * 
     * If one argument , is bigger than the other, 
     * a substraction must return, one negative, and with switched 
     * operands, a substraction must return a positive value.  
    */



    const double difference_a_to_b = a - b; 

    const double difference_b_to_a = b - a; 

    // if a is bigger than b, difference_a_to_b, must be positive 

    // if a is bigger than b, difference_b_to_a, must be negative 

    if((difference_a_to_b * -1.0 < 0) && (difference_b_to_a * -1.0 > 0)){

        return a; 
    }

    // if b is bigger than a, difference_a_to_b, must be negative

    // if b is bigger than a, difference_b_to_a, must be positive 

    else if((difference_a_to_b * -1.0 > 0) && (difference_b_to_a * -1.0 < 0)){

        return b; 
    }


};