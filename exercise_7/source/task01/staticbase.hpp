#ifndef STATICBASE_HPP
#define STATICBASE_HPP

// Declaration of class MyTime.
// Member functions are defined in staticbase.cpp

class StaticBase{

public: 

    /**
     * @brief describes a private member int variable  
     */

    static int private_member_int_variable;

    /**
     * @brief describes the function "myFunc"
     * @return (void) 
     */

    static void  myFunc();


}; // end of class StaticBase 
#endif 
