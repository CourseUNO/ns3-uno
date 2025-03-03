from setuptools import setup, Extension

module = Extension('uno_extension', sources=['person.c'])

setup(
    name='uno_extension',
    version='1.0',
    description='A module with a Person type',
    ext_modules=[module]
)
