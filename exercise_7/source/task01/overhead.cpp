#include <cstdio>

#include "purebase.hpp"
#include "virtbase.hpp"
#include "virtder.hpp"
#include "staticbase.hpp" 
#include "stopwatch.hpp"

StopWatch stopwatch;  

  

#define MEASURETIME(description, repetitions, instructions2test) \
        stopwatch.start();  \
        for(int ctr = 0; ctr < 50000000; ctr += 1){ \
            instructions2test\
        }\
        printf("My computer requires %f seconds to execute %s %d times \n",  stopwatch.stop(), description, repetitions); \
       

int main()
{
    #ifdef VERBOSE
        PureBase pure;
        VirtBase vbase;
        VirtDer vder;

        PureBase *ppure = new PureBase(); 
        VirtBase *pvbase = new VirtBase(); 
        VirtDer *pvder = new VirtDer(); 
        VirtBase *pvbaseder = pvder;
 
        //StaticBase::myFunc();

        /**
         * @bief non virutal member functions
         */
        pure.myFunc();
        ppure->myFunc();
    
        vbase.nvFunc();
        pvbase->nvFunc();

        /**
         * @bief non virtual member functions with inheritence 
         */

        vder.myFunc();
        pvder->myFunc();

        vder.nvFunc();
        pvder->nvFunc();

        /**
         * @bief non virtual member functions via pointer 
         */

        pvbaseder->nvFunc();

        /**
         * @bief virtual member functions
         */
        vbase.virtFunc();        
        pvbase->virtFunc();
    
         /**
         * @bief virtual member functions with inheritence 
         */
        vder.virtFunc();       
        pvder->virtFunc();
    
        /**
         * @bief virtual member functions via pointer 
         */

        pvbaseder->virtFunc();
    #endif

    #ifdef TASK02
        PureBase pure;
        VirtBase vbase;
        VirtDer vder;

        PureBase *ppure = new PureBase(); 
        VirtBase *pvbase = new VirtBase(); 
        VirtDer *pvder = new VirtDer(); 
        VirtBase *pvbaseder = pvder;

       // MEASURETIME("StaticBase::myFunc()", 50000000, StaticBase::myFunc(););

        MEASURETIME("pure.myFunc()", 50000000, pure.myFunc(););
        
        MEASURETIME("ppure->myFunc()", 50000000,  ppure->myFunc(););

        MEASURETIME("vbase.nvFunc()", 50000000, vbase.nvFunc(););
        
        MEASURETIME("pvbase->nvFunc()", 50000000, pvbase->nvFunc(););

        MEASURETIME("vder.myFunc()", 50000000,  vder.myFunc(););

        MEASURETIME("pvder->myFunc()", 50000000,  pvder->myFunc(););

        MEASURETIME("vder.nvFunc()", 50000000, vder.nvFunc(););

        MEASURETIME("pvder->nvFunc()", 50000000,   pvder->nvFunc(););

        MEASURETIME("pvbaseder->nvFunc()", 50000000, pvbaseder->nvFunc(););

        MEASURETIME("vbase.virtFunc()", 50000000, vbase.virtFunc(););

        MEASURETIME("pvbase->virtFunc()", 50000000, pvbase->virtFunc(););
    
        MEASURETIME("vder.virtFunc()", 50000000, vder.virtFunc(););

        MEASURETIME("pvder->virtFunc()", 50000000,  pvder->virtFunc(););

        MEASURETIME("pvbaseder->virtFunc()", 50000000, pvbaseder->virtFunc(););

    #endif
 
    #ifdef TASK03

        PureBase pure;
        VirtBase vbase;
        VirtDer vder;

        PureBase *ppure = new PureBase(); 
        VirtBase *pvbase = new VirtBase(); 
        VirtDer *pvder = new VirtDer(); 

        VirtBase *pvbaseder  = &vder; 

        MEASURETIME("// dynamic cast", 50000000, {

            VirtDer* casted =  dynamic_cast<VirtDer*>(pvbaseder);
            
            if(casted){

                casted->myFunc();
            }
        });

        MEASURETIME("// static cast", 50000000, {

                static_cast<VirtDer*>(pvbaseder)->myFunc();
        });


    #endif

    return 0;
}
