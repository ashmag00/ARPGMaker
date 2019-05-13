#include "Map.h"
#include <iostream>

Map::Map(int tileSize, int tileX, int tileY) { //Initialize a map
    // this->background = backgroundFilePath;
    this->tileSize = tileSize;
    this->tileX = tileX;
    this->tileY = tileY;
    for(int y = 0; y < tileY; y++) {
        for(int x = 0; x < tileX; x++) {
            tileList.push_back(new Tile(tileSize, y+(x*y)));
        }
    }
}

void Map::addEntity(Entity* entity) {
    int tempX = entity->x / tileSize;
    int tempY = entity->y / tileSize;
    Tile* tile = this->accessTile(tempX, tempY);
    this->addEntity(entity, tile);
}

void Map::addEntity(Entity* entity, Tile* tile) {
    entity->setTile(tile);
    this->entityList.push_back(entity);
}

void Map::removeEntity(Entity* entity) {
    this->entityList.remove(entity);
    // std::cout << this->entityListSize() << std::endl;
}

int Map::entityListSize() {
    return this->entityList.size();
}

Tile* Map::accessTile(int x, int y) {
    return tileList[y*(this->tileX) + x];
}

Entity* Map::getEntityByID(unsigned int entityID) {
    for(std::list<Entity*>::iterator it=entityList.begin(); it != entityList.end(); ++it) {
        if((*it)->id == entityID) {
            return *it;
        }
    }

    return NULL;
}

void remEntity(int entID) {
    Entity *tmp = demoMap.getEntityByID(entID);
    demoMap.removeEntity(tmp);
}

void createMap(int tileSize, int tileX, int tileY) {
    Map *map = new Map(tileSize, tileX, tileY);
    demoMap = *map;
}

Map demoMap;
