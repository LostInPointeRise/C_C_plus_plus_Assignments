#include "mytime.hpp"
#include <iostream>  
using namespace std; 

int main(){

    MyTime time(0,0,75);
    cout << time << endl;

    int castedToInt = (int) time;

    cout <<  castedToInt << endl;

}