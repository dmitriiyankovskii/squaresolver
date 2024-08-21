#include <TXLib.h>
#include <math.h>

#include "shared.h"
#include "In.h"
#include "Out.h"

//const int INF = -1;
const int SOLVING_ERROR = -2;
const double COMP_NUMBER2 = 0;
//const int ZERO = 0;

int Solve(double , double , double , double *, double *);
//int Out(int, double, double);
int unit_Solve_test(int, double, double, double, double, double, int);
void vyzov_tests(void);
int Solve_line(double b, double c, double *root1, double *root2);
int comp_D(double a, double b, double D, double *root1, double *root2);
int unit_line_test(int number_test, double b, double c, double root1_exp, int nRoots_exp);

int main(void){
    double a = NAN, b = NAN, c = NAN;

    printf("Unit tests:\n");
    vyzov_tests();

    In(&a, &b, &c);

    double root1 = NAN, root2 = NAN;

    int countroot = Solve(a, b, c, &root1, &root2);

    Out(countroot, root1, root2);

    return 0;
}

/*int Out(int countroot, double root1, double root2) {
    switch(countroot) {
        case 0:
            printf("No dicision\n");

            return 0;
            break;
        case 1:
            printf("x = %.2lg\n", root1);

            return 1;
            break;
        case 2:
            printf("x1 = %.2lg, x2 = %.2lg\n", root1, root2);

            return 2;
            break;
        case INF:
            printf("an infinite number of solution\n");

            return INF;
            break;
        default:
            printf("error\n");

            return ZERO;
            break;
    }
}*/
int unit_Solve_test(int number_test, double a, double b, double c, double root1_exp, double root2_exp, int nRoots_exp) {
    double root1 = NAN, root2 = NAN;

    int nRoots = Solve(a, b, c, &root1, &root2);

    if(!is_equal(nRoots, nRoots_exp) || !is_equal(root1, root1_exp) || !is_equal(root2, root2_exp)) {
        printf("ERROR in Solve\n");
        printf("ERROR test - %d, a = %lg, b = %lg, c = %lg, root1 = %lg, root2 = %lg, nRoots = %d\n",
                number_test, a, b, c, root1, root2, nRoots);
        printf("Expected: a = %lg, b = %lg, c = %lg, root1 = %lg, root2 = %lg, nRoots = %d\n",
                a, b, c, root1_exp, root2_exp, nRoots_exp);

        return number_test;
    } else {
        printf("No error\n");

        return 0;
    }
}

int unit_line_test(int number_test, double b, double c, double root1_exp, int nRoots_exp) {
    double root1 = NAN, root2 = NAN;

    int nRoots = Solve_line(b, c, &root1, &root2);

    if(!is_equal(root1, root1_exp) || !is_equal(nRoots, nRoots_exp)) {
        printf("ERROR in line\n");
        printf("ERROR test - %d, b = %lg, c = %lg, root1 = %lg, nRoots = %d\n",
                number_test, b, c, root1, nRoots);
        printf("Expected: b = %lg, c = %lg, root1 = %lg, nRoots = %d\n",
                b, c, root1_exp, nRoots_exp);

        return number_test;
    } else {
        printf("No error\n");

        return 0;
    }
}

int Solve(double a, double b, double c, double *root1, double *root2){
    if(is_equal(a, COMP_NUMBER2)) {

        return Solve_line(b, c, root1, root2);
    }else {
        double D = b*b - 4*a*c;

        return comp_D(a, b, D, root1, root2);
    }

    return SOLVING_ERROR;
}

int Solve_line(double b, double c, double *root1, double *root2) {
    if(is_equal(b, COMP_NUMBER2)) {
        if(is_equal(c, COMP_NUMBER2)) {
            *root1 = INF;
            *root2 = INF;

            return INF;
        } else {
            *root1 = ZERO;
            *root2 = ZERO;

            return 0;
        }
    }

    if(!is_equal(b, COMP_NUMBER2)) {
        if(is_equal(c, COMP_NUMBER2)) {
            *root1 = 0.0;
            *root2 = 0.0;

            return 1;
        }
        if(!is_equal(c, COMP_NUMBER2)) {
            *root1 = -c/b;
            *root2 = -c/b;

            return 1;
        }
    }

    return SOLVING_ERROR;
}

int comp_D(double a, double b, double D, double *root1, double *root2) {
    if(is_equal(D, COMP_NUMBER2)) {
        *root1 = *root2 = -b/(2*a);
        
        return 1;
    }

    if(D > 0) {
        double p1 = -b/(2*a);
        double p2 = sqrt(D)/(2*a);

        *root1 = p1 - p2;
        *root2 = p1 + p2;

        return 2;
    }

    if(D < 0) {
        *root1 = NAN;
        *root2 = NAN;

        return 0;
    }

    return SOLVING_ERROR;
}

void vyzov_tests(void) {
    unit_Solve_test(1, 1.0, 5.0, 6.0, -3.0, -2.0, 2);
    unit_Solve_test(2, 1.0, 2.0, 1.0, -1.0, -1.0, 1);
    unit_Solve_test(3, 0.0, 2.0, 1.0, -0.5, -0.5, 1);
    unit_line_test(4, 5.0, 4.0, -0.8, 1);
    unit_line_test(5, 0.0, 0.0, INF, INF);
    unit_line_test(6, 0.0, 4.0, ZERO, 0);
    unit_line_test(7, 5.0, 0.0, 0, 1);
}
