#include <string>
#include <iostream>
#include <vector> 
#include <mutex>

#include "chatbot.hpp"

using namespace std; 
 

#ifndef CHAT_HPP
#define CHAT_HPP
 
// Declaration of class Chat.
// Member functions are defined in Chat.cpp

/**
 * @brief declaration of the Chat Template
 * @param (class) Type of the elements that should be buffered 
 * @param (int) size of the Chat 
*/
 
class Chat{

private:

    /**
     * @brief structure that keeps the ChatBots of the Chat
    */

    vector<ChatBot*> botKeeper; 

    /**
     * @brief mutex for the chat bots
    */

    mutex chatMtx;

public: 

    /**
     * @brief method that adds a any ChatBot to the Chat
     * @param (ChatBot*) pointer to a ChatBot
    */

    void addBot(ChatBot* bot);


    /**
     * @brief method that publishes the message from a user to the cha bots 
    */

    void publishMessage(string sender, string msg);

    /**
     * @brief method that terminates all bots in the Chat
    */
    void terminateAllBots();
}; // end of class Chat 
#endif 
