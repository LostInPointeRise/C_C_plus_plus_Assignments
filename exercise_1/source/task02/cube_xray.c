#include "cube_xray.h" 
#include "stdio.h"

void xray( void * ptr_cube, int width, int length, int height){

    // shall be at the coordinate cube[0][0][0]
    int * currentCubeElement = (int *) ptr_cube; 
   
    // index of the current Cube Element
    int currentCubeElementIndex = 0;

    // loop that iterates an iterator for the "width" axis
    for(int widthItr = 0; widthItr < width; widthItr += 1){

        // loop that iterates an iterator for the "length" axis
        for(int lengthItr = 0; lengthItr < length; lengthItr += 1){
                
            // loop that iterates an iterator for the "height" axis
            for(int heightItr = 0; heightItr < height; heightItr += 1){
 
                printf("currentCubeElement[%d][%d][%d] at %p , got the value %d \n", widthItr, lengthItr, heightItr, &currentCubeElement[currentCubeElementIndex], currentCubeElement[currentCubeElementIndex ] );
                currentCubeElementIndex +=1;
            }
        
        }
    
    }

}