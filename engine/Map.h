#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Entity.cpp"

class Map {
    public:
        Map(int tileSize);//Initialize a map
        void addEntity(Entity entity);
        //void removeEntity(Entity entity);
        std::list<Entity> entityList;
    private:
        char *background;
        int tileSize;//Size in pixels of a tile in the map
};

#endif
