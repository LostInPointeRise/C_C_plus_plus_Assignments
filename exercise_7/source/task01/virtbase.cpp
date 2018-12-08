#include <iostream>
#include <typeinfo>
#include "virtbase.hpp"

VirtBase::VirtBase(){}
 
/**
 * @brief definition of nvFunc()
*/
 
void VirtBase::nvFunc(){

     // incrementing private_member_int_variable
    this->private_member_int_variable++;

    #ifdef VERBOSE
          std::cout << "Called " << typeid(*this).name() << "::"
          << __func__ << std::endl;
    #endif
} 

/**
 * @brief definition of virtFunc()
*/


void VirtBase::virtFunc(){

     // incrementing private_member_int_variable
    this->private_member_int_variable++;

    #ifdef VERBOSE
          std::cout << "Called " << typeid(*this).name() << "::"
          << __func__ << std::endl;
    #endif
}