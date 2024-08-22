#include <stdio.h>
#include <math.h>

#include "unit_solve_test.h"
#include "solve.h"
#include "shared.h"

int unit_solve_test(solve_test data) {
    double root1 = NAN, root2 = NAN;

    int nRoots = solve(data.a, data.b, data.c, &root1, &root2);

    if(!is_equal(nRoots, data.nRoots_exp) || !is_equal(root1, data.root1_exp) || !is_equal(root2, data.root2_exp)) {
        printf("ERROR in Solve\n");
        printf("ERROR test - %d, a = %lg, b = %lg, c = %lg, root1 = %lg, root2 = %lg, nRoots = %d\n",
                data.number_test, data.a, data.b, data.c, root1, root2, nRoots);
        printf("Expected: a = %lg, b = %lg, c = %lg, root1 = %lg, root2 = %lg, nRoots = %d\n",
                data.a, data.b, data.c, data.root1_exp, data.root2_exp, data.nRoots_exp);

        return data.number_test;
    } else {
        printf("No error\n");

        return 0;
    }
}