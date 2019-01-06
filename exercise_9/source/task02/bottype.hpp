#include <map>

using namespace std;

/**
 * enum indicating 
 * the type of any chatbot
 * 
*/

enum CHAT_BOT_TYPE {

    echo = 0, 
    counter = 1, 
    delay = 2, 
    prime = 3, 
    quiz = 4, 
    no_bot = 5
};


const map<string, CHAT_BOT_TYPE> CHAT_BOT_TYPE_MAPPING  =
{
    { "echo", CHAT_BOT_TYPE::echo},
    { "counter", CHAT_BOT_TYPE::counter},
    { "delay", CHAT_BOT_TYPE::delay},
    { "prime", CHAT_BOT_TYPE::prime},
    { "quiz", CHAT_BOT_TYPE::quiz}
}; 