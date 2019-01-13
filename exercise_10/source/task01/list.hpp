#include "collection.hpp"
#include "node.hpp"

#ifndef LIST_HPP
#define LIST_HPP
 
 
template<class T> 
class List:  public Collection<T>{

    private:

        Node<T>* first;

        Node<T>* last; 

    public:


        /**
         * @brief constructor of the list class
         */
        List();

         /**
         * @brief destructor of the list class
         */
        ~List();

        /**
         * @brief adds element at the front
         * @param (T) value to be added at the front
        */

        void add_front(T value);

         /**
         * @brief removes element from the front
         * @return T value that was removed
        */

        T remove_front();

        /**
         * @brief derived functions 
         */

        void add(T value); 

        T remove(); 

        bool isEmpty(); 

        bool contains(T obj); 

        void clear(); 

        int getSize(); 
};

#include "list.tpp"
#endif  // end of class List
 