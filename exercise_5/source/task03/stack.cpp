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

    //printf("Ctor: I am allocating space for %d integers\n", this->size);

    // when we allocate the memory, top and base ptr, point to the same address
    this->ptr_to_top = this->ptr_to_stack = new int[this->size];

    // we initalize a seed value needed for the random values
    this->seed = rand();
};

/**
 * @brief implementation of copy constructor 
 */

Stack::Stack(const Stack &other){

    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size;

    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_top = this->ptr_to_stack = new int[this->size];
    
    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    // after we reallocate the memory, we have to let the top, of the new stack
    // show to the correct place
    this->ptr_to_top += other.length();

    // we add the seed, from the moved object
    this->seed = other.seed;

    //printf("Cctor called \n");
};


/**
 * @brief move constructor of the Stack class 
 */

Stack::Stack(Stack &&other){
 
    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size; 

    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_top = this->ptr_to_stack = new int[this->size];

    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    this->ptr_to_top += other.length();
 
    this->seed = other.seed;

    delete[] other.ptr_to_stack;

    // we put the default values to the moved object
    other.size = 10; 

    other.ptr_to_stack = other.ptr_to_top = nullptr;

    other.seed = rand(); 

    //printf("Mctor called \n");
};


/**
 * @brief implementation of copy assignment operator
 */

Stack& Stack::operator=(Stack const  &other){

    delete[] this->ptr_to_stack;

    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size;

    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_top = this->ptr_to_stack  = new int[this->size];

    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    // after we reallocate the memory, we have to let the top, of the new stack
    // show to the correct place
    this->ptr_to_top += other.length();

    this->seed = other.seed;

    //printf("Cop= called\n");

    return *this;
}


/**
 * @brief implementation of move assignment operator
 */

Stack& Stack::operator=(Stack &&other){

    delete[] this->ptr_to_stack;

    // we must save the size of the capacity, from the other Stack, to the callee stack 
    this->size = other.size;

    // we must allocate some new memory, to store the values, thsat will be copied from other 
    this->ptr_to_top = this->ptr_to_stack  = new int[this->size];
    
    // then we will copy the values from  the other stack on our current stack
    memcpy(this->ptr_to_stack, other.ptr_to_stack, other.length() * sizeof(int));
 
    this->ptr_to_top += other.length();
  
    this->seed = other.seed;

    // we deallocate memory, that is not needed anymore 
    delete[] other.ptr_to_stack;

    // we put the default values to the moved object 
    other.size = 10; 

    other.ptr_to_stack = other.ptr_to_top = nullptr;

    // we need to initialize a new seed 
    other.seed = rand(); 

    //printf("Mop= called \n");

    return *this;
}


/**
 * @brief implementation of the destructor 
 */

Stack::~Stack(){
    // we deallocate memory, that is not needed anymore 
    delete[] this->ptr_to_stack;
    //printf("Dtor: I am deallocating a stack of %d integers filled with %d values.\n", this->size, this->length());
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

void Stack::load(){

    // now we will ceate the Random Numbers , that shall fill the stack
    this->createRandomNumbers();
    
    // we need to let the top pointer, point to the top of the stack
    this->ptr_to_top += this->size;
}


void Stack::createRandomNumbers()
{
    for(int ctr = 0; ctr < this->size ; ctr +=1){
     
        /**
         * default PRNG Generator, implemented from 
         * https://de.wikipedia.org/wiki/Xorshift
        */

        int current_seed = this->seed;
        
        current_seed ^= (current_seed  << 13);
        current_seed ^= (current_seed  >> 17);
        current_seed ^= (current_seed  << 5);

        current_seed ^= (current_seed  << 3);

        // after the current seed is calculated, it must be put on to the stack
        this->ptr_to_stack[ctr] =  this->seed = current_seed;
    } 
}
