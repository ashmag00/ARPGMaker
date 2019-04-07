from distutils.core import setup, Extension

module = Extension('ARPGMaker',
                   sources = ['ext.cpp'],
                   include_dirs = ['/usr/include/SFML/'],
                   extra_link_args = ['-std=c++11', '-lsfml-graphics', '-lsfml-window', '-lsfml-system',
                                      '-lsfml-audio', '-lsfml-network'],
                   language = 'c++')

setup(name = 'ARPGMaker', 
      version = '1.0',
      description = 'This is a demo package',
      ext_modules = [module])
