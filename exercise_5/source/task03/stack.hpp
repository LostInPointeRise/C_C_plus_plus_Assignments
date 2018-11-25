 
// Declaration of class Stack.
// Member functions are defined in stack.cpp
#ifndef STACK_H
#define STACK_H
// Stack abstract data type definition
class Stack {

private:
 
    // @brief loads the stack with random values
    void createRandomNumbers();

public:

    // @brief seed value, needed for creating random values
    int seed;

    // @brief maximum capacity of elements of this stack
    int size; 

    // @brief ptr to the memory, reserved for the stack
    int *ptr_to_stack;

    // @brief ptr to top element of the stack
    int *ptr_to_top;


    /**
     * @brief constructor of the Stack class 
     * @param (int) size, of the Stack class, default value is 10
    */
    Stack(int size = 10);

    /**
     * @brief copy constructor  of the Stack class 
     * @param (Stack) other stack object, that shall be copied to the callee
    */

    Stack(Stack const &other); 

    /**
     * @brief destructor of the stack class
    */

    ~Stack();

    /**
     * @brief move constructor of the Stack class 
     * @param (Stack) other stack object, that shall be moved to the callee
    */

    Stack(Stack &&other); 

    /**
     * @brief copy assignment operator of the Stack class 
     * @param (Stack) other stack object, that shall be copied to the callee
    */

    Stack& operator=(Stack const &other);

    /**
     * @brief move assignment operator of the Stack class 
     * @param (Stack) other stack object, that shall be moved to the callee
    */

    Stack& operator=(Stack &&other);

    /**
     * @brief function that returns a flag, indicationg, if the stack is full
     * @return true if stack is full, false otherwise
    */

    bool is_full();

    /**
     * @brief function that returns a flag, indicating, if the stack is empty
     * @return true if stack is empty, false otherwise
    */

    bool is_empty();

    /**
     * @brief function that pushes an argument at the top of the stack 
    */

    void push(int);

    /**
     * @brief removes the element at the top of the stack 
     * @return (int) the argument that was poped from the stack 
    */

    int pop();

    /**
     * @brief prints out each stored parameter of the stack in a single line,
     *        with single spaces between numbers
    */

    void show() const;

    /**
     * @brief sums up all integers in the stack
     * @return (int) the sum of all elements in the stack
    */

    int capacity() const;

    /**
     * @brief returns the number of elements, that are currently in the stack
     * @return (int) the number of elements currently in the stack
    */

    int length() const;

    /**
     * @brief loads the stack with random vaue, to its capacity 
    */

    void load();

 

}; // end class Stack
#endif