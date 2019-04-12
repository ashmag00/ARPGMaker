#ifndef MAP_CPP
#define MAP_CPP

#include <SFML/Graphics.hpp>
#include <list>

#include "Entity.cpp"

class Map {
    public:
        Map(int tileSize = 0) { //Initialize a map
            // this->background = backgroundFilePath;
            this->tileSize = tileSize;
        }

        void addEntity(Entity entity) {
            entityList.push_front(entity);
        }

        // void removeEntity(Entity entity) {
        //     entityList.remove(entity);
        // }

        std::list<Entity> entityList;
        char *background;
        int tileSize;//Size in pixels of a tile in the map
};

#endif
