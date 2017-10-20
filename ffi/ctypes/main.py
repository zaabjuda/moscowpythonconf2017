from ctypes import *

#load the shared object file
adder = CDLL('./adder.so')

#Calculate factorial
res_int = adder.fact(4)
print("Fact of 4 = " + str(res_int))

#Find mod of ints
a = c_int(5)
b = c_int(8)

my_mod = adder.my_mod
my_mod.restype = c_int
print("Mod of 5 and 8 = ", str(my_mod(a, b)))


#Find sum of floats
a = c_float(5.5)
b = c_float(4.1)

add_float = adder.add_float
add_float.restype = c_float
print("Sum of 5.5 and 4.1 = ", str(add_float(a, b)))