#ifndef MATRIXOP_H
#define MATRIXOP_H

double* multiply_mat(double* mat, double* array, int n_rows, int n_cols);
double* multiply_mat_transpose(double* array, double* mat, int n_rows, int n_cols);
double* subtract(double *a, double *b, int size);

#endif