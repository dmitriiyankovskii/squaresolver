#include <TXLib.h>
#include <math.h>

#include "shared.h"
#include "in.h"
#include "out.h"
#include "solve.h"
#include "unit_line_test.h"
#include "unit_solve_test.h"
#include "run_tests.h"

int main(void) {
    double a = NAN, b = NAN, c = NAN;

    run_tests();

    in(&a, &b, &c);

    double root1 = NAN, root2 = NAN;

    int countroot = solve(a, b, c, &root1, &root2);

    out(countroot, root1, root2);

    return 0;
}