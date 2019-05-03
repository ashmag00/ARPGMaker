#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "memory.h"
#include "Tile.h"

// Map g_tmap;
extern unsigned int currentID;

class Entity {
    public:
        Entity(int posx, int posy);
        // Entity(Tile tile);
        void setTexture(char *texturePath);
        void setPosition(int posx, int posy);
        void setTile(Tile* tile);
        void move(int movex, int movey);
        void movef(int numx, int denx, int numy, int deny);
    //private:
        Tile* tile;
        float x;
        float y;
        unsigned int id;
        char *texture;
        friend class Map;
};

int createEntity(int posx, int posy);
void move(int id, int posx, int posy);
void movef(int id, int numx, int denx, int numy, int deny);
void setTexture(unsigned int id, char *texturePath);

#else
class Entity;
#endif
