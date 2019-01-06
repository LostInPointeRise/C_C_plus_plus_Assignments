#include <iostream> 
#include <string.h>
 

class BotCommand; 

#ifndef MESSAGECONTAINER
#define MESSAGECONTAINER
 
 
// Declaration of class MessageContainer.
// Member functions are defined in MessageContainer.cpp
 
/**
 * @brief declaration of the MessageContainer 
*/
 

class MessageContainer{

private: 

    std::string message; 
  
public: 

    MessageContainer(std::string  _message);


    /**
     * @brief operator for BotCommand (Type) Casting
    */

    operator BotCommand() const;
 
}; // end of class MessageContainer 
#endif 
