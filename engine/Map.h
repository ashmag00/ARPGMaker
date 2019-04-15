#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Entity.h"

class Map {
    public:
        Map(int tileSize = 0);//Initialize a map
        void addEntity(Entity* entity);
        //void removeEntity(Entity entity);
        int entityListSize();
        Entity* getEntityByID(unsigned int entityID);
        std::list<Entity*> entityList;
    private:
        int tileSize;//Size in pixels of a tile in the map
        char *background;
};
#else
class Map;
#endif
