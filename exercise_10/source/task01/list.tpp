#include "list.hpp"

template <class T>
List<T>::List(){

    // cannot figure out object initialization error 
    // maybe inner pointers are null
    Node<T> node;

    *this->first = node;

    this->last = this->first;
}
 
template <class T>
List<T>::~List(){

    this->first = nullptr;

    this->last = this->first;
}

template <class T>
void List<T>::add_front(T value){
    
    /**
     * we save the pointer of the current last element
     */
    Node<T>* ptr_to_old_first =  this->first;

    *this->first = Node<T>(value, nullptr, nullptr  );

    ptr_to_old_first->previous = this->first;

    this->first->next = ptr_to_old_first;
}
 
template <class T>
T List<T>::remove_front(){

    Node<T> first_element = *this->first;

    Node<T>* new_first_element = this->first->next;

    new_first_element->previous = nullptr;

    this->first = new_first_element;

    return first_element.content;
}


template <class T>
void List<T>::add(T value){

    /**
     * we save the pointer of the current last element
     */
    Node<T>* ptr_to_old_last =  this->last;

    /**
     * we create a new element of Node, to the last pointer 
     */

    *this->last = Node<T>( value, ptr_to_old_last, nullptr);

    /**
     * we need to update the "next" pointer of the previous "last"
     * element
     */

    ptr_to_old_last->next = this->last ;
} 


template <class T>
T List<T>::remove(){

    /**
     * we save a current copy of the object that 
     * is pointed, by the last pointer
     */

    Node<T> last_element = *this->last;

    Node<T>* new_last_element = this->last->previous;

    new_last_element->next = nullptr;

    // we need to update the last pointer to the new "last" object

    this->last = new_last_element;

    return last_element.content;
} 

template <class T>
bool List<T>::isEmpty(){

    return getSize() == 0;
}

template <class T>
void List<T>::clear(){

    this->first = nullptr;

    this->last = this->first;
} 

template <class T>
bool List<T>::contains(T obj){

    for (Node<T>* ptr = this->first;  ptr != nullptr; ++ptr) {

        // need to comparable interface 
        if(ptr->content == obj){

            return true; 
        }
    }

    return false;
}


template <class T>
int List<T>::getSize(){
 
    /** 
     * we get the currently safed elements, 
     * while we substract the adress of the last element of the 
     * list from the first element of the list
     * 
     * The result will be a multiple of sizeof(Node<T>), so we get the number of elements 
    */ 
 
    return this->last - this->first;
}