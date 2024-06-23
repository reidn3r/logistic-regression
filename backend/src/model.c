#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/model.h"
#include "../include/linear_alg.h"

double* sigmoid(double *z, int size){
    double* out = (double *)malloc(size * sizeof(double));
    for(int i = 0; i < size; i++){
        out[i] = 1.0 / (1.0 + exp(-z[i]));
    }
    return out;
}

double* gradient(double *X, double *y, double *y_hat, int n_rows, int n_cols){
    double *array_diff = subtract(y, y_hat, n_rows);
    double *out = dot_1d_2d(array_diff, X, n_cols, n_rows);
    for(int i = 0; i < n_cols; i++){
        out[i] /= -n_rows;
    }
    free(array_diff);
    return out;
}

double logloss(double *y, double *y_hat, int size){
    double sum = 0.0;
    for(int i = 0; i < size; i++){
        sum += y[i] * log(y_hat[i]) + ((1 - y[i]) * log(1 - y_hat[i]));
    }
    return -sum / size;
}

double* update_params(double* params, double* gradient, int size){
    float lr = 0.1;
    for(int i = 0; i < size; ++i){
        params[i] = params[i] - (lr * gradient[i]);
    }
    return params;
}

double* fit(double* X, double* y, double* params, int n_cols, int n_rows, int epochs){
    double loss = 0;
    double *z, *y_hat, *computed_gradient;
    for(int i = 0; i < epochs; i++){
        double* z = dot_2d_1d(X, params, n_cols, n_rows);
        double* y_hat = sigmoid(z, n_rows);
        double* computed_gradient = gradient(X, y, y_hat, n_rows, n_cols);
        params = update_params(params, computed_gradient, n_cols);
        loss = logloss(y, y_hat, n_rows);
        free(z); free(y_hat); free(computed_gradient);
    }
    printf("logloss: %f\n", loss);
    return params;
}

double* predict(double *X, double* params, int n_rows, int n_cols){
    double* z = dot_2d_1d(X, params, n_cols, n_rows);
    double* y_hat = sigmoid(z, n_rows);
    free(z);
    return y_hat;
}

void hello(){
    printf("Hello, world");
}