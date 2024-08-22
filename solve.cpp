#include "Solve.h"
#include "shared.h"
#include <math.h>
#include "Out.h"

int comp_number2 = 0;

int solve(double a, double b, double c, double *root1, double *root2) {
    if(is_equal(a, comp_number2)) {

        return solve_line(b, c, root1, root2);
    }else {

        return comp_D(a, b, c, root1, root2);
    }

    return SOLVING_ERROR;
}
int solve_line(double b, double c, double *root1, double *root2) {
    if(is_equal(b, comp_number2)) {
        if(is_equal(c, comp_number2)) {
            *root1 = INF;
            *root2 = INF;

            return INF;
        } else {
            *root1 = POISON_ROOT;
            *root2 = POISON_ROOT;

            return 0;
        }
    }

    if(!is_equal(b, comp_number2)) {
        if(is_equal(c, comp_number2)) {
            *root1 = 0.0;
            *root2 = 0.0;

            return 1;
        }
        if(!is_equal(c, comp_number2)) {
            *root1 = -c/b;
            *root2 = -c/b;

            return 1;
        }
    }

    return SOLVING_ERROR;
}

int comp_D(double a, double b, double c, double *root1, double *root2) {
    double D = b*b - 4*a*c;

    if(is_equal(D, comp_number2)) {
        *root1 = *root2 = -b/(2*a);
        
        return 1;
    }

    if(D > 0) {
        double p1 = -b/(2*a);
        double p2 = sqrt(D)/(2*a);

        *root1 = p1 - p2;
        *root2 = p1 + p2;

        return 2;
    }

    if(D < 0) {
        *root1 = NAN;
        *root2 = NAN;

        return 0;
    }

    return SOLVING_ERROR;
}