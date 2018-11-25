#include <iostream>
#include "stopwatch.hpp"

using namespace std;


void  StopWatch::start(void){

    if(time_measurement_is_running)
    {
        cout << "StopWatch already running! \n" << endl;    
    }
    else{
        
        // if the stopwatch did start,         
        // we must change the values of class variables, to control 
        // the correct order of the start , stop cycle 

        this->m_timer = clock();
        this->time_measurement_is_running = true; 
        this->time_measurement_started = true; 
    }
}


double StopWatch::stop(void){

    if(!time_measurement_started){
    
        cout << "StopWatch not started yet!\n"  << endl; 
    }
    else{        
            // if the stopwatch did stop, 
            // we must change the values of class variables, to control 
            // the correct order of the start , stop cycle 

            this->time_measurement_started = false; 
            this->time_measurement_is_running = false; 
            return (double) (clock() - this->m_timer)  / CLOCKS_PER_SEC;  
        }
}
