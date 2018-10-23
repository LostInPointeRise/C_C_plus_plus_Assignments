#include "stdio.h"
#include "cube_xray.h"

 
int main(int argc, char const *argv[])
{
    // first cube 
    int cube1[3][2][4] = { {{1,2,3,4}}, {{2,3}, {4,6,8,10}}, {{3,4,5,6}, {6,8,10}} };

    printf("%d \n", sum2nd(&cube1[0][0][0], 3, 2, 4));
    // second cube 
    int cube2[2][3][3] ={ {{9,8,7}, {6}, {5,4}}, {{3,2}, {1,2,3}, {4}} };

    printf("%d \n", sum2nd(&cube2[0][0][0], 2, 3, 3));

    return 0;
}
