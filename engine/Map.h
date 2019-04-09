//TODO: Make specific structure for images, that maps will reference
#include <SFML/Graphics.hpp>
#ifndef MAP_H
#define MAP_H

class Map {
    public:
        Map(int tileSize, char *backgroundFilePath);//Initialize a map
    private:
        char *background;
        int tileSize;//Size in pixels of a tile in the map
};

#endif
