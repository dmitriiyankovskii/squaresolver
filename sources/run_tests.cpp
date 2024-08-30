#include <stdio.h>

#include "run_tests.h"
#include "unit_solve_test.h"
#include "unit_line_test.h"
#include "enum.h"

void run_tests(void) {
    printf("Unit tests:\n");

    struct solve_test test_square[3] = { {1, 1.0, 5.0, 6.0, -3.0, -2.0, 2},   
                                         {2, 1.0, 2.0, 1.0, -1.0, -1.0, 1},
                                         {3, 0.0, 2.0, 1.0, -0.5, -0.5, 1} };

    struct line_test test_linear[4] = {{4, 5.0, 4.0, -0.8, 1},
                                       {5, 0.0, 0.0, INF, INF},
                                       {6, 0.0, 4.0, POISON_ROOT, 0},
                                       {7, 5.0, 0.0, 0.0, 1}};

    for(int i = 0; i < 3; i++) {
        unit_solve_test(test_square[i]);
    }

    for(int i = 0; i < 4; i++) {
        unit_line_test(test_linear[i]);
    }
}