import cython

class ComplexCalc(object):
    @cython.cfunc
    @cython.returns(cython.float)
    @cython.locals(x=cython.float, y=cython.float)
    def __cget_length(self, x, y):
        return x+y

    @cython.cfunc
    @cython.returns(cython.float)
    @cython.locals(x=cython.float, y=cython.float, z=cython.float)
    def __ccomplex_calcs(self, x, y):
        z = self.__cget_length(x, y) ** 8 * self.__cget_anima()

    def get_length(self, x, y):
        return self.__cget_length(x, y)

    def complex_calcs(self, x,y):
        return self.__ccomplex_calcs(x, y)