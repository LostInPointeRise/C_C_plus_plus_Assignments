#include <time.h>
 
// Declaration of class StopWatch.
// Member functions are defined in StopWatch.cpp
#ifndef STOPWATCH_H
#define STOPWATCH_H
// StopWatch abstract data type definition


// StopWatch abstract data type definition
class StopWatch{

private:

    clock_t m_timer;

    // variable needed to indicate, if the time measurment was started 
    bool time_measurement_started = false; 

     // variable needed to indicate, if the time measurment was running
    bool time_measurement_is_running = false; 

public:
 
    /**
     * @brief construcotr for the StopWatch class
    */
    StopWatch(){}

    /**
     * @brief starts the time measurement
    */
    void start(void);

     /**
     * @brief stops the time measurement
    */
    double stop(void);

}; // end class StopWatch
#endif