#!/usr/bin/env python
from distutils.core import setup, Extension

package = 'butterfly'
setup(name=package, version='0.2', author='cloud', ext_package=package, ext_modules=[
                                                    Extension('linear_model', sources=['LinearModel/linear_model.c']),
                                                    #Extension('noddy2', sources=['test.c'])
    ])