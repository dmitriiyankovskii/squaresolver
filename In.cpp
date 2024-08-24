#include <stdio.h>
#include <assert.h>

#include "in.h"
#include "vari.h"


void skip_input(void);
void in(double *a, double *b, double *c) { 
    assert(a);
    assert(b);
    assert(c);
    format_printf(YELLOW, ITALICS, "Enter the parameters of the quadratic equation (a, b, c): \n");

    while((scanf("%lg %lg %lg", a, b, c)) != COUNT_INPUT) {

        skip_input();
        format_printf(RED, FAT, "invalid data type\n");
    }
}
void skip_input(void) {
    while(getchar() != '\n') {}
}