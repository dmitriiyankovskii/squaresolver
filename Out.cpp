#include <stdio.h>
#include "out.h"

int out(int countroot, double root1, double root2) { 
    switch(countroot) {
        case 0:
            printf("\033[33mNo dicision\033[97m\n");

            return 0;
        case 1:
            printf("\033[33mx = %.2lg\033[97m\n", root1);

            return 1;
        case 2:
            printf("\033[33mx1 = %.2lg, x2 = %.2lg\033[97m\n", root1, root2);

            return 2;
        case INF:
            printf("\033[33man infinite number of solution\033[97m\n");

            return INF;
        default:
            printf("\033[31merror\033[97m\n");

            return POISON_ROOT;
    }
}