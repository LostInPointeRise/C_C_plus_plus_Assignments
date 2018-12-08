#include <iostream>
#include <typeinfo>
#include "purebase.hpp" 

PureBase::PureBase(){}

void PureBase::myFunc(){

    // incrementing private_member_int_variable
    this->private_member_int_variable++;

    #ifdef VERBOSE
          std::cout << "Called " << typeid(*this).name() << "::"
          << __func__ << std::endl;
    #endif
}

