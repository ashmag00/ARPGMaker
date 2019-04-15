#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "memory.h"

// Map g_tmap;
extern unsigned int currentID;

class Entity {
    public:
        Entity(int posx, int posy);
        // Entity(Tile tile);
        void setTexture(char *texturePath);
        void setPosition(int posx, int posy);
        void move(int movex, int movey);
        void move(int numx, int denx, int numy, int deny);

        float x;
        float y;
        unsigned int id;
        char *texture;
};

void move(int id, int posx, int posy);
void setTexture(unsigned int id, char *texturePath);

#else
class Entity;
#endif
