#include <iostream>
#include "player.hpp"

// Declaration of class HumanPlayer.
// Member functions are defined in HumanPlayer.cpp
#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP
// HumanPlayer abstract data type definition

class HumanPlayer : public Player{

    public:

        /**
         * @brief constructor of HumanPlayer
        */
        HumanPlayer(int playerId) : Player(playerId){}


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
#endif  // end of class HumanPlayer