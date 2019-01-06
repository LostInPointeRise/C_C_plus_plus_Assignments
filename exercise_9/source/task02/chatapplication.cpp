#include <iostream> 
#include <string>

#include "botfactory.hpp"
#include "botcommand.hpp" 
#include "chatapplication.hpp"
#include "messagecontainer.hpp"
 
using namespace std;

MessageContainer readFromCommandLine();

void ChatApplication::doChatting(){
 
    
     // we read the parameter from the console
    BotCommand botcommand =  static_cast<BotCommand>(readFromCommandLine());
 
    handleMessage(botcommand );
}

 
void ChatApplication::handleMessage(BotCommand _command){

    BotFactory::createBot(_command);
    
}



MessageContainer readFromCommandLine(){
  
     string input;

    // getline(cin, input); 
 
     return MessageContainer("bot:echo dustin");
}
  