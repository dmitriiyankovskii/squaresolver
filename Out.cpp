#include <stdio.h>

#include "out.h"
#include "vari.h"

int out(int countroot, double root1, double root2) { 
    switch(countroot) {
        case 0:
            format_printf(YELLOW, ITALICS, "No dicision\n");
            
            return 0;
        case 1:
            format_printf(YELLOW, ITALICS, "x = %.2lg\n", root1);

            return 1;
        case 2:
            format_printf(YELLOW, ITALICS, "x1 = %.2lg, x2 = %.2lg\n", root1, root2);

            return 2;
        case INF:
            format_printf(YELLOW, ITALICS, "an infinite number of solution\n");
            
            return INF;
        default:
            printf("\033[31merror\033[97m\n");
            format_printf(RED, ITALICS, "error\n");
            return POISON_ROOT;
    }
}