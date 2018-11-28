#include <cstring>
#include <stdio.h>
#include <iostream>
#include "mytime.hpp"

using namespace std;


MyTime::MyTime( int hour, int minute, int second ){
  
  this->adjustTime(hour, minute, second);
};
 

MyTime::~MyTime(){

}

MyTime::operator int(){

    /* 
     * cause the seconds to 0:0:0 are requested, we simply need 
     * to transofrm the parts of the time, back to seconds 
     */

    return this->second + (this->minute * 60) + (this->hour * 60 * 60);
}

  
ostream& operator<<(ostream& os, const MyTime& time)  
{   
    return os << time.hour << ":" << time.minute << ":" << time.second ;  
}  
 
void MyTime::adjustTime(int hour, int minute, int second){


    // we need to adjust the given inputs

    /**
     *  If second or minute are larger than 59 it should be adjusted to the interval [0;59] 
     *  and the next time element (i.e. minute or hour) should be increased accordingly. 
     * 
     *  So we will divide to 60, with integer values. The rest of the division, is the 
     *  power to adjust the next time values 
    */

    int adjust_minute = second / 60;

    int adjust_hour = hour / (minute + adjust_minute);

    // we need to adjust the time, and save it back to the internal variables

    this->hour = (hour + adjust_hour) % 24;

    this->minute = (minute + adjust_minute) % 60;
    
    this->second = (second) % 60;
};
 
int MyTime::getHour(){

    return this->hour;
}

int MyTime::getMinute(){

    return this->minute; 
}

int MyTime::getSecond(){

    return this->second;
}
 