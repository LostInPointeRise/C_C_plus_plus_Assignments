 // Declaration of class Score.
// Member functions are defined in Score.cpp
#ifndef SCORE_HPP
#define SCORE_HPP
// Score abstract data type definition

class Score{

    public: 

        /**
         * @brief describes the x coordinate of a Score 
         */

        int x_coordinate; 


         /**
         * @brief describes the y coordinate of a Score 
         */

        int y_coordinate;


        /**
         * @brief variable indicating the value of a score
        */

        int value; 

        /**
         * @brief default Constructor of Score 
        */

        Score();

        /**
         * @brief Constructor of Score 
         * @param (int) _x_coordinate of the Score
         * @param (int) _y_coordinate of the Score
        */

        Score( int _x_coordinate , int _y_coordinate, int _valuew);
};

#endif