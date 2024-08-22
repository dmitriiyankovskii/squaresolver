#ifndef SOLVE_H
#define SOLVE_H

const int SOLVING_ERROR = -2;

int solve_line(double b, double c, double *root1, double *root2);
int solve(double , double , double , double *, double *);
int comp_D(double a, double b, double c, double *root1, double *root2);

#endif