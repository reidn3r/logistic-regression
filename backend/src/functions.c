#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* sigmoid(double *z, int size){
    double* out = malloc(size*sizeof(double));
    for(int i=0; i<size; i++){
        out[i] = 1.0/(1.0 + exp(-z[i]));
    }
    return out;
};

double* gradient(double *X, double *y, double *y_hat, int n_samples, int n_features){
    double* out = malloc(n_features*sizeof(double));
    for(int i=0; i<n_features; i++){
        out[i] = 0.0;
        for(int j=0; j<n_samples; j++){
            out[i] += (y[j] - y_hat[j])*X[i * n_samples + j] / (-1* n_samples);
        }
    }
    return out;
};

double logloss(double *y, double *y_hat, int size){
    double sum = 0.0;
    for(int i=0; i<size; i++){
        sum += y[i]*log(y_hat[i]) + ((1 - y[i]) * log(1-y_hat[i]));
    }
    return -sum/size;
}

double* fit(double* X, double* y, int n_features, int n_samples, int epochs){
    /* 
        1. Acesso aos parametros?
        2. Implementar função de produto escalar?
    */
}