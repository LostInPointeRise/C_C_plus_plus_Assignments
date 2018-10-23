#include "cube_xray.h" 
#include "stdio.h"
 
int sum2nd(int * ptr_cube, int width, int length, int height){

    // "distance" on the memory mapping of the second column
 
    int delimeter = height; 

    int ammount_of_all_elements = width * length * height; 

    // we are adressing the elements at , [index0][index1][1]

    const int ptr_to_the_element_of_the_second_columns = 1; 

    int sum_of_all_second_columns = 0; 

    for(int ptr = ptr_to_the_element_of_the_second_columns; ptr < ammount_of_all_elements; ptr += delimeter  ){

        sum_of_all_second_columns += ptr_cube[ptr];
    }
 
    return sum_of_all_second_columns; 

} 