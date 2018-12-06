#include "purebase.hpp"


int main()
{
    PureBase pure;
   // VirtBase vbase;
   // VirtDer vder;

    PureBase *ppure = new PureBase(); 
   // VirtBase *pvbase = new VirtBase(); 
   // VirtDer *pvder = new VirtDer(); 
   // VirtBase *pvbaseder = pvder;

       
    ppure->myFunc();

    return 0;
}
