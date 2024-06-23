#ifndef MATRIXOP_H
#define MATRIXOP_H

double* dot_1d_2d(double *y, double* X, int n_cols, int n_rows);
double* dot_2d_1d(double* X, double* y, int n_cols, int n_rows);
double* subtract(double *a, double *b, int size);

#endif