#include <string>
#include <iostream>


using namespace std; 
 

class Chat;

#ifndef CHATBOT_HPP
#define CHATBOT_HPP
 
// Declaration of class ChatBot.
// Member functions are defined in ChatBot.cpp

/**
 * @brief declaration of the ChatBot Template
 * @param (class) Type of the elements that should be buffered 
 * @param (int) size of the ChatBot 
*/
 
class ChatBot{

private:



protected:

    string name;

    Chat* chat; 

public: 

    /**
     * @brief method that publishes the message from a user to the cha bots 
    */

    void publishMessage(string sender, string msg);

    /**
     * @brief method that terminates all bots in the ChatBot
    */
    void terminateAllBots();
}; // end of class ChatBot 
#endif 
