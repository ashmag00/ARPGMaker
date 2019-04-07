from distutils.core import setup, Extension

module = Extension('spam',
                   sources = ['ext.cpp'],
                   include_dirs = ['/usr/include/SFML/'],
                   extra_link_args = ['-std=c++11', '-lsfml-graphics', '-lsfml-window', '-lsfml-system',
                                      '-lsfml-audio', '-lsfml-network', '-g'],
                   language = 'c++')

setup(name = 'PackageName', 
      version = '1.0',
      description = 'This is a demo package',
      ext_modules = [module])
