#include <iostream>
#include "player.hpp"
#include "gameboard.hpp"

// Declaration of class GameMaster.
// Member functions are defined in GameMaster.cpp
#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP
// GameMaster abstract data type definition

class GameMaster{

    private: 

        /**
         * @brief (Player*) current round of the Game
         */
        int round; 

        /**
         * @brief (Player*) player1 of the GameMaster 
         */
        Player* player1; 

        /**
         * @brief (Player*) player2 of the GameMaster 
         */
        Player* player2; 

        /**
         * @brief (Player*) player of the current turn
         */
        Player* currentPlayer; 


        /**
         * @brief (GameBoard) gameBoard if the GameMaster
         */
        GameBoard gameBoard;

    public:

        /**
         * @brief function, that starts a game 
         */
        void start(void);


        /**
         * @brief function, that determines the current player
         */
        void determinecurrentPlayer(void);

         /**
         * @brief function, that reads the user actions
         */
        void readUserActions(void);

        /**
         * @brief setter method of player 1
         */
        void setplayer1(Player* _player1);

        /**
         * @brief setter method of player 2
         */
        void setplayer2(Player* _player2);

        /**
         * @brief setter method of gameBoard
         */
        void setgameboard(GameBoard _gameBoard);
};
#endif  // end of class GameMaster