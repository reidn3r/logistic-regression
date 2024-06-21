from src.lib import lib
from src.helper_function import Helper
import numpy as np

class LogisticRegression():
    def __init__(self):
        self.params = None
        self.epochs = 100
        self.h = Helper()

    def fit(self, X, y):
        self.params = self.h.matrix2double(np.zeros(X.shape[1], dtype=np.float64))
        X_cast, y = self.h.matrix2double(X.flatten()), self.h.matrix2double(y)

        output_ptr = lib.fit(X_cast, y, self.params, X.shape[1], X.shape[0], self.epochs)
        self.params = np.ctypeslib.as_array(output_ptr, shape=(X.shape[1],))

    def predict(self, X):
        self.params = self.h.matrix2double(self.params) if self.h.matrix2double(self.params) is None else self.params
        
        X_cast = self.h.matrix2double(X.flatten())
        output_ptr = lib.predict(X_cast, self.h.matrix2double(self.params), X.shape[0], X.shape[1])
        return np.ctypeslib.as_array(output_ptr, shape=(X.shape[0],))


    def hello(self):
        return lib.hello()