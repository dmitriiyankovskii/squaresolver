#ifndef UNIT_SOLVE_TEST_H
#define UNIT_SOLVE_TEST_H

struct solve_test {
    int number_test;
    double a, b, c, root1_exp, root2_exp; 
    int nRoots_exp;
};

int unit_solve_test(solve_test );

#endif