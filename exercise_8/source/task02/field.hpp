// Declaration of class Field.
// Member functions are defined in Field.cpp
#ifndef FIELD_HPP
#define FIELD_HPP
// Field abstract data type definition

class Field{

    public: 

        /**
         * @brief describes the x coordinate of a field 
         */

        int x_coordinate; 


         /**
         * @brief describes the y coordinate of a field 
         */

        int y_coordinate;
        /**
         * @brief default Constructor of Field 
        */

        Field();

        /**
         * @brief Constructor of Field 
         * @param (int) _x_coordinate of the field
         * @param (int) _y_coordinate of the field
        */

        Field( int _x_coordinate , int _y_coordinate);
};

#endif