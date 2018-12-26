#include <string>
#include <iostream>
#include <stdexcept>

using namespace std; 
 

#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP
 
// Declaration of class RingBuffer.
// Member functions are defined in RingBuffer.cpp

/**
 * @brief declaration of the RingBuffer Template
 * @param (class) Type of the elements that should be buffered 
 * @param (int) size of the RingBuffer 
*/
 
template<class T, int size>

class RingBuffer{

private: 

    /**
     * @brief buffer that keeps the elements
     */
    T _buffer [size];

    /**
     * @brief capacity of the ringbuffer
     */

    int _amount = size;

    int _current_amount = 0;

    /**
     * @brief (int) back index of the ringbuffer 
     */

    int _back = 0;

    /**
     * @brief (int) front index of the ringbuffer 
     */

    int _front = 0;


public: 
 
    /**
     * @brief method that pushes an element to the indicated front
     * @param (T) element to be pushed at the indicated front
     */
    void push_front(T element){

        if(!full()){
            _current_amount++;
            _front = (mod((_front + 1), _amount));
            _buffer[mod((_front - 1), _amount)] = element;
        }
    }
 
 
    /**
     * @brief method that pops the element that is at the front
     * @return (T) popped element
    */
    T pop_front(void){

        if(!empty()){
            _current_amount--;
            _front = mod((_front - 1), _amount);
            return _buffer[mod((_front + 1), _amount)];
        }
        else{

            throw std::out_of_range("pop_front on empty buffer");
        }
    }
 

    /**
     * @brief method that pushes an element to the indicated back
     * @param (T) element to be pushed at the indicated back
     */
    void push_back(T element){

        if(!full()){
            _current_amount++;
            _back = mod(_back - 1, _amount);
            _buffer[_back] = element;
        }
    }


 
    /**
     * @brief method that pops the element that is at the back
     * @return (T) popped element
    */
    T pop_back(void){

        if(!empty()){
            _current_amount--;
            _back = mod(_back - 1, _amount);
            return _buffer[mod(_back + 1, _amount)];
        }
        else{

            throw std::out_of_range("pop_back on empty buffer");
        }
    }


    /**
     * @brief method that indicates if the ringbuffer is empty 
     * @return (bool) flag indicating if the ringbuffer is empty
     * 
    */

    bool empty(void){
  
        return  _current_amount == 0;
    }

 
    /**
     * @brief method that indicates if the ringbuffer is full 
     * @return (bool) flag indicating if the ringbuffer is full
     * 
    */

    bool full(void){

        return  _current_amount == _amount;
    }

    /**
     * @brief method that prints the content of the ring buffer.
    */

    void print(void){
  
        if(empty()){
            cout << "Buffer is empty\n" << endl; 
        }
        else{

            string buffer_content; 
  
                for(int ctr = _front , flag = 0; flag < (_current_amount); ctr = mod(ctr + 1, _amount)){
                    
                    buffer_content +=  (to_string(_buffer[ctr]) + "\t");
                    flag++; 
                }
            
            
            cout << "Content of buffer: " << buffer_content << "\n" << endl; 
        } 
    }


     /**
      * @brief method that calculates the mod of two numbers 
      * @param (int) element, that needs should be calculated 
      * @param (int) base 
      * @return (int) mod value of element and base
      */

    int mod (int element, int base)
    {
        int ret = element % base;
        if(ret < 0)
            ret+=base;
        return ret;
    }

}; // end of class RingBuffer 
#endif 
