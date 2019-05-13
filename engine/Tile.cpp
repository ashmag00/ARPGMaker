#include "Tile.h"

// Store information on a single tile
Tile::Tile(int size, unsigned int ID) {
    this->size = size;
    this->ID = ID;
}
void Tile::setTexture(char *filePath) {
    texture = filePath;
}
void Tile::setTypeID(unsigned int typeID) {
    this->typeID = typeID;
}
