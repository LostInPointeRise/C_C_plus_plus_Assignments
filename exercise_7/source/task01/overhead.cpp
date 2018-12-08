#include "purebase.hpp"
#include "virtbase.hpp"
#include "virtder.hpp"
#include "staticbase.hpp"


int main()
{
    PureBase pure;
    VirtBase vbase;
    VirtDer vder;

    PureBase *ppure = new PureBase(); 
    VirtBase *pvbase = new VirtBase(); 
    VirtDer *pvder = new VirtDer(); 
    VirtBase *pvbaseder = pvder;

    StaticBase::myFunc();

    pure.myFunc();
    ppure->myFunc();
 
    vbase.nvFunc();
    vbase.virtFunc();

    pvbase->nvFunc();
    pvbase->virtFunc();
 
    vder.myFunc();
    vder.nvFunc();
    vder.virtFunc();

    pvder->myFunc();
    pvder->nvFunc();
    pvder->virtFunc();
 
    pvbaseder->nvFunc();
    pvbaseder->virtFunc();

    return 0;
}
