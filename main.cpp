#include <TXLib.h>
#include <math.h>

#include "shared.h"

#include "In.h"
#include "Out.h"
#include "Solve.h"

struct Solve_test {
    int number_test;
    double a, b, c, root1_exp, root2_exp; 
    int nRoots_exp;
};

struct line_test {
    int number_test;
    double b, c, root1_exp; 
    int nRoots_exp;
};

int unit_Solve_test(Solve_test );
void run_tests(void);
int unit_line_test(line_test data);

int main(void) {
    double a = NAN, b = NAN, c = NAN;

    printf("Unit tests:\n");
    run_tests();

    In(&a, &b, &c);

    double root1 = NAN, root2 = NAN;

    int countroot = Solve(a, b, c, &root1, &root2);

    Out(countroot, root1, root2);

    return 0;
}

int unit_Solve_test(Solve_test data) {
    double root1 = NAN, root2 = NAN;

    int nRoots = Solve(data.a, data.b, data.c, &root1, &root2);

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

int unit_line_test(line_test data) {
    double root1 = NAN, root2 = NAN;

    int nRoots = Solve_line(data.b, data.c, &root1, &root2);

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

void run_tests(void) {
    struct Solve_test test1 = {.number_test = 1, .a = 1.0, .b = 5.0, .c = 6.0, .root1_exp = -3.0, .root2_exp = -2.0, .nRoots_exp = 2};
    struct Solve_test test2 = {.number_test = 2, .a = 1.0, .b = 2.0, .c = 1.0, .root1_exp = -1.0, .root2_exp = -1.0, .nRoots_exp = 1};
    struct Solve_test test3 = {.number_test = 3, .a = 0.0, .b = 2.0, .c = 1.0, .root1_exp = -0.5, .root2_exp = -0.5, .nRoots_exp = 1};
    struct line_test test4 = {.number_test = 4, .b = 5.0, .c = 4.0, .root1_exp = -0.8, .nRoots_exp = 1};
    struct line_test test5 = {.number_test = 5, .b = 0.0, .c = 0.0, .root1_exp = INF, .nRoots_exp = INF};
    struct line_test test6 = {.number_test = 6, .b = 0.0, .c = 4.0, .root1_exp = ZERO, .nRoots_exp = 0};
    struct line_test test7 = {.number_test = 7, .b = 5.0, .c = 0.0, .root1_exp = 0, .nRoots_exp = 1};
    
    unit_Solve_test(test1);
    unit_Solve_test(test2);
    unit_Solve_test(test3);
    unit_line_test(test4);
    unit_line_test(test5);
    unit_line_test(test6);
    unit_line_test(test7);
}
