#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "Tile.h"
#include "Entity.h"

// GABE: "I included the sound.h and music.h files so that
//       the list objects I created in them are created."
#include "Sound.h"
#include "Music.h"

class Map {
    public:
        Map(int tileSize = 0, int tileX = 0, int tileY = 0);//Initialize a map
        void addEntity(Entity* entity);
        void addEntity(Entity* entity, Tile* tile);
        void removeEntity(Entity* entity, Tile* tile);
        int entityListSize();
        Tile* accessTile(int x, int y);
        Entity* getEntityByID(unsigned int entityID);
        //std::list<Entity*> entityList;
    private:
        std::vector<Tile*> tileList;
        std::list<Entity*> entityList;
        int tileSize;//Size in pixels of a tile in the map
        int tileX;
        int tileY;
        char *background;
};
#else
class Map;
#endif
