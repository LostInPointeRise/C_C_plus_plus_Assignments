
class BotCommand;

#ifndef CHATAPPLICATION_HPP
#define CHATAPPLICATION_HPP
 
// Declaration of class ChatApplication.
// Member functions are defined in chatapplication.cpp

/**
 * @brief declaration of the ChatApplication 
*/
 
class ChatApplication{

private: 

    static void handleMessage(BotCommand _command);

public: 

    /**
     * @brief method that publishes the message from a user to the cha bots 
    */

    static void doChatting();
 
}; // end of class chatapplication 
#endif 
