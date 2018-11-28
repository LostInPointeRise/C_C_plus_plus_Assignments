#include <iostream>

// Declaration of class MyTime.
// Member functions are defined in stack.cpp
#ifndef STACK_H
#define STACK_H
// Stack abstract data type definition

class MyTime{

private: 

    // @brief hour part of the time
    int hour; 

    // @brief minute part of the time
    int minute;

    // @brief second part of the time
    int second; 

public:
  
    /**
     * @brief constructor of the MyTime class
     * 
     * @param (int) hour of the time
     * @param (int) minute of the time
     * @param (int) second of the time
    */

    MyTime(int hour = 0, int minute = 0, int second = 0);


    /**
     * Overloading Type Cast operator
     * 
     * @brief a cast to int, shall return the seconds from 0:0:0 to the current 
     * time 
     */
    
    operator int(); 

    /**
     * @brief Overload the '<<' operator
     */

    friend std::ostream& operator<<(std::ostream& os, const MyTime& time); 

    /**
     * @brief destructor of the MyTime class
    */

    ~MyTime();
 
    /**
     * The methods getHour(), getMinute() 
     * and getSecond() return the hour, 
     * mi- nute and second of a MyTime object as int.
    */

    /**
     * @brief method, that shall form any time date, to a valid time ,
     * if the params are incorrect 
     * 
     * @param (int) hour of the time
     * @param (int) minute of the time
     * @param (int) second of the time
    */

    void adjustTime(int hour, int minute , int second );


    // getter setter 

    /**
     * @brief method to return the current hour
     */
    int getHour();

    /**
     * @brief method to return the current minute
     */
    int getMinute();

    /**
     * @brief method to return the current second
     */
    int getSecond();

}; // end of class MyTime
#endif