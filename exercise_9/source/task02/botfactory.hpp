
class BotCommand;
class ChatBot;

#ifndef BOTFACTORY_HPP
#define BOTFACTORY_HPP
 
// Declaration of class BotFactory.
// Member functions are defined in BotFactory.cpp

/**
 * @brief declaration of the BotFactory 
*/
 
class BotFactory{

public: 

    /**
     * @brief method that publishes the message from a user to the cha bots 
    */

    static ChatBot createBot(BotCommand _command);
 
}; // end of class BotFactory 
#endif 
