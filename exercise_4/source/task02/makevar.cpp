#include <iostream>

/*
* === Add your code here, implement MAKEVAR macro
*/

#define MAKEVAR(value, type) \
    /*type gets replaced , by the preprocessor with the given type, the same happens with the value*/  \
    type value = (value); \ 
    /*we have to use the "##" token concatenator at this point, cause we need to concatenate a token from the macro, with a token from the macro*/ \
    void set_##value(type val) { value = val; } \
    /*we have to use the "##" token concatenator at this point, cause we need to concatenate a token from the macro, with a token from the macro*/ \
    /*value was replaced before*/ \
    type get_##value(void) { return value; } \


MAKEVAR(weight, int)
MAKEVAR(price, float)

int main(void) {
  set_weight(100);
  set_price(1.25);
  std::cout << "Weight: " << get_weight() << ", Price: " << get_price() << std::endl;
}