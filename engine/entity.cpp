#include <SFML/Graphics.hpp>

#ifndef ENTITY_CPP
#define ENTITY_CPP

class Entity {
    Entity(int posx, int posy) {
        x = (float) posx;
        y = (float) posy;
    }

    // Entity(Tile tile) {

    // }

    void setTexture(char *texturePath) {
        texture = texturePath;
    }

    void setPosition(int posx, int posy) {
        x = (float) posx;
        y = (float) posy;
    }

    void move(int movex, int movey) {
        x += (float) movex;
        y += (float) movey;
    }

    void move(int numx, int denx, int numy, int deny) {
        x += (float) numx / (float) denx;
        y += (float) numy / (float) deny;
    }


    float x;
    float y;
    char *texture;
    int id;
};

#endif
