INCLUDE_SFML = -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/
INCLUDE_SFML_EXTRAS = -lsfml-audio -lsfml-network
INCLUDE_GL = -lGL -lGLU -lglut -I/usr/include/GL/

.PHONY: all clean

ARPGMaker: main.cpp Map.cpp
	g++ -std=c++11 -o ARPGMaker main.cpp Map.cpp $(INCLUDE_SFML)

demo: main.cpp demo.cpp
	g++ -std=c++11 -o ARPGMaker demo.cpp render.cpp Entity.cpp inputs.cpp Tile.cpp main.cpp memory.cpp Map.cpp collisions.cpp $(INCLUDE_SFML)

debug: main.cpp demo.cpp
	g++ -std=c++11 -g -o ARPGMaker main.cpp demo.cpp $(INCLUDE_SFML)

all: ARPGMaker

clean :
	rm -rf ARPGMaker *.o
