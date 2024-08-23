#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "unit_line_test.h"
#include "solve.h"
#include "shared.h"

int unit_line_test(line_test data) {
    double root1 = NAN, root2 = NAN;

    assert(root1);
    assert(root2);

    int nRoots = solve_line(data.b, data.c, &root1, &root2);

    if(!is_equal(root1, data.root1_exp) || !is_equal(nRoots, data.nRoots_exp)) {
        printf("\033[31mERROR in line\033[97m\n");
        printf("\033[31mERROR test - %d, b = %lg, c = %lg, root1 = %lg, nRoots = %d\033[97m\n",
                data.number_test, data.b, data.c, root1, nRoots);
        printf("\033[31mExpected: b = %lg, c = %lg, root1 = %lg, nRoots = %d\033[97m\n",
                data.b, data.c, data.root1_exp, data.nRoots_exp);

        return data.number_test;
    } else {
        printf("\033[32mNo error\033[97m\n");

        return 0;
    }
}