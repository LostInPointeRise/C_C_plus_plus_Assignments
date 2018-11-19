#include <stdio.h>
#include <time.h>

class StopWatch 
{

private: 
    clock_t m_timer;

    // variable needed to indicate, if the time measurment was started 
    bool time_measurement_started = false; 

     // variable needed to indicate, if the time measurment was running
    bool time_measurement_is_running = false; 

public:
    StopWatch(){}
 
    /**
     * @brief starts the time measurement
    */
    void start(void){

        if(time_measurement_is_running){
                 printf("StopWatch already running!\n");    
        }
        else{

            // if the stopwatch did start, 
            // we must change the values of class variables, to control 
            // the correct order of the start , stop cycle 

            m_timer = clock();
            time_measurement_is_running = true; 
            time_measurement_started = true; 
        }
    };

    /**
     * @brief stops the time measurement
    */
    double stop(void){
         
        if(!time_measurement_started){
            printf("StopWatch not started yet!\n");
        }
        else{
            
            // if the stopwatch did stop, 
            // we must change the values of class variables, to control 
            // the correct order of the start , stop cycle 

            time_measurement_started = false; 
            time_measurement_is_running = false; 
            return (double) (clock() - m_timer)  / CLOCKS_PER_SEC;  
        }
    };
};

