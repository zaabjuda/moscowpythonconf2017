
from setuptools import setup
from setuptools_rust import Binding, RustExtension

setup(name='addList',
      version='1.0',
      rust_extensions=[RustExtension('addList._addList',
                                     'Cargo.toml', binding=Binding.PyO3)],
      packages=['addList'],
      # rust extensions are not zip safe, just like C-extensions.
      zip_safe=False
)