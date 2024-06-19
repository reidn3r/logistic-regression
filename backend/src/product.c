#include "product.h"
#include <stdio.h>
#include <stdlib.h>

double* multiply_matrix_1Darray(double* mat, double* array, int n_rows, int n_cols){
    /* 
        @x1: vetor unidimensional
        @x2: vetor bidimensional
        @n: 
        @cols: 

        - Multiplicação Matriz-Vetor: Caso onde x1 
            é uma matriz unidimensional (1D) e
            x2 é uma matriz bidimensional (2D)
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

