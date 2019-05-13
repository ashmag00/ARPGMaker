#ifndef TILE_H
#define TILE_H

#include <stack>
#include <list>
#include "Entity.h"

class Tile {
    public:
        Tile(int size, unsigned int ID);
        void setTexture(char *filePath);
        void setTypeID(unsigned int typeID);
    // private:
        int size;
        unsigned int ID;
        unsigned int typeID;
        char *texture;
};

#else
class Tile;
#endif
