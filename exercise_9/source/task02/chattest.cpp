//#include "chat.hpp"
//#include "chatbot.hpp"
#include "chatapplication.hpp"
#include "constants.hpp"

int main(int argc, char const *argv[])
{
    
    do{
        // main loop, execution is running till the user aborts the execution 
        ChatApplication::doChatting();
    }
    while(RUNNING);

    return 0;
}
