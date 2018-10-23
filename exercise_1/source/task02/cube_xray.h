#ifndef _cube_xray_h
#define _cube_xray_h

/*
    Function that shall print the 
    adresses, of the element, and their values

    @param (void *) ptr_cube, ptr to a certain cube
    
    // Dimension of the certain cube 

    @param (int) width
    @param (int) length
    @param (int) height,
*/

void xray(void * ptr_cube, int width, int length, int height);


/**
 * 
 * Function that shall sum up, 
 * every element on the second column, 
 * so called second element of a certain
 * (sub) array
 * 
 * @param (int *) ptr_cube, ptr to a certain cube
 * 
 *  // Dimension of the certain cube 

    @param (int) width
    @param (int) length
    @param (int) height,
 * 
*/


int sum2nd(int * ptr_cube, int width, int length, int height);

#endif