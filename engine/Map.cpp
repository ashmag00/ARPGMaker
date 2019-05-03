#include "Map.h"

Map::Map(int tileSize, int tileX, int tileY) { //Initialize a map
    // this->background = backgroundFilePath;
    this->tileSize = tileSize;
    this->tileX = tileX;
    this->tileY = tileY;
    for(int y = 0; y < tileY; y++) {
        for(int x = 0; x < tileX; x++) {
            tileList.push_back(new Tile(tileSize));
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

 void Map::removeEntity(Entity* entity, Tile* tile) {
     this->entityList.remove(entity);
 }

int Map::entityListSize() {
    return this->entityList.size();
}

Tile* Map::accessTile(int x, int y) {
    return tileList[y*this->tileX + x];
}

Entity* Map::getEntityByID(unsigned int entityID) {
    for(std::list<Entity*>::iterator it=entityList.begin(); it != entityList.end(); ++it) {
        if((*it)->id == entityID) {
            return *it;
        }
    }

    return NULL;
}

Map demoMap;
