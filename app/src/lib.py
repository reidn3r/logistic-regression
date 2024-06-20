import ctypes

so = "../backend/build/library.so"
lib = ctypes.CDLL(so)

#sigmoid method ctypes args
lib.sigmoid.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int \
)
lib.sigmoid.restype = (ctypes.POINTER(ctypes.c_double))

#gradient method ctypes args
lib.gradient.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int, \
    ctypes.c_int \
)
lib.gradient.restype = (ctypes.POINTER(ctypes.c_double))

#logloss method ctypes args
lib.logloss.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int \
)
lib.logloss.restype = (ctypes.c_double)

#update_params method ctypes args
lib.update_params.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int \
)
lib.update_params.restype = (ctypes.POINTER(ctypes.c_double))

#fit method ctypes args
lib.fit.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int, \
    ctypes.c_int \
)
lib.fit.restype = (ctypes.POINTER(ctypes.c_double))

#predict method ctypes args
lib.predict.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int, \
    ctypes.c_int, \
)
lib.predict.restype = (ctypes.POINTER(ctypes.c_double))


#multiply_mat method ctypes args
lib.multiply_mat.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int, \
    ctypes.c_int, \
)
lib.multiply_mat.restype = (ctypes.POINTER(ctypes.c_double))

#subtract method ctypes args
lib.subtract.argtypes = (
    ctypes.POINTER(ctypes.c_double), \
    ctypes.POINTER(ctypes.c_double), \
    ctypes.c_int, \
)
lib.subtract.restype = (ctypes.POINTER(ctypes.c_double))