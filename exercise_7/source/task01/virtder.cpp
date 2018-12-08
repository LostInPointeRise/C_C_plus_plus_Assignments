#include <iostream>
#include <typeinfo>
#include "virtder.hpp"

VirtDer::VirtDer(){}

void VirtDer::myFunc(){

 
    // incrementing private_member_int_variable
    this->private_member_int_variable++;

    #ifdef VERBOSE
          std::cout << "Called " << typeid(*this).name() << "::"
          << __func__ << std::endl;
    #endif
}

void VirtDer::virtFunc(){


    // incrementing private_member_int_variable
    this->private_member_int_variable++;

    #ifdef VERBOSE
          std::cout << "Called " << typeid(*this).name() << "::"
          << __func__ << std::endl;
    #endif
}