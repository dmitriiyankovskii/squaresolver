#include <TXLib.h>
#include <math.h>

#include "shared.h"

#include "in.h"

#include "out.h"
#include "solve.h"

#include "unit_line_test.h"
#include "unit_solve_test.h"

void run_tests(void);

int main(void) {
    double a = NAN, b = NAN, c = NAN;

    printf("Unit tests:\n");
    run_tests();

    in(&a, &b, &c);

    double root1 = NAN, root2 = NAN;

    int countroot = solve(a, b, c, &root1, &root2);

    out(countroot, root1, root2);

    return 0;
}

void run_tests(void) {
    struct solve_test test1 = {.number_test = 1, .a = 1.0, .b = 5.0, .c = 6.0, .root1_exp = -3.0, .root2_exp = -2.0, .nRoots_exp = 2};
    struct solve_test test2 = {.number_test = 2, .a = 1.0, .b = 2.0, .c = 1.0, .root1_exp = -1.0, .root2_exp = -1.0, .nRoots_exp = 1};
    struct solve_test test3 = {.number_test = 3, .a = 0.0, .b = 2.0, .c = 1.0, .root1_exp = -0.5, .root2_exp = -0.5, .nRoots_exp = 1};
    struct line_test test4 = {.number_test = 4, .b = 5.0, .c = 4.0, .root1_exp = -0.8, .nRoots_exp = 1};
    struct line_test test5 = {.number_test = 5, .b = 0.0, .c = 0.0, .root1_exp = INF, .nRoots_exp = INF};
    struct line_test test6 = {.number_test = 6, .b = 0.0, .c = 4.0, .root1_exp = POISON_ROOT, .nRoots_exp = 0};
    struct line_test test7 = {.number_test = 7, .b = 5.0, .c = 0.0, .root1_exp = 0, .nRoots_exp = 1};
    
    unit_solve_test(test1);
    unit_solve_test(test2);
    unit_solve_test(test3);
    unit_line_test(test4);
    unit_line_test(test5);
    unit_line_test(test6);
    unit_line_test(test7);
}
