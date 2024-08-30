#include <stdio.h>

#include "vari.h"
#include "enum.h"

int out(enum countroot_ count, double root1, double root2) { 
    switch(count) {
        case ROOT1:
            format_printf(YELLOW, ITALICS, "No dicision\n");
            
            return 0;
        case ROOT2:
            format_printf(YELLOW, ITALICS, "x = %.2lg\n", root1);

            return 1;
        case ROOT3:
            format_printf(YELLOW, ITALICS, "x1 = %.2lg, x2 = %.2lg\n", root1, root2);

            return 2;
        case INF:
            format_printf(YELLOW, ITALICS, "an infinite number of solution\n");
            
            return INF;
        default:
            format_printf(RED, ITALICS, "error\n");
            return POISON_ROOT;
    }
}