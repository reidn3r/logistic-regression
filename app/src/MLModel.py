from src.lib import lib
import numpy as np
import ctypes

class LogisticRegression():
    def __init__(self):
        self.params = None

    def fit(self, X, y, epochs):
        n_cols, n_rows = X.shape[1], X.shape[0]
        self.params = np.zeros(n_cols, dtype=np.float64)
        X_cast, y = X.flatten().astype(np.float64), y.astype(np.float64)

        X_ptr = X_cast.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
        y_ptr = y.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
        params_ptr = self.params.ctypes.data_as(ctypes.POINTER(ctypes.c_double))

        output_ptr = lib.fit(X_ptr, y_ptr, params_ptr, n_cols, n_rows, epochs)
        self.params = np.ctypeslib.as_array(output_ptr, shape=(n_cols,))
        return;

    def predict(self, X):
        if X.shape[1] != self.params.size:
            raise ValueError("Dimensões diferentes")

        X_cast = X.flatten().astype(np.float64)
        X_ptr = X_cast.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
        params_ptr = self.params.ctypes.data_as(ctypes.POINTER(ctypes.c_double))

        output_ptr = lib.predict(X_ptr, params_ptr, X.shape[0], X.shape[1])
        return np.ctypeslib.as_array(output_ptr, shape=(X.shape[0],))


    def hello(self):
        return lib.hello()