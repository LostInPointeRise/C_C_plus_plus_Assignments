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

    public:

        /**
         * @brief constructor of ComputerPlayer
         * @param (int) playerId of the ComputerPlayer
         * @param (Mode) _mode of the ComputerPlayer
        */ 
        ComputerPlayer(int playerId, Mode _mode) : Player(playerId), mode(_mode){}


        /**
         * @brief function to do "Games" actions
         * @param (GameBoard&) Game board on which the moves are carried out
         */

        void play(GameBoard& gameBoard);



        /**
         * @brief function needed to read the cordinates of the gameboard moves
         * @param (string) questionedIndex that is questioned, can be row or column
         * @return (int) read index
         */
         
        int read_index(std::string questionedIndex);

};
#endif  // end of class ComputerPlayer