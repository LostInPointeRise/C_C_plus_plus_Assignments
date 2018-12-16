#include <iostream>

#include "player.hpp"
#include "mode.hpp"

// Declaration of class ComputerPlayer.
// Member functions are defined in ComputerPlayer.cpp
#ifndef COMPUTERPLAYER_HPP
#define ComputerPlayer_HPP
// ComputerPlayer abstract data type definition

class ComputerPlayer : public Player{



    private:
     
        /**
         * @brief mode of the computer player
        */

        Mode mode; 

};
#endif  // end of class ComputerPlayer