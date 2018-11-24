#include <cstring>
#include <stdio.h>
#include <iostream>
#include "stack.hpp"

using namespace std;

/**
 * @brief implementation of Stack(int size = 10), constrcutor
 */

Stack::Stack(int size){

    // we must save the needed capacity of the stack for further use
    
    this->size = size; 

    printf("Ctor: I am allocating space for %d integers\n", this->size);

    this->ptr_to_top = this->ptr_to_stack = new int[this->size];

};

/**
 * @brief implementation of copy constructor 
 */

Stack::Stack(const Stack &other){

    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size;

    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_stack  = new int[this->size];
    
    this->ptr_to_top = this->ptr_to_stack;

    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    this->ptr_to_top += other.length();

    printf("Cctor called \n");
};


/**
 * @brief move constructor of the Stack class 
 */

Stack::Stack(Stack &&other){

    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size;
 
    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_stack  = new int[this->size];
    
    this->ptr_to_top = this->ptr_to_stack;

    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    this->ptr_to_top += other.length();
 
    other.size = 10; 

    other.ptr_to_stack = other.ptr_to_top = new int[this->size];

    printf("Mctor called \n");
};


/**
 * @brief implementation of copy assignment operator
 */

Stack& Stack::operator=(Stack &other){

    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size;

    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_stack  = new int[this->size];
    
    this->ptr_to_top = this->ptr_to_stack;

    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    this->ptr_to_top += other.length();

    printf("Cop= called\n");

    return *this;
}


/**
 * @brief implementation of move assignment operator
 */

Stack& Stack::operator=(Stack &&other){

   
    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size;

    delete[] this->ptr_to_stack;

    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_stack  = new int[this->size];
    
    this->ptr_to_top = this->ptr_to_stack;

    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    this->ptr_to_top += other.length();
  
    other.size = 10; 

    other.ptr_to_stack = other.ptr_to_top = new int[this->size];

    printf("Mop= called \n");

    return *this;
}


/**
 * @brief implementation of the destructor 
 */

Stack::~Stack(){
    delete[] this->ptr_to_stack;
    printf("Dtor: I am deallocating a stack of %d integers filled with %d values.\n", this->size, this->length());
}

/**
 * @brief implementation of the is_full() function
*/

bool Stack::is_full(){

    return (this->length() == this->size) ? true : false; 
}
 
/**
 * @brief implementation of the function push(int)
 * */

void Stack::push(int element){

    if(this->length() < this->size){

      // then we will point to the new reallocated stack

      *this->ptr_to_top = element;   

       /* 
      *  we need to increase the pointer , to the top element of the tack, 
      * to point to the freshly inserted element
      */

      this->ptr_to_top++;

    }

    else{
        
        cout<< "The stack is full \n" <<endl; 
    }
}

int Stack::pop(){

    if(this->length() > 0){

      // we save the element, that will be popped off, for further use

      const int popped_element = this->ptr_to_stack[this->length() - 1]; 
    
     /* 
      *  we need to decrease the pointer , to the top element of the tack, 
      * to point to the new top of element
      */
  
      this->ptr_to_top--;  

      return popped_element;
    }

    else{
        
        cout<< "The stack is empty \n" <<endl;

        return 0; 
    }
}



/**
 * @brief implementation of the is_full() function
*/

bool Stack::is_empty(){

    return (this->length() == 0) ? true : false; 
}

/**
 * @brief implementation of the length() function
 */

int Stack::length() const{

    /**
     * 
     * we get the currently safed elements, 
     * while we substract the adress of the top element of the 
     * stack from the "pointer" to the stack 
     * 
     * The result will be a multiple of sizeof(int), so we get the number of elements 
    */ 

    return  this->ptr_to_top - this->ptr_to_stack ;
}

int Stack::capacity() const{

    return this->size;
}

void Stack::show() const{

    for(int ctr = 0; ctr < this->length(); ctr += 1){
 
        printf("%d ", this->ptr_to_stack[ctr]); 
    }

    printf("\n"); 
}