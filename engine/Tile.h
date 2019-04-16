#ifndef TILE_H
#define TILE_H

#include <stack>

class Tile {
    Tile(int size);
    void setTexture(char *filePath);

    int size;
    unsigned int typeID;
    char *texture;
};

#else
class Tile;
#endif
