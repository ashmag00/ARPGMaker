#include "Entity.h"

extern Map demoMap;
unsigned int currentID;

// Class Methods
Entity::Entity(int posx, int posy) {
    x = (float) posx;
    y = (float) posy;
    demoMap.addEntity(this);
}

// Entity(Tile tile) {

// }

void Entity::setTexture(char *texturePath) {
    texture = texturePath;
}

void Entity::setPosition(int posx, int posy) {
    x = (float) posx;
    y = (float) posy;
}

void Entity::move(int movex, int movey) {
    x += (float) movex;
    y += (float) movey;
}

void Entity::movef(int numx, int denx, int numy, int deny) {
    x += (float) numx / (float) denx;
    y += (float) numy / (float) deny;
}

// Helpers/Wrappers
int createEntity(int posx, int posy) {
    Entity *entity = new Entity(posx, posy);
    entity->id = currentID;
    return currentID++;
}

// Entity getByID(unsigned int id) {
//     for(auto entity: g_tmap.entityList) {
//         if (entity.id == id) {
//             return entity;
//         }
//     }
// }

void move(int id, int posx, int posy) {
    Entity *tmp = demoMap.getEntityByID(id);
    tmp->move(posx, posy);
}

void movef(int id, int numx, int denx, int numy, int deny) {
    Entity *tmp = demoMap.getEntityByID(id);
    tmp->movef(numx, denx, numy, deny);
}

void setTexture(unsigned int id, char *texturePath) {
    Entity *tmp = demoMap.getEntityByID(id);
    tmp->setTexture(texturePath);
}
