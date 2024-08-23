#include <stdio.h>
#include <assert.h>

#include "in.h"
#include "in.h"


void skip_input(void);
void in(double *a, double *b, double *c) { 
    assert(a);
    assert(b);
    assert(c);

    printf("Enter the parameters of the quadratic equation (a, b, c): \n");
    while((scanf("%lg %lg %lg", a, b, c)) != COUNT_INPUT) {

        skip_input();

        printf("invalid data type\n");
    }
}
void skip_input(void) {
    while(getchar() != '\n') {}
}