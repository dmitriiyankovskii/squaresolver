#include <stdio.h>
#include <math.h>

#include "shared.h"
#include "in.h"
#include "enum.h"
#include "solve.h"
#include "unit_line_test.h"
#include "unit_solve_test.h"
#include "run_tests.h"

int main() {
    double a = NAN, b = NAN, c = NAN;
    
    run_tests();

    in(&a, &b, &c); //rename 

    double root1 = NAN, root2 = NAN;

    enum countroot_ count = (enum countroot_) solve(a, b, c, &root1, &root2);

    out(count, root1, root2); //rename

    return 0;
}