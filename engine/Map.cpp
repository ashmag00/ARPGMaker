#include "Map.h"

Map::Map(int tileSize) { //Initialize a map
    // this->background = backgroundFilePath;
    this->tileSize = tileSize;
}

void Map::addEntity(Entity* entity) {
    entityList.push_front(entity);
}

// void Map::removeEntity(Entity entity) {
//     entityList.remove(entity);
// }

int Map::entityListSize() {
    return entityList.size();
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

