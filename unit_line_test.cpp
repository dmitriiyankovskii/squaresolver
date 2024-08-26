#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "unit_line_test.h"
#include "solve.h"
#include "shared.h"
#include "vari.h"

int unit_line_test(line_test data) {
    double root1 = NAN, root2 = NAN;

    int nRoots = solve_line(data.b, data.c, &root1, &root2);

    if(!is_equal(root1, data.root1_exp) || !is_equal(nRoots, data.nRoots_exp)) {
        format_printf(RED, FAT, "ERROR in line\n");
        format_printf(RED, FAT, "ERROR test - %d, b = %lg, c = %lg, root1 = %lg, nRoots = %d\n",
                data.number_test, data.b, data.c, root1, nRoots);
        format_printf(RED, FAT, "Expected: b = %lg, c = %lg, root1 = %lg, nRoots = %d\n",
                data.b, data.c, data.root1_exp, data.nRoots_exp);

        return data.number_test;
    } else {
        format_printf(GREEN, ITALICS, "No error\n");

        return 0;
    }
}