import ctypes

class Helper():
    def __init__(self):
        self.active = True

    def matrix2double(self, X):
        return X.ctypes.data_as(ctypes.POINTER(ctypes.c_double))
    
