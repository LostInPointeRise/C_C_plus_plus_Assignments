#include "messagecontainer.hpp"
#include "botcommand.hpp"
#include <stdlib.h> 


#define EXIT_MESSAGE  "exit"

const string BOT_MESSAGE_PREFIX  = "bot:";

using namespace std;



MessageContainer::MessageContainer(std::string _message){

    cout << _message << endl; 
    this->message  = _message;
} 

MessageContainer::operator BotCommand() const{ 
 
    /**
     * At first we check if the exit message was typed
    */

    if(message == EXIT_MESSAGE){

        exit(1);
    }
    else{

            /**
             * If not , we try to cast the command to any BotCommand
            */

            BotCommand botCommand;

            string message = this->message;

            char * ptr_to_parts = nullptr;

            const int prefix_pos = static_cast<int>( this->message.find( BOT_MESSAGE_PREFIX ) );
                  
               if( prefix_pos >  -1){

                     
                  string bot_and_type = message .replace(0,  BOT_MESSAGE_PREFIX .length(), ""); 
  
                  char * ptr_to_parts = strtok ( (char*) bot_and_type.c_str()  ,",");
 
                  
                  try {
                      
                       if(ptr_to_parts != NULL){
 
                            string str(ptr_to_parts);

                            botCommand.bot_type = CHAT_BOT_TYPE_MAPPING.at(str);

                            ptr_to_parts = strtok (NULL, "");

                            botCommand.bot_name = ptr_to_parts;
                        }
                        else{
                            
                            botCommand.bot_type = CHAT_BOT_TYPE::no_bot;
        
                            botCommand.bot_name = message;
                        }
       
                  } catch(const out_of_range &e) {

                        botCommand.bot_type = CHAT_BOT_TYPE::no_bot;
        
                        botCommand.bot_name = message;
                  }

               }
               else{
                    
                     botCommand.bot_type = CHAT_BOT_TYPE::no_bot;
  
                     botCommand.bot_name = message;
                  }
 
            return botCommand; 
    }
} 

