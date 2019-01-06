#include <iostream> 
#include <string.h>
#include "bottype.hpp"

using namespace std; 
 

#ifndef BOTCOMMAND_HPP
#define BOTCOMMAND_HPP
 
 
// Declaration of class BotCommand.
// Member functions are defined in BotCommand.cpp
 
/**
 * @brief declaration of the BotCommand 
*/
 

class BotCommand{

public: 

    string message; 

    CHAT_BOT_TYPE bot_type;

    string bot_name;  

    BotCommand();
 
 
}; // end of class BotCommand 
#endif 
