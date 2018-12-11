#ifndef VIRTDER_HPP
#define VIRTDER_HPP
 
#include "virtbase.hpp"

// Declaration of class VirstBase.
// Member functions are defined in virtbase.cpp
class VirtDer: public VirtBase {

 
private: 
 
    /**
     * @brief describes a private member int variable  
     */

    int private_member_int_variable;

public: 
 
    /**
     * @brief Constructof of VirtDer 
    */
    VirtDer();

    /**
     * @brief describes the non-virtual function "nvFunc"
     * @return (void) 
    */
    void myFunc();

    /**
     * @brief describes the virtual function "virtFunc"
     * @return (void) 
    */

    void virtFunc(); 

}; // end of class PureBase 
#endif