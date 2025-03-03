from setuptools import setup, Extension

module = Extension('mymodule', sources=['mymodule.c'])

setup(
    name='mymodule',
    version='1.0',
    description='A module with a Person type',
    ext_modules=[module]
)
