#include <iostream>

using namespace std; 

class HelloWorldChanger{

public:

    HelloWorldChanger(){cout << "---start---" << endl;}; // constructor called when an object of this class is initiated
    ~HelloWorldChanger(){cout << "---end---" << endl;}; // deconstructor called the lifecycle of an object of this class ends

}; // end of class HelloWorldChanger

