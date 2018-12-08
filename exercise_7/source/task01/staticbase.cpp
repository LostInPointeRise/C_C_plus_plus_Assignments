#include <iostream>
#include <typeinfo>
#include "staticbase.hpp"

int StaticBase::private_member_int_variable = 0; // now we define it

void StaticBase::myFunc(){
    // incrementing private_member_int_variable
    StaticBase::private_member_int_variable++;

    #ifdef VERBOSE
          std::cout << "Called " <<  "StaticBase" << "::"
          << __func__ << std::endl;
    #endif
}