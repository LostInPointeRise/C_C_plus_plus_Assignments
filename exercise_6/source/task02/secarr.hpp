  
// Declaration of class SecArr.
// Member functions are defined in SecArr.cpp
#ifndef SECARR_H
#define SECARR_H
// SecArr abstract data type definition
class SecArr {

private:

    // @brief pointer to the first element in the class 
    int *first_element; 

    // @breif pointer to the last element in the class
    int *last_element;

    // @brief pointer to the current elmenet
    int *current_element; 

public:

    /**
     * @brief copy constructor of SecArr Class 
    */

    SecArr(const SecArr &other);



    /**
     * @brief constructor of SecArr Class 
     * @param (int*) ptr_to_first_element
     * @param (int*) ptr_to_last_element
    */

    SecArr(int *ptr_to_first_element, int *ptr_to_last_element);


    /**
     * @brief function that checks if a certain pointer is between a specific boundary
     * @param (int *) ptr_to_check
     * @return (bool) flag indicating, if the pointer is between the first and last element
    */
    bool check_boundaries(int *ptr_to_check);

    //@brief overload of the '++' pre form 
    SecArr operator++ ();

    //@brief overload of the '++' post form 
    SecArr operator++ (int);

    //@brief overload of the '--' pre form 
    SecArr operator-- ();

    //@brief overload of the '--' post form 
    SecArr operator-- (int);

    /*
     * @brief overload of the brackets operator 
     * @param (int) index
     * @return (int) the element at the certain index
     */
    int& operator[] (int index);
  
    /*
     * @brief overload of the brackets operator 
     * @return (int&) reference from the certain array
     */
    int& operator * ();
 

}; // end class SecArr
#endif