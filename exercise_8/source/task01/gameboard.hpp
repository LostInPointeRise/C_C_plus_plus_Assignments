#include <iostream>

// Declaration of class GameBoard.
// Member functions are defined in gameboard.cpp
#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
// GameBoard abstract data type definition

class GameBoard {

    private: 

        /**
         * @brief size of the GameBoard
         */

        int size; 

        /**
         * @brief pointer to the matrix, that 
         *        containing the moves
        */

        char **matrix;

        /**
         * @brief function that initialize the moves-Matrix
         * @param (int) _size of the Matrix (Column/Row)
        */

        void initializeMatrix(int _size);


        /**
         * @brief variable indicating the player that did the last move
        */

        int lastPlayerId; 


        /**
         * @brief variable that describes the number of 
         *        fields that are occupied
        */

        int choosenFields = 0;

    public: 

        /**
         * @brief constructor of the GameBoard
         * @param (int) size of the GameBoard
        */
        GameBoard(int _size = 3);

        /**
         * @brief destructor of the GameBoard
        */
        ~GameBoard();

        /**
         * @brief function to do actions on the GameBoard
         * @param (int) playerId of the player that takes a certain action
         * @param (int) x coordinate of an action 
         * @param (int) y coordinare of an action
        */
        void insert(int playerId, int x_coordinate, int y_coordinate);

        /**
         * @brief function that shows, if a field is free 
         * @param (int) x coordinate of an action 
         * @param (int) y coordinare of an action
         * @return (bool) flag indicating if a certain field was not set yet 
        */
        bool isFree(int x_coordinate, int y_coordinate);

        /**
         * @brief function that shows the size of the GameBoard
         * @return (int) size of the GameBoard
        */
        int getSize();

        /**
         * @brief function that shows the id of the winning player
         * @return (int) id of the winning player
        */
        int getWinner();


        /**
         * @brief function that indicates, if the GameBoard, does contain fields, that were not set yet
         * @return (bool) flag indicting if the Board is "playable"
        */
        bool hasAvailableMoves();

        /**
         * @brief Overload the '<<' operator
        */

        friend std::ostream& operator<<(std::ostream& os, const GameBoard& gameboard); 
 
};
#endif // end of class GameBoard 