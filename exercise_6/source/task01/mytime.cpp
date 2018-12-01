#include <cstring>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "mytime.hpp"

using namespace std;


MyTime::MyTime( int hour, int minute, int second ){
  
    // we need to adjust the given inputs

    /**
     *  If second or minute are larger than 59 it should be adjusted to the interval [0;59] 
     *  and the next time element (i.e. minute or hour) should be increased accordingly. 
     * 
     *  So we will divide to 60, with integer values. The rest of the division, is the 
     *  power to adjust the next time values 
    */

    int adjust_minute = second / 60;

    int adjust_hour = (minute + adjust_minute) / 60;

    // we need to adjust the time, and save it back to the internal variables

    this->hour = (hour + adjust_hour) % 24;

    this->minute = (minute + adjust_minute) % 60;
    
    this->second = (second) % 60;
};
 

MyTime::~MyTime(){

}
 
MyTime::operator int() const{

    /* 
     * cause the seconds to 0:0:0 are requested, we simply need 
     * to transofrm the parts of the time, back to seconds 
     */

    return this->second + (this->minute * 60) + (this->hour * 60 * 60);
} 
 

MyTime operator+(MyTime const& summand1, MyTime const& summand2){

    // we save the first "MyTime" summand as an int
    int current_time = summand1;
 
    // we save the second "MyTime" summand as an int
    int other_time = summand2;
 
    return  MyTime(0, 0 , current_time + other_time);
}

MyTime operator+(MyTime const& summand1, int summand2){

     // we save the first "MyTime" summand as an int
    int current_time = summand1;
 
    return  MyTime(0, 0 , current_time + summand2);
}

MyTime operator+(int summand1 , MyTime const& summand2){

     // we save the first "MyTime" summand as an int
    int current_time = summand2;
 
    return  MyTime(0, 0 , summand1 + current_time);
} 

ostream& operator<<(ostream& os, const MyTime& time)  
{  
    return os << setw(2) << setfill('0') << time.hour << ":" << setw(2) << setfill('0') << time.minute << ":" << setw(2) << setfill('0') << time.second;  
}  
 

MyTime& MyTime::operator+=(MyTime& summand){
    
    int seconds_current_time = this->hour * 60 * 60 + this->minute * 60 + this->second;

    int seconds_other_time = summand.getHour() * 60 * 60 + summand.getMinute() * 60 + summand.getSecond();

    MyTime sum(0, 0, seconds_current_time + seconds_other_time);

    this->hour = sum.getHour();

    this->minute = sum.getMinute();

    this->second = sum.getSecond();

    return *this;
} 
  
MyTime& MyTime::operator+=(int summand){
    
    MyTime MyTimesummand(0, 0 , summand);

    int seconds_current_time = this->hour * 60 * 60 + this->minute * 60 + this->second;

    int seconds_other_time = MyTimesummand.getHour() * 60 * 60 + MyTimesummand.getMinute() * 60 + MyTimesummand.getSecond();

    MyTime sum(0, 0, seconds_current_time + seconds_other_time);

    this->hour = sum.getHour();

    this->minute = sum.getMinute();

    this->second = sum.getSecond();

    return *this;
} 


int MyTime::getHour(){

    return this->hour;
}

int MyTime::getMinute(){

    return this->minute; 
}

int MyTime::getSecond(){

    return this->second;
}
 