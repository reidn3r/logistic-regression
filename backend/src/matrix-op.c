#include "matrix-op.h"
#include <stdio.h>
#include <stdlib.h>

double* multiply_mat(double* mat, double* array, int n_rows, int n_cols){
    /* 
        - Multiplicação Matriz-Vetor: Caso onde x1 
            é uma matriz unidimensional (1D) e
            x2 é uma matriz bidimensional (2D)

        @array: vetor unidimensional
        @mat: vetor bidimensional
        @n_rows:   numero de linhas de mat
        @n_cols:   numero de colunas de mat

    */
    double* out = malloc(n_rows*sizeof(double));
    for(int i=0; i<n_rows; i++){
        out[i] = 0.0;
        for(int j=0; j<n_cols; j++){
            out[i] += array[j] * mat[i*n_cols + j]; 
        }
    }
    return out;
}


double* subtract(double *a, double *b, int size){
    /*
        - Subtrai dois array's unidimensionai

        @a: vetor 1D
        @b: vetor 1D
        @out: subtração dos vetores a e b
        
    */
    double* out = malloc(size*sizeof(double));
    for(int i=0; i<size; i++){
        out[i] = a[i] - b[i];
    }

    return out;
}

