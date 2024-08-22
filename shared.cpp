#include <math.h>

#include "shared.h"

int is_equal(double comp_number1, double comp_number2) {
    if((fabs(comp_number1 - comp_number2)) <= EPS) {
        return 1;
    }
    
    return 0;
}