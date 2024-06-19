#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H

double* sigmoid(double *z, int size);

double* gradient(double *X, double *y, double *y_hat, int n_samples, int n_features);

double logloss(double *y, double *y_hat, int size);

double* fit(double* X, double* y, int n_features, int n_samples, int epochs);

#endif