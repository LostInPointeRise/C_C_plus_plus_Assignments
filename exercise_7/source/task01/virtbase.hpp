#ifndef VIRTBASE_HPP
#define VIRTBASE_HPP

// Declaration of class VirstBase.
// Member functions are defined in virtbase.cpp
class VirtBase{
 

private: 

    /**
     * @brief describes a private member int variable  
     */

    int private_member_int_variable;

public: 
 
    /**
     * @brief Constructof of VirtBase 
    */
    VirtBase();

    /**
     * @brief describes the non-virtual function "nvFunc"
     * @return (void) 
    */
    void nvFunc();

    /**
     * @brief describes the virtual function "virtFunc"
     * @return (void) 
    */

    virtual void virtFunc(); 

}; // end of class PureBase 
#endif