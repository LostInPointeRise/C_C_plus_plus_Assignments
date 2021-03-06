#include <iostream>
#include "gameboard.hpp"

// Declaration of interface Player.
// Member functions are defined in player.cpp
#ifndef PLAYER_HPP
#define PLAYER_HPP
// Player abstract data type definition

class Player{

    protected: 

        /**
         * @brief id that describes the certain player 
         */

        int turn; 


        /**
         * @brief constructor of the Player  
         * @param (int) id of the player 
        */

        Player(int _id);
 
    public: 

        /**
         * @brief function to do "Games" actions
         * @param (GameBoard&) Game board on which the moves are carried out
        */

        virtual void play(GameBoard& gameBoard) = 0;


         /**
          * @brief Overload the '<<' operator
          */

        friend std::ostream& operator<<(std::ostream& os, const Player& player); 
};

#endif