#include <iostream>
#include "secarr.hpp"

using namespace std;
 
int main(void) {
  int a[] = {1,2,3,4};
  SecArr sarr(a, a+(sizeof(a)/sizeof(int))-1);
  cout << "*sarr = " <<  *sarr << endl;
  *sarr = 0; 
  //  {0,2,3,4} , current = 0
  cout << "sarr[0] = " <<  sarr[0] << endl;
  // sarr[0] = 0
  ++sarr; 
   //  {0,2,3,4} , current = 2
  cout << "After increment: *sarr = " << *sarr << ", sarr[0] = " <<  sarr[0] << endl;
   //  After increment: *sarr = 2, sarr[0] = 2
  cout << "sarr[2] = " <<  sarr[2] << endl;
   //  sarr[2] = 4
  cout << "sarr[-1] = " <<  sarr[-1] << endl;
   //  sarr[-1] = 0
  cout << "sarr[-2] = " <<  sarr[-2] << endl;
   //  sarr[-2] = invalid Input 0
  sarr[2] = 6;
   //  {0,2,3,6} , current = 2
  cout << "sarr[3] = " <<  sarr[3] << endl;
   //  sarr[3] = 6
  cout << "*(sarr++) = " << *(sarr++) << endl;
   // *(sarr++) =  2, current = 3 
  cout << "*sarr = " <<  *sarr << endl;
   // *sarr = 3
  cout << "*(++sarr) = " << *(++sarr) << endl;
   //*(++sarr) = 6
  cout << "*sarr = " <<  *sarr << endl;
   //*sarr = 6
  cout << "Should not increment 2x: " << endl;
   
  cout << "*(++sarr) = " << *(++sarr) << endl;
   //*(++sarr) = invalid input 6
  sarr++;
  cout << "*sarr = " <<  *sarr << endl;
   // *sarr =  6
  cout << "*(sarr--) = " << *(sarr--) << endl;
   // *(sarr--) =  6
  cout << "*sarr = " <<  *sarr << endl;
   // *sarr =  3
  cout << "*(--sarr) = " << *(--sarr) << endl;
   // *(--sarr) = 2
  cout << "*sarr = " <<  *sarr << endl;
   // *sarr =  2
  --sarr;
  cout << "Should not decrement 2x: " << endl;
  cout << "*(--sarr) = " << *(--sarr) << endl;
    // *sarr = 0,  invalid input 
  sarr--;
  cout << "*sarr = " <<  *sarr << endl;
   // *sarr = 0, invalid input*/
}
