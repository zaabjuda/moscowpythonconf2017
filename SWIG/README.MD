* `swig -python example.i`
* `gcc -c example.c example_wrap.c \
        -I/usr/local/Cellar/python3/3.6.3/Frameworks/Python.framework/Versions/3.6/include/python3.6m`
* `ld -bundle -flat_namespace -undefined suppress -o _adder.so *.o`
* `python3 main.py`