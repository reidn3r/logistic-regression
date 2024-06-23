#include "../include/linear_alg.h"
#include <stdio.h>
#include <stdlib.h>

double* subtract(double *a, double *b, int size){
    /*
        - Subtrai dois array's unidimensionai

        @a:   vetor 1D
        @b:   vetor 1D
        @out: subtração dos vetores a e b
        
    */
    double* out = malloc(size*sizeof(double));
    for(int i=0; i<size; i++){
        out[i] = a[i] - b[i];
    }

    return out;
}

double* dot_1d_2d(double *y, double* X, int n_cols, int n_rows){
    /*
        - Produto entre vetor 1D e vetor 2D
        @y: vetor 1D
        @X: vetor 2D
        @n_cols: num. de colunas do vetor 2D
        @n_rows: num. de linhas do vetor 2D
    */
    double* out = (double *)malloc(n_cols * sizeof(double));
    for(int j=0; j<n_cols; ++j){
        out[j] = 0.0;
        for(int i=0; i<n_rows; ++i){
            out[j] += y[i] * X[i * n_cols + j];
        }
    }
    return out;
}

double* dot_2d_1d(double* X, double* y, int n_cols, int n_rows){
    /*
        - Produto entre vetor 2D e vetor 1D
        @y: vetor 1D
        @X: vetor 2D
        @n_cols: num. de colunas do vetor 2D
        @n_rows: num. de linhas do vetor 2D
    */
    double* out = (double *)malloc(n_rows * sizeof(double));
    for(int i=0; i<n_rows; ++i){
        out[i] = 0.0;
        for(int j=0; j<n_cols; ++j){
            out[i] += X[i * n_cols + j] * y[j];
        }
    }
    return out;
}