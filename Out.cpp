#include <stdio.h>
#include "Out.h"

int Out(int countroot, double root1, double root2) {
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

            return POISON_ROOT;
            break;
    }
}