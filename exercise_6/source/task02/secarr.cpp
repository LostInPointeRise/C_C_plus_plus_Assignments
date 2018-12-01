#include <iostream>
#include <stdlib.h>
#include "secarr.hpp"

using namespace std;


SecArr::SecArr(const SecArr &other){

    this->first_element = other.first_element;

    this->last_element = other.last_element;

    this->current_element = other.current_element;
}
 
SecArr::SecArr(int *ptr_to_first_element, int *ptr_to_last_element){
 
    
    /**
     * 
     * we get the locations, where in memory, shall be the edges 
     * of some locations, that shall be stored / managed by this class. 
     * 
     * To ensure, we will not be tricked by faulty ndexes
     * we must check, if the indexes are correclty assigned. 
     * 
     * If they are not correctly assigned, then the ptr_to_last_element, 
     * is located in memory before ptr_to_first_element. 
     * 
     * Therefore ptr_to_last_element must be stored in a higher memory location, than 
     * ptr_to_first_element. 
     * 
     * If we substract these values , we will get a multiply of sizeof(int). 
     * 
     * Especially a negative multiply, if ptr_to_first_element is located after ptr_to_last_element. 
     * So we can try to identify a negative value, to enusre the values are faulty
    */ 

    if(ptr_to_last_element - ptr_to_first_element < 0){

        cout << "WARNING: Pointer to last element , is before the first element\n" << "The pointer to the last element, will show to the first one\n" << endl;

        // if the values are invalid, we will store the value of ptr_to_first_element, ton both pointer 
        this->first_element = this->last_element = ptr_to_first_element;
    }
    else{

        // if the values are valued, we will simply copy them

        this->first_element = ptr_to_first_element;

        this->last_element = ptr_to_last_element;
    }

    // finally we need to enusre the current , and only elment, is pointing to 
    // the first one 

    this->current_element = this->first_element; 
}

SecArr SecArr::operator++(){

    // we create a temp copy of the current element 
    int *temp_ptr = this->current_element; 

    // we will do the pre increment 
    ++temp_ptr;

    // we will check if the updated pointer address is valid
    if(this->check_boundaries(temp_ptr)){

        // we will do the post increment on the original pointer to the current_element
        ++this->current_element;
    }

    return *this;    
}


SecArr SecArr::operator++(int){

    // we create a temp copy of the current element 
    int *temp_ptr = this->current_element; 

    // we will do the post increment 
    temp_ptr++;
 
    // we will check if the updated pointer address is valid
    if(this->check_boundaries(temp_ptr)){

        SecArr post_incremented_SecArr(*this);

         // we will do the post increment on the original pointer to the current_element
        this->current_element = temp_ptr;

        return post_incremented_SecArr;
    }
    else{

        return *this;
    }
}

SecArr SecArr::operator--(){

    // we create a temp copy of the current element 
    int *temp_ptr = this->current_element; 

    // we will do the pre increment 
    --temp_ptr;

    // we will check if the updated pointer address is valid
    if(this->check_boundaries(temp_ptr)){

        // we will do the pre increment on the original pointer to the current_element
        --this->current_element;
    }

    return *this;    
}
 
SecArr SecArr::operator--(int){

    // we create a temp copy of the current element 
    int *temp_ptr = this->current_element; 

    // we will do the pre increment 
    temp_ptr--;

    // we will check if the updated pointer address is valid
    if(this->check_boundaries(temp_ptr)){

        SecArr post_incremented_SecArr(*this);

         // we will do the post increment on the original pointer to the current_element
        this->current_element = temp_ptr;

        return post_incremented_SecArr;
    }   
    else{

        return *this;
    }
} 


int& SecArr::operator[] (int index){

    int *temp_ptr = this->current_element + index;

    /**
     * If the designated element would be out of the bounds defined in the constructor, 
     * it prints a warning “Inva- lid index” and returns the last element of the array 
     * in the direction of iteration
    */

    // we will check if the updated pointer address is valid
    if(this->check_boundaries(temp_ptr)){

        return *temp_ptr;
    }   
    else{

        int direction_to_last = abs(this->last_element - (this->first_element + index));

        int direction_to_first = abs(this->first_element - (this->first_element + index));

        return !(direction_to_last > direction_to_first) ? *this->last_element : *this->first_element;
    }
}

int& SecArr::operator * (){

    return *this->current_element;
}

bool SecArr::check_boundaries(int *ptr_to_check){

    if(this->last_element - ptr_to_check < 0){

        // if the last element is before a certain pointer
        cout << "Invalid index" << endl;
        return false; 
    }
    else if (ptr_to_check - this->first_element < 0){

        // if the first element is behind a certain pointer
        cout << "Invalid index" << endl;
        return false; 
    }
    else{
        // the index is in the boundaries 
        return true; 
    }
}