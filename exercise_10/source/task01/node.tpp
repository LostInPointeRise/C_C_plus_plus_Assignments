#include "node.hpp"


template <class T>
Node<T>::Node(){}

template <class T>
Node<T>::Node(T _content, Node* _next, Node* _previous){

    this->content = _content; 

    // caution, if copy constructor is more convinient
    this->next = _next; 

    this->previous = _previous;
}
 
template <class T>
Node<T>::~Node(){

    // caution, memory must be freed
    this->next = nullptr;
    this->previous = nullptr;
}