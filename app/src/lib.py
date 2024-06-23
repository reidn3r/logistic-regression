# Configuração dos tipos de argumento e retorno das funções
import ctypes

so = "../backend/build/library.so"
lib = ctypes.CDLL(so)

#sigmoid
lib.sigmoid.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.c_int)
lib.sigmoid.restype = ctypes.POINTER(ctypes.c_double)

#gradient
lib.gradient.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int, ctypes.c_int)
lib.gradient.restype = ctypes.POINTER(ctypes.c_double)

#logloss
lib.logloss.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int)
lib.logloss.restype = ctypes.c_double

#update_params
lib.update_params.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int)
lib.update_params.restype = ctypes.POINTER(ctypes.c_double)

#fit
lib.fit.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int, ctypes.c_int, ctypes.c_int)
lib.fit.restype = ctypes.POINTER(ctypes.c_double)

#predict
lib.predict.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int, ctypes.c_int)
lib.predict.restype = ctypes.POINTER(ctypes.c_double)

#subtract
lib.subtract.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int)
lib.subtract.restype = ctypes.POINTER(ctypes.c_double)

#dot_2d_1d
lib.dot_2d_1d.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int, ctypes.c_int)
lib.dot_2d_1d.restype = ctypes.POINTER(ctypes.c_double)

#dot_1d_2d
lib.dot_1d_2d.argtypes = (ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double), ctypes.c_int, ctypes.c_int)
lib.dot_1d_2d.restype = ctypes.POINTER(ctypes.c_double)