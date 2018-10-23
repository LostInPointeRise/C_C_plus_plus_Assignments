#include "stdio.h"


/**
 * 
 * Write a program that prints the sizes of all simple data types in the following order: 
 * char, 
 * short, 
 * int, 
 * long, 
 * long long, 
 * float, 
 * double, 
 * long double, 
 * pointer. 
 * 
 * First print the name, then its size.Beginning of example output:
 * 
 * 
*/

int main(int argc, char const *argv[])
{ 

    printf("char %lu\n", sizeof(char));

    printf("short %lu\n", sizeof(short));

    printf("int %lu\n", sizeof(int));

    printf("long %lu\n", sizeof(long));

    printf("long long %lu\n", sizeof(long long));

    printf("float %lu\n", sizeof(float));

    printf("double %lu\n", sizeof(double));

    printf("long double %lu\n", sizeof(long double));

    printf("pointer %lu\n", sizeof(void *));
 
    return 0;
}
