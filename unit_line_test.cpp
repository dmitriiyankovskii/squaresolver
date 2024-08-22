#include <stdio.h>
#include <math.h>

#include "unit_line_test.h"
#include "solve.h"
#include "shared.h"

int unit_line_test(line_test data) {
    double root1 = NAN, root2 = NAN;

    int nRoots = solve_line(data.b, data.c, &root1, &root2);

    if(!is_equal(root1, data.root1_exp) || !is_equal(nRoots, data.nRoots_exp)) {
        printf("ERROR in line\n");
        printf("ERROR test - %d, b = %lg, c = %lg, root1 = %lg, nRoots = %d\n",
                data.number_test, data.b, data.c, root1, nRoots);
        printf("Expected: b = %lg, c = %lg, root1 = %lg, nRoots = %d\n",
                data.b, data.c, data.root1_exp, data.nRoots_exp);

        return data.number_test;
    } else {
        printf("No error\n");

        return 0;
    }
}