from distutils.core import setup, Extension

module = Extension('ARPGMaker',
                   sources = ['extend.cpp', 'engine/render.cpp', 'engine/Entity.cpp', 'engine/inputs.cpp', 'engine/main.cpp', 'engine/Map.cpp', 'engine/Music.cpp', 'engine/Sound.cpp', 'engine/Tile.cpp', 'engine/collisions.cpp'],
                   include_dirs = ['/usr/include/SFML/'],
                   extra_compile_args = ['-std=c++11'],
                   extra_link_args = ['-lsfml-graphics', '-lsfml-window', '-lsfml-system',
                                      '-lsfml-audio', '-lsfml-network'],
                   language = 'c++')

setup(name = 'ARPGMaker', 
      version = '1.0',
      description = 'This is a demo package',
      ext_modules = [module])
