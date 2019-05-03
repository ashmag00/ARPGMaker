// Store information on a single tile
Tile::Tile(int size) {
    this->size = size;
}
void Tile::setTexture(char *filePath) {
    texture = filePath;
}
void Tile::setTypeID(unsigned int typeID) {
    this->typeID = typeID;
}
