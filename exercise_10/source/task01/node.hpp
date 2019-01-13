  
 
#ifndef Node_HPP
#define Node_HPP
 
 
template<class T> 

class Node{

    public:

        /**
         * @brief T content of class Node 
         */

        T content; 

        /**
         * @brief Node* next of class Node 
         */

        Node* next; 

         /**
         * @brief Node* previous of class Node 
         */

        Node* previous; 

        /**
         * @brief destructor of class Node
         */

        Node();

        /**
         * @brief constructor of class Node
         * @param T _constent
         * @param Node* _next 
         * @param Node* _previous
         */

        Node(T _content, Node* _next, Node* _previous);

        /**
         * @brief destructor of class Node
         */

        ~Node();

};

#include "node.tpp"
#endif  // end of class Node
 