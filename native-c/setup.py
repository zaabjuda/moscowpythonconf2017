from setuptools import setup, Extension
setup(name='addList',
      version='1.0.1',
      description='Simple Python native c extension',
      ext_modules=[Extension('addList', ['src/adder.c'], include_dirs=['src'])],
)