#ifndef MAP_CPP
#define MAP_CPP
#include "map.h"

Map::Map(int tileSize = 0) { //Initialize a map
    // this->background = backgroundFilePath;
    this->tileSize = tileSize;
}

void Map::addEntity(Entity entity) {
    entityList.push_front(entity);
}

// void Map::removeEntity(Entity entity) {
//     entityList.remove(entity);
// }
#endif
