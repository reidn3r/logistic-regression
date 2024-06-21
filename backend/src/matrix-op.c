#include "../include/matrix-op.h"
#include <stdio.h>
#include <stdlib.h>

double* multiply_mat(double* mat, double* array, int n_rows, int n_cols){
    /* 
        - Multiplicação Matriz-Vetor: Caso onde mat 
            é uma matriz unidimensional (1D) e
            array é uma matriz bidimensional (2D)

        @array:  vetor unidimensional
        @mat:    vetor bidimensional
        @n_rows: numero de linhas de mat
        @n_cols: numero de colunas de mat

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


// Função corrigida para multiplicar um vetor 1D por uma matriz 2D
double* multiply_mat_transpose(double* array, double* mat, int n_rows, int n_cols){
    double* out = malloc(n_cols * sizeof(double));
    for(int j = 0; j < n_cols; j++){
        out[j] = 0.0;
        for(int i = 0; i < n_rows; i++){
            out[j] += array[i] * mat[i * n_cols + j];
        }
    }
    return out;
}


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

