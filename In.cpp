#include <stdio.h>

#include "in.h"


void skip_input(void);
void In(double *a, double *b, double *c) {
    printf("Enter the parameters of the quadratic equation (a, b, c): \n");
    while((scanf("%lg %lg %lg", a, b, c)) != COUNT_INPUT) {

        skip_input();

        printf("invalid data type\n");
    }
}
void skip_input(void) {
    int ch;
    while((ch = getchar()) != '\n') {}
}