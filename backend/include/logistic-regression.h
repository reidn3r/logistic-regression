#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H
#define LR 0.001

double* sigmoid(double *z, int size);

double* gradient(double *X, double *y, double *y_hat, int n_rows, int n_cols);

double logloss(double *y, double *y_hat, int size);

double* fit(double* X, double* y, double*params, int n_cols, int n_rows, int epochs);

double* update_params(double* current_params, double* gradient, int size);

double* predict(double *X, double* params, int n_rows, int n_cols);

void hello();

#endif